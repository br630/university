#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Create_Courses
	/// </summary>
	public ref class Create_Courses : public System::Windows::Forms::Form
	{
	public:
		Create_Courses(void)
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
		~Create_Courses()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_create;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txt_cname;

	private: System::Windows::Forms::TextBox^ txt_prerequisite;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btn_coursePic;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ txt_course;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Create_Courses::typeid));
			this->btn_create = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_cname = (gcnew System::Windows::Forms::TextBox());
			this->txt_prerequisite = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_coursePic = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_course = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_create
			// 
			this->btn_create->Location = System::Drawing::Point(68, 395);
			this->btn_create->Name = L"btn_create";
			this->btn_create->Size = System::Drawing::Size(282, 51);
			this->btn_create->TabIndex = 0;
			this->btn_create->Text = L"Create Course";
			this->btn_create->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Course Name";
			// 
			// txt_cname
			// 
			this->txt_cname->Location = System::Drawing::Point(52, 78);
			this->txt_cname->Name = L"txt_cname";
			this->txt_cname->Size = System::Drawing::Size(329, 26);
			this->txt_cname->TabIndex = 2;
			// 
			// txt_prerequisite
			// 
			this->txt_prerequisite->Location = System::Drawing::Point(52, 185);
			this->txt_prerequisite->Name = L"txt_prerequisite";
			this->txt_prerequisite->Size = System::Drawing::Size(329, 26);
			this->txt_prerequisite->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(48, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Prerequisites ";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(512, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(259, 246);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// btn_coursePic
			// 
			this->btn_coursePic->Location = System::Drawing::Point(543, 314);
			this->btn_coursePic->Name = L"btn_coursePic";
			this->btn_coursePic->Size = System::Drawing::Size(198, 38);
			this->btn_coursePic->TabIndex = 6;
			this->btn_coursePic->Text = L"Edit Course Picture";
			this->btn_coursePic->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(48, 242);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Course Description  ";
			// 
			// txt_course
			// 
			this->txt_course->Location = System::Drawing::Point(52, 279);
			this->txt_course->Name = L"txt_course";
			this->txt_course->Size = System::Drawing::Size(329, 96);
			this->txt_course->TabIndex = 8;
			this->txt_course->Text = L"";
			// 
			// Create_Courses
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(861, 473);
			this->Controls->Add(this->txt_course);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btn_coursePic);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txt_prerequisite);
			this->Controls->Add(this->txt_cname);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_create);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Create_Courses";
			this->Text = L"Create_Courses";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
