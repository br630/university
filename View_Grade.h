#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class View_Grade : public System::Windows::Forms::Form {
    public:
        View_Grade(int studentId) {
            InitializeComponent();
            this->studentId = studentId;
        }

    protected:
        ~View_Grade() {
            if (components) {
                delete components;
            }
        }

    private:
        int studentId;
        System::ComponentModel::Container^ components;

        // Form Controls
        System::Windows::Forms::DataGridView^ dgvGrades;
        System::Windows::Forms::ComboBox^ cmbSemester;
        System::Windows::Forms::ComboBox^ cmbYear;
        System::Windows::Forms::Label^ lblGPA;
        System::Windows::Forms::Label^ lblCredits;
        System::Windows::Forms::Label^ lblSemester;
        System::Windows::Forms::Label^ lblYear;
        System::Windows::Forms::GroupBox^ grpSummary;
        System::Windows::Forms::Button^ btnRefresh;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Label^ lblSearch;

        // Method declarations
        void LoadGrades();
        void CalculateGPA();
        void CalculateTotalCredits();
        void FilterGrades(System::Object^ sender, System::EventArgs^ e);
        void SearchGrades(System::Object^ sender, System::EventArgs^ e);
        void Form_Load(System::Object^ sender, System::EventArgs^ e);

        void InitializeComponent(void) {
            this->dgvGrades = (gcnew System::Windows::Forms::DataGridView());
            this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
            this->cmbYear = (gcnew System::Windows::Forms::ComboBox());
            this->lblGPA = (gcnew System::Windows::Forms::Label());
            this->lblCredits = (gcnew System::Windows::Forms::Label());
            this->lblSemester = (gcnew System::Windows::Forms::Label());
            this->lblYear = (gcnew System::Windows::Forms::Label());
            this->grpSummary = (gcnew System::Windows::Forms::GroupBox());
            this->btnRefresh = (gcnew System::Windows::Forms::Button());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->lblSearch = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvGrades))->BeginInit();
            this->grpSummary->SuspendLayout();
            this->SuspendLayout();
            // 
            // dgvGrades
            // 
            this->dgvGrades->AllowUserToAddRows = false;
            this->dgvGrades->AllowUserToDeleteRows = false;
            this->dgvGrades->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dgvGrades->ColumnHeadersHeight = 29;
            this->dgvGrades->Location = System::Drawing::Point(20, 180);
            this->dgvGrades->MultiSelect = false;
            this->dgvGrades->Name = L"dgvGrades";
            this->dgvGrades->ReadOnly = true;
            this->dgvGrades->RowHeadersWidth = 51;
            this->dgvGrades->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvGrades->Size = System::Drawing::Size(940, 370);
            this->dgvGrades->TabIndex = 8;
            // 
            // cmbSemester
            // 
            this->cmbSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbSemester->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"All", L"Semester1", L"Semester2" });
            this->cmbSemester->Location = System::Drawing::Point(410, 30);
            this->cmbSemester->Name = L"cmbSemester";
            this->cmbSemester->Size = System::Drawing::Size(150, 24);
            this->cmbSemester->TabIndex = 2;
            this->cmbSemester->SelectedIndexChanged += gcnew System::EventHandler(this, &View_Grade::FilterGrades);
            // 
            // cmbYear
            // 
            this->cmbYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbYear->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"All", L"Year1", L"Year2", L"Year3", L"Year4" });
            this->cmbYear->Location = System::Drawing::Point(620, 30);
            this->cmbYear->Name = L"cmbYear";
            this->cmbYear->Size = System::Drawing::Size(150, 24);
            this->cmbYear->TabIndex = 4;
            this->cmbYear->SelectedIndexChanged += gcnew System::EventHandler(this, &View_Grade::FilterGrades);
            // 
            // lblGPA
            // 
            this->lblGPA->Location = System::Drawing::Point(20, 30);
            this->lblGPA->Name = L"lblGPA";
            this->lblGPA->Size = System::Drawing::Size(260, 20);
            this->lblGPA->TabIndex = 0;
            this->lblGPA->Text = L"Cumulative GPA: ";
            // 
            // lblCredits
            // 
            this->lblCredits->Location = System::Drawing::Point(20, 60);
            this->lblCredits->Name = L"lblCredits";
            this->lblCredits->Size = System::Drawing::Size(260, 20);
            this->lblCredits->TabIndex = 1;
            this->lblCredits->Text = L"Total Credits: ";
            // 
            // lblSemester
            // 
            this->lblSemester->Location = System::Drawing::Point(340, 30);
            this->lblSemester->Name = L"lblSemester";
            this->lblSemester->Size = System::Drawing::Size(70, 20);
            this->lblSemester->TabIndex = 1;
            this->lblSemester->Text = L"Semester:";
            // 
            // lblYear
            // 
            this->lblYear->Location = System::Drawing::Point(580, 30);
            this->lblYear->Name = L"lblYear";
            this->lblYear->Size = System::Drawing::Size(40, 20);
            this->lblYear->TabIndex = 3;
            this->lblYear->Text = L"Year:";
            // 
            // grpSummary
            // 
            this->grpSummary->Controls->Add(this->lblGPA);
            this->grpSummary->Controls->Add(this->lblCredits);
            this->grpSummary->Location = System::Drawing::Point(20, 20);
            this->grpSummary->Name = L"grpSummary";
            this->grpSummary->Size = System::Drawing::Size(300, 100);
            this->grpSummary->TabIndex = 0;
            this->grpSummary->TabStop = false;
            this->grpSummary->Text = L"Academic Summary";
            // 
            // btnRefresh
            // 
            this->btnRefresh->Location = System::Drawing::Point(790, 30);
            this->btnRefresh->Name = L"btnRefresh";
            this->btnRefresh->Size = System::Drawing::Size(100, 25);
            this->btnRefresh->TabIndex = 5;
            this->btnRefresh->Text = L"Refresh";
            this->btnRefresh->Click += gcnew System::EventHandler(this, &View_Grade::FilterGrades);
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(76, 137);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(200, 22);
            this->txtSearch->TabIndex = 7;
            this->txtSearch->TextChanged += gcnew System::EventHandler(this, &View_Grade::SearchGrades);
            // 
            // lblSearch
            // 
            this->lblSearch->Location = System::Drawing::Point(20, 140);
            this->lblSearch->Name = L"lblSearch";
            this->lblSearch->Size = System::Drawing::Size(50, 20);
            this->lblSearch->TabIndex = 6;
            this->lblSearch->Text = L"Search:";
            // 
            // View_Grades
            // 
            this->ClientSize = System::Drawing::Size(982, 553);
            this->Controls->Add(this->grpSummary);
            this->Controls->Add(this->lblSemester);
            this->Controls->Add(this->cmbSemester);
            this->Controls->Add(this->lblYear);
            this->Controls->Add(this->cmbYear);
            this->Controls->Add(this->btnRefresh);
            this->Controls->Add(this->lblSearch);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->dgvGrades);
            this->MaximizeBox = false;
            this->Name = L"View_Grades";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"View Grades";
            this->Load += gcnew System::EventHandler(this, &View_Grade::Form_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvGrades))->EndInit();
            this->grpSummary->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    };
}