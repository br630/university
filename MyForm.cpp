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
            String^ email = txtuserName->Text;  // We're still using txtuserName but it will contain email
            String^ password = txtPassword->Text;

            if (String::IsNullOrEmpty(email) || String::IsNullOrEmpty(password)) {
                MessageBox::Show("Please enter both email and password!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            sqlConn->Open();
            sqlCmd->Connection = sqlConn;
            sqlCmd->CommandText = "SELECT * FROM users WHERE email = @email AND password = @password;";
            sqlCmd->Parameters->Clear();
            sqlCmd->Parameters->AddWithValue("@email", email);
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
                MessageBox::Show("Invalid email or password!", "Error",
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

    System::Void MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        Application::ExitThread();
    }
}