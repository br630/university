#pragma once;

using namespace MySql::Data::MySqlClient;
using namespace System::Data;
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
    private:
        int currentFacultyID;
    public:
        Enter_Grade(int facultyID) {
            InitializeComponent();
            this->currentFacultyID = facultyID;
        }

        void LoadCourses();
        void LoadStudentGrades();
        void SubmitGrade();
        void UpdateGrade();
        void ClearForm();

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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Enter_Grade::typeid));
            this->groupBoxCourseSelect = (gcnew System::Windows::Forms::GroupBox());
            this->lblCourse = (gcnew System::Windows::Forms::Label());
            this->comboCourses = (gcnew System::Windows::Forms::ComboBox());
            this->lblSemester = (gcnew System::Windows::Forms::Label());
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
            this->groupBoxGradeInput = (gcnew System::Windows::Forms::GroupBox());
            this->lblStudentID = (gcnew System::Windows::Forms::Label());
            this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
            this->lblStudentName = (gcnew System::Windows::Forms::Label());
            this->txtStudentName = (gcnew System::Windows::Forms::TextBox());
            this->lblGrade = (gcnew System::Windows::Forms::Label());
            this->txtGrade = (gcnew System::Windows::Forms::TextBox());
            this->lblNotes = (gcnew System::Windows::Forms::Label());
            this->txtNotes = (gcnew System::Windows::Forms::RichTextBox());
            this->btnSubmit = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->dataGridGrades = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxCourseSelect->SuspendLayout();
            this->groupBoxGradeInput->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridGrades))->BeginInit();
            this->SuspendLayout();
            // 
            // groupBoxCourseSelect
            // 
            this->groupBoxCourseSelect->Controls->Add(this->lblCourse);
            this->groupBoxCourseSelect->Controls->Add(this->comboCourses);
            this->groupBoxCourseSelect->Controls->Add(this->lblSemester);
            this->groupBoxCourseSelect->Controls->Add(this->comboSemester);
            this->groupBoxCourseSelect->Location = System::Drawing::Point(18, 18);
            this->groupBoxCourseSelect->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxCourseSelect->Name = L"groupBoxCourseSelect";
            this->groupBoxCourseSelect->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxCourseSelect->Size = System::Drawing::Size(600, 154);
            this->groupBoxCourseSelect->TabIndex = 0;
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
            this->comboCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &Enter_Grade::comboCourses_SelectedIndexChanged);
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
            this->comboSemester->SelectedIndexChanged += gcnew System::EventHandler(this, &Enter_Grade::comboSemester_SelectedIndexChanged);
            // 
            // groupBoxGradeInput
            // 
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
            this->groupBoxGradeInput->Location = System::Drawing::Point(18, 185);
            this->groupBoxGradeInput->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxGradeInput->Name = L"groupBoxGradeInput";
            this->groupBoxGradeInput->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxGradeInput->Size = System::Drawing::Size(600, 462);
            this->groupBoxGradeInput->TabIndex = 1;
            this->groupBoxGradeInput->TabStop = false;
            this->groupBoxGradeInput->Text = L"Grade Input";
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
            // lblStudentName
            // 
            this->lblStudentName->Location = System::Drawing::Point(30, 92);
            this->lblStudentName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblStudentName->Name = L"lblStudentName";
            this->lblStudentName->Size = System::Drawing::Size(150, 35);
            this->lblStudentName->TabIndex = 2;
            this->lblStudentName->Text = L"Student Name:";
            // 
            // txtStudentName
            // 
            this->txtStudentName->Location = System::Drawing::Point(180, 88);
            this->txtStudentName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtStudentName->Name = L"txtStudentName";
            this->txtStudentName->ReadOnly = true;
            this->txtStudentName->Size = System::Drawing::Size(298, 26);
            this->txtStudentName->TabIndex = 3;
            // 
            // lblGrade
            // 
            this->lblGrade->Location = System::Drawing::Point(30, 138);
            this->lblGrade->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblGrade->Name = L"lblGrade";
            this->lblGrade->Size = System::Drawing::Size(150, 35);
            this->lblGrade->TabIndex = 4;
            this->lblGrade->Text = L"Grade:";
            // 
            // txtGrade
            // 
            this->txtGrade->Location = System::Drawing::Point(180, 134);
            this->txtGrade->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtGrade->Name = L"txtGrade";
            this->txtGrade->Size = System::Drawing::Size(148, 26);
            this->txtGrade->TabIndex = 5;
            // 
            // lblNotes
            // 
            this->lblNotes->Location = System::Drawing::Point(30, 185);
            this->lblNotes->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblNotes->Name = L"lblNotes";
            this->lblNotes->Size = System::Drawing::Size(150, 35);
            this->lblNotes->TabIndex = 6;
            this->lblNotes->Text = L"Notes:";
            // 
            // txtNotes
            // 
            this->txtNotes->Location = System::Drawing::Point(180, 180);
            this->txtNotes->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtNotes->Name = L"txtNotes";
            this->txtNotes->Size = System::Drawing::Size(373, 152);
            this->txtNotes->TabIndex = 7;
            this->txtNotes->Text = L"";
            // 
            // btnSubmit
            // 
            this->btnSubmit->Location = System::Drawing::Point(180, 354);
            this->btnSubmit->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnSubmit->Name = L"btnSubmit";
            this->btnSubmit->Size = System::Drawing::Size(120, 46);
            this->btnSubmit->TabIndex = 8;
            this->btnSubmit->Text = L"Submit";
            this->btnSubmit->Click += gcnew System::EventHandler(this, &Enter_Grade::btnSubmit_Click);
            // 
            // btnUpdate
            // 
            this->btnUpdate->Location = System::Drawing::Point(315, 354);
            this->btnUpdate->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(120, 46);
            this->btnUpdate->TabIndex = 9;
            this->btnUpdate->Text = L"Update";
            this->btnUpdate->Click += gcnew System::EventHandler(this, &Enter_Grade::btnUpdate_Click);
            // 
            // btnClear
            // 
            this->btnClear->Location = System::Drawing::Point(450, 354);
            this->btnClear->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(120, 46);
            this->btnClear->TabIndex = 10;
            this->btnClear->Text = L"Clear";
            this->btnClear->Click += gcnew System::EventHandler(this, &Enter_Grade::btnClear_Click);
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(645, 18);
            this->txtSearch->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(298, 26);
            this->txtSearch->TabIndex = 2;
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(960, 15);
            this->btnSearch->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(120, 40);
            this->btnSearch->TabIndex = 3;
            this->btnSearch->Text = L"Search";
            this->btnSearch->Click += gcnew System::EventHandler(this, &Enter_Grade::btnSearch_Click);
            // 
            // dataGridGrades
            // 
            this->dataGridGrades->AllowUserToAddRows = false;
            this->dataGridGrades->AllowUserToDeleteRows = false;
            this->dataGridGrades->ColumnHeadersHeight = 34;
            this->dataGridGrades->Location = System::Drawing::Point(645, 69);
            this->dataGridGrades->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->dataGridGrades->MultiSelect = false;
            this->dataGridGrades->Name = L"dataGridGrades";
            this->dataGridGrades->ReadOnly = true;
            this->dataGridGrades->RowHeadersWidth = 62;
            this->dataGridGrades->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridGrades->Size = System::Drawing::Size(870, 577);
            this->dataGridGrades->TabIndex = 4;
            // 
            // Enter_Grade
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1536, 692);
            this->Controls->Add(this->groupBoxCourseSelect);
            this->Controls->Add(this->groupBoxGradeInput);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridGrades);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Enter_Grade";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Enter Grade";
            this->Load += gcnew System::EventHandler(this, &Enter_Grade::Enter_Grade_Load);
            this->groupBoxCourseSelect->ResumeLayout(false);
            this->groupBoxGradeInput->ResumeLayout(false);
            this->groupBoxGradeInput->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridGrades))->EndInit();
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

        void SetupDataGridView() {
            dataGridGrades->Columns->Add("StudentID", "Student ID");
            dataGridGrades->Columns->Add("StudentName", "Student Name");
            dataGridGrades->Columns->Add("Grade", "Grade");
            dataGridGrades->Columns->Add("SubmissionDate", "Submission Date");
            dataGridGrades->Columns->Add("Notes", "Notes");
        }
    private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void comboCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
    private: System::Void comboSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
    private: System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
};
}