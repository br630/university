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

        // Helper methods
        void SetupDataGridView();
        void LoadCourses();
        void ClearForm();
        bool ValidateInput();

        // Event handlers
// Event handlers - only declarations
        System::Void Course_Management_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void dataGridCourses_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e);

        void InitializeComponent(void)
        {
            this->groupBoxCourseDetails = (gcnew System::Windows::Forms::GroupBox());
            this->lblCourseID = (gcnew System::Windows::Forms::Label());
            this->txtCourseID = (gcnew System::Windows::Forms::TextBox());
            this->lblCourseName = (gcnew System::Windows::Forms::Label());
            this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
            this->lblCredits = (gcnew System::Windows::Forms::Label());
            this->numCredits = (gcnew System::Windows::Forms::NumericUpDown());
            this->lblSemester = (gcnew System::Windows::Forms::Label());
            this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
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
            this->groupBoxCourseDetails->Controls->Add(this->btnAdd);
            this->groupBoxCourseDetails->Controls->Add(this->btnUpdate);
            this->groupBoxCourseDetails->Controls->Add(this->btnDelete);
            this->groupBoxCourseDetails->Controls->Add(this->btnClear);
            this->groupBoxCourseDetails->Location = System::Drawing::Point(16, 54);
            this->groupBoxCourseDetails->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->groupBoxCourseDetails->Name = L"groupBoxCourseDetails";
            this->groupBoxCourseDetails->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->groupBoxCourseDetails->Size = System::Drawing::Size(533, 417);
            this->groupBoxCourseDetails->TabIndex = 0;
            this->groupBoxCourseDetails->TabStop = false;
            this->groupBoxCourseDetails->Text = L"Course Details";
            // 
            // lblCourseID
            // 
            this->lblCourseID->Location = System::Drawing::Point(49, 168);
            this->lblCourseID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblCourseID->Name = L"lblCourseID";
            this->lblCourseID->Size = System::Drawing::Size(118, 22);
            this->lblCourseID->TabIndex = 0;
            this->lblCourseID->Text = L"Course ID:";
            // 
            // txtCourseID
            // 
            this->txtCourseID->Location = System::Drawing::Point(167, 166);
            this->txtCourseID->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->txtCourseID->Name = L"txtCourseID";
            this->txtCourseID->ReadOnly = true;
            this->txtCourseID->Size = System::Drawing::Size(236, 22);
            this->txtCourseID->TabIndex = 1;
            // 
            // lblCourseName
            // 
            this->lblCourseName->Location = System::Drawing::Point(49, 198);
            this->lblCourseName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblCourseName->Name = L"lblCourseName";
            this->lblCourseName->Size = System::Drawing::Size(118, 22);
            this->lblCourseName->TabIndex = 2;
            this->lblCourseName->Text = L"Course Name:";
            // 
            // txtCourseName
            // 
            this->txtCourseName->Location = System::Drawing::Point(167, 194);
            this->txtCourseName->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->txtCourseName->Name = L"txtCourseName";
            this->txtCourseName->Size = System::Drawing::Size(236, 22);
            this->txtCourseName->TabIndex = 3;
            // 
            // lblCredits
            // 
            this->lblCredits->Location = System::Drawing::Point(49, 226);
            this->lblCredits->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblCredits->Name = L"lblCredits";
            this->lblCredits->Size = System::Drawing::Size(118, 22);
            this->lblCredits->TabIndex = 4;
            this->lblCredits->Text = L"Credits:";
            // 
            // numCredits
            // 
            this->numCredits->Location = System::Drawing::Point(167, 224);
            this->numCredits->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
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
            this->lblSemester->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblSemester->Name = L"lblSemester";
            this->lblSemester->Size = System::Drawing::Size(118, 22);
            this->lblSemester->TabIndex = 6;
            this->lblSemester->Text = L"Semester:";
            // 
            // comboSemester
            // 
            this->comboSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboSemester->Location = System::Drawing::Point(167, 254);
            this->comboSemester->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->comboSemester->Name = L"comboSemester";
            this->comboSemester->Size = System::Drawing::Size(236, 24);
            this->comboSemester->TabIndex = 7;
            // 
            // btnAdd
            // 
            this->btnAdd->Location = System::Drawing::Point(23, 305);
            this->btnAdd->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(95, 30);
            this->btnAdd->TabIndex = 10;
            this->btnAdd->Text = L"Add";
            // 
            // btnUpdate
            // 
            this->btnUpdate->Location = System::Drawing::Point(130, 305);
            this->btnUpdate->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(95, 30);
            this->btnUpdate->TabIndex = 11;
            this->btnUpdate->Text = L"Update";
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(236, 305);
            this->btnDelete->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(95, 30);
            this->btnDelete->TabIndex = 12;
            this->btnDelete->Text = L"Delete";
            // 
            // btnClear
            // 
            this->btnClear->Location = System::Drawing::Point(343, 305);
            this->btnClear->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->btnClear->Name = L"btnClear";
            this->btnClear->Size = System::Drawing::Size(95, 30);
            this->btnClear->TabIndex = 13;
            this->btnClear->Text = L"Clear";
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(1025, 25);
            this->txtSearch->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(236, 22);
            this->txtSearch->TabIndex = 1;
            // 
            // btnSearch
            // 
            this->btnSearch->Location = System::Drawing::Point(1274, 24);
            this->btnSearch->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->btnSearch->Name = L"btnSearch";
            this->btnSearch->Size = System::Drawing::Size(95, 24);
            this->btnSearch->TabIndex = 2;
            this->btnSearch->Text = L"Search";
            // 
            // dataGridCourses
            // 
            this->dataGridCourses->AllowUserToAddRows = false;
            this->dataGridCourses->AllowUserToDeleteRows = false;
            this->dataGridCourses->ColumnHeadersHeight = 34;
            this->dataGridCourses->Location = System::Drawing::Point(611, 54);
            this->dataGridCourses->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->dataGridCourses->MultiSelect = false;
            this->dataGridCourses->Name = L"dataGridCourses";
            this->dataGridCourses->ReadOnly = true;
            this->dataGridCourses->RowHeadersWidth = 62;
            this->dataGridCourses->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridCourses->Size = System::Drawing::Size(758, 394);
            this->dataGridCourses->TabIndex = 3;
            // 
            // Course_Management
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1460, 716);
            this->Controls->Add(this->groupBoxCourseDetails);
            this->Controls->Add(this->txtSearch);
            this->Controls->Add(this->btnSearch);
            this->Controls->Add(this->dataGridCourses);
            this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Course_Management";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Course Management";
            this->Load += gcnew System::EventHandler(this, &Course_Management::Course_Management_Load);


            this->btnAdd->Click += gcnew System::EventHandler(this, &Course_Management::btnAdd_Click);
            this->btnUpdate->Click += gcnew System::EventHandler(this, &Course_Management::btnUpdate_Click);
            this->btnDelete->Click += gcnew System::EventHandler(this, &Course_Management::btnDelete_Click);
            this->btnSearch->Click += gcnew System::EventHandler(this, &Course_Management::btnSearch_Click);
            this->btnClear->Click += gcnew System::EventHandler(this, &Course_Management::btnClear_Click);
            this->dataGridCourses->CellClick += gcnew DataGridViewCellEventHandler(this, &Course_Management::dataGridCourses_CellClick);

            this->groupBoxCourseDetails->ResumeLayout(false);
            this->groupBoxCourseDetails->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCredits))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridCourses))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }


    };
}