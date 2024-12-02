#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Register_User : public System::Windows::Forms::Form {
    public:
        Register_User(void) {
            InitializeComponent();
        }

    protected:
        ~Register_User() {
            if (components) {
                delete components;
            }
        }

    private:
        // UI Components
        System::Windows::Forms::TextBox^ txtFirstName;
        System::Windows::Forms::TextBox^ txtLastName;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::TextBox^ txtPassword;
        System::Windows::Forms::ComboBox^ comboMajor;
        System::Windows::Forms::DateTimePicker^ datePickerDOB;
        System::Windows::Forms::Button^ btnRegister;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::Label^ lblFirstName;
        System::Windows::Forms::Label^ lblLastName;
        System::Windows::Forms::Label^ lblEmail;
        System::Windows::Forms::Label^ lblPassword;
        System::Windows::Forms::Label^ lblMajor;
        System::Windows::Forms::Label^ lblDOB;
        System::ComponentModel::Container^ components;

        // Helper methods
        bool ValidateInput();
        bool IsValidEmail(String^ email);
        void ClearForm();

        // Event handlers
        System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void Register_User_Load(System::Object^ sender, System::EventArgs^ e);

        void InitializeComponent(void)
        {
            this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
            this->txtLastName = (gcnew System::Windows::Forms::TextBox());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->comboMajor = (gcnew System::Windows::Forms::ComboBox());
            this->datePickerDOB = (gcnew System::Windows::Forms::DateTimePicker());
            this->btnRegister = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->lblFirstName = (gcnew System::Windows::Forms::Label());
            this->lblLastName = (gcnew System::Windows::Forms::Label());
            this->lblEmail = (gcnew System::Windows::Forms::Label());
            this->lblPassword = (gcnew System::Windows::Forms::Label());
            this->lblMajor = (gcnew System::Windows::Forms::Label());
            this->lblDOB = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // txtFirstName
            // 
            this->txtFirstName->Location = System::Drawing::Point(150, 27);
            this->txtFirstName->Name = L"txtFirstName";
            this->txtFirstName->Size = System::Drawing::Size(250, 22);
            this->txtFirstName->TabIndex = 1;
            // 
            // txtLastName
            // 
            this->txtLastName->Location = System::Drawing::Point(150, 67);
            this->txtLastName->Name = L"txtLastName";
            this->txtLastName->Size = System::Drawing::Size(250, 22);
            this->txtLastName->TabIndex = 3;
            // 
            // txtEmail
            // 
            this->txtEmail->Location = System::Drawing::Point(150, 107);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(250, 22);
            this->txtEmail->TabIndex = 5;
            // 
            // txtPassword
            // 
            this->txtPassword->Location = System::Drawing::Point(150, 147);
            this->txtPassword->Name = L"txtPassword";
            this->txtPassword->PasswordChar = '*';
            this->txtPassword->Size = System::Drawing::Size(250, 22);
            this->txtPassword->TabIndex = 7;
            // 
            // comboMajor
            // 
            this->comboMajor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboMajor->FormattingEnabled = true;
            this->comboMajor->Location = System::Drawing::Point(150, 187);
            this->comboMajor->Name = L"comboMajor";
            this->comboMajor->Size = System::Drawing::Size(250, 24);
            this->comboMajor->TabIndex = 9;
            this->comboMajor->SelectedIndexChanged += gcnew System::EventHandler(this, &Register_User::comboMajor_SelectedIndexChanged);
            // 
            // datePickerDOB
            // 
            this->datePickerDOB->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->datePickerDOB->Location = System::Drawing::Point(150, 227);
            this->datePickerDOB->Name = L"datePickerDOB";
            this->datePickerDOB->Size = System::Drawing::Size(250, 22);
            this->datePickerDOB->TabIndex = 11;
            // 
            // btnRegister
            // 
            this->btnRegister->Location = System::Drawing::Point(150, 280);
            this->btnRegister->Name = L"btnRegister";
            this->btnRegister->Size = System::Drawing::Size(120, 35);
            this->btnRegister->TabIndex = 12;
            this->btnRegister->Text = L"Register";
            this->btnRegister->UseVisualStyleBackColor = true;
            this->btnRegister->Click += gcnew System::EventHandler(this, &Register_User::btnRegister_Click);
            // 
            // btnCancel
            // 
            this->btnCancel->Location = System::Drawing::Point(280, 280);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(120, 35);
            this->btnCancel->TabIndex = 13;
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &Register_User::btnCancel_Click);
            // 
            // lblFirstName
            // 
            this->lblFirstName->AutoSize = true;
            this->lblFirstName->Location = System::Drawing::Point(30, 30);
            this->lblFirstName->Name = L"lblFirstName";
            this->lblFirstName->Size = System::Drawing::Size(75, 16);
            this->lblFirstName->TabIndex = 0;
            this->lblFirstName->Text = L"First Name:";
            // 
            // lblLastName
            // 
            this->lblLastName->AutoSize = true;
            this->lblLastName->Location = System::Drawing::Point(30, 70);
            this->lblLastName->Name = L"lblLastName";
            this->lblLastName->Size = System::Drawing::Size(75, 16);
            this->lblLastName->TabIndex = 2;
            this->lblLastName->Text = L"Last Name:";
            // 
            // lblEmail
            // 
            this->lblEmail->AutoSize = true;
            this->lblEmail->Location = System::Drawing::Point(30, 110);
            this->lblEmail->Name = L"lblEmail";
            this->lblEmail->Size = System::Drawing::Size(44, 16);
            this->lblEmail->TabIndex = 4;
            this->lblEmail->Text = L"Email:";
            // 
            // lblPassword
            // 
            this->lblPassword->AutoSize = true;
            this->lblPassword->Location = System::Drawing::Point(30, 150);
            this->lblPassword->Name = L"lblPassword";
            this->lblPassword->Size = System::Drawing::Size(70, 16);
            this->lblPassword->TabIndex = 6;
            this->lblPassword->Text = L"Password:";
            // 
            // lblMajor
            // 
            this->lblMajor->AutoSize = true;
            this->lblMajor->Location = System::Drawing::Point(30, 190);
            this->lblMajor->Name = L"lblMajor";
            this->lblMajor->Size = System::Drawing::Size(44, 16);
            this->lblMajor->TabIndex = 8;
            this->lblMajor->Text = L"Major:";
            this->lblMajor->Click += gcnew System::EventHandler(this, &Register_User::lblMajor_Click);
            // 
            // lblDOB
            // 
            this->lblDOB->AutoSize = true;
            this->lblDOB->Location = System::Drawing::Point(30, 230);
            this->lblDOB->Name = L"lblDOB";
            this->lblDOB->Size = System::Drawing::Size(82, 16);
            this->lblDOB->TabIndex = 10;
            this->lblDOB->Text = L"Date of Birth:";
            // 
            // Register_User
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(434, 351);
            this->Controls->Add(this->lblFirstName);
            this->Controls->Add(this->txtFirstName);
            this->Controls->Add(this->lblLastName);
            this->Controls->Add(this->txtLastName);
            this->Controls->Add(this->lblEmail);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->lblPassword);
            this->Controls->Add(this->txtPassword);
            this->Controls->Add(this->lblMajor);
            this->Controls->Add(this->comboMajor);
            this->Controls->Add(this->lblDOB);
            this->Controls->Add(this->datePickerDOB);
            this->Controls->Add(this->btnRegister);
            this->Controls->Add(this->btnCancel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Register_User";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Register New Student";
            this->Load += gcnew System::EventHandler(this, &Register_User::Register_User_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void lblMajor_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void comboMajor_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}