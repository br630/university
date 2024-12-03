#include "Manage_Faculty.h"
#include "db_conn.h"
#include "PasswordHasher.h"

namespace university {
    System::Void Manage_Faculty::Form_Load(System::Object^ sender, System::EventArgs^ e) {
        SetupDataGridView();
        LoadDepartments();
        LoadFaculty();
    }

    void Manage_Faculty::LoadDepartments() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT DepartmentName FROM departments ORDER BY DepartmentName";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            comboDepartment->Items->Clear();
            comboDepartment->Items->Add("-- Select Department --");

            while (reader->Read()) {
                comboDepartment->Items->Add(reader["DepartmentName"]->ToString());
            }

            comboDepartment->SelectedIndex = 0;

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading departments: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void Manage_Faculty::SetupDataGridView() {
        dataGridFaculty->AutoGenerateColumns = false;
        dataGridFaculty->Columns->Clear();

        array<String^>^ columnHeaders = {
            "Faculty ID", "First Name", "Last Name", "Email", "Department"
        };

        for each (String ^ header in columnHeaders) {
            DataGridViewColumn^ column = gcnew DataGridViewTextBoxColumn();
            column->HeaderText = header;
            column->Name = header->Replace(" ", "");
            column->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            dataGridFaculty->Columns->Add(column);
        }
    }

    void Manage_Faculty::LoadFaculty() {
        MySqlDataReader^ reader = nullptr;
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT f.facultyID, u.firstName, u.lastName, u.email, "
                "f.department "
                "FROM faculty f "
                "JOIN users u ON f.userID = u.userID "
                "WHERE u.role = 'Faculty'";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            dbManager->ConnectToDatabase();
            reader = cmd->ExecuteReader();

            dataGridFaculty->Rows->Clear();

            while (reader->Read()) {
                dataGridFaculty->Rows->Add(
                    reader["facultyID"]->ToString(),
                    reader["firstName"]->ToString(),
                    reader["lastName"]->ToString(),
                    reader["email"]->ToString(),
                    reader["department"]->ToString()
                );
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading faculty data: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (reader != nullptr) reader->Close();
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    // Modified Manage_Faculty.cpp (relevant parts)
    System::Void Manage_Faculty::btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput()) return;

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            MySqlTransaction^ transaction = conn->BeginTransaction();

            try {
                String^ hashedPassword = PasswordHasher::HashPassword(txtPassword->Text);

                String^ userQuery = "INSERT INTO users (firstName, lastName, email, password, role) "
                    "VALUES (@firstName, @lastName, @email, @password, 'Faculty'); SELECT LAST_INSERT_ID();";

                MySqlCommand^ userCmd = gcnew MySqlCommand(userQuery, conn);
                userCmd->Transaction = transaction;

                userCmd->Parameters->AddWithValue("@firstName", txtFirstName->Text);
                userCmd->Parameters->AddWithValue("@lastName", txtLastName->Text);
                userCmd->Parameters->AddWithValue("@email", txtEmail->Text);
                userCmd->Parameters->AddWithValue("@password", hashedPassword);

                int userID = Convert::ToInt32(userCmd->ExecuteScalar());

                String^ facultyQuery = "INSERT INTO faculty (userID, department) VALUES (@userID, @department)";
                MySqlCommand^ facultyCmd = gcnew MySqlCommand(facultyQuery, conn);
                facultyCmd->Transaction = transaction;

                facultyCmd->Parameters->AddWithValue("@userID", userID);
                facultyCmd->Parameters->AddWithValue("@department", comboDepartment->Text);

                facultyCmd->ExecuteNonQuery();

                transaction->Commit();
                MessageBox::Show("Faculty member added successfully!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);

                LoadFaculty();
                ClearForm();
            }
            catch (Exception^ ex) {
                transaction->Rollback();
                throw ex;
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error adding faculty member: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Manage_Faculty::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput() || String::IsNullOrEmpty(txtFacultyID->Text)) return;

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            MySqlTransaction^ transaction = conn->BeginTransaction();

            try {
                int facultyID = Convert::ToInt32(txtFacultyID->Text);

                String^ userQuery = "UPDATE users u "
                    "JOIN faculty f ON u.userID = f.userID "
                    "SET u.firstName = @firstName, u.lastName = @lastName, "
                    "u.email = @email "
                    "WHERE f.facultyID = @facultyID";

                MySqlCommand^ userCmd = gcnew MySqlCommand(userQuery, conn);
                userCmd->Transaction = transaction;

                userCmd->Parameters->AddWithValue("@facultyID", facultyID);
                userCmd->Parameters->AddWithValue("@firstName", txtFirstName->Text);
                userCmd->Parameters->AddWithValue("@lastName", txtLastName->Text);
                userCmd->Parameters->AddWithValue("@email", txtEmail->Text);

                userCmd->ExecuteNonQuery();

                String^ facultyQuery = "UPDATE faculty SET department = @department WHERE facultyID = @facultyID";
                MySqlCommand^ facultyCmd = gcnew MySqlCommand(facultyQuery, conn);
                facultyCmd->Transaction = transaction;

                facultyCmd->Parameters->AddWithValue("@facultyID", facultyID);
                facultyCmd->Parameters->AddWithValue("@department", comboDepartment->Text);

                facultyCmd->ExecuteNonQuery();

                transaction->Commit();
                MessageBox::Show("Faculty member updated successfully!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);

                LoadFaculty();
                ClearForm();
            }
            catch (Exception^ ex) {
                transaction->Rollback();
                throw ex;
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating faculty member: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    bool Manage_Faculty::ValidateInput() {
        if (String::IsNullOrWhiteSpace(txtFirstName->Text) ||
            String::IsNullOrWhiteSpace(txtLastName->Text) ||
            String::IsNullOrWhiteSpace(txtEmail->Text) ||
            comboDepartment->SelectedIndex == 0) {
            MessageBox::Show("Please fill in all required fields.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }
        if (!String::IsNullOrEmpty(txtEmail->Text)) {
            try {
                System::Net::Mail::MailAddress^ addr = gcnew System::Net::Mail::MailAddress(txtEmail->Text);
            }
            catch (...) {
                MessageBox::Show("Please enter a valid email address.", "Validation Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return false;
            }
        }

        if (!String::IsNullOrEmpty(txtPassword->Text) && txtPassword->Text->Length < 6) {
            MessageBox::Show("Password must be at least 6 characters long.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }
        return true;
    }

    void Manage_Faculty::ClearForm() {
        txtFacultyID->Clear();
        txtFirstName->Clear();
        txtLastName->Clear();
        txtEmail->Clear();
        txtPassword->Clear();
        comboDepartment->SelectedIndex = 0;
    }

    System::Void Manage_Faculty::dataGridFaculty_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            txtFacultyID->Text = dataGridFaculty->Rows[e->RowIndex]->Cells["FacultyID"]->Value->ToString();
            txtFirstName->Text = dataGridFaculty->Rows[e->RowIndex]->Cells["FirstName"]->Value->ToString();
            txtLastName->Text = dataGridFaculty->Rows[e->RowIndex]->Cells["LastName"]->Value->ToString();
            txtEmail->Text = dataGridFaculty->Rows[e->RowIndex]->Cells["Email"]->Value->ToString();
            comboDepartment->Text = dataGridFaculty->Rows[e->RowIndex]->Cells["Department"]->Value->ToString();
            txtPassword->Clear();
        }
    }

    // TODO: Implement these methods
    System::Void Manage_Faculty::btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        // Implementation needed
    }

    System::Void Manage_Faculty::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        // Implementation needed
    }

    System::Void Manage_Faculty::btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
        ClearForm();
    }
}