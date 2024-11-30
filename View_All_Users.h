#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class View_All_Users : public System::Windows::Forms::Form {
    public:
        View_All_Users(void)
        {
            InitializeComponent();
            LoadUsersData();
        }

    protected:
        ~View_All_Users()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ gridUsers;
        System::Windows::Forms::GroupBox^ groupBoxFilters;
        System::Windows::Forms::ComboBox^ comboUserRole;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnExportUsers;
        System::Windows::Forms::Button^ btnResetFilters;
        System::Windows::Forms::Label^ lblTotalUsers;
        System::Windows::Forms::StatusStrip^ statusStrip;
        System::Windows::Forms::ToolStripStatusLabel^ statusLabel;
        System::ComponentModel::Container^ components;

    private:
        void InitializeComponent(void)
        {
            this->gridUsers = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxFilters = (gcnew System::Windows::Forms::GroupBox());
            this->comboUserRole = (gcnew System::Windows::Forms::ComboBox());
            this->txtSearch = (gcnew System::Windows::Forms::TextBox());
            this->btnExportUsers = (gcnew System::Windows::Forms::Button());
            this->btnResetFilters = (gcnew System::Windows::Forms::Button());
            this->lblTotalUsers = (gcnew System::Windows::Forms::Label());
            this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
            this->statusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridUsers))->BeginInit();
            this->groupBoxFilters->SuspendLayout();
            this->statusStrip->SuspendLayout();
            this->SuspendLayout();
            // 
            // gridUsers
            // 
            this->gridUsers->AllowUserToAddRows = false;
            this->gridUsers->ColumnHeadersHeight = 34;
            this->gridUsers->Location = System::Drawing::Point(14, 125);
            this->gridUsers->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->gridUsers->Name = L"gridUsers";
            this->gridUsers->ReadOnly = true;
            this->gridUsers->RowHeadersWidth = 62;
            this->gridUsers->Size = System::Drawing::Size(1080, 500);
            this->gridUsers->TabIndex = 0;
            // 
            // groupBoxFilters
            // 
            this->groupBoxFilters->Controls->Add(this->comboUserRole);
            this->groupBoxFilters->Controls->Add(this->txtSearch);
            this->groupBoxFilters->Controls->Add(this->btnExportUsers);
            this->groupBoxFilters->Controls->Add(this->btnResetFilters);
            this->groupBoxFilters->Location = System::Drawing::Point(14, 15);
            this->groupBoxFilters->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxFilters->Name = L"groupBoxFilters";
            this->groupBoxFilters->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxFilters->Size = System::Drawing::Size(1080, 100);
            this->groupBoxFilters->TabIndex = 1;
            this->groupBoxFilters->TabStop = false;
            this->groupBoxFilters->Text = L"Filters";
            // 
            // comboUserRole
            // 
            this->comboUserRole->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboUserRole->FormattingEnabled = true;
            this->comboUserRole->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Faculty", L"Administrator" });
            this->comboUserRole->Location = System::Drawing::Point(22, 38);
            this->comboUserRole->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->comboUserRole->Name = L"comboUserRole";
            this->comboUserRole->Size = System::Drawing::Size(224, 28);
            this->comboUserRole->TabIndex = 2;
            this->comboUserRole->SelectedIndexChanged += gcnew System::EventHandler(this, &View_All_Users::comboUserRole_SelectedIndexChanged);
            // 
            // txtSearch
            // 
            this->txtSearch->Location = System::Drawing::Point(270, 38);
            this->txtSearch->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->txtSearch->Name = L"txtSearch";
            this->txtSearch->Size = System::Drawing::Size(337, 26);
            this->txtSearch->TabIndex = 3;
            this->txtSearch->TextChanged += gcnew System::EventHandler(this, &View_All_Users::txtSearch_TextChanged);
            // 
            // btnExportUsers
            // 
            this->btnExportUsers->Location = System::Drawing::Point(821, 38);
            this->btnExportUsers->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnExportUsers->Name = L"btnExportUsers";
            this->btnExportUsers->Size = System::Drawing::Size(129, 38);
            this->btnExportUsers->TabIndex = 4;
            this->btnExportUsers->Text = L"Export to Excel";
            this->btnExportUsers->UseVisualStyleBackColor = true;
            this->btnExportUsers->Click += gcnew System::EventHandler(this, &View_All_Users::btnExportUsers_Click);
            // 
            // btnResetFilters
            // 
            this->btnResetFilters->Location = System::Drawing::Point(956, 38);
            this->btnResetFilters->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnResetFilters->Name = L"btnResetFilters";
            this->btnResetFilters->Size = System::Drawing::Size(112, 38);
            this->btnResetFilters->TabIndex = 5;
            this->btnResetFilters->Text = L"Reset Filters";
            this->btnResetFilters->UseVisualStyleBackColor = true;
            this->btnResetFilters->Click += gcnew System::EventHandler(this, &View_All_Users::btnResetFilters_Click);
            // 
            // lblTotalUsers
            // 
            this->lblTotalUsers->AutoSize = true;
            this->lblTotalUsers->Location = System::Drawing::Point(14, 638);
            this->lblTotalUsers->Name = L"lblTotalUsers";
            this->lblTotalUsers->Size = System::Drawing::Size(107, 20);
            this->lblTotalUsers->TabIndex = 6;
            this->lblTotalUsers->Text = L"Total Users: 0";
            // 
            // statusStrip
            // 
            this->statusStrip->ImageScalingSize = System::Drawing::Size(24, 24);
            this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusLabel });
            this->statusStrip->Location = System::Drawing::Point(0, 679);
            this->statusStrip->Name = L"statusStrip";
            this->statusStrip->Padding = System::Windows::Forms::Padding(1, 0, 16, 0);
            this->statusStrip->Size = System::Drawing::Size(1107, 22);
            this->statusStrip->TabIndex = 7;
            // 
            // statusLabel
            // 
            this->statusLabel->Name = L"statusLabel";
            this->statusLabel->Size = System::Drawing::Size(0, 15);
            // 
            // View_All_Users
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1107, 701);
            this->Controls->Add(this->statusStrip);
            this->Controls->Add(this->lblTotalUsers);
            this->Controls->Add(this->groupBoxFilters);
            this->Controls->Add(this->gridUsers);
            this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->MinimumSize = System::Drawing::Size(1122, 736);
            this->Name = L"View_All_Users";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"View All Users";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridUsers))->EndInit();
            this->groupBoxFilters->ResumeLayout(false);
            this->groupBoxFilters->PerformLayout();
            this->statusStrip->ResumeLayout(false);
            this->statusStrip->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void SetupUsersGrid(void) {
            this->gridUsers->ColumnCount = 7;
            array<String^>^ columnNames = {
                "ID",
                "First Name",
                "Last Name",
                "Email",
                "Role",
                "Department",
                "Status"
            };

            for (int i = 0; i < columnNames->Length; i++) {
                this->gridUsers->Columns[i]->Name = columnNames[i];
                this->gridUsers->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            }
        }

        void LoadUsersData(void) {
            try {
                this->gridUsers->Rows->Clear();

                // Add sample data (replace with database query)
                this->gridUsers->Rows->Add("1", "John", "Doe", "john.doe@university.edu", "Student", "Computer Science", "Active");
                this->gridUsers->Rows->Add("2", "Jane", "Smith", "jane.smith@university.edu", "Faculty", "Mathematics", "Active");
                this->gridUsers->Rows->Add("3", "Admin", "User", "admin@university.edu", "Administrator", "Administration", "Active");

                UpdateStatusBar();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading users data: " + ex->Message);
            }
        }

        void UpdateStatusBar(void) {
            int totalUsers = this->gridUsers->Rows->Count;
            this->statusLabel->Text = String::Format("Total Users: {0}", totalUsers);
            this->lblTotalUsers->Text = String::Format("Total Users: {0}", totalUsers);
        }

        void FilterUsers(void) {
            String^ searchText = this->txtSearch->Text->ToLower();
            String^ selectedRole = this->comboUserRole->SelectedItem ? this->comboUserRole->SelectedItem->ToString() : "";

            for each (DataGridViewRow ^ row in this->gridUsers->Rows) {
                bool showRow = true;

                // Check role filter
                if (!String::IsNullOrEmpty(selectedRole)) {
                    String^ rowRole = row->Cells["Role"]->Value->ToString();
                    if (rowRole != selectedRole) {
                        showRow = false;
                    }
                }

                // Check search text
                if (!String::IsNullOrEmpty(searchText)) {
                    bool matchFound = false;
                    for each (DataGridViewCell ^ cell in row->Cells) {
                        if (cell->Value != nullptr) {
                            String^ cellValue = cell->Value->ToString()->ToLower();
                            if (cellValue->Contains(searchText)) {
                                matchFound = true;
                                break;
                            }
                        }
                    }
                    if (!matchFound) {
                        showRow = false;
                    }
                }

                row->Visible = showRow;
            }

            UpdateStatusBar();
        }

        System::Void comboUserRole_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            FilterUsers();
        }

        System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            FilterUsers();
        }

        System::Void btnExportUsers_Click(System::Object^ sender, System::EventArgs^ e) {
            SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
            saveFileDialog1->Filter = "Excel Files (*.xlsx)|*.xlsx";
            saveFileDialog1->FilterIndex = 1;
            saveFileDialog1->RestoreDirectory = true;

            if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                try {
                    // Here you would implement the actual Excel export
                    MessageBox::Show("Exporting data to Excel: " + saveFileDialog1->FileName);
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error exporting data: " + ex->Message);
                }
            }
        }

        System::Void btnResetFilters_Click(System::Object^ sender, System::EventArgs^ e) {
            this->comboUserRole->SelectedIndex = -1;
            this->txtSearch->Clear();
            LoadUsersData();
        }
    };
}