#include "Signup.h"
#include "MDIForm.h"  

void university::Signup::btn_Signup_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Basic validation
            if (String::IsNullOrEmpty(txt_fname->Text) ||
                String::IsNullOrEmpty(txt_lname->Text) ||
                String::IsNullOrEmpty(txt_Email->Text) ||
                String::IsNullOrEmpty(txt_password->Text) ||
                String::IsNullOrEmpty(txt_TPassword->Text)) {
                MessageBox::Show("Please fill in all fields!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            // Check if passwords match
            if (txt_password->Text != txt_TPassword->Text) {
                MessageBox::Show("Passwords do not match!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            sqlConn->Open();
            sqlCmd->Connection = sqlConn;

            // Check if email already exists
            sqlCmd->CommandText = "SELECT * FROM users WHERE username = @email";
            sqlCmd->Parameters->Clear();
            sqlCmd->Parameters->AddWithValue("@email", txt_Email->Text);

            sqlRd = sqlCmd->ExecuteReader();
            if (sqlRd->Read()) {
                sqlRd->Close();
                MessageBox::Show("Email already registered!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            sqlRd->Close();

            // Insert new user
            sqlCmd->CommandText = "INSERT INTO users (firstname, lastname, username, password) VALUES (@fname, @lname, @email, @password)";
            sqlCmd->Parameters->Clear();
            sqlCmd->Parameters->AddWithValue("@fname", txt_fname->Text);
            sqlCmd->Parameters->AddWithValue("@lname", txt_lname->Text);
            sqlCmd->Parameters->AddWithValue("@email", txt_Email->Text);
            sqlCmd->Parameters->AddWithValue("@password", txt_password->Text);

            sqlCmd->ExecuteNonQuery();
            MessageBox::Show("Registration successful!", "Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            // Proceed to main form
            MDIForm^ MdiParent = gcnew MDIForm();
            MdiParent->Show();
            this->Hide();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (sqlConn->State == ConnectionState::Open)
                sqlConn->Close();
        }
    }