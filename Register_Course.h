#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    public ref class Register_Course : public System::Windows::Forms::Form {
    public:
        Register_Course(int studentId) {
            InitializeComponent();
            this->studentId = studentId;
        }

    protected:
        ~Register_Course() {
            if (components) {
                delete components;
            }
        }

    private:
        int studentId;
        System::ComponentModel::Container^ components;

        // Form Controls - declare only once
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::ComboBox^ comboBox1;
        System::Windows::Forms::ComboBox^ comboBox2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;

        // Method declarations
        void LoadAvailableCourses();
        void LoadCurrentEnrollments();
        bool HasCompletedPrerequisites(int courseId);
        bool IsAlreadyEnrolled(int courseId);
        bool ShowPrerequisites(int courseId, String^ courseName);
        void RegisterForCourse(int courseId, String^ courseName);

        // Event handlers
        System::Void Register_Course_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void Course_Button_Click(System::Object^ sender, System::EventArgs^ e);

        void InitializeComponent(void) {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(896, 1);
            this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(266, 22);
            this->textBox1->TabIndex = 1;
            this->textBox1->TextChanged += gcnew System::EventHandler(this, &Register_Course::textBox1_TextChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(788, 3);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(99, 16);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Search Course:";
            // 
            // menuStrip1
            // 
            this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
            this->menuStrip1->Size = System::Drawing::Size(1170, 24);
            this->menuStrip1->TabIndex = 3;
            this->menuStrip1->Text = L"menuStrip1";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(572, 66);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(125, 16);
            this->label2->TabIndex = 28;
            this->label2->Text = L"Course Registration";
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->ImeMode = System::Windows::Forms::ImeMode::Off;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Semester1", L"Semester2" });
            this->comboBox1->Location = System::Drawing::Point(11, 40);
            this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(219, 24);
            this->comboBox1->TabIndex = 29;
            this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Register_Course::comboBox1_SelectedIndexChanged);
            // 
            // comboBox2
            // 
            this->comboBox2->FormattingEnabled = true;
            this->comboBox2->ImeMode = System::Windows::Forms::ImeMode::Off;
            this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Year1", L"Year2", L"Year3", L"Year4" });
            this->comboBox2->Location = System::Drawing::Point(11, 88);
            this->comboBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->comboBox2->Name = L"comboBox2";
            this->comboBox2->Size = System::Drawing::Size(219, 24);
            this->comboBox2->TabIndex = 31;
            this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Register_Course::comboBox1_SelectedIndexChanged);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(7, 13);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(65, 16);
            this->label3->TabIndex = 30;
            this->label3->Text = L"Semester";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(7, 68);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(36, 16);
            this->label4->TabIndex = 32;
            this->label4->Text = L"Year";
            // 
            // Register_Course
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1170, 468);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->comboBox2);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->menuStrip1);
            this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Register_Course";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Course Registration";
            this->Load += gcnew System::EventHandler(this, &Register_Course::Register_Course_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
    };
}