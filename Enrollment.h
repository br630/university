#pragma once

namespace university {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Enrollment : public System::Windows::Forms::Form
    {
    public:
        Enrollment(void)
        {
            InitializeComponent();
        }

    protected:
        ~Enrollment()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Label^ std_status;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ txt_admission;
        System::Windows::Forms::Label^ txt_Department;
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Label^ txt_program;
        System::Windows::Forms::Label^ txt_Admission_Year;
        System::Windows::Forms::Label^ View_transcript;
        System::Windows::Forms::Button^ btn_view;
        System::Windows::Forms::TabControl^ tabControl1;
        System::Windows::Forms::TabPage^ tabEnrollment;
        System::Windows::Forms::TabPage^ tabTranscript;
        System::Windows::Forms::GroupBox^ groupBoxFilters;
        System::Windows::Forms::ComboBox^ comboSemester;
        System::Windows::Forms::ComboBox^ comboYear;
        System::Windows::Forms::Button^ btnExportPDF;
        System::Windows::Forms::Button^ btnPrint;
        System::Windows::Forms::Label^ lblGPA;
        System::Windows::Forms::Label^ lblCreditsEarned;
        System::Windows::Forms::DataGridView^ gridTranscript;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Enrollment::typeid));
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->std_status = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->txt_admission = (gcnew System::Windows::Forms::Label());
            this->txt_Department = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->txt_program = (gcnew System::Windows::Forms::Label());
            this->txt_Admission_Year = (gcnew System::Windows::Forms::Label());
            this->View_transcript = (gcnew System::Windows::Forms::Label());
            this->btn_view = (gcnew System::Windows::Forms::Button());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabEnrollment = (gcnew System::Windows::Forms::TabPage());
            this->tabTranscript = (gcnew System::Windows::Forms::TabPage());
            this->groupBoxFilters = (gcnew System::Windows::Forms::GroupBox());
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
            this->comboYear = (gcnew System::Windows::Forms::ComboBox());
            this->gridTranscript = (gcnew System::Windows::Forms::DataGridView());
            this->btnExportPDF = (gcnew System::Windows::Forms::Button());
            this->btnPrint = (gcnew System::Windows::Forms::Button());
            this->lblGPA = (gcnew System::Windows::Forms::Label());
            this->lblCreditsEarned = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->tabControl1->SuspendLayout();
            this->tabEnrollment->SuspendLayout();
            this->tabTranscript->SuspendLayout();
            this->groupBoxFilters->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridTranscript))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(692, 38);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(348, 258);
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // std_status
            // 
            this->std_status->AutoSize = true;
            this->std_status->Location = System::Drawing::Point(75, 97);
            this->std_status->Name = L"std_status";
            this->std_status->Size = System::Drawing::Size(121, 20);
            this->std_status->TabIndex = 2;
            this->std_status->Text = L"Student Status:";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(72, 38);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(274, 37);
            this->label1->TabIndex = 3;
            this->label1->Text = L"<Student Name>";
            // 
            // txt_admission
            // 
            this->txt_admission->AutoSize = true;
            this->txt_admission->Location = System::Drawing::Point(75, 146);
            this->txt_admission->Name = L"txt_admission";
            this->txt_admission->Size = System::Drawing::Size(110, 20);
            this->txt_admission->TabIndex = 4;
            this->txt_admission->Text = L"Admission No.";
            // 
            // txt_Department
            // 
            this->txt_Department->AutoSize = true;
            this->txt_Department->Location = System::Drawing::Point(75, 194);
            this->txt_Department->Name = L"txt_Department";
            this->txt_Department->Size = System::Drawing::Size(98, 20);
            this->txt_Department->TabIndex = 5;
            this->txt_Department->Text = L"Department:";
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(6, 6);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 62;
            this->dataGridView1->Size = System::Drawing::Size(1060, 275);
            this->dataGridView1->TabIndex = 6;
            // 
            // txt_program
            // 
            this->txt_program->AutoSize = true;
            this->txt_program->Location = System::Drawing::Point(75, 233);
            this->txt_program->Name = L"txt_program";
            this->txt_program->Size = System::Drawing::Size(73, 20);
            this->txt_program->TabIndex = 7;
            this->txt_program->Text = L"Program:";
            // 
            // txt_Admission_Year
            // 
            this->txt_Admission_Year->AutoSize = true;
            this->txt_Admission_Year->Location = System::Drawing::Point(75, 276);
            this->txt_Admission_Year->Name = L"txt_Admission_Year";
            this->txt_Admission_Year->Size = System::Drawing::Size(120, 20);
            this->txt_Admission_Year->TabIndex = 8;
            this->txt_Admission_Year->Text = L"Admission Year";
            // 
            // View_transcript
            // 
            this->View_transcript->AutoSize = true;
            this->View_transcript->Location = System::Drawing::Point(741, 322);
            this->View_transcript->Name = L"View_transcript";
            this->View_transcript->Size = System::Drawing::Size(117, 20);
            this->View_transcript->TabIndex = 9;
            this->View_transcript->Text = L"View Transcript";
            // 
            // btn_view
            // 
            this->btn_view->Location = System::Drawing::Point(874, 316);
            this->btn_view->Name = L"btn_view";
            this->btn_view->Size = System::Drawing::Size(152, 32);
            this->btn_view->TabIndex = 10;
            this->btn_view->Text = L"View";
            this->btn_view->UseVisualStyleBackColor = true;
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabEnrollment);
            this->tabControl1->Controls->Add(this->tabTranscript);
            this->tabControl1->Location = System::Drawing::Point(10, 300);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(1080, 320);
            this->tabControl1->TabIndex = 11;
            // 
            // tabEnrollment
            // 
            this->tabEnrollment->Controls->Add(this->dataGridView1);
            this->tabEnrollment->Location = System::Drawing::Point(4, 29);
            this->tabEnrollment->Name = L"tabEnrollment";
            this->tabEnrollment->Padding = System::Windows::Forms::Padding(3);
            this->tabEnrollment->Size = System::Drawing::Size(1072, 287);
            this->tabEnrollment->TabIndex = 0;
            this->tabEnrollment->Text = L"Current Enrollment";
            this->tabEnrollment->UseVisualStyleBackColor = true;
            // 
            // tabTranscript
            // 
            this->tabTranscript->Controls->Add(this->groupBoxFilters);
            this->tabTranscript->Controls->Add(this->gridTranscript);
            this->tabTranscript->Controls->Add(this->btnExportPDF);
            this->tabTranscript->Controls->Add(this->btnPrint);
            this->tabTranscript->Location = System::Drawing::Point(4, 29);
            this->tabTranscript->Name = L"tabTranscript";
            this->tabTranscript->Size = System::Drawing::Size(1072, 287);
            this->tabTranscript->TabIndex = 1;
            this->tabTranscript->Text = L"Academic Transcript";
            this->tabTranscript->UseVisualStyleBackColor = true;
            // 
            // groupBoxFilters
            // 
            this->groupBoxFilters->Controls->Add(this->comboSemester);
            this->groupBoxFilters->Controls->Add(this->comboYear);
            this->groupBoxFilters->Location = System::Drawing::Point(10, 10);
            this->groupBoxFilters->Name = L"groupBoxFilters";
            this->groupBoxFilters->Size = System::Drawing::Size(300, 100);
            this->groupBoxFilters->TabIndex = 12;
            this->groupBoxFilters->TabStop = false;
            this->groupBoxFilters->Text = L"Filters";
            // 
            // comboSemester
            // 
            this->comboSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboSemester->FormattingEnabled = true;
            this->comboSemester->Location = System::Drawing::Point(10, 30);
            this->comboSemester->Name = L"comboSemester";
            this->comboSemester->Size = System::Drawing::Size(121, 28);
            this->comboSemester->TabIndex = 13;
            // 
            // comboYear
            // 
            this->comboYear->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboYear->FormattingEnabled = true;
            this->comboYear->Location = System::Drawing::Point(150, 30);
            this->comboYear->Name = L"comboYear";
            this->comboYear->Size = System::Drawing::Size(121, 28);
            this->comboYear->TabIndex = 14;
            // 
            // gridTranscript
            // 
            this->gridTranscript->AllowUserToAddRows = false;
            this->gridTranscript->AllowUserToDeleteRows = false;
            this->gridTranscript->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->gridTranscript->Location = System::Drawing::Point(10, 120);
            this->gridTranscript->Name = L"gridTranscript";
            this->gridTranscript->ReadOnly = true;
            this->gridTranscript->RowHeadersWidth = 62;
            this->gridTranscript->Size = System::Drawing::Size(1050, 150);
            this->gridTranscript->TabIndex = 19;
            // 
            // btnExportPDF
            // 
            this->btnExportPDF->Location = System::Drawing::Point(850, 30);
            this->btnExportPDF->Name = L"btnExportPDF";
            this->btnExportPDF->Size = System::Drawing::Size(100, 35);
            this->btnExportPDF->TabIndex = 15;
            this->btnExportPDF->Text = L"Export PDF";
            this->btnExportPDF->UseVisualStyleBackColor = true;
            this->btnExportPDF->Click += gcnew System::EventHandler(this, &Enrollment::btnExportPDF_Click);
            // 
            // btnPrint
            // 
            this->btnPrint->Location = System::Drawing::Point(960, 30);
            this->btnPrint->Name = L"btnPrint";
            this->btnPrint->Size = System::Drawing::Size(100, 35);
            this->btnPrint->TabIndex = 16;
            this->btnPrint->Text = L"Print";
            this->btnPrint->UseVisualStyleBackColor = true;
            this->btnPrint->Click += gcnew System::EventHandler(this, &Enrollment::btnPrint_Click);
            // 
            // lblGPA
            // 
            this->lblGPA->AutoSize = true;
            this->lblGPA->Location = System::Drawing::Point(320, 30);
            this->lblGPA->Name = L"lblGPA";
            this->lblGPA->Size = System::Drawing::Size(45, 20);
            this->lblGPA->TabIndex = 17;
            this->lblGPA->Text = L"GPA:";
            // 
            // lblCreditsEarned
            // 
            this->lblCreditsEarned->AutoSize = true;
            this->lblCreditsEarned->Location = System::Drawing::Point(320, 60);
            this->lblCreditsEarned->Name = L"lblCreditsEarned";
            this->lblCreditsEarned->Size = System::Drawing::Size(116, 20);
            this->lblCreditsEarned->TabIndex = 18;
            this->lblCreditsEarned->Text = L"Credits Earned:";
            // 
            // Enrollment
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1111, 634);
            this->Controls->Add(this->tabControl1);
            this->Controls->Add(this->btn_view);
            this->Controls->Add(this->View_transcript);
            this->Controls->Add(this->txt_Admission_Year);
            this->Controls->Add(this->txt_program);
            this->Controls->Add(this->txt_Department);
            this->Controls->Add(this->txt_admission);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->std_status);
            this->Controls->Add(this->pictureBox1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Enrollment";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Enrollment";
            this->Load += gcnew System::EventHandler(this, &Enrollment::Enrollment_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->tabControl1->ResumeLayout(false);
            this->tabEnrollment->ResumeLayout(false);
            this->tabTranscript->ResumeLayout(false);
            this->groupBoxFilters->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridTranscript))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void LoadYears(void) {
            int currentYear = DateTime::Now.Year;
            for (int i = currentYear - 4; i <= currentYear; i++) {
                this->comboYear->Items->Add(i.ToString());
            }
            this->comboYear->SelectedIndex = this->comboYear->Items->Count - 1;
        }

        void SetupTranscriptGrid(void) {
            this->gridTranscript->ColumnCount = 6;
            array<String^>^ columnNames = {
                "Course Code",
                "Course Name",
                "Credits",
                "Grade",
                "Semester",
                "Year"
            };

            for (int i = 0; i < columnNames->Length; i++) {
                this->gridTranscript->Columns[i]->Name = columnNames[i];
                this->gridTranscript->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            }
        }

        void LoadStudentData(void) {
            try {
                // Sample data population
                this->label1->Text = "John Doe";
                this->txt_admission->Text = "STD2024001";
                this->txt_Department->Text = "Computer Science";
                this->txt_program->Text = "Bachelor of Science";
                this->txt_Admission_Year->Text = "2024";

                LoadTranscriptData();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading student data: " + ex->Message);
            }
        }

        void LoadTranscriptData(void) {
            try {
                this->gridTranscript->Rows->Clear();

                // Sample transcript data
                this->gridTranscript->Rows->Add("CS101", "Introduction to Programming", "3", "A", "Semester 1", "2024");
                this->gridTranscript->Rows->Add("CS102", "Data Structures", "3", "B+", "Semester 1", "2024");
                this->gridTranscript->Rows->Add("MATH101", "Calculus I", "3", "A-", "Semester 1", "2024");

                CalculateGPA();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading transcript data: " + ex->Message);
            }
        }

        void CalculateGPA(void) {
            double totalPoints = 0;
            int totalCredits = 0;

            for each (DataGridViewRow ^ row in this->gridTranscript->Rows) {
                if (row->Cells["Grade"]->Value != nullptr) {
                    String^ grade = row->Cells["Grade"]->Value->ToString();
                    int credits = Int32::Parse(row->Cells["Credits"]->Value->ToString());

                    double points = 0;
                    if (grade == "A") points = 4.0;
                    else if (grade == "A-") points = 3.7;
                    else if (grade == "B+") points = 3.3;
                    else if (grade == "B") points = 3.0;
                    else if (grade == "B-") points = 2.7;
                    else if (grade == "C+") points = 2.3;
                    else if (grade == "C") points = 2.0;
                    else if (grade == "C-") points = 1.7;
                    else if (grade == "D+") points = 1.3;
                    else if (grade == "D") points = 1.0;
                    else if (grade == "F") points = 0.0;

                    totalPoints += points * credits;
                    totalCredits += credits;
                }
            }

            double gpa = totalCredits > 0 ? totalPoints / totalCredits : 0.0;
            this->lblGPA->Text = String::Format("GPA: {0:F2}", gpa);
            this->lblCreditsEarned->Text = String::Format("Credits Earned: {0}", totalCredits);
        }

        System::Void Enrollment_Load(System::Object^ sender, System::EventArgs^ e) {
            LoadYears();
            SetupTranscriptGrid();
            LoadStudentData();
        }

        System::Void comboSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            LoadTranscriptData();
        }

        System::Void btnExportPDF_Click(System::Object^ sender, System::EventArgs^ e) {
            SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
            saveFileDialog1->Filter = "PDF files (*.pdf)|*.pdf";
            saveFileDialog1->FilterIndex = 1;
            saveFileDialog1->RestoreDirectory = true;

            if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                MessageBox::Show("Exporting to PDF: " + saveFileDialog1->FileName);
                // Implement PDF export logic here
            }
        }

        System::Void btnPrint_Click(System::Object^ sender, System::EventArgs^ e) {
            PrintDialog^ printDialog1 = gcnew PrintDialog();
            if (printDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                MessageBox::Show("Printing transcript...");
                // Implement printing logic here
            }
        }
    };
}