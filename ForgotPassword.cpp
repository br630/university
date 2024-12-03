// ForgotPassword.cpp
#include "ForgotPassword.h"

namespace university {
    System::Void ForgotPassword::btnResetPassword_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ email = txtEmail->Text->Trim();
            String^ newPassword = txtNewPassword->Text;
            String^ confirmPassword = txtConfirmPassword->Text;

            if (String::IsNullOrEmpty(email) ||
                String::IsNullOrEmpty(newPassword) ||
                String::IsNullOrEmpty(confirmPassword)) {
                MessageBox::Show("Please fill in all fields!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            if (newPassword != confirmPassword) {
                MessageBox::Show("Passwords do not match!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            if (newPassword->Length < 6) {
                MessageBox::Show("Password must be at least 6 characters long!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            // First verify if the email exists
            MySqlCommand^ checkCmd = gcnew MySqlCommand(
                "SELECT COUNT(*) FROM users WHERE email = @email", conn);
            checkCmd->Parameters->AddWithValue("@email", email);

            dbManager->ConnectToDatabase();
            int userExists = Convert::ToInt32(checkCmd->ExecuteScalar());

            if (userExists == 0) {
                MessageBox::Show("No account found with this email address!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Update the password
            MySqlCommand^ updateCmd = gcnew MySqlCommand(
                "UPDATE users SET password = @password WHERE email = @email", conn);
            updateCmd->Parameters->AddWithValue("@password", newPassword);
            updateCmd->Parameters->AddWithValue("@email", email);

            updateCmd->ExecuteNonQuery();

            MessageBox::Show("Password has been reset successfully!", "Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            this->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error resetting password: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void ForgotPassword::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
}