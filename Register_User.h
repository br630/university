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
        System::Windows::Forms::Label^ lblCurrentYear;
        System::Windows::Forms::ComboBox^ comboCurrentYear;
        System::ComponentModel::Container^ components;

        // Helper methods
        bool ValidateInput();
        bool IsValidEmail(String^ email);
        void ClearForm();

        // Event handlers
        System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void Register_User_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void comboMajor_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        

        void InitializeComponent(void)
        {
            this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
            this->txtLastName = (gcnew System::Windows::Forms::TextBox());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->comboMajor = (gcnew System::Windows::Forms::ComboBox());
            this->comboCurrentYear = (gcnew System::Windows::Forms::ComboBox());
            this->datePickerDOB = (gcnew System::Windows::Forms::DateTimePicker());
            this->btnRegister = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->lblFirstName = (gcnew System::Windows::Forms::Label());
            this->lblLastName = (gcnew System::Windows::Forms::Label());
            this->lblEmail = (gcnew System::Windows::Forms::Label());
            this->lblPassword = (gcnew System::Windows::Forms::Label());
            this->lblMajor = (gcnew System::Windows::Forms::Label());
            this->lblDOB = (gcnew System::Windows::Forms::Label());
            this->lblCurrentYear = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();

            // Input Fields
            this->txtFirstName->Location = System::Drawing::Point(150, 27);
            this->txtFirstName->Size = System::Drawing::Size(250, 22);
            this->txtFirstName->TabIndex = 1;

            this->txtLastName->Location = System::Drawing::Point(150, 72);
            this->txtLastName->Size = System::Drawing::Size(250, 22);
            this->txtLastName->TabIndex = 3;

            this->txtEmail->Location = System::Drawing::Point(150, 120);
            this->txtEmail->Size = System::Drawing::Size(250, 22);
            this->txtEmail->TabIndex = 5;

            this->txtPassword->Location = System::Drawing::Point(150, 165);
            this->txtPassword->PasswordChar = '*';
            this->txtPassword->Size = System::Drawing::Size(250, 22);
            this->txtPassword->TabIndex = 7;

            // Major Combo Box
            this->comboMajor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboMajor->FormattingEnabled = true;
            this->comboMajor->Location = System::Drawing::Point(150, 205);
            this->comboMajor->Size = System::Drawing::Size(250, 24);
            this->comboMajor->TabIndex = 9;
            this->comboMajor->SelectedIndexChanged += gcnew System::EventHandler(this, &Register_User::comboMajor_SelectedIndexChanged);

            // Date Picker
            this->datePickerDOB->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->datePickerDOB->Location = System::Drawing::Point(150, 245);
            this->datePickerDOB->Size = System::Drawing::Size(250, 22);
            this->datePickerDOB->TabIndex = 11;

            // Current Year Combo Box
            this->comboCurrentYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboCurrentYear->FormattingEnabled = true;
            this->comboCurrentYear->Location = System::Drawing::Point(150, 285);
            this->comboCurrentYear->Size = System::Drawing::Size(250, 24);
            this->comboCurrentYear->TabIndex = 14;
            this->comboCurrentYear->Items->AddRange(gcnew cli::array<System::Object^>(4) {
                (System::Object^)L"Year 1",
                    (System::Object^)L"Year 2",
                    (System::Object^)L"Year 3",
                    (System::Object^)L"Year 4"
            });

            // Buttons
            this->btnRegister->Location = System::Drawing::Point(150, 330);
            this->btnRegister->Size = System::Drawing::Size(120, 35);
            this->btnRegister->TabIndex = 12;
            this->btnRegister->Text = L"Register";
            this->btnRegister->UseVisualStyleBackColor = true;
            this->btnRegister->Click += gcnew System::EventHandler(this, &Register_User::btnRegister_Click);

            this->btnCancel->Location = System::Drawing::Point(280, 330);
            this->btnCancel->Size = System::Drawing::Size(120, 35);
            this->btnCancel->TabIndex = 13;
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &Register_User::btnCancel_Click);

            // Labels
            this->lblFirstName->AutoSize = true;
            this->lblFirstName->Location = System::Drawing::Point(30, 30);
            this->lblFirstName->Size = System::Drawing::Size(75, 16);
            this->lblFirstName->TabIndex = 0;
            this->lblFirstName->Text = L"First Name:";

            this->lblLastName->AutoSize = true;
            this->lblLastName->Location = System::Drawing::Point(30, 75);
            this->lblLastName->Size = System::Drawing::Size(75, 16);
            this->lblLastName->TabIndex = 2;
            this->lblLastName->Text = L"Last Name:";

            this->lblEmail->AutoSize = true;
            this->lblEmail->Location = System::Drawing::Point(30, 123);
            this->lblEmail->Size = System::Drawing::Size(44, 16);
            this->lblEmail->TabIndex = 4;
            this->lblEmail->Text = L"Email:";

            this->lblPassword->AutoSize = true;
            this->lblPassword->Location = System::Drawing::Point(30, 168);
            this->lblPassword->Size = System::Drawing::Size(70, 16);
            this->lblPassword->TabIndex = 6;
            this->lblPassword->Text = L"Password:";

            this->lblMajor->AutoSize = true;
            this->lblMajor->Location = System::Drawing::Point(30, 208);
            this->lblMajor->Size = System::Drawing::Size(44, 16);
            this->lblMajor->TabIndex = 8;
            this->lblMajor->Text = L"Major:";

            this->lblDOB->AutoSize = true;
            this->lblDOB->Location = System::Drawing::Point(30, 248);
            this->lblDOB->Size = System::Drawing::Size(82, 16);
            this->lblDOB->TabIndex = 10;
            this->lblDOB->Text = L"Date of Birth:";

            this->lblCurrentYear->AutoSize = true;
            this->lblCurrentYear->Location = System::Drawing::Point(30, 288);
            this->lblCurrentYear->Size = System::Drawing::Size(82, 16);
            this->lblCurrentYear->TabIndex = 15;
            this->lblCurrentYear->Text = L"Current Year:";

            // Form
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(434, 434);
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
            this->Controls->Add(this->lblCurrentYear);
            this->Controls->Add(this->comboCurrentYear);
            this->Controls->Add(this->btnRegister);
            this->Controls->Add(this->btnCancel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Register New Student";
            this->Load += gcnew System::EventHandler(this, &Register_User::Register_User_Load);

            this->ResumeLayout(false);
            this->PerformLayout();
        }
 
};
}