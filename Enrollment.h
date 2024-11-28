#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Enrollment
	/// </summary>
	public ref class Enrollment : public System::Windows::Forms::Form
	{
	public:
		Enrollment(void)
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
		~Enrollment()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ std_status;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ txt_admission;

	private: System::Windows::Forms::Label^ txt_Department;
	private: System::Windows::Forms::DataGridView^ dataGridView1;






	private: System::Windows::Forms::Label^ txt_program;
	private: System::Windows::Forms::Label^ txt_Admission_Year;
	private: System::Windows::Forms::Label^ View_transcript;
	private: System::Windows::Forms::Button^ btn_view;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Academic_Year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Semester_head;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Course_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ status_head;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Enrollment_type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ action_on;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ Student_Department;
	private: System::Windows::Forms::Label^ Student_Program;
	private: System::Windows::Forms::Label^ Admission_Year;

	protected:

	protected:






	protected:











	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->std_status = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_admission = (gcnew System::Windows::Forms::Label());
			this->txt_Department = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Academic_Year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Semester_head = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Course_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->status_head = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Enrollment_type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->action_on = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txt_program = (gcnew System::Windows::Forms::Label());
			this->txt_Admission_Year = (gcnew System::Windows::Forms::Label());
			this->View_transcript = (gcnew System::Windows::Forms::Label());
			this->btn_view = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Student_Department = (gcnew System::Windows::Forms::Label());
			this->Student_Program = (gcnew System::Windows::Forms::Label());
			this->Admission_Year = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Academic_Year,
					this->Semester_head, this->Course_name, this->status_head, this->Enrollment_type, this->action_on
			});
			this->dataGridView1->Location = System::Drawing::Point(79, 367);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(961, 231);
			this->dataGridView1->TabIndex = 6;
			// 
			// Academic_Year
			// 
			this->Academic_Year->HeaderText = L"Academic Year";
			this->Academic_Year->MinimumWidth = 8;
			this->Academic_Year->Name = L"Academic_Year";
			this->Academic_Year->Width = 150;
			// 
			// Semester_head
			// 
			this->Semester_head->HeaderText = L"Semester";
			this->Semester_head->MinimumWidth = 8;
			this->Semester_head->Name = L"Semester_head";
			this->Semester_head->Width = 150;
			// 
			// Course_name
			// 
			this->Course_name->HeaderText = L"Course Name";
			this->Course_name->MinimumWidth = 8;
			this->Course_name->Name = L"Course_name";
			this->Course_name->Width = 150;
			// 
			// status_head
			// 
			this->status_head->HeaderText = L"Status";
			this->status_head->MinimumWidth = 8;
			this->status_head->Name = L"status_head";
			this->status_head->Width = 150;
			// 
			// Enrollment_type
			// 
			this->Enrollment_type->HeaderText = L"Enrollment Type";
			this->Enrollment_type->MinimumWidth = 8;
			this->Enrollment_type->Name = L"Enrollment_type";
			this->Enrollment_type->Width = 150;
			// 
			// action_on
			// 
			this->action_on->HeaderText = L"Action On ";
			this->action_on->MinimumWidth = 8;
			this->action_on->Name = L"action_on";
			this->action_on->Width = 150;
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(216, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 20);
			this->label2->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(232, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(140, 20);
			this->label3->TabIndex = 12;
			this->label3->Text = L"<Student_Status>";
			this->label3->Click += gcnew System::EventHandler(this, &Enrollment::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(232, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(209, 20);
			this->label4->TabIndex = 13;
			this->label4->Text = L"<Student_Admission_Year>";
			// 
			// Student_Department
			// 
			this->Student_Department->AutoSize = true;
			this->Student_Department->Location = System::Drawing::Point(232, 194);
			this->Student_Department->Name = L"Student_Department";
			this->Student_Department->Size = System::Drawing::Size(178, 20);
			this->Student_Department->TabIndex = 14;
			this->Student_Department->Text = L"<Student_Department>";
			// 
			// Student_Program
			// 
			this->Student_Program->AutoSize = true;
			this->Student_Program->Location = System::Drawing::Point(236, 233);
			this->Student_Program->Name = L"Student_Program";
			this->Student_Program->Size = System::Drawing::Size(153, 20);
			this->Student_Program->TabIndex = 15;
			this->Student_Program->Text = L"<Student_Program>";
			// 
			// Admission_Year
			// 
			this->Admission_Year->AutoSize = true;
			this->Admission_Year->Location = System::Drawing::Point(240, 276);
			this->Admission_Year->Name = L"Admission_Year";
			this->Admission_Year->Size = System::Drawing::Size(209, 20);
			this->Admission_Year->TabIndex = 16;
			this->Admission_Year->Text = L"<Student_Admission_Year>";
			// 
			// Enrollment
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1111, 634);
			this->Controls->Add(this->Admission_Year);
			this->Controls->Add(this->Student_Program);
			this->Controls->Add(this->Student_Department);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_view);
			this->Controls->Add(this->View_transcript);
			this->Controls->Add(this->txt_Admission_Year);
			this->Controls->Add(this->txt_program);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->txt_Department);
			this->Controls->Add(this->txt_admission);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->std_status);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Enrollment";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Enrollment";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
