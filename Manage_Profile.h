#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Manage_Profile
	/// </summary>
	public ref class Manage_Profile : public System::Windows::Forms::Form
	{
	public:
		Manage_Profile(void)
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
		~Manage_Profile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ txt_name;
	private: System::Windows::Forms::Label^ txt_age;
	private: System::Windows::Forms::Label^ name;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ txt_year;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txt_name = (gcnew System::Windows::Forms::Label());
			this->txt_age = (gcnew System::Windows::Forms::Label());
			this->name = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_year = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(761, 50);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(308, 237);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(828, 304);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(181, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Edit Picture ";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// txt_name
			// 
			this->txt_name->AutoSize = true;
			this->txt_name->Location = System::Drawing::Point(180, 98);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(133, 20);
			this->txt_name->TabIndex = 2;
			this->txt_name->Text = L"<Student_name>";
			this->txt_name->Click += gcnew System::EventHandler(this, &Manage_Profile::label1_Click);
			// 
			// txt_age
			// 
			this->txt_age->AutoSize = true;
			this->txt_age->Location = System::Drawing::Point(86, 153);
			this->txt_age->Name = L"txt_age";
			this->txt_age->Size = System::Drawing::Size(42, 20);
			this->txt_age->TabIndex = 3;
			this->txt_age->Text = L"Age:";
			// 
			// name
			// 
			this->name->AutoSize = true;
			this->name->Location = System::Drawing::Point(82, 98);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(55, 20);
			this->name->TabIndex = 4;
			this->name->Text = L"Name:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(180, 153);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"<Student_age>";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(82, 219);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Year of Completion:";
			// 
			// txt_year
			// 
			this->txt_year->AutoSize = true;
			this->txt_year->Location = System::Drawing::Point(248, 219);
			this->txt_year->Name = L"txt_year";
			this->txt_year->Size = System::Drawing::Size(123, 20);
			this->txt_year->TabIndex = 7;
			this->txt_year->Text = L"<Student_year>";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(86, 293);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Bio";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(114, 316);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(569, 181);
			this->richTextBox1->TabIndex = 9;
			this->richTextBox1->Text = L"";
			// 
			// Manage_Profile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1180, 569);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txt_year);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->name);
			this->Controls->Add(this->txt_age);
			this->Controls->Add(this->txt_name);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Manage_Profile";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Manage_Profile";
			this->Load += gcnew System::EventHandler(this, &Manage_Profile::Manage_Profile_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Manage_Profile_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
