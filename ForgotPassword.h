// ForgotPassword.h
#pragma once
#include "db_conn.h"

namespace university {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace MySql::Data::MySqlClient;

    public ref class ForgotPassword : public System::Windows::Forms::Form {
    private:
        TextBox^ txtEmail;
        TextBox^ txtNewPassword;
        TextBox^ txtConfirmPassword;
        Button^ btnResetPassword;
        Button^ btnCancel;
        Label^ lblEmail;
        Label^ lblNewPassword;
        Label^ lblConfirmPassword;
        System::ComponentModel::Container^ components;

    public:
        ForgotPassword(void) {
            InitializeComponent();
        }

    protected:
        ~ForgotPassword() {
            if (components) {
                delete components;
            }
        }

    private:
        void InitializeComponent(void) {
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->txtNewPassword = (gcnew System::Windows::Forms::TextBox());
            this->txtConfirmPassword = (gcnew System::Windows::Forms::TextBox());
            this->btnResetPassword = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->lblEmail = (gcnew System::Windows::Forms::Label());
            this->lblNewPassword = (gcnew System::Windows::Forms::Label());
            this->lblConfirmPassword = (gcnew System::Windows::Forms::Label());

            // Set up form properties
            this->Text = L"Forgot Password";
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            // Configure controls
            this->txtNewPassword->PasswordChar = '*';
            this->txtConfirmPassword->PasswordChar = '*';

            // Set up labels
            this->lblEmail->Text = L"Email:";
            this->lblNewPassword->Text = L"New Password:";
            this->lblConfirmPassword->Text = L"Confirm Password:";

            // Set up buttons
            this->btnResetPassword->Text = L"Reset Password";
            this->btnCancel->Text = L"Cancel";

            // Add event handlers
            this->btnResetPassword->Click += gcnew System::EventHandler(this, &ForgotPassword::btnResetPassword_Click);
            this->btnCancel->Click += gcnew System::EventHandler(this, &ForgotPassword::btnCancel_Click);

            // Layout controls (you'll need to set proper locations and sizes)
            // ... Add control positioning code here ...

            // Add controls to form
            this->Controls->Add(this->lblEmail);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->lblNewPassword);
            this->Controls->Add(this->txtNewPassword);
            this->Controls->Add(this->lblConfirmPassword);
            this->Controls->Add(this->txtConfirmPassword);
            this->Controls->Add(this->btnResetPassword);
            this->Controls->Add(this->btnCancel);
        }

        System::Void btnResetPassword_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
    };
}