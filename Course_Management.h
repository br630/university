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
            // Initialize GroupBox
            this->groupBoxCourseDetails = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxCourseDetails->Location = System::Drawing::Point(12, 12);
            this->groupBoxCourseDetails->Size = System::Drawing::Size(400, 450);
            this->groupBoxCourseDetails->Text = L"Course Details";

            // Course ID
            this->lblCourseID = (gcnew System::Windows::Forms::Label());
            this->lblCourseID->Location = System::Drawing::Point(20, 30);
            this->lblCourseID->Text = L"Course ID:";
            this->txtCourseID = (gcnew System::Windows::Forms::TextBox());
            this->txtCourseID->Location = System::Drawing::Point(120, 27);
            this->txtCourseID->Size = System::Drawing::Size(200, 20);
            this->txtCourseID->ReadOnly = true; // Since it's AUTO_INCREMENT

            // Course Name
            this->lblCourseName = (gcnew System::Windows::Forms::Label());
            this->lblCourseName->Location = System::Drawing::Point(20, 60);
            this->lblCourseName->Text = L"Course Name:";
            this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
            this->txtCourseName->Location = System::Drawing::Point(120, 57);
            this->txtCourseName->Size = System::Drawing::Size(200, 20);

            // Credits
            this->lblCredits = (gcnew System::Windows::Forms::Label());
            this->lblCredits->Location = System::Drawing::Point(20, 90);
            this->lblCredits->Text = L"Credits:";
            this->numCredits = (gcnew System::Windows::Forms::NumericUpDown());
            this->numCredits->Location = System::Drawing::Point(120, 87);
            this->numCredits->Size = System::Drawing::Size(60, 20);
            this->numCredits->Minimum = 1;
            this->numCredits->Maximum = 6;

            // Semester
            this->lblSemester = (gcnew System::Windows::Forms::Label());
            this->lblSemester->Location = System::Drawing::Point(20, 120);
            this->lblSemester->Text = L"Semester:";
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
            this->comboSemester->Location = System::Drawing::Point(120, 117);
            this->comboSemester->Size = System::Drawing::Size(200, 20);
            this->comboSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboSemester->Items->AddRange(gcnew cli::array<Object^>(2) { "Semester1", "Semester2" });

            // Picture Upload
            this->pictureCourse = (gcnew System::Windows::Forms::PictureBox());
            this->pictureCourse->Location = System::Drawing::Point(120, 150);
            this->pictureCourse->Size = System::Drawing::Size(200, 150);
            this->pictureCourse->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureCourse->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

            this->btnUploadImage = (gcnew System::Windows::Forms::Button());
            this->btnUploadImage->Location = System::Drawing::Point(120, 310);
            this->btnUploadImage->Size = System::Drawing::Size(200, 30);
            this->btnUploadImage->Text = L"Upload Course Image";
            this->btnUploadImage->Click += gcnew System::EventHandler(this, &Course_Management::btnUploadImage_Click);

            this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->openFileDialog->Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG";
            this->openFileDialog->Title = "Select Course Image";

            // Buttons
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnAdd->Location = System::Drawing::Point(20, 360);
            this->btnAdd->Size = System::Drawing::Size(80, 30);
            this->btnAdd->Text = L"Add";

            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnUpdate->Location = System::Drawing::Point(110, 360);
            this->btnUpdate->Size = System::Drawing::Size(80, 30);
            this->btnUpdate->Text = L"Update";

            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnDelete->Location = System::Drawing::Point(200, 360);
            this->btnDelete->Size = System::Drawing::Size(80, 30);
            this->btnDelete->Text = L"Delete";

            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->btnClear->Location = System::Drawing::Point(290, 360);
            this->btnClear->Size = System::Drawing::Size(80, 30);
            this->btnClear->Text = L"Clear";

            // Search
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->txtSearch->Location = System::Drawing::Point(430, 12);
            this->txtSearch->Size = System::Drawing::Size(200, 20);
           

            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->btnSearch->Location = System::Drawing::Point(640, 10);
            this->btnSearch->Size = System::Drawing::Size(80, 25);
            this->btnSearch->Text = L"Search";

            // DataGridView
            this->dataGridCourses = (gcnew System::Windows::Forms::DataGridView());
            this->dataGridCourses->Location = System::Drawing::Point(430, 45);
            this->dataGridCourses->Size = System::Drawing::Size(640, 400);
            this->dataGridCourses->AllowUserToAddRows = false;
            this->dataGridCourses->AllowUserToDeleteRows = false;
            this->dataGridCourses->MultiSelect = false;
            this->dataGridCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridCourses->ReadOnly = true;

            // Form settings
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1095, 473);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Course_Management";
            this->Text = L"Course Management";
            this->Load += gcnew System::EventHandler(this, &Course_Management::Course_Management_Load);

            // Add controls to form
            this->Controls->Add(this->groupBoxCourseDetails);
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
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridCourses);

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