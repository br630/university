#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class Manage_Enrollments : public System::Windows::Forms::Form, public System::IDisposable {
    public:
        Manage_Enrollments(int facultyId) {
            InitializeComponent();
            this->facultyId = facultyId;
        }

    protected:
        ~Manage_Enrollments() {
            if (components) {
                delete components;
            }

        }

    private:
        int facultyId;
        System::ComponentModel::Container^ components;

        // Controls declaration
        System::Windows::Forms::TabControl^ tabControlEnrollments;
        System::Windows::Forms::TabPage^ tabPagePending;
        System::Windows::Forms::TabPage^ tabPageHistory;
        System::Windows::Forms::DataGridView^ dataGridPending;
        System::Windows::Forms::DataGridView^ dataGridHistory;
        System::Windows::Forms::Button^ btnApprove;
        System::Windows::Forms::Button^ btnReject;
        System::Windows::Forms::Button^ btnRefresh;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Label^ lblSearch;
        System::Windows::Forms::ComboBox^ cmbSemester;
        System::Windows::Forms::ComboBox^ cmbYear;

        // Method declarations
        void InitializeDataGrids();
        void LoadPendingEnrollments();
        void LoadEnrollmentHistory();
        void HandleApproval(bool isApproved);
        void RefreshData();
        void SetupSearchFilters();

        void InitializeComponent(void) {
            this->components = gcnew System::ComponentModel::Container();

            this->tabControlEnrollments = gcnew System::Windows::Forms::TabControl();
            this->tabPagePending = gcnew System::Windows::Forms::TabPage();
            this->tabPageHistory = gcnew System::Windows::Forms::TabPage();
            this->dataGridPending = gcnew System::Windows::Forms::DataGridView();
            this->dataGridHistory = gcnew System::Windows::Forms::DataGridView();
            this->btnApprove = gcnew System::Windows::Forms::Button();
            this->btnReject = gcnew System::Windows::Forms::Button();
            this->btnRefresh = gcnew System::Windows::Forms::Button();
            this->txtSearch = gcnew System::Windows::Forms::TextBox();
            this->lblSearch = gcnew System::Windows::Forms::Label();
            this->cmbSemester = gcnew System::Windows::Forms::ComboBox();
            this->cmbYear = gcnew System::Windows::Forms::ComboBox();

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridPending))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridHistory))->BeginInit();
            this->tabControlEnrollments->SuspendLayout();
            this->tabPagePending->SuspendLayout();
            this->tabPageHistory->SuspendLayout();
            this->SuspendLayout();

            // Form Settings
            this->ClientSize = System::Drawing::Size(1200, 800);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Manage Enrollments";
            this->MaximizeBox = false;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;

            // Search Controls Layout
            this->lblSearch->Location = System::Drawing::Point(12, 15);
            this->lblSearch->Size = System::Drawing::Size(70, 23);
            this->lblSearch->Text = L"Search:";

            this->txtSearch->Location = System::Drawing::Point(82, 12);
            this->txtSearch->Size = System::Drawing::Size(200, 23);

            this->cmbSemester->Location = System::Drawing::Point(292, 12);
            this->cmbSemester->Size = System::Drawing::Size(150, 23);
            this->cmbSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

            this->cmbYear->Location = System::Drawing::Point(452, 12);
            this->cmbYear->Size = System::Drawing::Size(150, 23);
            this->cmbYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

            this->btnRefresh->Location = System::Drawing::Point(612, 11);
            this->btnRefresh->Size = System::Drawing::Size(75, 25);
            this->btnRefresh->Text = L"Refresh";

            // Tab Control Setup
            this->tabControlEnrollments->Location = System::Drawing::Point(12, 45);
            this->tabControlEnrollments->Size = System::Drawing::Size(1160, 730);
            this->tabControlEnrollments->Controls->Add(this->tabPagePending);
            this->tabControlEnrollments->Controls->Add(this->tabPageHistory);

            // Pending Tab
            this->tabPagePending->Text = L"Pending Enrollments";
            this->tabPagePending->Padding = System::Windows::Forms::Padding(3);
            this->dataGridPending->Dock = System::Windows::Forms::DockStyle::Top;
            this->dataGridPending->Size = System::Drawing::Size(1154, 650);

            // Approval Buttons
            this->btnApprove->Location = System::Drawing::Point(10, 660);
            this->btnApprove->Size = System::Drawing::Size(100, 30);
            this->btnApprove->Text = L"Approve";
            this->btnApprove->Enabled = false;

            this->btnReject->Location = System::Drawing::Point(120, 660);
            this->btnReject->Size = System::Drawing::Size(100, 30);
            this->btnReject->Text = L"Reject";
            this->btnReject->Enabled = false;

            this->tabPagePending->Controls->Add(this->dataGridPending);
            this->tabPagePending->Controls->Add(this->btnApprove);
            this->tabPagePending->Controls->Add(this->btnReject);

            // History Tab
            this->tabPageHistory->Text = L"Enrollment History";
            this->tabPageHistory->Padding = System::Windows::Forms::Padding(3);
            this->dataGridHistory->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabPageHistory->Controls->Add(this->dataGridHistory);

            // Add controls to form
            this->Controls->Add(this->lblSearch);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->cmbSemester);
            this->Controls->Add(this->cmbYear);
            this->Controls->Add(this->btnRefresh);
            this->Controls->Add(this->tabControlEnrollments);

            // Finalize initialization
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridPending))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridHistory))->EndInit();
            this->tabControlEnrollments->ResumeLayout(false);
            this->tabPagePending->ResumeLayout(false);
            this->tabPageHistory->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

            // Event handlers
            this->Load += gcnew System::EventHandler(this, &Manage_Enrollments::Manage_Enrollments_Load);
            this->btnApprove->Click += gcnew System::EventHandler(this, &Manage_Enrollments::btnApprove_Click);
            this->btnReject->Click += gcnew System::EventHandler(this, &Manage_Enrollments::btnReject_Click);
            this->btnRefresh->Click += gcnew System::EventHandler(this, &Manage_Enrollments::btnRefresh_Click);
            this->txtSearch->TextChanged += gcnew System::EventHandler(this, &Manage_Enrollments::txtSearch_TextChanged);
            this->cmbSemester->SelectedIndexChanged += gcnew System::EventHandler(this, &Manage_Enrollments::cmbSemester_SelectedIndexChanged);
            this->cmbYear->SelectedIndexChanged += gcnew System::EventHandler(this, &Manage_Enrollments::cmbYear_SelectedIndexChanged);
            this->dataGridPending->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Manage_Enrollments::dataGridPending_CellClick);
        }

        // Event handler declarations
        System::Void Manage_Enrollments_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void btnApprove_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnReject_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void cmbSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void cmbYear_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void dataGridPending_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e);
    };
}