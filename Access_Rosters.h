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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Access_Rosters::typeid));
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->homeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->groupBoxCourseSelect = (gcnew System::Windows::Forms::GroupBox());
            this->lblCourse = (gcnew System::Windows::Forms::Label());
            this->comboCourses = (gcnew System::Windows::Forms::ComboBox());
            this->lblSemester = (gcnew System::Windows::Forms::Label());
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
            this->groupBoxStudentDetails = (gcnew System::Windows::Forms::GroupBox());
            this->lblStudentID = (gcnew System::Windows::Forms::Label());
            this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
            this->lblUserID = (gcnew System::Windows::Forms::Label());
            this->txtUserID = (gcnew System::Windows::Forms::TextBox());
            this->lblDateOfBirth = (gcnew System::Windows::Forms::Label());
            this->datePickerDOB = (gcnew System::Windows::Forms::DateTimePicker());
            this->lblMajor = (gcnew System::Windows::Forms::Label());
            this->txtMajor = (gcnew System::Windows::Forms::TextBox());
            this->lblEnrollmentDate = (gcnew System::Windows::Forms::Label());
            this->datePickerEnrollment = (gcnew System::Windows::Forms::DateTimePicker());
            this->pictureStudent = (gcnew System::Windows::Forms::PictureBox());
            this->btnAddStudent = (gcnew System::Windows::Forms::Button());
            this->btnRemoveStudent = (gcnew System::Windows::Forms::Button());
            this->btnUpdateStudent = (gcnew System::Windows::Forms::Button());
            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->dataGridStudents = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxCourseSelect->SuspendLayout();
            this->groupBoxStudentDetails->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureStudent))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridStudents))->BeginInit();
            this->SuspendLayout();
            // 
            // menuStrip1
            // 
            this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
            this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(1552, 24);
            this->menuStrip1->TabIndex = 0;
            // 
            // homeToolStripMenuItem
            // 
            this->homeToolStripMenuItem->Name = L"homeToolStripMenuItem";
            this->homeToolStripMenuItem->Size = System::Drawing::Size(32, 19);
            // 
            // groupBoxCourseSelect
            // 
            this->groupBoxCourseSelect->Controls->Add(this->lblCourse);
            this->groupBoxCourseSelect->Controls->Add(this->comboCourses);
            this->groupBoxCourseSelect->Controls->Add(this->lblSemester);
            this->groupBoxCourseSelect->Controls->Add(this->comboSemester);
            this->groupBoxCourseSelect->Location = System::Drawing::Point(18, 62);
            this->groupBoxCourseSelect->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxCourseSelect->Name = L"groupBoxCourseSelect";
            this->groupBoxCourseSelect->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxCourseSelect->Size = System::Drawing::Size(600, 154);
            this->groupBoxCourseSelect->TabIndex = 1;
            this->groupBoxCourseSelect->TabStop = false;
            this->groupBoxCourseSelect->Text = L"Course Selection";
            // 
            // lblCourse
            // 
            this->lblCourse->Location = System::Drawing::Point(30, 46);
            this->lblCourse->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblCourse->Name = L"lblCourse";
            this->lblCourse->Size = System::Drawing::Size(150, 35);
            this->lblCourse->TabIndex = 0;
            this->lblCourse->Text = L"Course:";
            // 
            // comboCourses
            // 
            this->comboCourses->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboCourses->Location = System::Drawing::Point(150, 42);
            this->comboCourses->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->comboCourses->Name = L"comboCourses";
            this->comboCourses->Size = System::Drawing::Size(373, 28);
            this->comboCourses->TabIndex = 1;
            // 
            // lblSemester
            // 
            this->lblSemester->Location = System::Drawing::Point(30, 92);
            this->lblSemester->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblSemester->Name = L"lblSemester";
            this->lblSemester->Size = System::Drawing::Size(150, 35);
            this->lblSemester->TabIndex = 2;
            this->lblSemester->Text = L"Semester:";
            // 
            // comboSemester
            // 
            this->comboSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboSemester->Location = System::Drawing::Point(150, 88);
            this->comboSemester->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->comboSemester->Name = L"comboSemester";
            this->comboSemester->Size = System::Drawing::Size(373, 28);
            this->comboSemester->TabIndex = 3;
            // 
            // groupBoxStudentDetails
            // 
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
            this->groupBoxStudentDetails->Location = System::Drawing::Point(18, 231);
            this->groupBoxStudentDetails->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxStudentDetails->Name = L"groupBoxStudentDetails";
            this->groupBoxStudentDetails->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxStudentDetails->Size = System::Drawing::Size(600, 615);
            this->groupBoxStudentDetails->TabIndex = 2;
            this->groupBoxStudentDetails->TabStop = false;
            this->groupBoxStudentDetails->Text = L"Student Details";
            // 
            // lblStudentID
            // 
            this->lblStudentID->Location = System::Drawing::Point(30, 46);
            this->lblStudentID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblStudentID->Name = L"lblStudentID";
            this->lblStudentID->Size = System::Drawing::Size(150, 35);
            this->lblStudentID->TabIndex = 0;
            this->lblStudentID->Text = L"Student ID:";
            // 
            // txtStudentID
            // 
            this->txtStudentID->Location = System::Drawing::Point(180, 42);
            this->txtStudentID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtStudentID->Name = L"txtStudentID";
            this->txtStudentID->ReadOnly = true;
            this->txtStudentID->Size = System::Drawing::Size(298, 26);
            this->txtStudentID->TabIndex = 1;
            // 
            // lblUserID
            // 
            this->lblUserID->Location = System::Drawing::Point(30, 92);
            this->lblUserID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblUserID->Name = L"lblUserID";
            this->lblUserID->Size = System::Drawing::Size(150, 35);
            this->lblUserID->TabIndex = 2;
            this->lblUserID->Text = L"User ID:";
            // 
            // txtUserID
            // 
            this->txtUserID->Location = System::Drawing::Point(180, 88);
            this->txtUserID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtUserID->Name = L"txtUserID";
            this->txtUserID->Size = System::Drawing::Size(298, 26);
            this->txtUserID->TabIndex = 3;
            // 
            // lblDateOfBirth
            // 
            this->lblDateOfBirth->Location = System::Drawing::Point(30, 138);
            this->lblDateOfBirth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblDateOfBirth->Name = L"lblDateOfBirth";
            this->lblDateOfBirth->Size = System::Drawing::Size(150, 35);
            this->lblDateOfBirth->TabIndex = 4;
            this->lblDateOfBirth->Text = L"Date of Birth:";
            // 
            // datePickerDOB
            // 
            this->datePickerDOB->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->datePickerDOB->Location = System::Drawing::Point(180, 134);
            this->datePickerDOB->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->datePickerDOB->Name = L"datePickerDOB";
            this->datePickerDOB->Size = System::Drawing::Size(298, 26);
            this->datePickerDOB->TabIndex = 5;
            // 
            // lblMajor
            // 
            this->lblMajor->Location = System::Drawing::Point(30, 185);
            this->lblMajor->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblMajor->Name = L"lblMajor";
            this->lblMajor->Size = System::Drawing::Size(150, 35);
            this->lblMajor->TabIndex = 6;
            this->lblMajor->Text = L"Major:";
            // 
            // txtMajor
            // 
            this->txtMajor->Location = System::Drawing::Point(180, 180);
            this->txtMajor->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtMajor->Name = L"txtMajor";
            this->txtMajor->Size = System::Drawing::Size(298, 26);
            this->txtMajor->TabIndex = 7;
            // 
            // lblEnrollmentDate
            // 
            this->lblEnrollmentDate->Location = System::Drawing::Point(30, 231);
            this->lblEnrollmentDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblEnrollmentDate->Name = L"lblEnrollmentDate";
            this->lblEnrollmentDate->Size = System::Drawing::Size(150, 35);
            this->lblEnrollmentDate->TabIndex = 8;
            this->lblEnrollmentDate->Text = L"Enrollment Date:";
            // 
            // datePickerEnrollment
            // 
            this->datePickerEnrollment->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->datePickerEnrollment->Location = System::Drawing::Point(180, 226);
            this->datePickerEnrollment->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->datePickerEnrollment->Name = L"datePickerEnrollment";
            this->datePickerEnrollment->Size = System::Drawing::Size(298, 26);
            this->datePickerEnrollment->TabIndex = 9;
            // 
            // pictureStudent
            // 
            this->pictureStudent->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pictureStudent->Location = System::Drawing::Point(180, 277);
            this->pictureStudent->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->pictureStudent->Name = L"pictureStudent";
            this->pictureStudent->Size = System::Drawing::Size(299, 230);
            this->pictureStudent->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureStudent->TabIndex = 10;
            this->pictureStudent->TabStop = false;
            // 
            // btnAddStudent
            // 
            this->btnAddStudent->Location = System::Drawing::Point(30, 538);
            this->btnAddStudent->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnAddStudent->Name = L"btnAddStudent";
            this->btnAddStudent->Size = System::Drawing::Size(120, 46);
            this->btnAddStudent->TabIndex = 11;
            this->btnAddStudent->Text = L"Add";
            // 
            // btnRemoveStudent
            // 
            this->btnRemoveStudent->Location = System::Drawing::Point(165, 538);
            this->btnRemoveStudent->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnRemoveStudent->Name = L"btnRemoveStudent";
            this->btnRemoveStudent->Size = System::Drawing::Size(120, 46);
            this->btnRemoveStudent->TabIndex = 12;
            this->btnRemoveStudent->Text = L"Remove";
            // 
            // btnUpdateStudent
            // 
            this->btnUpdateStudent->Location = System::Drawing::Point(300, 538);
            this->btnUpdateStudent->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnUpdateStudent->Name = L"btnUpdateStudent";
            this->btnUpdateStudent->Size = System::Drawing::Size(120, 46);
            this->btnUpdateStudent->TabIndex = 13;
            this->btnUpdateStudent->Text = L"Update";
            // 
            // btnClear
            // 
            this->btnClear->Location = System::Drawing::Point(435, 538);
            this->btnClear->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(120, 46);
            this->btnClear->TabIndex = 14;
            this->btnClear->Text = L"Clear";
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(645, 18);
            this->txtSearch->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(298, 26);
            this->txtSearch->TabIndex = 3;
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(960, 15);
            this->btnSearch->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(120, 40);
            this->btnSearch->TabIndex = 4;
            this->btnSearch->Text = L"Search";
            // 
            // dataGridStudents
            // 
            this->dataGridStudents->AllowUserToAddRows = false;
            this->dataGridStudents->AllowUserToDeleteRows = false;
            this->dataGridStudents->ColumnHeadersHeight = 34;
            this->dataGridStudents->Location = System::Drawing::Point(645, 69);
            this->dataGridStudents->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->dataGridStudents->MultiSelect = false;
            this->dataGridStudents->Name = L"dataGridStudents";
            this->dataGridStudents->ReadOnly = true;
            this->dataGridStudents->RowHeadersWidth = 62;
            this->dataGridStudents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridStudents->Size = System::Drawing::Size(870, 777);
            this->dataGridStudents->TabIndex = 5;
            // 
            // Access_Rosters
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1552, 888);
            this->Controls->Add(this->menuStrip1);
            this->Controls->Add(this->groupBoxCourseSelect);
            this->Controls->Add(this->groupBoxStudentDetails);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridStudents);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Access_Rosters";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Access Rosters";
            this->Load += gcnew System::EventHandler(this, &Access_Rosters::Access_Rosters_Load);
            this->groupBoxCourseSelect->ResumeLayout(false);
            this->groupBoxStudentDetails->ResumeLayout(false);
            this->groupBoxStudentDetails->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureStudent))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridStudents))->EndInit();
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