#include "Register_User.h"
#include "db_conn.h"
#include "PasswordHasher.h"

namespace university {

    System::Void Register_User::btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput()) {
                return;
            }

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            MySqlTransaction^ transaction = conn->BeginTransaction();

            try {
                // Hash the password before storing
                String^ hashedPassword = PasswordHasher::HashPassword(txtPassword->Text);

                String^ userQuery = "INSERT INTO users (firstName, lastName, email, password, role) "
                    "VALUES (@firstName, @lastName, @email, @password, 'Student'); "
                    "SELECT LAST_INSERT_ID();";

                MySqlCommand^ userCmd = gcnew MySqlCommand(userQuery, conn);
                userCmd->Transaction = transaction;

                userCmd->Parameters->AddWithValue("@firstName", txtFirstName->Text);
                userCmd->Parameters->AddWithValue("@lastName", txtLastName->Text);
                userCmd->Parameters->AddWithValue("@email", txtEmail->Text);
                userCmd->Parameters->AddWithValue("@password", hashedPassword); ;

                // Get the inserted user ID
                int userID = Convert::ToInt32(userCmd->ExecuteScalar());

                // Now insert into students table
                String^ studentQuery = "INSERT INTO students (userID, dateOfBirth, major, enrollmentDate) "
                    "VALUES (@userID, @dateOfBirth, @major, @enrollmentDate)";

                MySqlCommand^ studentCmd = gcnew MySqlCommand(studentQuery, conn);
                studentCmd->Transaction = transaction;

                studentCmd->Parameters->AddWithValue("@userID", userID);
                studentCmd->Parameters->AddWithValue("@dateOfBirth", datePickerDOB->Value);
                studentCmd->Parameters->AddWithValue("@major", comboMajor->Text);
                studentCmd->Parameters->AddWithValue("@enrollmentDate", DateTime::Now);

                studentCmd->ExecuteNonQuery();

                // Now insert into currentYR table
                String^ currentYearQuery = "INSERT INTO currentYR (userID, currentYear) "
                    "VALUES (@userID, @currentYear)";

                MySqlCommand^ currentYearCmd = gcnew MySqlCommand(currentYearQuery, conn);
                currentYearCmd->Transaction = transaction;

                currentYearCmd->Parameters->AddWithValue("@userID", userID);
                currentYearCmd->Parameters->AddWithValue("@currentYear", comboCurrentYear->Text);

                currentYearCmd->ExecuteNonQuery();

                // If we got here, everything worked - commit the transaction
                transaction->Commit();

                MessageBox::Show("Student registered successfully!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);

                ClearForm();
            }
            catch (Exception^ ex) {
                // Something went wrong - rollback the transaction
                transaction->Rollback();
                throw ex;
            }
            finally {
                dbManager->CloseConnection();
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error registering student: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void Register_User::comboMajor_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        btnRegister->Enabled = comboMajor->SelectedIndex != 0;
    }


    bool Register_User::ValidateInput() {
        // Check for empty fields
        if (String::IsNullOrWhiteSpace(txtFirstName->Text) ||
            String::IsNullOrWhiteSpace(txtLastName->Text) ||
            String::IsNullOrWhiteSpace(txtEmail->Text) ||
            String::IsNullOrWhiteSpace(txtPassword->Text) ||
            String::IsNullOrWhiteSpace(comboMajor->Text)) {
            MessageBox::Show("Please fill in all required fields.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }

        // Validate email format
        if (!IsValidEmail(txtEmail->Text)) {
            MessageBox::Show("Please enter a valid email address.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }

        // Validate password length
        if (txtPassword->Text->Length < 6) {
            MessageBox::Show("Password must be at least 6 characters long.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }

        // Validate date of birth (student must be at least 16 years old)
        TimeSpan age = DateTime::Now - datePickerDOB->Value;
        int years = age.Days / 365;
        if (years < 16) {
            MessageBox::Show("Student must be at least 16 years old.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }

        return true;
    }

    bool Register_User::IsValidEmail(String^ email) {
        try {
            System::Net::Mail::MailAddress^ addr = gcnew System::Net::Mail::MailAddress(email);
            return addr->Address == email;
        }
        catch (...) {
            return false;
        }
    }

    void Register_User::ClearForm() {
        txtFirstName->Clear();
        txtLastName->Clear();
        txtEmail->Clear();
        txtPassword->Clear();
        comboMajor->SelectedIndex = -1;
        datePickerDOB->Value = DateTime::Now;
    }

    System::Void Register_User::Register_User_Load(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Get database connection
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            // Create query to get all department names
            String^ query = "SELECT DepartmentName FROM departments ORDER BY DepartmentName";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            // Clear existing items
            comboMajor->Items->Clear();

            // Add default selection
            comboMajor->Items->Add("-- Select Department --");

            // Execute query and add departments to combo box
            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                comboMajor->Items->Add(reader["DepartmentName"]->ToString());
            }

            reader->Close();
            dbManager->CloseConnection();

            // Set default selection
            comboMajor->SelectedIndex = 0;

            // Set date picker settings
            datePickerDOB->Value = DateTime::Now.AddYears(-18);
            datePickerDOB->MaxDate = DateTime::Now.AddYears(-16);  // Must be at least 16
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading departments: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void Register_User::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
}