#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Access_Rosters
	/// </summary>
	public ref class Access_Rosters : public System::Windows::Forms::Form
	{
	public:
		Access_Rosters(void)
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
		~Access_Rosters()
		{
			if (components)
			{
				delete components;
			}
		}
    private:
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::ToolStripMenuItem^ homeToolStripMenuItem;

        // Course Selection Controls
        System::Windows::Forms::GroupBox^ groupBoxCourseSelect;
        System::Windows::Forms::Label^ lblCourse;
        System::Windows::Forms::ComboBox^ comboCourses;
        System::Windows::Forms::Label^ lblSemester;
        System::Windows::Forms::ComboBox^ comboSemester;

        // Student Details
        System::Windows::Forms::GroupBox^ groupBoxStudentDetails;
        System::Windows::Forms::Label^ lblStudentID;
        System::Windows::Forms::TextBox^ txtStudentID;
        System::Windows::Forms::Label^ lblUserID;
        System::Windows::Forms::TextBox^ txtUserID;
        System::Windows::Forms::Label^ lblDateOfBirth;
        System::Windows::Forms::DateTimePicker^ datePickerDOB;
        System::Windows::Forms::Label^ lblMajor;
        System::Windows::Forms::TextBox^ txtMajor;
        System::Windows::Forms::Label^ lblEnrollmentDate;
        System::Windows::Forms::DateTimePicker^ datePickerEnrollment;
        System::Windows::Forms::PictureBox^ pictureStudent;

        // Buttons
        System::Windows::Forms::Button^ btnAddStudent;
        System::Windows::Forms::Button^ btnRemoveStudent;
        System::Windows::Forms::Button^ btnUpdateStudent;
        System::Windows::Forms::Button^ btnClear;

        // Student List
        System::Windows::Forms::DataGridView^ dataGridStudents;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            // MenuStrip setup (existing code)
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->homeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->menuStrip1->SuspendLayout();

            // Course Selection Group
            this->groupBoxCourseSelect = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxCourseSelect->Location = System::Drawing::Point(12, 40);
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

            // Student Details Group
            this->groupBoxStudentDetails = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxStudentDetails->Location = System::Drawing::Point(12, 150);
            this->groupBoxStudentDetails->Size = System::Drawing::Size(400, 400);
            this->groupBoxStudentDetails->Text = L"Student Details";

            // Student ID
            this->lblStudentID = (gcnew System::Windows::Forms::Label());
            this->lblStudentID->Location = System::Drawing::Point(20, 30);
            this->lblStudentID->Text = L"Student ID:";
            this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
            this->txtStudentID->Location = System::Drawing::Point(120, 27);
            this->txtStudentID->Size = System::Drawing::Size(200, 24);
            this->txtStudentID->ReadOnly = true;

            // User ID
            this->lblUserID = (gcnew System::Windows::Forms::Label());
            this->lblUserID->Location = System::Drawing::Point(20, 60);
            this->lblUserID->Text = L"User ID:";
            this->txtUserID = (gcnew System::Windows::Forms::TextBox());
            this->txtUserID->Location = System::Drawing::Point(120, 57);
            this->txtUserID->Size = System::Drawing::Size(200, 24);

            // Date of Birth
            this->lblDateOfBirth = (gcnew System::Windows::Forms::Label());
            this->lblDateOfBirth->Location = System::Drawing::Point(20, 90);
            this->lblDateOfBirth->Text = L"Date of Birth:";
            this->datePickerDOB = (gcnew System::Windows::Forms::DateTimePicker());
            this->datePickerDOB->Location = System::Drawing::Point(120, 87);
            this->datePickerDOB->Size = System::Drawing::Size(200, 24);
            this->datePickerDOB->Format = System::Windows::Forms::DateTimePickerFormat::Short;

            // Major
            this->lblMajor = (gcnew System::Windows::Forms::Label());
            this->lblMajor->Location = System::Drawing::Point(20, 120);
            this->lblMajor->Text = L"Major:";
            this->txtMajor = (gcnew System::Windows::Forms::TextBox());
            this->txtMajor->Location = System::Drawing::Point(120, 117);
            this->txtMajor->Size = System::Drawing::Size(200, 24);

            // Enrollment Date
            this->lblEnrollmentDate = (gcnew System::Windows::Forms::Label());
            this->lblEnrollmentDate->Location = System::Drawing::Point(20, 150);
            this->lblEnrollmentDate->Text = L"Enrollment Date:";
            this->datePickerEnrollment = (gcnew System::Windows::Forms::DateTimePicker());
            this->datePickerEnrollment->Location = System::Drawing::Point(120, 147);
            this->datePickerEnrollment->Size = System::Drawing::Size(200, 24);
            this->datePickerEnrollment->Format = System::Windows::Forms::DateTimePickerFormat::Short;

            // Student Picture
            this->pictureStudent = (gcnew System::Windows::Forms::PictureBox());
            this->pictureStudent->Location = System::Drawing::Point(120, 180);
            this->pictureStudent->Size = System::Drawing::Size(200, 150);
            this->pictureStudent->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureStudent->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

            // Action Buttons
            this->btnAddStudent = (gcnew System::Windows::Forms::Button());
            this->btnAddStudent->Location = System::Drawing::Point(20, 350);
            this->btnAddStudent->Size = System::Drawing::Size(80, 30);
            this->btnAddStudent->Text = L"Add";

            this->btnRemoveStudent = (gcnew System::Windows::Forms::Button());
            this->btnRemoveStudent->Location = System::Drawing::Point(110, 350);
            this->btnRemoveStudent->Size = System::Drawing::Size(80, 30);
            this->btnRemoveStudent->Text = L"Remove";

            this->btnUpdateStudent = (gcnew System::Windows::Forms::Button());
            this->btnUpdateStudent->Location = System::Drawing::Point(200, 350);
            this->btnUpdateStudent->Size = System::Drawing::Size(80, 30);
            this->btnUpdateStudent->Text = L"Update";

            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->btnClear->Location = System::Drawing::Point(290, 350);
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
            this->dataGridStudents = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridStudents->Location = System::Drawing::Point(430, 45);
            this->dataGridStudents->Size = System::Drawing::Size(580, 505);
            this->dataGridStudents->AllowUserToAddRows = false;
            this->dataGridStudents->AllowUserToDeleteRows = false;
            this->dataGridStudents->MultiSelect = false;
            this->dataGridStudents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridStudents->ReadOnly = true;

            // Add controls to form
            this->Controls->Add(this->menuStrip1);
            this->Controls->Add(this->groupBoxCourseSelect);
            this->Controls->Add(this->groupBoxStudentDetails);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridStudents);

            // Add controls to course selection group
            this->groupBoxCourseSelect->Controls->Add(this->lblCourse);
            this->groupBoxCourseSelect->Controls->Add(this->comboCourses);
            this->groupBoxCourseSelect->Controls->Add(this->lblSemester);
            this->groupBoxCourseSelect->Controls->Add(this->comboSemester);

            // Add controls to student details group
            this->groupBoxStudentDetails->Controls->Add(this->lblStudentID);
            this->groupBoxStudentDetails->Controls->Add(this->txtStudentID);
            this->groupBoxStudentDetails->Controls->Add(this->lblUserID);
            this->groupBoxStudentDetails->Controls->Add(this->txtUserID);
            this->groupBoxStudentDetails->Controls->Add(this->lblDateOfBirth);
            this->groupBoxStudentDetails->Controls->Add(this->datePickerDOB);
            this->groupBoxStudentDetails->Controls->Add(this->lblMajor);
            this->groupBoxStudentDetails->Controls->Add(this->txtMajor);
            this->groupBoxStudentDetails->Controls->Add(this->lblEnrollmentDate);
            this->groupBoxStudentDetails->Controls->Add(this->datePickerEnrollment);
            this->groupBoxStudentDetails->Controls->Add(this->pictureStudent);
            this->groupBoxStudentDetails->Controls->Add(this->btnAddStudent);
            this->groupBoxStudentDetails->Controls->Add(this->btnRemoveStudent);
            this->groupBoxStudentDetails->Controls->Add(this->btnUpdateStudent);
            this->groupBoxStudentDetails->Controls->Add(this->btnClear);

            // Form settings
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1035, 577);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Access_Rosters";
            this->Text = L"Access Rosters";
            this->Load += gcnew System::EventHandler(this, &Access_Rosters::Access_Rosters_Load);

            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private:
        System::Void Access_Rosters_Load(System::Object^ sender, System::EventArgs^ e) {
            // Load courses into comboCourses
            LoadCourses();
            // Set up DataGridView columns
            SetupDataGridView();
        }

        void LoadCourses() {
            // TODO: Implement loading courses from database
        }

        void SetupDataGridView() {
            dataGridStudents->Columns->Add("StudentID", "Student ID");
            dataGridStudents->Columns->Add("UserID", "User ID");
            dataGridStudents->Columns->Add("DateOfBirth", "Date of Birth");
            dataGridStudents->Columns->Add("Major", "Major");
            dataGridStudents->Columns->Add("EnrollmentDate", "Enrollment Date");
            dataGridStudents->Columns->Add("HasPicture", "Has Picture");
        }
    };
}