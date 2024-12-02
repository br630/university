#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Manage_Faculty : public System::Windows::Forms::Form {
    public:
        Manage_Faculty(void) {
            InitializeComponent();
        }

    protected:
        ~Manage_Faculty() {
            if (components) {
                delete components;
            }
        }

    private:
        // Form controls
        System::Windows::Forms::GroupBox^ groupBoxFacultyDetails;
        System::Windows::Forms::Label^ lblFacultyID;
        System::Windows::Forms::TextBox^ txtFacultyID;
        System::Windows::Forms::Label^ lblFirstName;
        System::Windows::Forms::TextBox^ txtFirstName;
        System::Windows::Forms::Label^ lblLastName;
        System::Windows::Forms::TextBox^ txtLastName;
        System::Windows::Forms::Label^ lblEmail;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::Label^ lblPassword;
        System::Windows::Forms::TextBox^ txtPassword;
        System::Windows::Forms::Label^ lblDepartment;
        System::Windows::Forms::ComboBox^ comboDepartment;

        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnClear;
        System::Windows::Forms::DataGridView^ dataGridFaculty;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;
        System::ComponentModel::Container^ components;

        // Helper methods
        void SetupDataGridView();
        void LoadFaculty();
        void ClearForm();
        bool ValidateInput();
        void LoadDepartments();

        // Event handlers
        System::Void Form_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void dataGridFaculty_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e);

        void InitializeComponent(void) {
            this->groupBoxFacultyDetails = (gcnew System::Windows::Forms::GroupBox());
            this->lblFacultyID = (gcnew System::Windows::Forms::Label());
            this->txtFacultyID = (gcnew System::Windows::Forms::TextBox());
            this->lblFirstName = (gcnew System::Windows::Forms::Label());
            this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
            this->lblLastName = (gcnew System::Windows::Forms::Label());
            this->txtLastName = (gcnew System::Windows::Forms::TextBox());
            this->lblEmail = (gcnew System::Windows::Forms::Label());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->lblPassword = (gcnew System::Windows::Forms::Label());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->lblDepartment = (gcnew System::Windows::Forms::Label());
            this->comboDepartment = (gcnew System::Windows::Forms::ComboBox());
            this->comboDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->dataGridFaculty = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxFacultyDetails->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridFaculty))->BeginInit();
            this->SuspendLayout();
            // 
            // groupBoxFacultyDetails
            // 
            this->groupBoxFacultyDetails->Controls->Add(this->lblFacultyID);
            this->groupBoxFacultyDetails->Controls->Add(this->txtFacultyID);
            this->groupBoxFacultyDetails->Controls->Add(this->lblFirstName);
            this->groupBoxFacultyDetails->Controls->Add(this->txtFirstName);
            this->groupBoxFacultyDetails->Controls->Add(this->lblLastName);
            this->groupBoxFacultyDetails->Controls->Add(this->txtLastName);
            this->groupBoxFacultyDetails->Controls->Add(this->lblEmail);
            this->groupBoxFacultyDetails->Controls->Add(this->txtEmail);
            this->groupBoxFacultyDetails->Controls->Add(this->lblPassword);
            this->groupBoxFacultyDetails->Controls->Add(this->txtPassword);
            this->groupBoxFacultyDetails->Controls->Add(this->lblDepartment);
            this->groupBoxFacultyDetails->Controls->Add(this->comboDepartment);
            this->groupBoxFacultyDetails->Controls->Add(this->btnAdd);
            this->groupBoxFacultyDetails->Controls->Add(this->btnUpdate);
            this->groupBoxFacultyDetails->Controls->Add(this->btnDelete);
            this->groupBoxFacultyDetails->Controls->Add(this->btnClear);
            this->groupBoxFacultyDetails->Location = System::Drawing::Point(16, 54);
            this->groupBoxFacultyDetails->Name = L"groupBoxFacultyDetails";
            this->groupBoxFacultyDetails->Size = System::Drawing::Size(533, 591);
            this->groupBoxFacultyDetails->TabIndex = 0;
            this->groupBoxFacultyDetails->TabStop = false;
            this->groupBoxFacultyDetails->Text = L"Faculty Details";
            // 
            // lblFacultyID
            // 
            this->lblFacultyID->Location = System::Drawing::Point(13, 101);
            this->lblFacultyID->Name = L"lblFacultyID";
            this->lblFacultyID->Size = System::Drawing::Size(100, 23);
            this->lblFacultyID->TabIndex = 0;
            this->lblFacultyID->Text = L"Faculty ID:";
         
            // 
            // txtFacultyID
            // 
            this->txtFacultyID->Location = System::Drawing::Point(119, 98);
            this->txtFacultyID->Name = L"txtFacultyID";
            this->txtFacultyID->ReadOnly = true;
            this->txtFacultyID->Size = System::Drawing::Size(200, 22);
            this->txtFacultyID->TabIndex = 1;
            // 
            // lblFirstName
            // 
            this->lblFirstName->Location = System::Drawing::Point(13, 156);
            this->lblFirstName->Name = L"lblFirstName";
            this->lblFirstName->Size = System::Drawing::Size(100, 23);
            this->lblFirstName->TabIndex = 2;
            this->lblFirstName->Text = L"First Name:";
            // 
            // txtFirstName
            // 
            this->txtFirstName->Location = System::Drawing::Point(119, 157);
            this->txtFirstName->Name = L"txtFirstName";
            this->txtFirstName->Size = System::Drawing::Size(200, 22);
            this->txtFirstName->TabIndex = 3;
            // 
            // lblLastName
            // 
            this->lblLastName->Location = System::Drawing::Point(13, 208);
            this->lblLastName->Name = L"lblLastName";
            this->lblLastName->Size = System::Drawing::Size(100, 23);
            this->lblLastName->TabIndex = 4;
            this->lblLastName->Text = L"Last Name:";
            // 
            // txtLastName
            // 
            this->txtLastName->Location = System::Drawing::Point(119, 209);
            this->txtLastName->Name = L"txtLastName";
            this->txtLastName->Size = System::Drawing::Size(200, 22);
            this->txtLastName->TabIndex = 5;
            // 
            // lblEmail
            // 
            this->lblEmail->Location = System::Drawing::Point(13, 262);
            this->lblEmail->Name = L"lblEmail";
            this->lblEmail->Size = System::Drawing::Size(100, 23);
            this->lblEmail->TabIndex = 6;
            this->lblEmail->Text = L"Email:";
            // 
            // txtEmail
            // 
            this->txtEmail->Location = System::Drawing::Point(119, 259);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(200, 22);
            this->txtEmail->TabIndex = 7;
            // 
            // lblPassword
            // 
            this->lblPassword->Location = System::Drawing::Point(13, 305);
            this->lblPassword->Name = L"lblPassword";
            this->lblPassword->Size = System::Drawing::Size(100, 23);
            this->lblPassword->TabIndex = 8;
            this->lblPassword->Text = L"Password:";
            // 
            // txtPassword
            // 
            this->txtPassword->Location = System::Drawing::Point(119, 306);
            this->txtPassword->Name = L"txtPassword";
            this->txtPassword->Size = System::Drawing::Size(200, 22);
            this->txtPassword->TabIndex = 9;
            this->txtPassword->UseSystemPasswordChar = true;
            // 
            // lblDepartment
            // 
            this->lblDepartment->Location = System::Drawing::Point(13, 354);
            this->lblDepartment->Name = L"lblDepartment";
            this->lblDepartment->Size = System::Drawing::Size(100, 23);
            this->lblDepartment->TabIndex = 10;
            this->lblDepartment->Text = L"Department:";

            // comboDepartment
            this->comboDepartment->Location = System::Drawing::Point(119, 355);
            this->comboDepartment->Name = L"comboDepartment";
            this->comboDepartment->Size = System::Drawing::Size(200, 24);
            this->comboDepartment->TabIndex = 11;
            // 
            // btnAdd
            // 
            this->btnAdd->Location = System::Drawing::Point(20, 416);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(75, 30);
            this->btnAdd->TabIndex = 14;
            this->btnAdd->Text = L"Add";
            this->btnAdd->Click += gcnew System::EventHandler(this, &Manage_Faculty::btnAdd_Click);
            // 
            // btnUpdate
            // 
            this->btnUpdate->Location = System::Drawing::Point(105, 416);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(75, 30);
            this->btnUpdate->TabIndex = 15;
            this->btnUpdate->Text = L"Update";
            this->btnUpdate->Click += gcnew System::EventHandler(this, &Manage_Faculty::btnUpdate_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(190, 416);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(75, 30);
            this->btnDelete->TabIndex = 16;
            this->btnDelete->Text = L"Delete";
            this->btnDelete->Click += gcnew System::EventHandler(this, &Manage_Faculty::btnDelete_Click);
            // 
            // btnClear
            // 
            this->btnClear->Location = System::Drawing::Point(275, 416);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(75, 30);
            this->btnClear->TabIndex = 17;
            this->btnClear->Text = L"Clear";
            this->btnClear->Click += gcnew System::EventHandler(this, &Manage_Faculty::btnClear_Click);
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(611, 20);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(200, 22);
            this->txtSearch->TabIndex = 1;
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(821, 20);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(75, 30);
            this->btnSearch->TabIndex = 2;
            this->btnSearch->Text = L"Search";
            this->btnSearch->Click += gcnew System::EventHandler(this, &Manage_Faculty::btnSearch_Click);
            // 
            // dataGridFaculty
            // 
            this->dataGridFaculty->AllowUserToAddRows = false;
            this->dataGridFaculty->AllowUserToDeleteRows = false;
            this->dataGridFaculty->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dataGridFaculty->ColumnHeadersHeight = 29;
            this->dataGridFaculty->Location = System::Drawing::Point(611, 54);
            this->dataGridFaculty->MultiSelect = false;
            this->dataGridFaculty->Name = L"dataGridFaculty";
            this->dataGridFaculty->ReadOnly = true;
            this->dataGridFaculty->RowHeadersVisible = false;
            this->dataGridFaculty->RowHeadersWidth = 51;
            this->dataGridFaculty->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridFaculty->Size = System::Drawing::Size(758, 394);
            this->dataGridFaculty->TabIndex = 3;
            this->dataGridFaculty->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Manage_Faculty::dataGridFaculty_CellClick);
            // 
            // Manage_Faculty
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1400, 716);
            this->Controls->Add(this->groupBoxFacultyDetails);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridFaculty);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Manage_Faculty";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Manage Faculty";
            this->Load += gcnew System::EventHandler(this, &Manage_Faculty::Form_Load);
            this->groupBoxFacultyDetails->ResumeLayout(false);
            this->groupBoxFacultyDetails->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridFaculty))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

};
}