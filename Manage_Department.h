#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class Manage_Department : public System::Windows::Forms::Form {
    public:
        Manage_Department(void) {
            InitializeComponent();
        }

    protected:
        ~Manage_Department() {
            if (components) {
                delete components;
            }
        }

    private:
        // Form controls
        System::Windows::Forms::GroupBox^ groupBoxDepartmentDetails;
        System::Windows::Forms::Label^ lblDepartmentID;
        System::Windows::Forms::TextBox^ txtDepartmentID;
        System::Windows::Forms::Label^ lblDepartmentName;
        System::Windows::Forms::TextBox^ txtDepartmentName;
        System::Windows::Forms::Label^ lblHeadOfDepartment;
        System::Windows::Forms::ComboBox^ comboHeadOfDepartment;

        // Buttons
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnClear;

        // TabControl for Members and Students
        System::Windows::Forms::TabControl^ tabControlMembers;
        System::Windows::Forms::TabPage^ tabPageFaculty;
        System::Windows::Forms::TabPage^ tabPageStudents;
        System::Windows::Forms::DataGridView^ dataGridFaculty;
        System::Windows::Forms::DataGridView^ dataGridStudents;

        // Main DataGridView for departments
        System::Windows::Forms::DataGridView^ dataGridDepartments;

        // Search controls
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;

        System::ComponentModel::Container^ components;

        // Helper methods
        void SetupDataGridView();
        void LoadDepartments();
        void LoadFacultyMembers();
        void LoadDepartmentFaculty(int departmentId);
        void LoadDepartmentStudents(int departmentId);
        void ClearForm();
        bool ValidateInput();

        // Event handlers
        System::Void Form_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void dataGridDepartments_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e);

        void InitializeComponent(void) {
            this->groupBoxDepartmentDetails = (gcnew System::Windows::Forms::GroupBox());
            this->lblDepartmentID = (gcnew System::Windows::Forms::Label());
            this->txtDepartmentID = (gcnew System::Windows::Forms::TextBox());
            this->lblDepartmentName = (gcnew System::Windows::Forms::Label());
            this->txtDepartmentName = (gcnew System::Windows::Forms::TextBox());
            this->lblHeadOfDepartment = (gcnew System::Windows::Forms::Label());
            this->comboHeadOfDepartment = (gcnew System::Windows::Forms::ComboBox());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->dataGridDepartments = (gcnew System::Windows::Forms::DataGridView());
            this->tabControlMembers = (gcnew System::Windows::Forms::TabControl());
            this->tabPageFaculty = (gcnew System::Windows::Forms::TabPage());
            this->dataGridFaculty = (gcnew System::Windows::Forms::DataGridView());
            this->tabPageStudents = (gcnew System::Windows::Forms::TabPage());
            this->dataGridStudents = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxDepartmentDetails->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDepartments))->BeginInit();
            this->tabControlMembers->SuspendLayout();
            this->tabPageFaculty->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridFaculty))->BeginInit();
            this->tabPageStudents->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridStudents))->BeginInit();
            this->SuspendLayout();
            // 
            // groupBoxDepartmentDetails
            // 
            this->groupBoxDepartmentDetails->Controls->Add(this->lblDepartmentID);
            this->groupBoxDepartmentDetails->Controls->Add(this->txtDepartmentID);
            this->groupBoxDepartmentDetails->Controls->Add(this->lblDepartmentName);
            this->groupBoxDepartmentDetails->Controls->Add(this->txtDepartmentName);
            this->groupBoxDepartmentDetails->Controls->Add(this->lblHeadOfDepartment);
            this->groupBoxDepartmentDetails->Controls->Add(this->comboHeadOfDepartment);
            this->groupBoxDepartmentDetails->Controls->Add(this->btnAdd);
            this->groupBoxDepartmentDetails->Controls->Add(this->btnUpdate);
            this->groupBoxDepartmentDetails->Controls->Add(this->btnDelete);
            this->groupBoxDepartmentDetails->Controls->Add(this->btnClear);
            this->groupBoxDepartmentDetails->Location = System::Drawing::Point(16, 54);
            this->groupBoxDepartmentDetails->Name = L"groupBoxDepartmentDetails";
            this->groupBoxDepartmentDetails->Size = System::Drawing::Size(533, 417);
            this->groupBoxDepartmentDetails->TabIndex = 0;
            this->groupBoxDepartmentDetails->TabStop = false;
            this->groupBoxDepartmentDetails->Text = L"Department Details";
            // 
            // lblDepartmentID
            // 
            this->lblDepartmentID->Location = System::Drawing::Point(49, 168);
            this->lblDepartmentID->Name = L"lblDepartmentID";
            this->lblDepartmentID->Size = System::Drawing::Size(118, 22);
            this->lblDepartmentID->TabIndex = 0;
            this->lblDepartmentID->Text = L"Department ID:";
            // 
            // txtDepartmentID
            // 
            this->txtDepartmentID->Location = System::Drawing::Point(167, 166);
            this->txtDepartmentID->Name = L"txtDepartmentID";
            this->txtDepartmentID->ReadOnly = true;
            this->txtDepartmentID->Size = System::Drawing::Size(236, 22);
            this->txtDepartmentID->TabIndex = 1;
            // 
            // lblDepartmentName
            // 
            this->lblDepartmentName->Location = System::Drawing::Point(49, 198);
            this->lblDepartmentName->Name = L"lblDepartmentName";
            this->lblDepartmentName->Size = System::Drawing::Size(118, 22);
            this->lblDepartmentName->TabIndex = 2;
            this->lblDepartmentName->Text = L"Department Name:";
            // 
            // txtDepartmentName
            // 
            this->txtDepartmentName->Location = System::Drawing::Point(167, 194);
            this->txtDepartmentName->Name = L"txtDepartmentName";
            this->txtDepartmentName->Size = System::Drawing::Size(236, 22);
            this->txtDepartmentName->TabIndex = 3;
            // 
            // lblHeadOfDepartment
            // 
            this->lblHeadOfDepartment->Location = System::Drawing::Point(49, 226);
            this->lblHeadOfDepartment->Name = L"lblHeadOfDepartment";
            this->lblHeadOfDepartment->Size = System::Drawing::Size(118, 22);
            this->lblHeadOfDepartment->TabIndex = 4;
            this->lblHeadOfDepartment->Text = L"Department Head:";
            // 
            // comboHeadOfDepartment
            // 
            this->comboHeadOfDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboHeadOfDepartment->Location = System::Drawing::Point(167, 224);
            this->comboHeadOfDepartment->Name = L"comboHeadOfDepartment";
            this->comboHeadOfDepartment->Size = System::Drawing::Size(236, 24);
            this->comboHeadOfDepartment->TabIndex = 5;
            // 
            // btnAdd
            // 
            this->btnAdd->Location = System::Drawing::Point(49, 305);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(95, 30);
            this->btnAdd->TabIndex = 6;
            this->btnAdd->Text = L"Add";
            // 
            // btnUpdate
            // 
            this->btnUpdate->Location = System::Drawing::Point(156, 305);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(95, 30);
            this->btnUpdate->TabIndex = 7;
            this->btnUpdate->Text = L"Update";
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(262, 305);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(95, 30);
            this->btnDelete->TabIndex = 8;
            this->btnDelete->Text = L"Delete";
            // 
            // btnClear
            // 
            this->btnClear->Location = System::Drawing::Point(369, 305);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(95, 30);
            this->btnClear->TabIndex = 9;
            this->btnClear->Text = L"Clear";
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(1025, 25);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(236, 22);
            this->txtSearch->TabIndex = 1;
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(1274, 24);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(95, 24);
            this->btnSearch->TabIndex = 2;
            this->btnSearch->Text = L"Search";
            // 
            // dataGridDepartments
            // 
            this->dataGridDepartments->AllowUserToAddRows = false;
            this->dataGridDepartments->AllowUserToDeleteRows = false;
            this->dataGridDepartments->ColumnHeadersHeight = 29;
            this->dataGridDepartments->Location = System::Drawing::Point(611, 54);
            this->dataGridDepartments->MultiSelect = false;
            this->dataGridDepartments->Name = L"dataGridDepartments";
            this->dataGridDepartments->ReadOnly = true;
            this->dataGridDepartments->RowHeadersWidth = 51;
            this->dataGridDepartments->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridDepartments->Size = System::Drawing::Size(758, 394);
            this->dataGridDepartments->TabIndex = 3;
            // 
            // tabControlMembers
            // 
            this->tabControlMembers->Controls->Add(this->tabPageFaculty);
            this->tabControlMembers->Controls->Add(this->tabPageStudents);
            this->tabControlMembers->Location = System::Drawing::Point(16, 484);
            this->tabControlMembers->Name = L"tabControlMembers";
            this->tabControlMembers->SelectedIndex = 0;
            this->tabControlMembers->Size = System::Drawing::Size(1353, 220);
            this->tabControlMembers->TabIndex = 4;
            // 
            // tabPageFaculty
            // 
            this->tabPageFaculty->Controls->Add(this->dataGridFaculty);
            this->tabPageFaculty->Location = System::Drawing::Point(4, 25);
            this->tabPageFaculty->Name = L"tabPageFaculty";
            this->tabPageFaculty->Size = System::Drawing::Size(1345, 191);
            this->tabPageFaculty->TabIndex = 0;
            this->tabPageFaculty->Text = L"Faculty Members";
            // 
            // dataGridFaculty
            // 
            this->dataGridFaculty->AllowUserToAddRows = false;
            this->dataGridFaculty->ColumnHeadersHeight = 29;
            this->dataGridFaculty->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dataGridFaculty->Location = System::Drawing::Point(0, 0);
            this->dataGridFaculty->Name = L"dataGridFaculty";
            this->dataGridFaculty->ReadOnly = true;
            this->dataGridFaculty->RowHeadersWidth = 51;
            this->dataGridFaculty->Size = System::Drawing::Size(1345, 191);
            this->dataGridFaculty->TabIndex = 0;
            // 
            // tabPageStudents
            // 
            this->tabPageStudents->Controls->Add(this->dataGridStudents);
            this->tabPageStudents->Location = System::Drawing::Point(4, 25);
            this->tabPageStudents->Name = L"tabPageStudents";
            this->tabPageStudents->Size = System::Drawing::Size(1345, 191);
            this->tabPageStudents->TabIndex = 1;
            this->tabPageStudents->Text = L"Students";
            // 
            // dataGridStudents
            // 
            this->dataGridStudents->AllowUserToAddRows = false;
            this->dataGridStudents->ColumnHeadersHeight = 29;
            this->dataGridStudents->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dataGridStudents->Location = System::Drawing::Point(0, 0);
            this->dataGridStudents->Name = L"dataGridStudents";
            this->dataGridStudents->ReadOnly = true;
            this->dataGridStudents->RowHeadersWidth = 51;
            this->dataGridStudents->Size = System::Drawing::Size(1345, 191);
            this->dataGridStudents->TabIndex = 0;
            // 
            // Manage_Department
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1460, 716);
            this->Controls->Add(this->groupBoxDepartmentDetails);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridDepartments);
            this->Controls->Add(this->tabControlMembers);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Manage_Department";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Department Management";
            this->Load += gcnew System::EventHandler(this, &Manage_Department::Manage_Department_Load);
            this->groupBoxDepartmentDetails->ResumeLayout(false);
            this->groupBoxDepartmentDetails->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDepartments))->EndInit();
            this->tabControlMembers->ResumeLayout(false);
            this->tabPageFaculty->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridFaculty))->EndInit();
            this->tabPageStudents->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridStudents))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    private: System::Void Manage_Department_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}