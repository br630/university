#include "MyForm.h"
#include "Signup.h"
#include "MDIForm.h"

namespace university {
    MyForm::MyForm(void)
    {
        InitializeComponent();
        sqlConn = gcnew MySqlConnection();
        sqlCmd = gcnew MySqlCommand();
        connectionString = "datasource=localhost;port=3306;username=root;password=;database=university_management;";
        sqlConn->ConnectionString = connectionString;
    }

    System::Void MyForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }

    System::Void MyForm::btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            String^ username = txtuserName->Text;
            String^ password = txtPassword->Text;

            if (String::IsNullOrEmpty(username) || String::IsNullOrEmpty(password)) {
                MessageBox::Show("Please enter both username and password!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            sqlConn->Open();
            sqlCmd->Connection = sqlConn;

            sqlCmd->CommandText = "SELECT * FROM users WHERE username = @username AND password = @password;";
            sqlCmd->Parameters->Clear();
            sqlCmd->Parameters->AddWithValue("@username", username);
            sqlCmd->Parameters->AddWithValue("@password", password);

            sqlRd = sqlCmd->ExecuteReader();
            if (sqlRd->Read()) {
                sqlRd->Close();
                sqlConn->Close();
                MessageBox::Show("Login successful!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                MDIForm^ mdiParent = gcnew MDIForm();
                mdiParent->Show();
                this->Hide();
            }
            else {
                sqlRd->Close();
                sqlConn->Close();
                MessageBox::Show("Invalid username or password!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
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

    System::Void MyForm::Username_Click(System::Object^ sender, System::EventArgs^ e) {
    }

    System::Void MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }

    System::Void MyForm::linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        Signup^ signupForm = gcnew Signup();
        signupForm->Show();
        this->Hide();
    }
}