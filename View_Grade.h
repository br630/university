#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for View_Grade
	/// </summary>
	public ref class View_Grade : public System::Windows::Forms::Form
	{
	public:
		View_Grade(void)
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
		~View_Grade()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ homeToolStripMenuItem;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ semesters;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ txt_web;
	private: System::Windows::Forms::Label^ txt_hardware;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ page_view;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ txt_algo;
	private: System::Windows::Forms::Label^ std_grade;


	private: System::Windows::Forms::Label^ std_grade1;

	private: System::Windows::Forms::Label^ std_grade2;
	private: System::Windows::Forms::Label^ std_grade3;





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
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->homeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->semesters = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_web = (gcnew System::Windows::Forms::Label());
			this->txt_hardware = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->page_view = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txt_algo = (gcnew System::Windows::Forms::Label());
			this->std_grade = (gcnew System::Windows::Forms::Label());
			this->std_grade1 = (gcnew System::Windows::Forms::Label());
			this->std_grade2 = (gcnew System::Windows::Forms::Label());
			this->std_grade3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(79, 100);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(961, 52);
			this->progressBar1->TabIndex = 0;
			this->progressBar1->Value = 50;
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->homeToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1166, 33);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// homeToolStripMenuItem
			// 
			this->homeToolStripMenuItem->Name = L"homeToolStripMenuItem";
			this->homeToolStripMenuItem->Size = System::Drawing::Size(77, 29);
			this->homeToolStripMenuItem->Text = L"Home";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(433, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(222, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Progress Made This Semester";
			// 
			// semesters
			// 
			this->semesters->FormattingEnabled = true;
			this->semesters->ItemHeight = 20;
			this->semesters->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Semester 1(2024/2025)", L"Semester 2(2024/2025)",
					L"Semester 1(2025/2026)", L"Semester 2(2025/2026)"
			});
			this->semesters->Location = System::Drawing::Point(79, 190);
			this->semesters->Name = L"semesters";
			this->semesters->Size = System::Drawing::Size(234, 24);
			this->semesters->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(75, 253);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(271, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Intermediate Computer Programming";
			// 
			// txt_web
			// 
			this->txt_web->AutoSize = true;
			this->txt_web->Location = System::Drawing::Point(75, 311);
			this->txt_web->Name = L"txt_web";
			this->txt_web->Size = System::Drawing::Size(140, 20);
			this->txt_web->TabIndex = 4;
			this->txt_web->Text = L"Web Technologies";
			// 
			// txt_hardware
			// 
			this->txt_hardware->AutoSize = true;
			this->txt_hardware->Location = System::Drawing::Point(75, 368);
			this->txt_hardware->Name = L"txt_hardware";
			this->txt_hardware->Size = System::Drawing::Size(284, 20);
			this->txt_hardware->TabIndex = 5;
			this->txt_hardware->Text = L"Hardware Systems and Fundamentals ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(75, 423);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 20);
			this->label5->TabIndex = 6;
			// 
			// page_view
			// 
			this->page_view->AutoSize = true;
			this->page_view->Location = System::Drawing::Point(766, 190);
			this->page_view->Name = L"page_view";
			this->page_view->Size = System::Drawing::Size(117, 20);
			this->page_view->TabIndex = 7;
			this->page_view->Text = L"View Transcript";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(889, 183);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 27);
			this->button1->TabIndex = 8;
			this->button1->Text = L"View";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// txt_algo
			// 
			this->txt_algo->AutoSize = true;
			this->txt_algo->Location = System::Drawing::Point(75, 423);
			this->txt_algo->Name = L"txt_algo";
			this->txt_algo->Size = System::Drawing::Size(235, 20);
			this->txt_algo->TabIndex = 9;
			this->txt_algo->Text = L"Algorithms Design and Analysis ";
			// 
			// std_grade
			// 
			this->std_grade->AutoSize = true;
			this->std_grade->Location = System::Drawing::Point(628, 253);
			this->std_grade->Name = L"std_grade";
			this->std_grade->Size = System::Drawing::Size(142, 20);
			this->std_grade->TabIndex = 10;
			this->std_grade->Text = L"<Students_grade>";
			// 
			// std_grade1
			// 
			this->std_grade1->AutoSize = true;
			this->std_grade1->Location = System::Drawing::Point(628, 311);
			this->std_grade1->Name = L"std_grade1";
			this->std_grade1->Size = System::Drawing::Size(142, 20);
			this->std_grade1->TabIndex = 11;
			this->std_grade1->Text = L"<Students_grade>";
			// 
			// std_grade2
			// 
			this->std_grade2->AutoSize = true;
			this->std_grade2->Location = System::Drawing::Point(628, 368);
			this->std_grade2->Name = L"std_grade2";
			this->std_grade2->Size = System::Drawing::Size(142, 20);
			this->std_grade2->TabIndex = 12;
			this->std_grade2->Text = L"<Students_grade>";
			// 
			// std_grade3
			// 
			this->std_grade3->AutoSize = true;
			this->std_grade3->Location = System::Drawing::Point(628, 423);
			this->std_grade3->Name = L"std_grade3";
			this->std_grade3->Size = System::Drawing::Size(142, 20);
			this->std_grade3->TabIndex = 13;
			this->std_grade3->Text = L"<Students_grade>";
			// 
			// View_Grade
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1166, 546);
			this->Controls->Add(this->std_grade3);
			this->Controls->Add(this->std_grade2);
			this->Controls->Add(this->std_grade1);
			this->Controls->Add(this->std_grade);
			this->Controls->Add(this->txt_algo);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->page_view);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txt_hardware);
			this->Controls->Add(this->txt_web);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->semesters);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"View_Grade";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"View_Grade";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
