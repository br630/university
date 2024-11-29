#include "MyForm.h"
#include "Signup.h"
#include "MDIForm.h"

namespace university {
    Signup::Signup(void)
    {
        InitializeComponent();
        sqlConn = gcnew MySqlConnection();
        sqlCmd = gcnew MySqlCommand();
        connectionString = "datasource=localhost;port=3306;username=root;password=;database=university_management;";
        sqlConn->ConnectionString = connectionString;

    }

    System::Void Signup::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }

    System::Void Signup::btnSignup_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ email = txtuserName->Text;
            String^ password = txtPassword->Text;
            String^ confirmPassword = txtPassword1->Text;
            String^ firstName = txt_fname->Text;
            String^ lastName = txt_lname->Text;

            if (String::IsNullOrEmpty(email) || String::IsNullOrEmpty(password) ||
                String::IsNullOrEmpty(confirmPassword) || String::IsNullOrEmpty(firstName) ||
                String::IsNullOrEmpty(lastName)) {
                MessageBox::Show("Please fill in all fields!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            if (password != confirmPassword) {
                MessageBox::Show("Passwords do not match!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            sqlConn->Open();
            sqlCmd->Connection = sqlConn;

            // Check if email already exists
            sqlCmd->CommandText = "SELECT * FROM users WHERE email = @email;";
            sqlCmd->Parameters->Clear();
            sqlCmd->Parameters->AddWithValue("@email", email);
            sqlRd = sqlCmd->ExecuteReader();

            if (sqlRd->Read()) {
                sqlRd->Close();
                MessageBox::Show("Email already registered!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            sqlRd->Close();

            // Insert new user
            sqlCmd->CommandText = "INSERT INTO users (email, password, firstName, lastName) VALUES (@email, @password, @firstName, @lastName);";
            sqlCmd->Parameters->Clear();
            sqlCmd->Parameters->AddWithValue("@email", email);
            sqlCmd->Parameters->AddWithValue("@password", password);
            sqlCmd->Parameters->AddWithValue("@firstName", firstName);
            sqlCmd->Parameters->AddWithValue("@lastName", lastName);

            sqlCmd->ExecuteNonQuery();

            MessageBox::Show("Registration successful!", "Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            MyForm^ loginForm = gcnew MyForm();
            loginForm->Show();
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

    System::Void Signup::btn_Login_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        MyForm^ loginForm = gcnew MyForm();
        loginForm->Show();
    }

    System::Void Signup::Signup_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        Application::ExitThread();
    }
}
