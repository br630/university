#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;
    using namespace System::IO;

    public ref class Generate_Report : public System::Windows::Forms::Form {
    public:
        Generate_Report(void) {
            InitializeComponent();
        }

    protected:
        ~Generate_Report() {
            if (components) {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

        // Form Controls
        System::Windows::Forms::TabControl^ tabControlReports;
        System::Windows::Forms::TabPage^ tabPageStudents;
        System::Windows::Forms::TabPage^ tabPageFaculty;
        System::Windows::Forms::DataGridView^ dgvStudents;
        System::Windows::Forms::DataGridView^ dgvFaculty;
        System::Windows::Forms::Button^ btnExportStudents;
        System::Windows::Forms::Button^ btnExportFaculty;
        System::Windows::Forms::TextBox^ txtStudentSearch;
        System::Windows::Forms::TextBox^ txtFacultySearch;
        System::Windows::Forms::Label^ lblStudentSearch;
        System::Windows::Forms::Label^ lblFacultySearch;
        System::Windows::Forms::SaveFileDialog^ saveFileDialog1;

        // Method declarations
        void LoadStudentData();
        void LoadFacultyData();
        void ExportToExcel(DataGridView^ dgv, String^ filePath);
        void FilterStudents(System::Object^ sender, System::EventArgs^ e);
        void FilterFaculty(System::Object^ sender, System::EventArgs^ e);
        void ExportStudents(System::Object^ sender, System::EventArgs^ e);
        void ExportFaculty(System::Object^ sender, System::EventArgs^ e);
        void Form_Load(System::Object^ sender, System::EventArgs^ e);

        void InitializeComponent(void) {
            this->components = gcnew System::ComponentModel::Container();

            // Initialize all controls
            this->tabControlReports = gcnew System::Windows::Forms::TabControl();
            this->tabPageStudents = gcnew System::Windows::Forms::TabPage();
            this->tabPageFaculty = gcnew System::Windows::Forms::TabPage();
            this->dgvStudents = gcnew System::Windows::Forms::DataGridView();
            this->dgvFaculty = gcnew System::Windows::Forms::DataGridView();
            this->btnExportStudents = gcnew System::Windows::Forms::Button();
            this->btnExportFaculty = gcnew System::Windows::Forms::Button();
            this->txtStudentSearch = gcnew System::Windows::Forms::TextBox();
            this->txtFacultySearch = gcnew System::Windows::Forms::TextBox();
            this->lblStudentSearch = gcnew System::Windows::Forms::Label();
            this->lblFacultySearch = gcnew System::Windows::Forms::Label();
            this->saveFileDialog1 = gcnew System::Windows::Forms::SaveFileDialog();

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudents))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFaculty))->BeginInit();
            this->SuspendLayout();

            // Form Settings
            this->Text = L"Generate Reports";
            this->Size = System::Drawing::Size(1200, 800);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->MaximizeBox = false;

            // Tab Control setup
            this->tabControlReports->Location = System::Drawing::Point(12, 12);
            this->tabControlReports->Size = System::Drawing::Size(1160, 740);
            this->tabControlReports->SelectedIndex = 0;
            this->tabControlReports->Controls->Add(this->tabPageStudents);
            this->tabControlReports->Controls->Add(this->tabPageFaculty);

            // Add TabControl to form
            this->Controls->Add(this->tabControlReports);

            // Students Tab
            this->tabPageStudents->Text = L"Student Reports";
            this->tabPageStudents->Padding = System::Windows::Forms::Padding(3);
            this->tabPageStudents->Size = System::Drawing::Size(1152, 714);

            // Faculty Tab
            this->tabPageFaculty->Text = L"Faculty Reports";
            this->tabPageFaculty->Padding = System::Windows::Forms::Padding(3);
            this->tabPageFaculty->Size = System::Drawing::Size(1152, 714);

            // Student Search
            this->lblStudentSearch->Location = System::Drawing::Point(10, 15);
            this->lblStudentSearch->Size = System::Drawing::Size(100, 23);
            this->lblStudentSearch->Text = L"Search Students:";
            this->tabPageStudents->Controls->Add(this->lblStudentSearch);

            this->txtStudentSearch->Location = System::Drawing::Point(110, 12);
            this->txtStudentSearch->Size = System::Drawing::Size(200, 23);
            this->tabPageStudents->Controls->Add(this->txtStudentSearch);

            // Faculty Search
            this->lblFacultySearch->Location = System::Drawing::Point(10, 15);
            this->lblFacultySearch->Size = System::Drawing::Size(100, 23);
            this->lblFacultySearch->Text = L"Search Faculty:";
            this->tabPageFaculty->Controls->Add(this->lblFacultySearch);

            this->txtFacultySearch->Location = System::Drawing::Point(110, 12);
            this->txtFacultySearch->Size = System::Drawing::Size(200, 23);
            this->tabPageFaculty->Controls->Add(this->txtFacultySearch);

            // Student DataGridView
            this->dgvStudents->Location = System::Drawing::Point(6, 50);
            this->dgvStudents->Size = System::Drawing::Size(1140, 620);
            this->dgvStudents->AllowUserToAddRows = false;
            this->dgvStudents->ReadOnly = true;
            this->dgvStudents->MultiSelect = false;
            this->dgvStudents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvStudents->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->tabPageStudents->Controls->Add(this->dgvStudents);

            // Faculty DataGridView
            this->dgvFaculty->Location = System::Drawing::Point(6, 50);
            this->dgvFaculty->Size = System::Drawing::Size(1140, 620);
            this->dgvFaculty->AllowUserToAddRows = false;
            this->dgvFaculty->ReadOnly = true;
            this->dgvFaculty->MultiSelect = false;
            this->dgvFaculty->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvFaculty->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->tabPageFaculty->Controls->Add(this->dgvFaculty);

            // Export Buttons
            this->btnExportStudents->Text = L"Export to CSV";
            this->btnExportStudents->Location = System::Drawing::Point(1020, 12);
            this->btnExportStudents->Size = System::Drawing::Size(120, 30);
            this->tabPageStudents->Controls->Add(this->btnExportStudents);

            this->btnExportFaculty->Text = L"Export to CSV";
            this->btnExportFaculty->Location = System::Drawing::Point(1020, 12);
            this->btnExportFaculty->Size = System::Drawing::Size(120, 30);
            this->tabPageFaculty->Controls->Add(this->btnExportFaculty);

            // Save File Dialog
            this->saveFileDialog1->Filter = "CSV Files|*.csv";
            this->saveFileDialog1->Title = "Save Report";

            // Event Handlers
            this->Load += gcnew System::EventHandler(this, &Generate_Report::Form_Load);
            this->txtStudentSearch->TextChanged += gcnew System::EventHandler(this, &Generate_Report::FilterStudents);
            this->txtFacultySearch->TextChanged += gcnew System::EventHandler(this, &Generate_Report::FilterFaculty);
            this->btnExportStudents->Click += gcnew System::EventHandler(this, &Generate_Report::ExportStudents);
            this->btnExportFaculty->Click += gcnew System::EventHandler(this, &Generate_Report::ExportFaculty);

            // Finalize
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudents))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFaculty))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
    };
}