#pragma once
using namespace System::IO;

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class View_All_Students : public System::Windows::Forms::Form {
    public:
        View_All_Students(void)
        {
            InitializeComponent();
            LoadUsersData();
        }

    protected:
        ~View_All_Students()
        {
            if (components)
            {
                delete components;
            }
        }
    private:
        System::Windows::Forms::GroupBox^ groupBoxEdit;
        System::Windows::Forms::TextBox^ txtEditFirstName;
        System::Windows::Forms::TextBox^ txtEditLastName;
        System::Windows::Forms::TextBox^ txtEditEmail;
        System::Windows::Forms::TextBox^ txtEditMajor;
        System::Windows::Forms::Label^ lblEditFirstName;
        System::Windows::Forms::Label^ lblEditLastName;
        System::Windows::Forms::Label^ lblEditEmail;
        System::Windows::Forms::Label^ lblEditMajor;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::DataGridView^ gridUsers;
        System::Windows::Forms::GroupBox^ groupBoxFilters;

        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnExportUsers;

        System::Windows::Forms::Label^ lblTotalUsers;
        System::Windows::Forms::StatusStrip^ statusStrip;
        System::Windows::Forms::ToolStripStatusLabel^ statusLabel;

        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnDelete;

        void ClearEditFields();

        System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Windows::Forms::Label^ Search;

           System::ComponentModel::Container^ components;

        // Add these method declarations here
        void SetupUsersGrid(void);
        void LoadUsersData(void);
        void UpdateStatusBar(void);
        void FilterUsers(void);
        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        void InitializeComponent(void)
        {
            this->gridUsers = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxFilters = (gcnew System::Windows::Forms::GroupBox());
            this->btnUpdate = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->Search = (gcnew System::Windows::Forms::Label());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnExportUsers = (gcnew System::Windows::Forms::Button());
            this->lblTotalUsers = (gcnew System::Windows::Forms::Label());
            this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
            this->statusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
            this->groupBoxEdit = (gcnew System::Windows::Forms::GroupBox());
            this->lblEditFirstName = (gcnew System::Windows::Forms::Label());
            this->txtEditFirstName = (gcnew System::Windows::Forms::TextBox());
            this->lblEditLastName = (gcnew System::Windows::Forms::Label());
            this->txtEditLastName = (gcnew System::Windows::Forms::TextBox());
            this->lblEditEmail = (gcnew System::Windows::Forms::Label());
            this->txtEditEmail = (gcnew System::Windows::Forms::TextBox());
            this->lblEditMajor = (gcnew System::Windows::Forms::Label());
            this->txtEditMajor = (gcnew System::Windows::Forms::TextBox());
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridUsers))->BeginInit();
            this->groupBoxFilters->SuspendLayout();
            this->statusStrip->SuspendLayout();
            this->groupBoxEdit->SuspendLayout();
            this->SuspendLayout();
            // 
            // gridUsers
            // 
            this->gridUsers->AllowUserToAddRows = false;
            this->gridUsers->ColumnHeadersHeight = 34;
            this->gridUsers->Location = System::Drawing::Point(12, 100);
            this->gridUsers->Name = L"gridUsers";
            this->gridUsers->ReadOnly = true;
            this->gridUsers->RowHeadersWidth = 62;
            this->gridUsers->Size = System::Drawing::Size(960, 359);
            this->gridUsers->TabIndex = 0;
            this->gridUsers->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &View_All_Students::gridUsers_CellContentClick);
            // 
            // groupBoxFilters
            // 
            this->groupBoxFilters->Controls->Add(this->btnUpdate);
            this->groupBoxFilters->Controls->Add(this->btnDelete);
            this->groupBoxFilters->Controls->Add(this->Search);
            this->groupBoxFilters->Controls->Add(this->txtSearch);
            this->groupBoxFilters->Controls->Add(this->btnExportUsers);
            this->groupBoxFilters->Location = System::Drawing::Point(12, 12);
            this->groupBoxFilters->Name = L"groupBoxFilters";
            this->groupBoxFilters->Size = System::Drawing::Size(960, 80);
            this->groupBoxFilters->TabIndex = 1;
            this->groupBoxFilters->TabStop = false;
            this->groupBoxFilters->Text = L"Filters";
            // 
            // btnUpdate
            // 
            this->btnUpdate->Location = System::Drawing::Point(600, 30);
            this->btnUpdate->Name = L"btnUpdate";
            this->btnUpdate->Size = System::Drawing::Size(100, 30);
            this->btnUpdate->TabIndex = 5;
            this->btnUpdate->Text = L"Update";
            this->btnUpdate->UseVisualStyleBackColor = true;
            this->btnUpdate->Click += gcnew System::EventHandler(this, &View_All_Students::btnUpdate_Click);
            // 
            // btnDelete
            // 
            this->btnDelete->Location = System::Drawing::Point(710, 30);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(100, 30);
            this->btnDelete->TabIndex = 6;
            this->btnDelete->Text = L"Delete";
            this->btnDelete->UseVisualStyleBackColor = true;
            this->btnDelete->Click += gcnew System::EventHandler(this, &View_All_Students::btnDelete_Click);
            // 
            // Search
            // 
            this->Search->AutoSize = true;
            this->Search->Location = System::Drawing::Point(19, 41);
            this->Search->Name = L"Search";
            this->Search->Size = System::Drawing::Size(53, 16);
            this->Search->TabIndex = 5;
            this->Search->Text = L"Search:";
            this->Search->Click += gcnew System::EventHandler(this, &View_All_Students::label1_Click);
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(75, 38);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(300, 22);
            this->txtSearch->TabIndex = 3;
            this->txtSearch->TextChanged += gcnew System::EventHandler(this, &View_All_Students::txtSearch_TextChanged);
            // 
            // btnExportUsers
            // 
            this->btnExportUsers->Location = System::Drawing::Point(825, 30);
            this->btnExportUsers->Name = L"btnExportUsers";
            this->btnExportUsers->Size = System::Drawing::Size(115, 30);
            this->btnExportUsers->TabIndex = 4;
            this->btnExportUsers->Text = L"Export";
            this->btnExportUsers->UseVisualStyleBackColor = true;
            this->btnExportUsers->Click += gcnew System::EventHandler(this, &View_All_Students::btnExportUsers_Click);
            // 
            // lblTotalUsers
            // 
            this->lblTotalUsers->AutoSize = true;
            this->lblTotalUsers->Location = System::Drawing::Point(9, 484);
            this->lblTotalUsers->Name = L"lblTotalUsers";
            this->lblTotalUsers->Size = System::Drawing::Size(90, 16);
            this->lblTotalUsers->TabIndex = 6;
            this->lblTotalUsers->Text = L"Total Users: 0";
            // 
            // statusStrip
            // 
            this->statusStrip->ImageScalingSize = System::Drawing::Size(24, 24);
            this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusLabel });
            this->statusStrip->Location = System::Drawing::Point(0, 736);
            this->statusStrip->Name = L"statusStrip";
            this->statusStrip->Size = System::Drawing::Size(983, 22);
            this->statusStrip->TabIndex = 7;
            // 
            // statusLabel
            // 
            this->statusLabel->Name = L"statusLabel";
            this->statusLabel->Size = System::Drawing::Size(0, 16);
            // 
            // groupBoxEdit
            // 
            this->groupBoxEdit->Controls->Add(this->lblEditFirstName);
            this->groupBoxEdit->Controls->Add(this->txtEditFirstName);
            this->groupBoxEdit->Controls->Add(this->lblEditLastName);
            this->groupBoxEdit->Controls->Add(this->txtEditLastName);
            this->groupBoxEdit->Controls->Add(this->lblEditEmail);
            this->groupBoxEdit->Controls->Add(this->txtEditEmail);
            this->groupBoxEdit->Controls->Add(this->lblEditMajor);
            this->groupBoxEdit->Controls->Add(this->txtEditMajor);
            this->groupBoxEdit->Controls->Add(this->btnSave);
            this->groupBoxEdit->Controls->Add(this->btnCancel);
            this->groupBoxEdit->Location = System::Drawing::Point(12, 520);
            this->groupBoxEdit->Name = L"groupBoxEdit";
            this->groupBoxEdit->Size = System::Drawing::Size(960, 180);
            this->groupBoxEdit->TabIndex = 8;
            this->groupBoxEdit->TabStop = false;
            this->groupBoxEdit->Text = L"Edit Student";
            // 
            // lblEditFirstName
            // 
            this->lblEditFirstName->Location = System::Drawing::Point(20, 30);
            this->lblEditFirstName->Name = L"lblEditFirstName";
            this->lblEditFirstName->Size = System::Drawing::Size(100, 23);
            this->lblEditFirstName->TabIndex = 0;
            this->lblEditFirstName->Text = L"First Name:";
            // 
            // txtEditFirstName
            // 
            this->txtEditFirstName->Location = System::Drawing::Point(120, 30);
            this->txtEditFirstName->Name = L"txtEditFirstName";
            this->txtEditFirstName->Size = System::Drawing::Size(200, 22);
            this->txtEditFirstName->TabIndex = 1;
            // 
            // lblEditLastName
            // 
            this->lblEditLastName->Location = System::Drawing::Point(20, 60);
            this->lblEditLastName->Name = L"lblEditLastName";
            this->lblEditLastName->Size = System::Drawing::Size(100, 23);
            this->lblEditLastName->TabIndex = 2;
            this->lblEditLastName->Text = L"Last Name:";
            // 
            // txtEditLastName
            // 
            this->txtEditLastName->Location = System::Drawing::Point(120, 60);
            this->txtEditLastName->Name = L"txtEditLastName";
            this->txtEditLastName->Size = System::Drawing::Size(200, 22);
            this->txtEditLastName->TabIndex = 3;
            // 
            // lblEditEmail
            // 
            this->lblEditEmail->Location = System::Drawing::Point(20, 90);
            this->lblEditEmail->Name = L"lblEditEmail";
            this->lblEditEmail->Size = System::Drawing::Size(100, 23);
            this->lblEditEmail->TabIndex = 4;
            this->lblEditEmail->Text = L"Email:";
            // 
            // txtEditEmail
            // 
            this->txtEditEmail->Location = System::Drawing::Point(120, 90);
            this->txtEditEmail->Name = L"txtEditEmail";
            this->txtEditEmail->Size = System::Drawing::Size(200, 22);
            this->txtEditEmail->TabIndex = 5;
            // 
            // lblEditMajor
            // 
            this->lblEditMajor->Location = System::Drawing::Point(20, 120);
            this->lblEditMajor->Name = L"lblEditMajor";
            this->lblEditMajor->Size = System::Drawing::Size(100, 23);
            this->lblEditMajor->TabIndex = 6;
            this->lblEditMajor->Text = L"Major:";
            // 
            // txtEditMajor
            // 
            this->txtEditMajor->Location = System::Drawing::Point(120, 120);
            this->txtEditMajor->Name = L"txtEditMajor";
            this->txtEditMajor->Size = System::Drawing::Size(200, 22);
            this->txtEditMajor->TabIndex = 7;
            // 
            // btnSave
            // 
            this->btnSave->Location = System::Drawing::Point(120, 150);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(75, 23);
            this->btnSave->TabIndex = 8;
            this->btnSave->Text = L"Save";
            this->btnSave->Click += gcnew System::EventHandler(this, &View_All_Students::btnSave_Click);
            // 
            // btnCancel
            // 
            this->btnCancel->Location = System::Drawing::Point(200, 150);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(75, 23);
            this->btnCancel->TabIndex = 9;
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->Click += gcnew System::EventHandler(this, &View_All_Students::btnCancel_Click);
            // 
            // View_All_Students
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(983, 758);
            this->Controls->Add(this->statusStrip);
            this->Controls->Add(this->lblTotalUsers);
            this->Controls->Add(this->groupBoxFilters);
            this->Controls->Add(this->gridUsers);
            this->Controls->Add(this->groupBoxEdit);
            this->MinimumSize = System::Drawing::Size(999, 598);
            this->Name = L"View_All_Students";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"View All Students";
            this->Load += gcnew System::EventHandler(this, &View_All_Students::View_All_Users_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridUsers))->EndInit();
            this->groupBoxFilters->ResumeLayout(false);
            this->groupBoxFilters->PerformLayout();
            this->statusStrip->ResumeLayout(false);
            this->statusStrip->PerformLayout();
            this->groupBoxEdit->ResumeLayout(false);
            this->groupBoxEdit->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        System::Void comboUserRole_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            FilterUsers();
        }

        System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            FilterUsers();
        }

        System::Void btnExportUsers_Click(System::Object^ sender, System::EventArgs^ e) {
            SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
            saveFileDialog1->Filter = "CSV Files (*.csv)|*.csv";
            saveFileDialog1->FilterIndex = 1;
            saveFileDialog1->RestoreDirectory = true;

            if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                try {
                    StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);

                    // Write Headers
                    for (int i = 0; i < gridUsers->Columns->Count; i++) {
                        sw->Write(gridUsers->Columns[i]->HeaderText);
                        if (i < gridUsers->Columns->Count - 1) {
                            sw->Write(",");
                        }
                    }
                    sw->WriteLine();

                    // Write Data
                    for (int i = 0; i < gridUsers->Rows->Count; i++) {
                        for (int j = 0; j < gridUsers->Columns->Count; j++) {
                            if (gridUsers->Rows[i]->Cells[j]->Value != nullptr) {
                                String^ value = gridUsers->Rows[i]->Cells[j]->Value->ToString();
                                // If the value contains a comma, wrap it in quotes
                                if (value->Contains(",")) {
                                    value = "\"" + value + "\"";
                                }
                                sw->Write(value);
                            }
                            if (j < gridUsers->Columns->Count - 1) {
                                sw->Write(",");
                            }
                        }
                        sw->WriteLine();
                    }

                    sw->Close();
                    MessageBox::Show("Data exported successfully!", "Success",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error exporting data: " + ex->Message, "Export Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }

    private: System::Void gridUsers_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
           inline System::Void View_All_Students::View_All_Users_Load(System::Object^ sender, System::EventArgs^ e)
           {
               return System::Void();
           }
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}