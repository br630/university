#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using System::IO::Path;
    using System::IO::File;

	/// <summary>
	/// Summary for Course_Management
	/// </summary>
	public ref class Course_Management : public System::Windows::Forms::Form
	{
	public:
		Course_Management(void)
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
		~Course_Management()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
        System::Windows::Forms::GroupBox^ groupBoxCourseDetails;
        System::Windows::Forms::Label^ lblCourseID;
        System::Windows::Forms::TextBox^ txtCourseID;
        System::Windows::Forms::Label^ lblCourseName;
        System::Windows::Forms::TextBox^ txtCourseName;
        System::Windows::Forms::Label^ lblCredits;
        System::Windows::Forms::NumericUpDown^ numCredits;
        System::Windows::Forms::Label^ lblSemester;
        System::Windows::Forms::ComboBox^ comboSemester;

        // Picture Upload Controls
        System::Windows::Forms::PictureBox^ pictureCourse;
        System::Windows::Forms::Button^ btnUploadImage;
        System::Windows::Forms::OpenFileDialog^ openFileDialog;
        String^ imagePath;

        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnClear;

        System::Windows::Forms::DataGridView^ dataGridCourses;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;

        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Course_Management::typeid));
            this->groupBoxCourseDetails = (gcnew System::Windows::Forms::GroupBox());
            this->lblCourseID = (gcnew System::Windows::Forms::Label());
            this->txtCourseID = (gcnew System::Windows::Forms::TextBox());
            this->lblCourseName = (gcnew System::Windows::Forms::Label());
            this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
            this->lblCredits = (gcnew System::Windows::Forms::Label());
            this->numCredits = (gcnew System::Windows::Forms::NumericUpDown());
            this->lblSemester = (gcnew System::Windows::Forms::Label());
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
            this->pictureCourse = (gcnew System::Windows::Forms::PictureBox());
            this->btnUploadImage = (gcnew System::Windows::Forms::Button());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->dataGridCourses = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxCourseDetails->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCredits))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCourse))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridCourses))->BeginInit();
            this->SuspendLayout();
            // 
            // groupBoxCourseDetails
            // 
            this->groupBoxCourseDetails->Controls->Add(this->lblCourseID);
            this->groupBoxCourseDetails->Controls->Add(this->txtCourseID);
            this->groupBoxCourseDetails->Controls->Add(this->lblCourseName);
            this->groupBoxCourseDetails->Controls->Add(this->txtCourseName);
            this->groupBoxCourseDetails->Controls->Add(this->lblCredits);
            this->groupBoxCourseDetails->Controls->Add(this->numCredits);
            this->groupBoxCourseDetails->Controls->Add(this->lblSemester);
            this->groupBoxCourseDetails->Controls->Add(this->comboSemester);
            this->groupBoxCourseDetails->Controls->Add(this->pictureCourse);
            this->groupBoxCourseDetails->Controls->Add(this->btnUploadImage);
            this->groupBoxCourseDetails->Controls->Add(this->btnAdd);
            this->groupBoxCourseDetails->Controls->Add(this->btnUpdate);
            this->groupBoxCourseDetails->Controls->Add(this->btnDelete);
            this->groupBoxCourseDetails->Controls->Add(this->btnClear);
            this->groupBoxCourseDetails->Location = System::Drawing::Point(18, 18);
            this->groupBoxCourseDetails->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxCourseDetails->Name = L"groupBoxCourseDetails";
            this->groupBoxCourseDetails->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->groupBoxCourseDetails->Size = System::Drawing::Size(600, 692);
            this->groupBoxCourseDetails->TabIndex = 0;
            this->groupBoxCourseDetails->TabStop = false;
            this->groupBoxCourseDetails->Text = L"Course Details";
            // 
            // lblCourseID
            // 
            this->lblCourseID->Location = System::Drawing::Point(30, 46);
            this->lblCourseID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblCourseID->Name = L"lblCourseID";
            this->lblCourseID->Size = System::Drawing::Size(150, 35);
            this->lblCourseID->TabIndex = 0;
            this->lblCourseID->Text = L"Course ID:";
            // 
            // txtCourseID
            // 
            this->txtCourseID->Location = System::Drawing::Point(180, 42);
            this->txtCourseID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtCourseID->Name = L"txtCourseID";
            this->txtCourseID->ReadOnly = true;
            this->txtCourseID->Size = System::Drawing::Size(298, 26);
            this->txtCourseID->TabIndex = 1;
            // 
            // lblCourseName
            // 
            this->lblCourseName->Location = System::Drawing::Point(30, 92);
            this->lblCourseName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblCourseName->Name = L"lblCourseName";
            this->lblCourseName->Size = System::Drawing::Size(150, 35);
            this->lblCourseName->TabIndex = 2;
            this->lblCourseName->Text = L"Course Name:";
            // 
            // txtCourseName
            // 
            this->txtCourseName->Location = System::Drawing::Point(180, 88);
            this->txtCourseName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtCourseName->Name = L"txtCourseName";
            this->txtCourseName->Size = System::Drawing::Size(298, 26);
            this->txtCourseName->TabIndex = 3;
            // 
            // lblCredits
            // 
            this->lblCredits->Location = System::Drawing::Point(30, 138);
            this->lblCredits->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblCredits->Name = L"lblCredits";
            this->lblCredits->Size = System::Drawing::Size(150, 35);
            this->lblCredits->TabIndex = 4;
            this->lblCredits->Text = L"Credits:";
            // 
            // numCredits
            // 
            this->numCredits->Location = System::Drawing::Point(180, 134);
            this->numCredits->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->numCredits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
            this->numCredits->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numCredits->Name = L"numCredits";
            this->numCredits->Size = System::Drawing::Size(90, 26);
            this->numCredits->TabIndex = 5;
            this->numCredits->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // lblSemester
            // 
            this->lblSemester->Location = System::Drawing::Point(30, 185);
            this->lblSemester->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblSemester->Name = L"lblSemester";
            this->lblSemester->Size = System::Drawing::Size(150, 35);
            this->lblSemester->TabIndex = 6;
            this->lblSemester->Text = L"Semester:";
            // 
            // comboSemester
            // 
            this->comboSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboSemester->Location = System::Drawing::Point(180, 180);
            this->comboSemester->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->comboSemester->Name = L"comboSemester";
            this->comboSemester->Size = System::Drawing::Size(298, 28);
            this->comboSemester->TabIndex = 7;
            // 
            // pictureCourse
            // 
            this->pictureCourse->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->pictureCourse->Location = System::Drawing::Point(180, 231);
            this->pictureCourse->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->pictureCourse->Name = L"pictureCourse";
            this->pictureCourse->Size = System::Drawing::Size(299, 230);
            this->pictureCourse->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureCourse->TabIndex = 8;
            this->pictureCourse->TabStop = false;
            // 
            // btnUploadImage
            // 
            this->btnUploadImage->Location = System::Drawing::Point(180, 477);
            this->btnUploadImage->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnUploadImage->Name = L"btnUploadImage";
            this->btnUploadImage->Size = System::Drawing::Size(300, 46);
            this->btnUploadImage->TabIndex = 9;
            this->btnUploadImage->Text = L"Upload Course Image";
            this->btnUploadImage->Click += gcnew System::EventHandler(this, &Course_Management::btnUploadImage_Click);
            // 
            // btnAdd
            // 
            this->btnAdd->Location = System::Drawing::Point(30, 554);
            this->btnAdd->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(120, 46);
            this->btnAdd->TabIndex = 10;
            this->btnAdd->Text = L"Add";
            // 
            // btnUpdate
            // 
            this->btnUpdate->Location = System::Drawing::Point(165, 554);
            this->btnUpdate->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(120, 46);
            this->btnUpdate->TabIndex = 11;
            this->btnUpdate->Text = L"Update";
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(300, 554);
            this->btnDelete->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(120, 46);
            this->btnDelete->TabIndex = 12;
            this->btnDelete->Text = L"Delete";
            // 
            // btnClear
            // 
            this->btnClear->Location = System::Drawing::Point(435, 554);
            this->btnClear->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(120, 46);
            this->btnClear->TabIndex = 13;
            this->btnClear->Text = L"Clear";
            // 
            // openFileDialog
            // 
            this->openFileDialog->Filter = L"Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG";
            this->openFileDialog->Title = L"Select Course Image";
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(645, 18);
            this->txtSearch->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(298, 26);
            this->txtSearch->TabIndex = 1;
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(960, 15);
            this->btnSearch->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(120, 38);
            this->btnSearch->TabIndex = 2;
            this->btnSearch->Text = L"Search";
            // 
            // dataGridCourses
            // 
            this->dataGridCourses->AllowUserToAddRows = false;
            this->dataGridCourses->AllowUserToDeleteRows = false;
            this->dataGridCourses->ColumnHeadersHeight = 34;
            this->dataGridCourses->Location = System::Drawing::Point(645, 69);
            this->dataGridCourses->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->dataGridCourses->MultiSelect = false;
            this->dataGridCourses->Name = L"dataGridCourses";
            this->dataGridCourses->ReadOnly = true;
            this->dataGridCourses->RowHeadersWidth = 62;
            this->dataGridCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridCourses->Size = System::Drawing::Size(960, 615);
            this->dataGridCourses->TabIndex = 3;
            // 
            // Course_Management
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1642, 728);
            this->Controls->Add(this->groupBoxCourseDetails);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridCourses);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Course_Management";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Course Management";
            this->Load += gcnew System::EventHandler(this, &Course_Management::Course_Management_Load);
            this->groupBoxCourseDetails->ResumeLayout(false);
            this->groupBoxCourseDetails->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCredits))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCourse))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridCourses))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:
        System::Void Course_Management_Load(System::Object^ sender, System::EventArgs^ e) {
            // TODO: Load existing courses into dataGridCourses
            LoadCourses();
        }

        System::Void btnUploadImage_Click(System::Object^ sender, System::EventArgs^ e) {
            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                imagePath = openFileDialog->FileName;
                pictureCourse->ImageLocation = imagePath;
            }
        }

        void LoadCourses() {
            // TODO: Implement database connection and loading logic
            // Example structure for DataGridView columns:
            dataGridCourses->Columns->Add("CourseID", "Course ID");
            dataGridCourses->Columns->Add("CourseName", "Course Name");
            dataGridCourses->Columns->Add("Credits", "Credits");
            dataGridCourses->Columns->Add("Semester", "Semester");
            dataGridCourses->Columns->Add("HasImage", "Has Image");
        }
    };
}