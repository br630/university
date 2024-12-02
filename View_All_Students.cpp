#include "View_All_Students.h"
#include "db_conn.h"

namespace university {
    System::Void View_All_Students::btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (gridUsers->SelectedRows->Count == 0) return;

            int studentID = Convert::ToInt32(gridUsers->SelectedRows[0]->Cells["Student ID"]->Value);

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "UPDATE students s "
                "JOIN users u ON s.userID = u.userID "
                "SET u.firstName = @firstName, u.lastName = @lastName, "
                "u.email = @email, s.major = @major "
                "WHERE s.studentID = @studentID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@firstName", txtEditFirstName->Text);
            cmd->Parameters->AddWithValue("@lastName", txtEditLastName->Text);
            cmd->Parameters->AddWithValue("@email", txtEditEmail->Text);
            cmd->Parameters->AddWithValue("@major", txtEditMajor->Text);
            cmd->Parameters->AddWithValue("@studentID", studentID);

            dbManager->ConnectToDatabase();
            cmd->ExecuteNonQuery();
            dbManager->CloseConnection();

            MessageBox::Show("Student updated successfully!", "Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            LoadUsersData();
            ClearEditFields();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating student: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void View_All_Students::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        ClearEditFields();
    }

    void View_All_Students::ClearEditFields() {
        txtEditFirstName->Clear();
        txtEditLastName->Clear();
        txtEditEmail->Clear();
        txtEditMajor->Clear();
    }
    System::Void View_All_Students::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
        if (gridUsers->SelectedRows->Count > 0) {
            txtEditFirstName->Text = gridUsers->SelectedRows[0]->Cells["First Name"]->Value->ToString();
            txtEditLastName->Text = gridUsers->SelectedRows[0]->Cells["Last Name"]->Value->ToString();
            txtEditEmail->Text = gridUsers->SelectedRows[0]->Cells["Email"]->Value->ToString();
            txtEditMajor->Text = gridUsers->SelectedRows[0]->Cells["Major"]->Value->ToString();
        }
        else {
            MessageBox::Show("Please select a student to update.", "Warning",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
    System::Void View_All_Students::btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        if (gridUsers->SelectedRows->Count > 0) {
            try {
                if (MessageBox::Show("Are you sure you want to delete this student?", "Confirm Delete",
                    MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) {

                    int studentID = Convert::ToInt32(gridUsers->SelectedRows[0]->Cells["Student ID"]->Value);
                    int userID = 0;

                    DatabaseManager^ dbManager = DatabaseManager::GetInstance();
                    MySqlConnection^ conn = dbManager->GetConnection();

                    // Start transaction
                    dbManager->ConnectToDatabase();
                    MySqlTransaction^ transaction = conn->BeginTransaction();

                    try {
                        // First get the userID
                        String^ queryGetUserID = "SELECT userID FROM students WHERE studentID = @studentID";
                        MySqlCommand^ cmdGetUserID = gcnew MySqlCommand(queryGetUserID, conn);
                        cmdGetUserID->Transaction = transaction;
                        cmdGetUserID->Parameters->AddWithValue("@studentID", studentID);

                        MySqlDataReader^ reader = cmdGetUserID->ExecuteReader();
                        if (reader->Read()) {
                            userID = Convert::ToInt32(reader["userID"]);
                        }
                        reader->Close();

                        // Delete from students table
                        String^ queryDeleteStudent = "DELETE FROM students WHERE studentID = @studentID";
                        MySqlCommand^ cmdDeleteStudent = gcnew MySqlCommand(queryDeleteStudent, conn);
                        cmdDeleteStudent->Transaction = transaction;
                        cmdDeleteStudent->Parameters->AddWithValue("@studentID", studentID);
                        cmdDeleteStudent->ExecuteNonQuery();

                        // Delete from users table
                        String^ queryDeleteUser = "DELETE FROM users WHERE userID = @userID";
                        MySqlCommand^ cmdDeleteUser = gcnew MySqlCommand(queryDeleteUser, conn);
                        cmdDeleteUser->Transaction = transaction;
                        cmdDeleteUser->Parameters->AddWithValue("@userID", userID);
                        cmdDeleteUser->ExecuteNonQuery();

                        // Commit transaction
                        transaction->Commit();

                        MessageBox::Show("Student deleted successfully!", "Success",
                            MessageBoxButtons::OK, MessageBoxIcon::Information);

                        // Refresh the data
                        LoadUsersData();
                    }
                    catch (Exception^ ex) {
                        transaction->Rollback();
                        throw ex;
                    }
                    finally {
                        dbManager->CloseConnection();
                    }
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error deleting student: " + ex->Message, "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        else {
            MessageBox::Show("Please select a student to delete.", "Warning",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
    void View_All_Students::LoadUsersData(void) {
        try {
            // Clear existing rows
            this->gridUsers->Rows->Clear();

            // Get database instance
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            // Create command for querying users and students
            String^ query = "SELECT u.userID, u.firstName, u.lastName, u.email, u.role, "
                "s.studentID, s.major, s.enrollmentDate "
                "FROM users u "
                "INNER JOIN students s ON u.userID = s.userID "
                "WHERE u.role = 'Student'";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            // Open connection and execute query
            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            // Setup grid if not already done
            if (this->gridUsers->ColumnCount == 0) {
                SetupUsersGrid();
            }

            // Add data to grid
            while (reader->Read()) {
                String^ status = "Active"; // You might want to add a status field to your database

                this->gridUsers->Rows->Add(
                    reader["studentID"]->ToString(),
                    reader["firstName"]->ToString(),
                    reader["lastName"]->ToString(),
                    reader["email"]->ToString(),
                    reader["major"]->ToString(),
                    reader["enrollmentDate"]->ToString(),
                    status
                );
            }

            reader->Close();
            dbManager->CloseConnection();

            UpdateStatusBar();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading student data: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void View_All_Students::SetupUsersGrid(void) {
        this->gridUsers->ColumnCount = 7;
        array<String^>^ columnNames = {
            "Student ID",
            "First Name",
            "Last Name",
            "Email",
            "Major",
            "Enrollment Date",
            "Status"
        };

        // Set up columns
        for (int i = 0; i < columnNames->Length; i++) {
            this->gridUsers->Columns[i]->Name = columnNames[i];
            this->gridUsers->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
        }

        // Additional grid settings
        this->gridUsers->AllowUserToAddRows = false;
        this->gridUsers->AllowUserToDeleteRows = false;
        this->gridUsers->ReadOnly = true;
        this->gridUsers->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        this->gridUsers->MultiSelect = false;
    }

    void View_All_Students::FilterUsers(void) {
        String^ searchText = this->txtSearch->Text->ToLower();

        for each (DataGridViewRow ^ row in this->gridUsers->Rows) {
            bool showRow = true;

            if (!String::IsNullOrEmpty(searchText)) {
                bool matchFound = false;
                for each (DataGridViewCell ^ cell in row->Cells) {
                    if (cell->Value != nullptr) {
                        String^ cellValue = cell->Value->ToString()->ToLower();
                        if (cellValue->Contains(searchText)) {
                            matchFound = true;
                            break;
                        }
                    }
                }
                showRow = matchFound;
            }

            row->Visible = showRow;
        }

        UpdateStatusBar();
    }

    void View_All_Students::UpdateStatusBar(void) {
        int visibleRows = 0;
        for each (DataGridViewRow ^ row in this->gridUsers->Rows) {
            if (row->Visible) visibleRows++;
        }
        this->lblTotalUsers->Text = String::Format("Total Students: {0}", visibleRows);
        this->statusLabel->Text = String::Format("Showing {0} of {1} students",
            visibleRows, this->gridUsers->Rows->Count);
    }
}