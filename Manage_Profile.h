// Manage_Profile.h
#pragma once
#include "db_conn.h"

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;
    using namespace MySql::Data::MySqlClient;

    public ref class Manage_Profile : public System::Windows::Forms::Form {
    private:
        int currentUserID;
        String^ currentImagePath;
        DatabaseManager^ dbManager;

        // UI Components
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Label^ txt_name;
        System::Windows::Forms::Label^ txt_age;
        System::Windows::Forms::Label^ name;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ txt_year;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::RichTextBox^ richTextBox1;
        System::ComponentModel::Container^ components;

    public:
        Manage_Profile(int userID) {
            InitializeComponent();
            currentUserID = userID;
            dbManager = DatabaseManager::GetInstance();
            LoadUserData();
        }

    protected:
        ~Manage_Profile() {
            if (components) {
                delete components;
            }
            dbManager->CloseConnection();
        }

    private:
        void LoadUserData();
        void UpdateProfilePicture();
        int CalculateAge(String^ dateOfBirth);
        void SaveBioToDatabase();
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void Manage_Profile_Load(System::Object^ sender, System::EventArgs^ e);

        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Manage_Profile::typeid));
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
            this->pictureBox1->Size = System::Drawing::Size(348, 237);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(761, 304);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(348, 48);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Edit Picture";
            this->button1->Click += gcnew System::EventHandler(this, &Manage_Profile::button1_Click);
            // 
            // txt_name
            // 
            this->txt_name->AutoSize = true;
            this->txt_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txt_name->Location = System::Drawing::Point(413, 65);
            this->txt_name->Name = L"txt_name";
            this->txt_name->Size = System::Drawing::Size(196, 29);
            this->txt_name->TabIndex = 16;
            this->txt_name->Text = L"<Student_name>";
            // 
            // txt_age
            // 
            this->txt_age->AutoSize = true;
            this->txt_age->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txt_age->Location = System::Drawing::Point(82, 130);
            this->txt_age->Name = L"txt_age";
            this->txt_age->Size = System::Drawing::Size(77, 32);
            this->txt_age->TabIndex = 15;
            this->txt_age->Text = L"Age:";
            // 
            // name
            // 
            this->name->AutoSize = true;
            this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->name->Location = System::Drawing::Point(82, 62);
            this->name->Name = L"name";
            this->name->Size = System::Drawing::Size(102, 32);
            this->name->TabIndex = 14;
            this->name->Text = L"Name:";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(413, 130);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(177, 29);
            this->label1->TabIndex = 13;
            this->label1->Text = L"<Student_age>";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(82, 202);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(284, 32);
            this->label2->TabIndex = 12;
            this->label2->Text = L"Year of Completion:";
            // 
            // txt_year
            // 
            this->txt_year->AutoSize = true;
            this->txt_year->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txt_year->Location = System::Drawing::Point(413, 205);
            this->txt_year->Name = L"txt_year";
            this->txt_year->Size = System::Drawing::Size(182, 29);
            this->txt_year->TabIndex = 11;
            this->txt_year->Text = L"<Student_year>";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(82, 269);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(59, 32);
            this->label3->TabIndex = 10;
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
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Manage_Profile";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Manage Profile";
            this->Load += gcnew System::EventHandler(this, &Manage_Profile::Manage_Profile_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
    };
}
