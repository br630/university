// Enrollment.h
#pragma once
#include "db_conn.h"

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class Enrollment : public System::Windows::Forms::Form {
    private:
        int studentID;
        DatabaseManager^ dbManager;

    public:
        Enrollment(int currentStudentID) {
            InitializeComponent();
            studentID = currentStudentID;
            dbManager = DatabaseManager::GetInstance();
        }

    protected:
        ~Enrollment() {
            if (components) {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Label^ std_status;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ txt_admission;
        System::Windows::Forms::Label^ txt_Department;
        System::Windows::Forms::Label^ txt_program;
        System::Windows::Forms::Label^ txt_Admission_Year;
        System::Windows::Forms::Label^ View_transcript;
        System::Windows::Forms::Button^ btn_view;
        System::Windows::Forms::TabControl^ tabControl1;
        System::Windows::Forms::TabPage^ tabEnrollment;
        System::Windows::Forms::TabPage^ tabAvailableCourses;
        System::Windows::Forms::TabPage^ tabTranscript;
        System::Windows::Forms::GroupBox^ groupBoxFilters;
        System::Windows::Forms::ComboBox^ comboSemester;
        System::Windows::Forms::ComboBox^ comboYear;
        System::Windows::Forms::DataGridView^ gridTranscript;
        System::Windows::Forms::Button^ btnExportPDF;
        System::Windows::Forms::Button^ btnPrint;
        System::Windows::Forms::Label^ lblGPA;
        System::Windows::Forms::Label^ lblCreditsEarned;
        System::Windows::Forms::DataGridView^ dataGridEnrollment;
        System::Windows::Forms::GroupBox^ groupBoxAvailableCourses;
        System::Windows::Forms::ComboBox^ comboCourses;
        System::Windows::Forms::Button^ btnEnroll;
        System::Windows::Forms::DataGridView^ gridMaterials;
        System::Windows::Forms::Label^ lblMaterials;
        System::Windows::Forms::GroupBox^ groupBoxMaterials;

        void InitializeComponent() {
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->std_status = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->txt_admission = (gcnew System::Windows::Forms::Label());
            this->txt_Department = (gcnew System::Windows::Forms::Label());
            this->txt_program = (gcnew System::Windows::Forms::Label());
            this->txt_Admission_Year = (gcnew System::Windows::Forms::Label());
            this->View_transcript = (gcnew System::Windows::Forms::Label());
            this->btn_view = (gcnew System::Windows::Forms::Button());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabEnrollment = (gcnew System::Windows::Forms::TabPage());
            this->dataGridEnrollment = (gcnew System::Windows::Forms::DataGridView());
            this->tabAvailableCourses = (gcnew System::Windows::Forms::TabPage());
            this->groupBoxAvailableCourses = (gcnew System::Windows::Forms::GroupBox());
            this->comboCourses = (gcnew System::Windows::Forms::ComboBox());
            this->btnEnroll = (gcnew System::Windows::Forms::Button());
            this->groupBoxMaterials = (gcnew System::Windows::Forms::GroupBox());
            this->gridMaterials = (gcnew System::Windows::Forms::DataGridView());
            this->tabTranscript = (gcnew System::Windows::Forms::TabPage());
            this->gridTranscript = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxFilters = (gcnew System::Windows::Forms::GroupBox());
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
            this->comboYear = (gcnew System::Windows::Forms::ComboBox());
            this->btnExportPDF = (gcnew System::Windows::Forms::Button());
            this->btnPrint = (gcnew System::Windows::Forms::Button());
            this->lblGPA = (gcnew System::Windows::Forms::Label());
            this->lblCreditsEarned = (gcnew System::Windows::Forms::Label());
            this->lblMaterials = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->tabControl1->SuspendLayout();
            this->tabEnrollment->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEnrollment))->BeginInit();
            this->tabAvailableCourses->SuspendLayout();
            this->groupBoxAvailableCourses->SuspendLayout();
            this->groupBoxMaterials->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridMaterials))->BeginInit();
            this->tabTranscript->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridTranscript))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(0, 0);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(100, 50);
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // std_status
            // 
            this->std_status->Location = System::Drawing::Point(0, 0);
            this->std_status->Name = L"std_status";
            this->std_status->Size = System::Drawing::Size(100, 23);
            this->std_status->TabIndex = 0;
            // 
            // label1
            // 
            this->label1->Location = System::Drawing::Point(22, 25);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(338, 38);
            this->label1->TabIndex = 0;
            // 
            // txt_admission
            // 
            this->txt_admission->Location = System::Drawing::Point(22, 75);
            this->txt_admission->Name = L"txt_admission";
            this->txt_admission->Size = System::Drawing::Size(338, 25);
            this->txt_admission->TabIndex = 1;
            // 
            // txt_Department
            // 
            this->txt_Department->Location = System::Drawing::Point(22, 112);
            this->txt_Department->Name = L"txt_Department";
            this->txt_Department->Size = System::Drawing::Size(338, 25);
            this->txt_Department->TabIndex = 2;
            // 
            // txt_program
            // 
            this->txt_program->Location = System::Drawing::Point(0, 0);
            this->txt_program->Name = L"txt_program";
            this->txt_program->Size = System::Drawing::Size(100, 23);
            this->txt_program->TabIndex = 0;
            // 
            // txt_Admission_Year
            // 
            this->txt_Admission_Year->Location = System::Drawing::Point(0, 0);
            this->txt_Admission_Year->Name = L"txt_Admission_Year";
            this->txt_Admission_Year->Size = System::Drawing::Size(100, 23);
            this->txt_Admission_Year->TabIndex = 0;
            // 
            // View_transcript
            // 
            this->View_transcript->Location = System::Drawing::Point(0, 0);
            this->View_transcript->Name = L"View_transcript";
            this->View_transcript->Size = System::Drawing::Size(100, 23);
            this->View_transcript->TabIndex = 0;
            // 
            // btn_view
            // 
            this->btn_view->Location = System::Drawing::Point(0, 0);
            this->btn_view->Name = L"btn_view";
            this->btn_view->Size = System::Drawing::Size(75, 23);
            this->btn_view->TabIndex = 0;
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabEnrollment);
            this->tabControl1->Controls->Add(this->tabAvailableCourses);
            this->tabControl1->Controls->Add(this->tabTranscript);
            this->tabControl1->Location = System::Drawing::Point(22, 162);
            this->tabControl1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(1294, 750);
            this->tabControl1->TabIndex = 3;
            // 
            // tabEnrollment
            // 
            this->tabEnrollment->Controls->Add(this->dataGridEnrollment);
            this->tabEnrollment->Location = System::Drawing::Point(4, 29);
            this->tabEnrollment->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->tabEnrollment->Name = L"tabEnrollment";
            this->tabEnrollment->Size = System::Drawing::Size(1286, 717);
            this->tabEnrollment->TabIndex = 0;
            this->tabEnrollment->Text = L"Current Enrollments";
            // 
            // dataGridEnrollment
            // 
            this->dataGridEnrollment->AllowUserToAddRows = false;
            this->dataGridEnrollment->AllowUserToDeleteRows = false;
            this->dataGridEnrollment->ColumnHeadersHeight = 34;
            this->dataGridEnrollment->Location = System::Drawing::Point(0, 0);
            this->dataGridEnrollment->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->dataGridEnrollment->MultiSelect = false;
            this->dataGridEnrollment->Name = L"dataGridEnrollment";
            this->dataGridEnrollment->ReadOnly = true;
            this->dataGridEnrollment->RowHeadersWidth = 62;
            this->dataGridEnrollment->Size = System::Drawing::Size(1290, 771);
            this->dataGridEnrollment->TabIndex = 0;
            // 
            // tabAvailableCourses
            // 
            this->tabAvailableCourses->Controls->Add(this->groupBoxAvailableCourses);
            this->tabAvailableCourses->Controls->Add(this->groupBoxMaterials);
            this->tabAvailableCourses->Location = System::Drawing::Point(4, 29);
            this->tabAvailableCourses->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->tabAvailableCourses->Name = L"tabAvailableCourses";
            this->tabAvailableCourses->Size = System::Drawing::Size(1286, 717);
            this->tabAvailableCourses->TabIndex = 1;
            this->tabAvailableCourses->Text = L"Available Courses";
            // 
            // groupBoxAvailableCourses
            // 
            this->groupBoxAvailableCourses->Controls->Add(this->comboCourses);
            this->groupBoxAvailableCourses->Controls->Add(this->btnEnroll);
            this->groupBoxAvailableCourses->Location = System::Drawing::Point(11, 12);
            this->groupBoxAvailableCourses->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxAvailableCourses->Name = L"groupBoxAvailableCourses";
            this->groupBoxAvailableCourses->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxAvailableCourses->Size = System::Drawing::Size(1260, 125);
            this->groupBoxAvailableCourses->TabIndex = 0;
            this->groupBoxAvailableCourses->TabStop = false;
            this->groupBoxAvailableCourses->Text = L"Available Courses";
            // 
            // comboCourses
            // 
            this->comboCourses->Location = System::Drawing::Point(22, 38);
            this->comboCourses->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->comboCourses->Name = L"comboCourses";
            this->comboCourses->Size = System::Drawing::Size(450, 28);
            this->comboCourses->TabIndex = 0;
            this->comboCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &Enrollment::comboCourses_SelectedIndexChanged);
            // 
            // btnEnroll
            // 
            this->btnEnroll->Location = System::Drawing::Point(495, 38);
            this->btnEnroll->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnEnroll->Name = L"btnEnroll";
            this->btnEnroll->Size = System::Drawing::Size(112, 31);
            this->btnEnroll->TabIndex = 1;
            this->btnEnroll->Text = L"Enroll";
            this->btnEnroll->Click += gcnew System::EventHandler(this, &Enrollment::btnEnroll_Click);
            // 
            // groupBoxMaterials
            // 
            this->groupBoxMaterials->Controls->Add(this->gridMaterials);
            this->groupBoxMaterials->Location = System::Drawing::Point(11, 150);
            this->groupBoxMaterials->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxMaterials->Name = L"groupBoxMaterials";
            this->groupBoxMaterials->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxMaterials->Size = System::Drawing::Size(1260, 538);
            this->groupBoxMaterials->TabIndex = 1;
            this->groupBoxMaterials->TabStop = false;
            this->groupBoxMaterials->Text = L"Course Materials";
            // 
            // gridMaterials
            // 
            this->gridMaterials->AllowUserToAddRows = false;
            this->gridMaterials->AllowUserToDeleteRows = false;
            this->gridMaterials->ColumnHeadersHeight = 34;
            this->gridMaterials->Location = System::Drawing::Point(22, 38);
            this->gridMaterials->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->gridMaterials->MultiSelect = false;
            this->gridMaterials->Name = L"gridMaterials";
            this->gridMaterials->ReadOnly = true;
            this->gridMaterials->RowHeadersWidth = 62;
            this->gridMaterials->Size = System::Drawing::Size(1215, 475);
            this->gridMaterials->TabIndex = 0;
            // 
            // tabTranscript
            // 
            this->tabTranscript->Controls->Add(this->gridTranscript);
            this->tabTranscript->Location = System::Drawing::Point(4, 29);
            this->tabTranscript->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->tabTranscript->Name = L"tabTranscript";
            this->tabTranscript->Size = System::Drawing::Size(1286, 717);
            this->tabTranscript->TabIndex = 2;
            this->tabTranscript->Text = L"Transcript";
            // 
            // gridTranscript
            // 
            this->gridTranscript->AllowUserToAddRows = false;
            this->gridTranscript->AllowUserToDeleteRows = false;
            this->gridTranscript->ColumnHeadersHeight = 34;
            this->gridTranscript->Location = System::Drawing::Point(0, 0);
            this->gridTranscript->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->gridTranscript->MultiSelect = false;
            this->gridTranscript->Name = L"gridTranscript";
            this->gridTranscript->ReadOnly = true;
            this->gridTranscript->RowHeadersWidth = 62;
            this->gridTranscript->Size = System::Drawing::Size(1286, 654);
            this->gridTranscript->TabIndex = 0;
            // 
            // groupBoxFilters
            // 
            this->groupBoxFilters->Location = System::Drawing::Point(0, 0);
            this->groupBoxFilters->Name = L"groupBoxFilters";
            this->groupBoxFilters->Size = System::Drawing::Size(200, 100);
            this->groupBoxFilters->TabIndex = 0;
            this->groupBoxFilters->TabStop = false;
            // 
            // comboSemester
            // 
            this->comboSemester->Location = System::Drawing::Point(0, 0);
            this->comboSemester->Name = L"comboSemester";
            this->comboSemester->Size = System::Drawing::Size(121, 28);
            this->comboSemester->TabIndex = 0;
            // 
            // comboYear
            // 
            this->comboYear->Location = System::Drawing::Point(0, 0);
            this->comboYear->Name = L"comboYear";
            this->comboYear->Size = System::Drawing::Size(121, 28);
            this->comboYear->TabIndex = 0;
            // 
            // btnExportPDF
            // 
            this->btnExportPDF->Location = System::Drawing::Point(0, 0);
            this->btnExportPDF->Name = L"btnExportPDF";
            this->btnExportPDF->Size = System::Drawing::Size(75, 23);
            this->btnExportPDF->TabIndex = 0;
            // 
            // btnPrint
            // 
            this->btnPrint->Location = System::Drawing::Point(0, 0);
            this->btnPrint->Name = L"btnPrint";
            this->btnPrint->Size = System::Drawing::Size(75, 23);
            this->btnPrint->TabIndex = 0;
            // 
            // lblGPA
            // 
            this->lblGPA->Location = System::Drawing::Point(0, 0);
            this->lblGPA->Name = L"lblGPA";
            this->lblGPA->Size = System::Drawing::Size(100, 23);
            this->lblGPA->TabIndex = 0;
            // 
            // lblCreditsEarned
            // 
            this->lblCreditsEarned->Location = System::Drawing::Point(0, 0);
            this->lblCreditsEarned->Name = L"lblCreditsEarned";
            this->lblCreditsEarned->Size = System::Drawing::Size(100, 23);
            this->lblCreditsEarned->TabIndex = 0;
            // 
            // lblMaterials
            // 
            this->lblMaterials->Location = System::Drawing::Point(0, 0);
            this->lblMaterials->Name = L"lblMaterials";
            this->lblMaterials->Size = System::Drawing::Size(100, 23);
            this->lblMaterials->TabIndex = 0;
            // 
            // Enrollment
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1350, 1000);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->txt_admission);
            this->Controls->Add(this->txt_Department);
            this->Controls->Add(this->tabControl1);
            this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->MinimumSize = System::Drawing::Size(1347, 986);
            this->Name = L"Enrollment";
            this->Text = L"Student Enrollment";
            this->Load += gcnew System::EventHandler(this, &Enrollment::Enrollment_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->tabControl1->ResumeLayout(false);
            this->tabEnrollment->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEnrollment))->EndInit();
            this->tabAvailableCourses->ResumeLayout(false);
            this->groupBoxAvailableCourses->ResumeLayout(false);
            this->groupBoxMaterials->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridMaterials))->EndInit();
            this->tabTranscript->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridTranscript))->EndInit();
            this->ResumeLayout(false);

        }

        void LoadAvailableCourses();
        void LoadCurrentEnrollments();
        void LoadCourseMaterials(int courseID);
        void EnrollInCourse();
        void LoadTranscriptData();
        void LoadStudentData();
        void SetupGridColumns();
        void CalculateGPA();

        System::Void btnEnroll_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void comboCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void Enrollment_Load(System::Object^ sender, System::EventArgs^ e);
    };
}