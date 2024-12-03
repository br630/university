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

    public ref class Manage_Faculty_Profile : public System::Windows::Forms::Form {
    private:
        int currentUserID;
        String^ currentImagePath;
        DatabaseManager^ dbManager;

        // UI Components
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::Label^ txt_name;
        System::Windows::Forms::Label^ txt_department;
        System::Windows::Forms::Label^ name;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ txt_year;
        System::Windows::Forms::Label^ label3;
        System::ComponentModel::Container^ components;

    public:
        Manage_Faculty_Profile(int userID) {
            InitializeComponent();
            currentUserID = userID;
            dbManager = DatabaseManager::GetInstance();
            LoadUserData();
        }

    protected:
        ~Manage_Faculty_Profile() {
            if (components) {
                delete components;
            }
            dbManager->CloseConnection();
        }

    private:
        void LoadUserData();
        void UpdateProfilePicture();
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void Manage_Profile_Load(System::Object^ sender, System::EventArgs^ e);

        void InitializeComponent(void) {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Manage_Faculty_Profile::typeid));
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->txt_name = (gcnew System::Windows::Forms::Label());
            this->txt_department = (gcnew System::Windows::Forms::Label());
            this->name = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->txt_year = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();

            // pictureBox1
            this->pictureBox1->Location = System::Drawing::Point(761, 50);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(348, 237);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;

            // button1
            this->button1->Location = System::Drawing::Point(761, 304);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(348, 48);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Edit Picture";
            this->button1->Click += gcnew System::EventHandler(this, &Manage_Faculty_Profile::button1_Click);

            // txt_name
            this->txt_name->AutoSize = true;
            this->txt_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->txt_name->Location = System::Drawing::Point(413, 65);
            this->txt_name->Name = L"txt_name";
            this->txt_name->Size = System::Drawing::Size(196, 29);
            this->txt_name->TabIndex = 16;
            this->txt_name->Text = L"<Faculty_name>";

            // name
            this->name->AutoSize = true;
            this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->name->Location = System::Drawing::Point(82, 62);
            this->name->Name = L"name";
            this->name->Size = System::Drawing::Size(102, 32);
            this->name->TabIndex = 14;
            this->name->Text = L"Name:";

            // label1 (Department)
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(82, 130);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(77, 32);
            this->label1->TabIndex = 15;
            this->label1->Text = L"Department:";

            // txt_department
            this->txt_department->AutoSize = true;
            this->txt_department->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->txt_department->Location = System::Drawing::Point(413, 130);
            this->txt_department->Name = L"txt_department";
            this->txt_department->Size = System::Drawing::Size(177, 29);
            this->txt_department->TabIndex = 13;
            this->txt_department->Text = L"<Department>";

            // label2
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(82, 202);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(284, 32);
            this->label2->TabIndex = 12;
            this->label2->Text = L"Appointment Year:";

            // txt_year
            this->txt_year->AutoSize = true;
            this->txt_year->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->txt_year->Location = System::Drawing::Point(413, 205);
            this->txt_year->Name = L"txt_year";
            this->txt_year->Size = System::Drawing::Size(182, 29);
            this->txt_year->TabIndex = 11;
            this->txt_year->Text = L"<Appointment_year>";

            // Form settings
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1180, 500);
            this->Controls->Add(this->txt_year);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->txt_department);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->name);
            this->Controls->Add(this->txt_name);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->pictureBox1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Manage_Faculty_Profile";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Manage Faculty Profile";
            this->Load += gcnew System::EventHandler(this, &Manage_Faculty_Profile::Manage_Profile_Load);

            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
    };
}