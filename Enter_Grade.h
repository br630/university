#pragma once
#include "faculty.h"

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class Enter_Grade : public System::Windows::Forms::Form {
    public:
        Enter_Grade(void) {
            InitializeComponent();
            facultyInstance = Faculty::GetInstance();
        }

    protected:
        ~Enter_Grade() {
            if (components) {
                delete components;
            }
        }

    private:
        Faculty^ facultyInstance;
        System::ComponentModel::Container^ components;

        // Form Controls
        System::Windows::Forms::ComboBox^ cmbCourses;
        System::Windows::Forms::ComboBox^ cmbSemester;
        System::Windows::Forms::ComboBox^ cmbYear;
        System::Windows::Forms::DataGridView^ dgvEnrollments;
        System::Windows::Forms::Panel^ pnlGradeEntry;
        System::Windows::Forms::TextBox^ txtGrade;
        System::Windows::Forms::Label^ lblStudentName;
        System::Windows::Forms::Label^ lblCourse;
        System::Windows::Forms::Button^ btnSubmitGrade;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::TextBox^ txtSearch;

        // Method declarations
        void LoadFacultyCourses();
        void LoadEnrollments();
        void FilterChanged(System::Object^ sender, System::EventArgs^ e);
        void SearchTextChanged(System::Object^ sender, System::EventArgs^ e);
        void EnrollmentSelected(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
        void SubmitGrade(System::Object^ sender, System::EventArgs^ e);
        void CancelGradeEntry(System::Object^ sender, System::EventArgs^ e);
        void Enter_Grade_Load(System::Object^ sender, System::EventArgs^ e);
        void txtSearch_Enter(System::Object^ sender, System::EventArgs^ e);
        void txtSearch_Leave(System::Object^ sender, System::EventArgs^ e);

        void InitializeComponent(void) {
            this->components = gcnew System::ComponentModel::Container();
            this->cmbCourses = (gcnew System::Windows::Forms::ComboBox());
            this->cmbSemester = (gcnew System::Windows::Forms::ComboBox());
            this->cmbYear = (gcnew System::Windows::Forms::ComboBox());
            this->dgvEnrollments = (gcnew System::Windows::Forms::DataGridView());
            this->pnlGradeEntry = (gcnew System::Windows::Forms::Panel());
            this->txtGrade = (gcnew System::Windows::Forms::TextBox());
            this->lblStudentName = (gcnew System::Windows::Forms::Label());
            this->lblCourse = (gcnew System::Windows::Forms::Label());
            this->btnSubmitGrade = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEnrollments))->BeginInit();
            this->pnlGradeEntry->SuspendLayout();
            this->SuspendLayout();
            // 
            // Form Settings
            // 
            this->Text = L"Enter Grades";
            this->Size = System::Drawing::Size(1000, 600);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->MaximizeBox = false;
            // 
            // cmbCourses
            // 
            this->cmbCourses->Location = System::Drawing::Point(20, 20);
            this->cmbCourses->Size = System::Drawing::Size(200, 24);
            this->cmbCourses->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            // 
            // cmbSemester
            // 
            this->cmbSemester->Location = System::Drawing::Point(240, 20);
            this->cmbSemester->Size = System::Drawing::Size(150, 24);
            this->cmbSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

            this->cmbSemester->Items->AddRange(gcnew cli::array<System::Object^>(2) {
                L"Semester1",
                    L"Semester2"
            });
            
            // 
            // cmbYear
            // 
            this->cmbYear->Location = System::Drawing::Point(410, 20);
            this->cmbYear->Size = System::Drawing::Size(150, 24);
            this->cmbYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbYear->Items->AddRange(gcnew cli::array<System::Object^>(4) {
                L"Year1",
                    L"Year2",
                    L"Year3",
                    L"Year4"
            });
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(580, 20);
            this->txtSearch->Size = System::Drawing::Size(200, 24);
            this->txtSearch->Text = L"Search by student name...";
            this->txtSearch->ForeColor = System::Drawing::Color::Gray;
            // 
            // dgvEnrollments
            // 
            this->dgvEnrollments->Location = System::Drawing::Point(20, 60);
            this->dgvEnrollments->Size = System::Drawing::Size(760, 400);
            this->dgvEnrollments->AllowUserToAddRows = false;
            this->dgvEnrollments->ReadOnly = true;
            this->dgvEnrollments->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dgvEnrollments->MultiSelect = false;
            this->dgvEnrollments->ColumnHeadersHeight = 29;
            // 
            // pnlGradeEntry
            // 
            this->pnlGradeEntry->Location = System::Drawing::Point(800, 60);
            this->pnlGradeEntry->Size = System::Drawing::Size(180, 200);
            this->pnlGradeEntry->Visible = false;
            // 
            // lblStudentName
            // 
            this->lblStudentName->Location = System::Drawing::Point(10, 10);
            this->lblStudentName->Size = System::Drawing::Size(160, 20);
            // 
            // lblCourse
            // 
            this->lblCourse->Location = System::Drawing::Point(10, 40);
            this->lblCourse->Size = System::Drawing::Size(160, 20);
            // 
            // txtGrade
            // 
            this->txtGrade->Location = System::Drawing::Point(10, 70);
            this->txtGrade->Size = System::Drawing::Size(160, 24);
            // 
            // btnSubmitGrade
            // 
            this->btnSubmitGrade->Location = System::Drawing::Point(10, 100);
            this->btnSubmitGrade->Size = System::Drawing::Size(160, 30);
            this->btnSubmitGrade->Text = L"Submit Grade";
            // 
            // btnCancel
            // 
            this->btnCancel->Location = System::Drawing::Point(10, 140);
            this->btnCancel->Size = System::Drawing::Size(160, 30);
            this->btnCancel->Text = L"Cancel";
            // 
            // Control Additions
            // 
            this->pnlGradeEntry->Controls->Add(this->lblStudentName);
            this->pnlGradeEntry->Controls->Add(this->lblCourse);
            this->pnlGradeEntry->Controls->Add(this->txtGrade);
            this->pnlGradeEntry->Controls->Add(this->btnSubmitGrade);
            this->pnlGradeEntry->Controls->Add(this->btnCancel);

            this->Controls->Add(this->cmbCourses);
            this->Controls->Add(this->cmbSemester);
            this->Controls->Add(this->cmbYear);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->dgvEnrollments);
            this->Controls->Add(this->pnlGradeEntry);

            // Event handlers
            this->Load += gcnew System::EventHandler(this, &Enter_Grade::Enter_Grade_Load);
            this->cmbCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &Enter_Grade::FilterChanged);
            this->cmbSemester->SelectedIndexChanged += gcnew System::EventHandler(this, &Enter_Grade::FilterChanged);
            this->cmbYear->SelectedIndexChanged += gcnew System::EventHandler(this, &Enter_Grade::FilterChanged);
            this->txtSearch->TextChanged += gcnew System::EventHandler(this, &Enter_Grade::SearchTextChanged);
            this->txtSearch->Enter += gcnew System::EventHandler(this, &Enter_Grade::txtSearch_Enter);
            this->txtSearch->Leave += gcnew System::EventHandler(this, &Enter_Grade::txtSearch_Leave);
            this->dgvEnrollments->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Enter_Grade::EnrollmentSelected);
            this->btnSubmitGrade->Click += gcnew System::EventHandler(this, &Enter_Grade::SubmitGrade);
            this->btnCancel->Click += gcnew System::EventHandler(this, &Enter_Grade::CancelGradeEntry);

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEnrollments))->EndInit();
            this->pnlGradeEntry->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
    };
}