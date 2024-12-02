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
            this->components = gcnew System::ComponentModel::Container();
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
            this->tabPageStudents = (gcnew System::Windows::Forms::TabPage());
            this->dataGridFaculty = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridStudents = (gcnew System::Windows::Forms::DataGridView());

            this->groupBoxDepartmentDetails->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDepartments))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridFaculty))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridStudents))->BeginInit();
            this->tabControlMembers->SuspendLayout();
            this->tabPageFaculty->SuspendLayout();
            this->tabPageStudents->SuspendLayout();
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
            this->groupBoxDepartmentDetails->Text = L"Department Details";

            // 
            // Department ID
            // 
            this->lblDepartmentID->Location = System::Drawing::Point(49, 168);
            this->lblDepartmentID->Size = System::Drawing::Size(118, 22);
            this->lblDepartmentID->Text = L"Department ID:";

            this->txtDepartmentID->Location = System::Drawing::Point(167, 166);
            this->txtDepartmentID->Size = System::Drawing::Size(236, 22);
            this->txtDepartmentID->ReadOnly = true;

            // 
            // Department Name
            // 
            this->lblDepartmentName->Location = System::Drawing::Point(49, 198);
            this->lblDepartmentName->Size = System::Drawing::Size(118, 22);
            this->lblDepartmentName->Text = L"Department Name:";

            this->txtDepartmentName->Location = System::Drawing::Point(167, 194);
            this->txtDepartmentName->Size = System::Drawing::Size(236, 22);

            // 
            // Head of Department
            // 
            this->lblHeadOfDepartment->Location = System::Drawing::Point(49, 226);
            this->lblHeadOfDepartment->Size = System::Drawing::Size(118, 22);
            this->lblHeadOfDepartment->Text = L"Department Head:";

            this->comboHeadOfDepartment->Location = System::Drawing::Point(167, 224);
            this->comboHeadOfDepartment->Size = System::Drawing::Size(236, 24);
            this->comboHeadOfDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

            // 
            // Buttons
            // 
            this->btnAdd->Location = System::Drawing::Point(49, 305);
            this->btnAdd->Size = System::Drawing::Size(95, 30);
            this->btnAdd->Text = L"Add";
            this->btnAdd->Click += gcnew EventHandler(this, &Manage_Department::btnAdd_Click);

            this->btnUpdate->Location = System::Drawing::Point(156, 305);
            this->btnUpdate->Size = System::Drawing::Size(95, 30);
            this->btnUpdate->Text = L"Update";
            this->btnUpdate->Click += gcnew EventHandler(this, &Manage_Department::btnUpdate_Click);

            this->btnDelete->Location = System::Drawing::Point(262, 305);
            this->btnDelete->Size = System::Drawing::Size(95, 30);
            this->btnDelete->Text = L"Delete";
            this->btnDelete->Click += gcnew EventHandler(this, &Manage_Department::btnDelete_Click);

            this->btnClear->Location = System::Drawing::Point(369, 305);
            this->btnClear->Size = System::Drawing::Size(95, 30);
            this->btnClear->Text = L"Clear";
            this->btnClear->Click += gcnew EventHandler(this, &Manage_Department::btnClear_Click);

            // 
            // Search controls
            // 
            this->txtSearch->Location = System::Drawing::Point(1025, 25);
            this->txtSearch->Size = System::Drawing::Size(236, 22);

            this->btnSearch->Location = System::Drawing::Point(1274, 24);
            this->btnSearch->Size = System::Drawing::Size(95, 24);
            this->btnSearch->Text = L"Search";
            this->btnSearch->Click += gcnew EventHandler(this, &Manage_Department::btnSearch_Click);

            // 
            // DataGridView for Departments
            // 
            this->dataGridDepartments->AllowUserToAddRows = false;
            this->dataGridDepartments->AllowUserToDeleteRows = false;
            this->dataGridDepartments->Location = System::Drawing::Point(611, 54);
            this->dataGridDepartments->MultiSelect = false;
            this->dataGridDepartments->Name = L"dataGridDepartments";
            this->dataGridDepartments->ReadOnly = true;
            this->dataGridDepartments->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridDepartments->Size = System::Drawing::Size(758, 394);
            this->dataGridDepartments->TabIndex = 3;
            this->dataGridDepartments->CellClick += gcnew DataGridViewCellEventHandler(this, &Manage_Department::dataGridDepartments_CellClick);

            // 
            // TabControl
            // 
            this->tabControlMembers->Location = System::Drawing::Point(16, 484);
            this->tabControlMembers->Size = System::Drawing::Size(1353, 220);
            this->tabControlMembers->Controls->Add(this->tabPageFaculty);
            this->tabControlMembers->Controls->Add(this->tabPageStudents);

            // 
            // Faculty Tab
            // 
            this->tabPageFaculty->Text = L"Faculty Members";
            this->tabPageFaculty->Controls->Add(this->dataGridFaculty);
            this->dataGridFaculty->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dataGridFaculty->AllowUserToAddRows = false;
            this->dataGridFaculty->ReadOnly = true;

            // 
            // Students Tab
            // 
            this->tabPageStudents->Text = L"Students";
            this->tabPageStudents->Controls->Add(this->dataGridStudents);
            this->dataGridStudents->Dock = System::Windows::Forms::DockStyle::Fill;
            this->dataGridStudents->AllowUserToAddRows = false;
            this->dataGridStudents->ReadOnly = true;

            // 
            // Manage_Department Form
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
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Department Management";
            this->Load += gcnew EventHandler(this, &Manage_Department::Form_Load);

            this->groupBoxDepartmentDetails->ResumeLayout(false);
            this->groupBoxDepartmentDetails->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDepartments))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridFaculty))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridStudents))->EndInit();
            this->tabControlMembers->ResumeLayout(false);
            this->tabPageFaculty->ResumeLayout(false);
            this->tabPageStudents->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
    };
}