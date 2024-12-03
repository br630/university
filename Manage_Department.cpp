#include "Manage_Department.h"
#include "db_conn.h"

namespace university {
    // Helper class for ComboBox items
    ref class ComboboxItem {
    public:
        String^ Text;
        String^ Value;

        ComboboxItem(String^ text, String^ value) {
            Text = text;
            Value = value;
        }

        virtual String^ ToString() override {
            return Text;
        }
    };

    System::Void Manage_Department::Form_Load(System::Object^ sender, System::EventArgs^ e) {
        SetupDataGridView();
        LoadFacultyMembers();
        LoadDepartments();
    }

    void Manage_Department::SetupDataGridView() {
        // Setup Departments DataGridView
        dataGridDepartments->AutoGenerateColumns = false;
        dataGridDepartments->Columns->Clear();

        array<String^>^ columnHeaders = {
            "Department ID", "Department Name", "Head of Department"
        };

        for each (String ^ header in columnHeaders) {
            DataGridViewTextBoxColumn^ column = gcnew DataGridViewTextBoxColumn();
            column->HeaderText = header;
            column->Name = header->Replace(" ", "");
            column->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            dataGridDepartments->Columns->Add(column);
        }

        // Setup Faculty DataGridView
        dataGridFaculty->AutoGenerateColumns = false;
        dataGridFaculty->Columns->Clear();

        array<String^>^ facultyColumns = {
            "Faculty ID", "First Name", "Last Name", "Email", "Appointment Date"
        };

        for each (String ^ header in facultyColumns) {
            DataGridViewTextBoxColumn^ column = gcnew DataGridViewTextBoxColumn();
            column->HeaderText = header;
            column->Name = header->Replace(" ", "");
            column->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            dataGridFaculty->Columns->Add(column);
        }

        // Setup Students DataGridView
        dataGridStudents->AutoGenerateColumns = false;
        dataGridStudents->Columns->Clear();

        array<String^>^ studentColumns = {
            "Student ID", "First Name", "Last Name", "Email", "Major"
        };

        for each (String ^ header in studentColumns) {
            DataGridViewTextBoxColumn^ column = gcnew DataGridViewTextBoxColumn();
            column->HeaderText = header;
            column->Name = header->Replace(" ", "");
            column->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            dataGridStudents->Columns->Add(column);
        }
    }

    void Manage_Department::LoadFacultyMembers() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT f.facultyID, u.firstName, u.lastName "
                "FROM faculty f "
                "JOIN users u ON f.userID = u.userID "
                "WHERE u.role = 'Faculty' "
                "ORDER BY u.lastName, u.firstName";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            comboHeadOfDepartment->Items->Clear();
            comboHeadOfDepartment->Items->Add(gcnew ComboboxItem("-- Select Department Head --", "0"));

            while (reader->Read()) {
                String^ fullName = reader["firstName"]->ToString() + " " + reader["lastName"]->ToString();
                String^ facultyId = reader["facultyID"]->ToString();
                comboHeadOfDepartment->Items->Add(gcnew ComboboxItem(fullName, facultyId));
            }

            comboHeadOfDepartment->SelectedIndex = 0;
            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading faculty members: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void Manage_Department::LoadDepartments() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT d.DepartmentID, d.DepartmentName, "
                "CONCAT(u.firstName, ' ', u.lastName) as HeadName "
                "FROM departments d "
                "LEFT JOIN faculty f ON d.HeadOfDepartment = f.facultyID "
                "LEFT JOIN users u ON f.userID = u.userID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridDepartments->Rows->Clear();

            while (reader->Read()) {
                String^ headName = reader->IsDBNull(reader->GetOrdinal("HeadName")) ?
                    "Not Assigned" : reader["HeadName"]->ToString();

                dataGridDepartments->Rows->Add(
                    reader["DepartmentID"]->ToString(),
                    reader["DepartmentName"]->ToString(),
                    headName
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading departments: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void Manage_Department::LoadDepartmentFaculty(int departmentId) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT f.facultyID, u.firstName, u.lastName, u.email, f.dateOfAppointment "
                "FROM faculty f "
                "JOIN users u ON f.userID = u.userID "
                "WHERE f.department = (SELECT DepartmentName FROM departments WHERE DepartmentID = @deptId) "
                "ORDER BY u.lastName, u.firstName";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@deptId", departmentId);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridFaculty->Rows->Clear();

            while (reader->Read()) {
                dataGridFaculty->Rows->Add(
                    reader["facultyID"]->ToString(),
                    reader["firstName"]->ToString(),
                    reader["lastName"]->ToString(),
                    reader["email"]->ToString(),
                    reader["dateOfAppointment"]->ToString()
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading department faculty: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void Manage_Department::LoadDepartmentStudents(int departmentId) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT s.studentID, u.firstName, u.lastName, u.email, s.major "
                "FROM students s "
                "JOIN users u ON s.userID = u.userID "
                "WHERE s.major = (SELECT DepartmentName FROM departments WHERE DepartmentID = @deptId) "
                "ORDER BY u.lastName, u.firstName";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@deptId", departmentId);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridStudents->Rows->Clear();

            while (reader->Read()) {
                dataGridStudents->Rows->Add(
                    reader["studentID"]->ToString(),
                    reader["firstName"]->ToString(),
                    reader["lastName"]->ToString(),
                    reader["email"]->ToString(),
                    reader["major"]->ToString()
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading department students: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    bool Manage_Department::ValidateInput() {
        if (String::IsNullOrWhiteSpace(txtDepartmentName->Text)) {
            MessageBox::Show("Please enter a department name.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }
        return true;
    }

    void Manage_Department::ClearForm() {
        txtDepartmentID->Clear();
        txtDepartmentName->Clear();
        comboHeadOfDepartment->SelectedIndex = 0;
        txtSearch->Clear();
        dataGridFaculty->Rows->Clear();
        dataGridStudents->Rows->Clear();
    }

    System::Void Manage_Department::btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput()) return;

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "INSERT INTO departments (DepartmentName, HeadOfDepartment) "
                "VALUES (@name, @head)";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            ComboboxItem^ selectedHead = safe_cast<ComboboxItem^>(comboHeadOfDepartment->SelectedItem);

            cmd->Parameters->AddWithValue("@name", txtDepartmentName->Text);
            cmd->Parameters->AddWithValue("@head", DBNull::Value);  // Default to NULL

            // Only set head if one is selected and it's not the default "-- Select --" option
            if (selectedHead != nullptr && selectedHead->Value != "0") {
                cmd->Parameters->AddWithValue("@head", Convert::ToInt32(selectedHead->Value));
            }

            dbManager->ConnectToDatabase();
            cmd->ExecuteNonQuery();

            MessageBox::Show("Department added successfully!", "Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            LoadDepartments();
            ClearForm();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error adding department: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Manage_Department::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput() || String::IsNullOrEmpty(txtDepartmentID->Text)) {
                MessageBox::Show("Please select a department to update.", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "UPDATE departments SET DepartmentName = @name, HeadOfDepartment = @head "
                "WHERE DepartmentID = @id";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            ComboboxItem^ selectedHead = safe_cast<ComboboxItem^>(comboHeadOfDepartment->SelectedItem);

            cmd->Parameters->AddWithValue("@name", txtDepartmentName->Text);

            // Fixed the type incompatibility issue
            if (selectedHead->Value != "0") {
                cmd->Parameters->AddWithValue("@head", Convert::ToInt32(selectedHead->Value));
            }
            else {
                cmd->Parameters->AddWithValue("@head", DBNull::Value);
            }

            cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtDepartmentID->Text));

            dbManager->ConnectToDatabase();
            cmd->ExecuteNonQuery();

            MessageBox::Show("Department updated successfully!", "Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            LoadDepartments();
            ClearForm();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating department: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Manage_Department::btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (String::IsNullOrEmpty(txtDepartmentID->Text)) {
                MessageBox::Show("Please select a department to delete.", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            if (MessageBox::Show("Are you sure you want to delete this department?\nThis will affect all faculty and students in the department.",
                "Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) ==
                System::Windows::Forms::DialogResult::Yes) {

                DatabaseManager^ dbManager = DatabaseManager::GetInstance();
                MySqlConnection^ conn = dbManager->GetConnection();

                String^ query = "DELETE FROM departments WHERE DepartmentID = @id";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtDepartmentID->Text));

                dbManager->ConnectToDatabase();
                cmd->ExecuteNonQuery();

                MessageBox::Show("Department deleted successfully!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);

                LoadDepartments();
                ClearForm();
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error deleting department: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Manage_Department::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT d.DepartmentID, d.DepartmentName, "
                "CONCAT(u.firstName, ' ', u.lastName) as HeadName "
                "FROM departments d "
                "LEFT JOIN faculty f ON d.HeadOfDepartment = f.facultyID "
                "LEFT JOIN users u ON f.userID = u.userID "
                "WHERE d.DepartmentName LIKE @search";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@search", "%" + txtSearch->Text + "%");

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridDepartments->Rows->Clear();

            while (reader->Read()) {
                String^ headName = reader->IsDBNull(reader->GetOrdinal("HeadName")) ?
                    "Not Assigned" : reader["HeadName"]->ToString();

                dataGridDepartments->Rows->Add(
                    reader["DepartmentID"]->ToString(),
                    reader["DepartmentName"]->ToString(),
                    headName
                );
            }

            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error searching departments: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Manage_Department::btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
        ClearForm();
    }

    System::Void Manage_Department::dataGridDepartments_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            try {
                // Get the selected department's data
                txtDepartmentID->Text = dataGridDepartments->Rows[e->RowIndex]->Cells["DepartmentID"]->Value->ToString();
                txtDepartmentName->Text = dataGridDepartments->Rows[e->RowIndex]->Cells["DepartmentName"]->Value->ToString();

                String^ headName = dataGridDepartments->Rows[e->RowIndex]->Cells["HeadofDepartment"]->Value->ToString();

                // Find and select the department head in the combo box
                for (int i = 0; i < comboHeadOfDepartment->Items->Count; i++) {
                    ComboboxItem^ item = safe_cast<ComboboxItem^>(comboHeadOfDepartment->Items[i]);
                    if (item->Text == headName) {
                        comboHeadOfDepartment->SelectedIndex = i;
                        break;
                    }
                }

                // Load department members (faculty and students)
                int departmentId = Convert::ToInt32(txtDepartmentID->Text);
                LoadDepartmentFaculty(departmentId);
                LoadDepartmentStudents(departmentId);

                // Select the first tab by default
                tabControlMembers->SelectedIndex = 0;
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading department details: " + ex->Message,
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    }
};
