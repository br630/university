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
        // Form controls
        System::Windows::Forms::GroupBox^ groupBoxCourseDetails;
        System::Windows::Forms::Label^ lblCourseID;
        System::Windows::Forms::TextBox^ txtCourseID;
        System::Windows::Forms::Label^ lblCourseName;
        System::Windows::Forms::TextBox^ txtCourseName;
        System::Windows::Forms::Label^ lblCredits;
        System::Windows::Forms::NumericUpDown^ numCredits;
        System::Windows::Forms::Label^ lblSemester;
        System::Windows::Forms::ComboBox^ comboSemester;
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnClear;
        System::Windows::Forms::DataGridView^ dataGridCourses;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ lblDepartment;
        System::Windows::Forms::ComboBox^ comboDepartment;
        System::Windows::Forms::CheckBox^ chkAvailability;
        System::Windows::Forms::ListBox^ listPrerequisites;
        System::Windows::Forms::Label^ lblPrerequisites;
        System::Windows::Forms::ComboBox^ comboPrerequisites;
        System::Windows::Forms::Button^ btnAddPrerequisite;
        System::Windows::Forms::Button^ btnRemovePrerequisite;

        // Helper methods
        void SetupDataGridView();
        void LoadCourses();
        void ClearForm();
        bool ValidateInput();
        void LoadDepartments();
        void LoadCoursePrerequisites();
        void LoadCoursePrerequisitesList(int courseId);
        void SavePrerequisites(int courseId);
        System::Void btnAddPrerequisite_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnRemovePrerequisite_Click(System::Object^ sender, System::EventArgs^ e);

        // Event handlers
// Event handlers - only declarations
        System::Void Course_Management_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void dataGridCourses_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e);

        void InitializeComponent(void) {
            this->groupBoxCourseDetails = (gcnew System::Windows::Forms::GroupBox());
            this->lblCourseID = (gcnew System::Windows::Forms::Label());
            this->txtCourseID = (gcnew System::Windows::Forms::TextBox());
            this->lblCourseName = (gcnew System::Windows::Forms::Label());
            this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
            this->lblCredits = (gcnew System::Windows::Forms::Label());
            this->numCredits = (gcnew System::Windows::Forms::NumericUpDown());
            this->lblSemester = (gcnew System::Windows::Forms::Label());
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
            this->lblDepartment = (gcnew System::Windows::Forms::Label());
            this->comboDepartment = (gcnew System::Windows::Forms::ComboBox());
            this->chkAvailability = (gcnew System::Windows::Forms::CheckBox());
            this->lblPrerequisites = (gcnew System::Windows::Forms::Label());
            this->listPrerequisites = (gcnew System::Windows::Forms::ListBox());
            this->comboPrerequisites = (gcnew System::Windows::Forms::ComboBox());
            this->btnAddPrerequisite = (gcnew System::Windows::Forms::Button());
            this->btnRemovePrerequisite = (gcnew System::Windows::Forms::Button());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnClear = (gcnew System::Windows::Forms::Button());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnSearch = (gcnew System::Windows::Forms::Button());
            this->dataGridCourses = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxCourseDetails->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCredits))->BeginInit();
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
            this->groupBoxCourseDetails->Controls->Add(this->lblDepartment);
            this->groupBoxCourseDetails->Controls->Add(this->comboDepartment);
            this->groupBoxCourseDetails->Controls->Add(this->chkAvailability);
            this->groupBoxCourseDetails->Controls->Add(this->lblPrerequisites);
            this->groupBoxCourseDetails->Controls->Add(this->listPrerequisites);
            this->groupBoxCourseDetails->Controls->Add(this->comboPrerequisites);
            this->groupBoxCourseDetails->Controls->Add(this->btnAddPrerequisite);
            this->groupBoxCourseDetails->Controls->Add(this->btnRemovePrerequisite);
            this->groupBoxCourseDetails->Controls->Add(this->btnAdd);
            this->groupBoxCourseDetails->Controls->Add(this->btnUpdate);
            this->groupBoxCourseDetails->Controls->Add(this->btnDelete);
            this->groupBoxCourseDetails->Controls->Add(this->btnClear);
            this->groupBoxCourseDetails->Location = System::Drawing::Point(16, 54);
            this->groupBoxCourseDetails->Name = L"groupBoxCourseDetails";
            this->groupBoxCourseDetails->Size = System::Drawing::Size(533, 550);
            this->groupBoxCourseDetails->TabIndex = 0;
            this->groupBoxCourseDetails->TabStop = false;
            this->groupBoxCourseDetails->Text = L"Course Details";
            this->groupBoxCourseDetails->Enter += gcnew System::EventHandler(this, &Course_Management::groupBoxCourseDetails_Enter);
            // 
            // lblCourseID
            // 
            this->lblCourseID->Location = System::Drawing::Point(49, 168);
            this->lblCourseID->Name = L"lblCourseID";
            this->lblCourseID->Size = System::Drawing::Size(118, 22);
            this->lblCourseID->TabIndex = 0;
            this->lblCourseID->Text = L"Course ID:";
            // 
            // txtCourseID
            // 
            this->txtCourseID->Location = System::Drawing::Point(167, 166);
            this->txtCourseID->Name = L"txtCourseID";
            this->txtCourseID->ReadOnly = true;
            this->txtCourseID->Size = System::Drawing::Size(236, 22);
            this->txtCourseID->TabIndex = 1;
            // 
            // lblCourseName
            // 
            this->lblCourseName->Location = System::Drawing::Point(49, 198);
            this->lblCourseName->Name = L"lblCourseName";
            this->lblCourseName->Size = System::Drawing::Size(118, 22);
            this->lblCourseName->TabIndex = 2;
            this->lblCourseName->Text = L"Course Name:";
            // 
            // txtCourseName
            // 
            this->txtCourseName->Location = System::Drawing::Point(167, 194);
            this->txtCourseName->Name = L"txtCourseName";
            this->txtCourseName->Size = System::Drawing::Size(236, 22);
            this->txtCourseName->TabIndex = 3;
            // 
            // lblCredits
            // 
            this->lblCredits->Location = System::Drawing::Point(49, 226);
            this->lblCredits->Name = L"lblCredits";
            this->lblCredits->Size = System::Drawing::Size(118, 22);
            this->lblCredits->TabIndex = 4;
            this->lblCredits->Text = L"Credits:";
            // 
            // numCredits
            // 
            this->numCredits->Location = System::Drawing::Point(167, 224);
            this->numCredits->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
            this->numCredits->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numCredits->Name = L"numCredits";
            this->numCredits->Size = System::Drawing::Size(71, 22);
            this->numCredits->TabIndex = 5;
            this->numCredits->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // lblSemester
            // 
            this->lblSemester->Location = System::Drawing::Point(49, 257);
            this->lblSemester->Name = L"lblSemester";
            this->lblSemester->Size = System::Drawing::Size(118, 22);
            this->lblSemester->TabIndex = 6;
            this->lblSemester->Text = L"Semester:";
            // 
            // comboSemester
            // 
            this->comboSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboSemester->Location = System::Drawing::Point(167, 254);
            this->comboSemester->Name = L"comboSemester";
            this->comboSemester->Size = System::Drawing::Size(236, 24);
            this->comboSemester->TabIndex = 7;
            // 
            // lblDepartment
            // 
            this->lblDepartment->Location = System::Drawing::Point(49, 287);
            this->lblDepartment->Name = L"lblDepartment";
            this->lblDepartment->Size = System::Drawing::Size(118, 22);
            this->lblDepartment->TabIndex = 8;
            this->lblDepartment->Text = L"Department:";
            // 
            // comboDepartment
            // 
            this->comboDepartment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboDepartment->Location = System::Drawing::Point(167, 284);
            this->comboDepartment->Name = L"comboDepartment";
            this->comboDepartment->Size = System::Drawing::Size(236, 24);
            this->comboDepartment->TabIndex = 9;
            // 
            // chkAvailability
            // 
            this->chkAvailability->Checked = true;
            this->chkAvailability->CheckState = System::Windows::Forms::CheckState::Checked;
            this->chkAvailability->Location = System::Drawing::Point(167, 314);
            this->chkAvailability->Name = L"chkAvailability";
            this->chkAvailability->Size = System::Drawing::Size(100, 24);
            this->chkAvailability->TabIndex = 10;
            this->chkAvailability->Text = L"Available";
            // 
            // lblPrerequisites
            // 
            this->lblPrerequisites->Location = System::Drawing::Point(49, 344);
            this->lblPrerequisites->Name = L"lblPrerequisites";
            this->lblPrerequisites->Size = System::Drawing::Size(118, 22);
            this->lblPrerequisites->TabIndex = 11;
            this->lblPrerequisites->Text = L"Prerequisites:";
            // 
            // listPrerequisites
            // 
            this->listPrerequisites->ItemHeight = 16;
            this->listPrerequisites->Location = System::Drawing::Point(167, 344);
            this->listPrerequisites->Name = L"listPrerequisites";
            this->listPrerequisites->Size = System::Drawing::Size(236, 100);
            this->listPrerequisites->TabIndex = 12;
            // 
            // comboPrerequisites
            // 
            this->comboPrerequisites->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboPrerequisites->Location = System::Drawing::Point(167, 454);
            this->comboPrerequisites->Name = L"comboPrerequisites";
            this->comboPrerequisites->Size = System::Drawing::Size(236, 24);
            this->comboPrerequisites->TabIndex = 13;
            // 
            // btnAddPrerequisite
            // 
            this->btnAddPrerequisite->Location = System::Drawing::Point(413, 454);
            this->btnAddPrerequisite->Name = L"btnAddPrerequisite";
            this->btnAddPrerequisite->Size = System::Drawing::Size(80, 24);
            this->btnAddPrerequisite->TabIndex = 14;
            this->btnAddPrerequisite->Text = L"Add";
            this->btnAddPrerequisite->Click += gcnew System::EventHandler(this, &Course_Management::btnAddPrerequisite_Click);
            // 
            // btnRemovePrerequisite
            // 
            this->btnRemovePrerequisite->Location = System::Drawing::Point(413, 344);
            this->btnRemovePrerequisite->Name = L"btnRemovePrerequisite";
            this->btnRemovePrerequisite->Size = System::Drawing::Size(80, 24);
            this->btnRemovePrerequisite->TabIndex = 15;
            this->btnRemovePrerequisite->Text = L"Remove";
            this->btnRemovePrerequisite->Click += gcnew System::EventHandler(this, &Course_Management::btnRemovePrerequisite_Click);
            // 
            // btnAdd
            // 
            this->btnAdd->Location = System::Drawing::Point(23, 490);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(95, 30);
            this->btnAdd->TabIndex = 16;
            this->btnAdd->Text = L"Add";
            this->btnAdd->Click += gcnew System::EventHandler(this, &Course_Management::btnAdd_Click);
            // 
            // btnUpdate
            // 
            this->btnUpdate->Location = System::Drawing::Point(130, 490);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(95, 30);
            this->btnUpdate->TabIndex = 17;
            this->btnUpdate->Text = L"Update";
            this->btnUpdate->Click += gcnew System::EventHandler(this, &Course_Management::btnUpdate_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(236, 490);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(95, 30);
            this->btnDelete->TabIndex = 18;
            this->btnDelete->Text = L"Delete";
            this->btnDelete->Click += gcnew System::EventHandler(this, &Course_Management::btnDelete_Click);
            // 
            // btnClear
            // 
            this->btnClear->Location = System::Drawing::Point(343, 490);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(95, 30);
            this->btnClear->TabIndex = 19;
            this->btnClear->Text = L"Clear";
            this->btnClear->Click += gcnew System::EventHandler(this, &Course_Management::btnClear_Click);
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(1025, 25);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(236, 22);
            this->txtSearch->TabIndex = 1;
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(1274, 24);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(95, 24);
            this->btnSearch->TabIndex = 2;
            this->btnSearch->Text = L"Search";
            this->btnSearch->Click += gcnew System::EventHandler(this, &Course_Management::btnSearch_Click);
            // 
            // dataGridCourses
            // 
            this->dataGridCourses->AllowUserToAddRows = false;
            this->dataGridCourses->AllowUserToDeleteRows = false;
            this->dataGridCourses->ColumnHeadersHeight = 34;
            this->dataGridCourses->Location = System::Drawing::Point(611, 54);
            this->dataGridCourses->MultiSelect = false;
            this->dataGridCourses->Name = L"dataGridCourses";
            this->dataGridCourses->ReadOnly = true;
            this->dataGridCourses->RowHeadersWidth = 62;
            this->dataGridCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridCourses->Size = System::Drawing::Size(758, 550);
            this->dataGridCourses->TabIndex = 3;
            this->dataGridCourses->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Course_Management::dataGridCourses_CellClick);
            // 
            // Course_Management
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1460, 800);
            this->Controls->Add(this->groupBoxCourseDetails);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridCourses);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Course_Management";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Course Management";
            this->Load += gcnew System::EventHandler(this, &Course_Management::Course_Management_Load);
            this->groupBoxCourseDetails->ResumeLayout(false);
            this->groupBoxCourseDetails->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCredits))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridCourses))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }


    private: System::Void groupBoxCourseDetails_Enter(System::Object^ sender, System::EventArgs^ e) {
    }
};
}