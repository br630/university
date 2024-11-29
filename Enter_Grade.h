#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Enter_Grade
	/// </summary>
	public ref class Enter_Grade : public System::Windows::Forms::Form
	{
	public:
		Enter_Grade(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Enter_Grade()
		{
			if (components)
			{
				delete components;
			}
		}

    private:
        // Course Selection Controls
        System::Windows::Forms::GroupBox^ groupBoxCourseSelect;
        System::Windows::Forms::Label^ lblCourse;
        System::Windows::Forms::ComboBox^ comboCourses;
        System::Windows::Forms::Label^ lblSemester;
        System::Windows::Forms::ComboBox^ comboSemester;

        // Grade Input Controls
        System::Windows::Forms::GroupBox^ groupBoxGradeInput;
        System::Windows::Forms::Label^ lblStudentID;
        System::Windows::Forms::TextBox^ txtStudentID;
        System::Windows::Forms::Label^ lblStudentName;
        System::Windows::Forms::TextBox^ txtStudentName;
        System::Windows::Forms::Label^ lblGrade;
        System::Windows::Forms::TextBox^ txtGrade;
        System::Windows::Forms::Label^ lblNotes;
        System::Windows::Forms::RichTextBox^ txtNotes;

        // Buttons
        System::Windows::Forms::Button^ btnSubmit;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnClear;

        // Student List/Grades
        System::Windows::Forms::DataGridView^ dataGridGrades;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            // Course Selection Group
            this->groupBoxCourseSelect = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxCourseSelect->Location = System::Drawing::Point(12, 12);
            this->groupBoxCourseSelect->Size = System::Drawing::Size(400, 100);
            this->groupBoxCourseSelect->Text = L"Course Selection";

            this->lblCourse = (gcnew System::Windows::Forms::Label());
            this->lblCourse->Location = System::Drawing::Point(20, 30);
            this->lblCourse->Text = L"Course:";
            this->comboCourses = (gcnew System::Windows::Forms::ComboBox());
            this->comboCourses->Location = System::Drawing::Point(100, 27);
            this->comboCourses->Size = System::Drawing::Size(250, 24);
            this->comboCourses->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

            this->lblSemester = (gcnew System::Windows::Forms::Label());
            this->lblSemester->Location = System::Drawing::Point(20, 60);
            this->lblSemester->Text = L"Semester:";
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
            this->comboSemester->Location = System::Drawing::Point(100, 57);
            this->comboSemester->Size = System::Drawing::Size(250, 24);
            this->comboSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboSemester->Items->AddRange(gcnew cli::array<Object^>(2) { "Semester1", "Semester2" });

            // Grade Input Group
            this->groupBoxGradeInput = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxGradeInput->Location = System::Drawing::Point(12, 120);
            this->groupBoxGradeInput->Size = System::Drawing::Size(400, 300);
            this->groupBoxGradeInput->Text = L"Grade Input";

            // Student ID
            this->lblStudentID = (gcnew System::Windows::Forms::Label());
            this->lblStudentID->Location = System::Drawing::Point(20, 30);
            this->lblStudentID->Text = L"Student ID:";
            this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
            this->txtStudentID->Location = System::Drawing::Point(120, 27);
            this->txtStudentID->Size = System::Drawing::Size(200, 24);
            this->txtStudentID->ReadOnly = true;

            // Student Name
            this->lblStudentName = (gcnew System::Windows::Forms::Label());
            this->lblStudentName->Location = System::Drawing::Point(20, 60);
            this->lblStudentName->Text = L"Student Name:";
            this->txtStudentName = (gcnew System::Windows::Forms::TextBox());
            this->txtStudentName->Location = System::Drawing::Point(120, 57);
            this->txtStudentName->Size = System::Drawing::Size(200, 24);
            this->txtStudentName->ReadOnly = true;

            // Grade
            this->lblGrade = (gcnew System::Windows::Forms::Label());
            this->lblGrade->Location = System::Drawing::Point(20, 90);
            this->lblGrade->Text = L"Grade:";
            this->txtGrade = (gcnew System::Windows::Forms::TextBox());
            this->txtGrade->Location = System::Drawing::Point(120, 87);
            this->txtGrade->Size = System::Drawing::Size(100, 24);

            // Notes
            this->lblNotes = (gcnew System::Windows::Forms::Label());
            this->lblNotes->Location = System::Drawing::Point(20, 120);
            this->lblNotes->Text = L"Notes:";
            this->txtNotes = (gcnew System::Windows::Forms::RichTextBox());
            this->txtNotes->Location = System::Drawing::Point(120, 117);
            this->txtNotes->Size = System::Drawing::Size(250, 100);

            // Buttons
            this->btnSubmit = (gcnew System::Windows::Forms::Button());
            this->btnSubmit->Location = System::Drawing::Point(120, 230);
            this->btnSubmit->Size = System::Drawing::Size(80, 30);
            this->btnSubmit->Text = L"Submit";

            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnUpdate->Location = System::Drawing::Point(210, 230);
            this->btnUpdate->Size = System::Drawing::Size(80, 30);
            this->btnUpdate->Text = L"Update";

            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->btnClear->Location = System::Drawing::Point(300, 230);
            this->btnClear->Size = System::Drawing::Size(80, 30);
            this->btnClear->Text = L"Clear";

            // Search
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->txtSearch->Location = System::Drawing::Point(430, 12);
            this->txtSearch->Size = System::Drawing::Size(200, 24);

            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->btnSearch->Location = System::Drawing::Point(640, 10);
            this->btnSearch->Size = System::Drawing::Size(80, 26);
            this->btnSearch->Text = L"Search";

            // DataGridView
            this->dataGridGrades = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridGrades->Location = System::Drawing::Point(430, 45);
            this->dataGridGrades->Size = System::Drawing::Size(580, 375);
            this->dataGridGrades->AllowUserToAddRows = false;
            this->dataGridGrades->AllowUserToDeleteRows = false;
            this->dataGridGrades->MultiSelect = false;
            this->dataGridGrades->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridGrades->ReadOnly = true;

            // Form settings
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1024, 450);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Enter_Grade";
            this->Text = L"Enter Grade";
            this->Load += gcnew System::EventHandler(this, &Enter_Grade::Enter_Grade_Load);

            // Add controls to form
            this->Controls->Add(this->groupBoxCourseSelect);
            this->Controls->Add(this->groupBoxGradeInput);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridGrades);

            // Add controls to course selection group
            this->groupBoxCourseSelect->Controls->Add(this->lblCourse);
            this->groupBoxCourseSelect->Controls->Add(this->comboCourses);
            this->groupBoxCourseSelect->Controls->Add(this->lblSemester);
            this->groupBoxCourseSelect->Controls->Add(this->comboSemester);

            // Add controls to grade input group
            this->groupBoxGradeInput->Controls->Add(this->lblStudentID);
            this->groupBoxGradeInput->Controls->Add(this->txtStudentID);
            this->groupBoxGradeInput->Controls->Add(this->lblStudentName);
            this->groupBoxGradeInput->Controls->Add(this->txtStudentName);
            this->groupBoxGradeInput->Controls->Add(this->lblGrade);
            this->groupBoxGradeInput->Controls->Add(this->txtGrade);
            this->groupBoxGradeInput->Controls->Add(this->lblNotes);
            this->groupBoxGradeInput->Controls->Add(this->txtNotes);
            this->groupBoxGradeInput->Controls->Add(this->btnSubmit);
            this->groupBoxGradeInput->Controls->Add(this->btnUpdate);
            this->groupBoxGradeInput->Controls->Add(this->btnClear);

            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private:
        System::Void Enter_Grade_Load(System::Object^ sender, System::EventArgs^ e) {
            // Load courses into comboCourses
            LoadCourses();
            // Set up DataGridView columns
            SetupDataGridView();
        }

        void LoadCourses() {
            // TODO: Implement loading courses from database
        }

        void SetupDataGridView() {
            dataGridGrades->Columns->Add("StudentID", "Student ID");
            dataGridGrades->Columns->Add("StudentName", "Student Name");
            dataGridGrades->Columns->Add("Grade", "Grade");
            dataGridGrades->Columns->Add("SubmissionDate", "Submission Date");
            dataGridGrades->Columns->Add("Notes", "Notes");
        }
    };
}