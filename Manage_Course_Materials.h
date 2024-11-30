#pragma once

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Manage_Course_Materials : public System::Windows::Forms::Form {
    public:
        Manage_Course_Materials(void)
        {
            InitializeComponent();
            LoadMaterialsData();
        }

    protected:
        ~Manage_Course_Materials()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TreeView^ treeViewMaterials;
        System::Windows::Forms::Panel^ panelMaterialDetails;
        System::Windows::Forms::TextBox^ txtBookTitle;
        System::Windows::Forms::TextBox^ txtBookAuthor;
        System::Windows::Forms::TextBox^ txtISBN;
        System::Windows::Forms::RichTextBox^ txtDescription;
        System::Windows::Forms::Button^ btnAddMaterial;
        System::Windows::Forms::Button^ btnUpdateMaterial;
        System::Windows::Forms::Button^ btnDeleteMaterial;
        System::Windows::Forms::ComboBox^ comboMaterialType;
        System::Windows::Forms::CheckBox^ chkRequired;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Label^ lblAuthor;
        System::Windows::Forms::Label^ lblISBN;
        System::Windows::Forms::Label^ lblDescription;
        System::Windows::Forms::Label^ lblType;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Manage_Course_Materials::typeid));
            this->treeViewMaterials = (gcnew System::Windows::Forms::TreeView());
            this->panelMaterialDetails = (gcnew System::Windows::Forms::Panel());
            this->lblType = (gcnew System::Windows::Forms::Label());
            this->comboMaterialType = (gcnew System::Windows::Forms::ComboBox());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->txtBookTitle = (gcnew System::Windows::Forms::TextBox());
            this->lblAuthor = (gcnew System::Windows::Forms::Label());
            this->txtBookAuthor = (gcnew System::Windows::Forms::TextBox());
            this->lblISBN = (gcnew System::Windows::Forms::Label());
            this->txtISBN = (gcnew System::Windows::Forms::TextBox());
            this->lblDescription = (gcnew System::Windows::Forms::Label());
            this->txtDescription = (gcnew System::Windows::Forms::RichTextBox());
            this->chkRequired = (gcnew System::Windows::Forms::CheckBox());
            this->btnAddMaterial = (gcnew System::Windows::Forms::Button());
            this->btnUpdateMaterial = (gcnew System::Windows::Forms::Button());
            this->btnDeleteMaterial = (gcnew System::Windows::Forms::Button());
            this->panelMaterialDetails->SuspendLayout();
            this->SuspendLayout();
            // 
            // treeViewMaterials
            // 
            this->treeViewMaterials->Location = System::Drawing::Point(14, 15);
            this->treeViewMaterials->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->treeViewMaterials->Name = L"treeViewMaterials";
            this->treeViewMaterials->Size = System::Drawing::Size(337, 624);
            this->treeViewMaterials->TabIndex = 0;
            this->treeViewMaterials->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Manage_Course_Materials::treeViewMaterials_AfterSelect);
            // 
            // panelMaterialDetails
            // 
            this->panelMaterialDetails->Controls->Add(this->lblType);
            this->panelMaterialDetails->Controls->Add(this->comboMaterialType);
            this->panelMaterialDetails->Controls->Add(this->lblTitle);
            this->panelMaterialDetails->Controls->Add(this->txtBookTitle);
            this->panelMaterialDetails->Controls->Add(this->lblAuthor);
            this->panelMaterialDetails->Controls->Add(this->txtBookAuthor);
            this->panelMaterialDetails->Controls->Add(this->lblISBN);
            this->panelMaterialDetails->Controls->Add(this->txtISBN);
            this->panelMaterialDetails->Controls->Add(this->lblDescription);
            this->panelMaterialDetails->Controls->Add(this->txtDescription);
            this->panelMaterialDetails->Controls->Add(this->chkRequired);
            this->panelMaterialDetails->Controls->Add(this->btnAddMaterial);
            this->panelMaterialDetails->Controls->Add(this->btnUpdateMaterial);
            this->panelMaterialDetails->Controls->Add(this->btnDeleteMaterial);
            this->panelMaterialDetails->Location = System::Drawing::Point(364, 15);
            this->panelMaterialDetails->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->panelMaterialDetails->Name = L"panelMaterialDetails";
            this->panelMaterialDetails->Size = System::Drawing::Size(562, 625);
            this->panelMaterialDetails->TabIndex = 1;
            // 
            // lblType
            // 
            this->lblType->Location = System::Drawing::Point(11, 25);
            this->lblType->Name = L"lblType";
            this->lblType->Size = System::Drawing::Size(112, 25);
            this->lblType->TabIndex = 2;
            this->lblType->Text = L"Material Type:";
            // 
            // comboMaterialType
            // 
            this->comboMaterialType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->comboMaterialType->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
                L"Textbook", L"Reference Book", L"Online Resource",
                    L"Course Notes"
            });
            this->comboMaterialType->Location = System::Drawing::Point(135, 25);
            this->comboMaterialType->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->comboMaterialType->Name = L"comboMaterialType";
            this->comboMaterialType->Size = System::Drawing::Size(224, 28);
            this->comboMaterialType->TabIndex = 7;
            // 
            // lblTitle
            // 
            this->lblTitle->Location = System::Drawing::Point(11, 88);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(112, 25);
            this->lblTitle->TabIndex = 3;
            this->lblTitle->Text = L"Title:";
            // 
            // txtBookTitle
            // 
            this->txtBookTitle->Location = System::Drawing::Point(135, 88);
            this->txtBookTitle->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->txtBookTitle->Name = L"txtBookTitle";
            this->txtBookTitle->Size = System::Drawing::Size(393, 26);
            this->txtBookTitle->TabIndex = 8;
            // 
            // lblAuthor
            // 
            this->lblAuthor->Location = System::Drawing::Point(11, 150);
            this->lblAuthor->Name = L"lblAuthor";
            this->lblAuthor->Size = System::Drawing::Size(112, 25);
            this->lblAuthor->TabIndex = 4;
            this->lblAuthor->Text = L"Author:";
            // 
            // txtBookAuthor
            // 
            this->txtBookAuthor->Location = System::Drawing::Point(135, 150);
            this->txtBookAuthor->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->txtBookAuthor->Name = L"txtBookAuthor";
            this->txtBookAuthor->Size = System::Drawing::Size(393, 26);
            this->txtBookAuthor->TabIndex = 9;
            // 
            // lblISBN
            // 
            this->lblISBN->Location = System::Drawing::Point(11, 212);
            this->lblISBN->Name = L"lblISBN";
            this->lblISBN->Size = System::Drawing::Size(112, 25);
            this->lblISBN->TabIndex = 5;
            this->lblISBN->Text = L"ISBN:";
            // 
            // txtISBN
            // 
            this->txtISBN->Location = System::Drawing::Point(135, 212);
            this->txtISBN->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->txtISBN->Name = L"txtISBN";
            this->txtISBN->Size = System::Drawing::Size(224, 26);
            this->txtISBN->TabIndex = 10;
            // 
            // lblDescription
            // 
            this->lblDescription->Location = System::Drawing::Point(11, 275);
            this->lblDescription->Name = L"lblDescription";
            this->lblDescription->Size = System::Drawing::Size(112, 25);
            this->lblDescription->TabIndex = 6;
            this->lblDescription->Text = L"Description:";
            // 
            // txtDescription
            // 
            this->txtDescription->Location = System::Drawing::Point(135, 275);
            this->txtDescription->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->txtDescription->Name = L"txtDescription";
            this->txtDescription->Size = System::Drawing::Size(393, 124);
            this->txtDescription->TabIndex = 11;
            this->txtDescription->Text = L"";
            // 
            // chkRequired
            // 
            this->chkRequired->Location = System::Drawing::Point(135, 425);
            this->chkRequired->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->chkRequired->Name = L"chkRequired";
            this->chkRequired->Size = System::Drawing::Size(225, 38);
            this->chkRequired->TabIndex = 15;
            this->chkRequired->Text = L"Required Material";
            // 
            // btnAddMaterial
            // 
            this->btnAddMaterial->Location = System::Drawing::Point(135, 475);
            this->btnAddMaterial->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnAddMaterial->Name = L"btnAddMaterial";
            this->btnAddMaterial->Size = System::Drawing::Size(112, 38);
            this->btnAddMaterial->TabIndex = 12;
            this->btnAddMaterial->Text = L"Add Material";
            this->btnAddMaterial->UseVisualStyleBackColor = true;
            this->btnAddMaterial->Click += gcnew System::EventHandler(this, &Manage_Course_Materials::btnAddMaterial_Click);
            // 
            // btnUpdateMaterial
            // 
            this->btnUpdateMaterial->Location = System::Drawing::Point(259, 475);
            this->btnUpdateMaterial->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnUpdateMaterial->Name = L"btnUpdateMaterial";
            this->btnUpdateMaterial->Size = System::Drawing::Size(112, 38);
            this->btnUpdateMaterial->TabIndex = 13;
            this->btnUpdateMaterial->Text = L"Update";
            this->btnUpdateMaterial->UseVisualStyleBackColor = true;
            this->btnUpdateMaterial->Click += gcnew System::EventHandler(this, &Manage_Course_Materials::btnUpdateMaterial_Click);
            // 
            // btnDeleteMaterial
            // 
            this->btnDeleteMaterial->Location = System::Drawing::Point(382, 475);
            this->btnDeleteMaterial->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnDeleteMaterial->Name = L"btnDeleteMaterial";
            this->btnDeleteMaterial->Size = System::Drawing::Size(112, 38);
            this->btnDeleteMaterial->TabIndex = 14;
            this->btnDeleteMaterial->Text = L"Delete";
            this->btnDeleteMaterial->UseVisualStyleBackColor = true;
            this->btnDeleteMaterial->Click += gcnew System::EventHandler(this, &Manage_Course_Materials::btnDeleteMaterial_Click);
            // 
            // Manage_Course_Materials
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(950, 655);
            this->Controls->Add(this->treeViewMaterials);
            this->Controls->Add(this->panelMaterialDetails);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->MinimumSize = System::Drawing::Size(965, 698);
            this->Name = L"Manage_Course_Materials";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Manage Course Materials";
            this->panelMaterialDetails->ResumeLayout(false);
            this->panelMaterialDetails->PerformLayout();
            this->ResumeLayout(false);

        }

        void LoadMaterialsData(void) {
            try {
                this->treeViewMaterials->Nodes->Clear();

                TreeNode^ courseNode = this->treeViewMaterials->Nodes->Add("CS101 - Programming Fundamentals");
                courseNode->Nodes->Add("Textbooks")->Nodes->Add("Introduction to Programming with Python");
                courseNode->Nodes->Add("Reference Materials")->Nodes->Add("Python Documentation");
                courseNode->Nodes->Add("Online Resources")->Nodes->Add("Course Website");

                courseNode = this->treeViewMaterials->Nodes->Add("CS102 - Data Structures");
                courseNode->Nodes->Add("Textbooks")->Nodes->Add("Data Structures and Algorithms");
                courseNode->Nodes->Add("Course Notes")->Nodes->Add("Lecture Notes Week 1-15");

                this->treeViewMaterials->ExpandAll();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error loading materials: " + ex->Message);
            }
        }

        void ClearForm(void) {
            this->txtBookTitle->Clear();
            this->txtBookAuthor->Clear();
            this->txtISBN->Clear();
            this->txtDescription->Clear();
            this->comboMaterialType->SelectedIndex = -1;
            this->chkRequired->Checked = false;
        }

        System::Void treeViewMaterials_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
            if (e->Node->Parent != nullptr && e->Node->Parent->Parent != nullptr) {
                txtBookTitle->Text = e->Node->Text;
                comboMaterialType->SelectedItem = e->Node->Parent->Text;
            }
        }

        System::Void btnAddMaterial_Click(System::Object^ sender, System::EventArgs^ e) {
            if (String::IsNullOrEmpty(txtBookTitle->Text) || comboMaterialType->SelectedItem == nullptr) {
                MessageBox::Show("Please fill in all required fields.");
                return;
            }

            try {
                TreeNode^ typeNode = nullptr;
                if (treeViewMaterials->SelectedNode != nullptr) {
                    TreeNode^ courseNode = treeViewMaterials->SelectedNode;
                    while (courseNode->Parent != nullptr) {
                        courseNode = courseNode->Parent;
                    }

                    for each (TreeNode ^ node in courseNode->Nodes) {
                        if (node->Text == comboMaterialType->Text) {
                            typeNode = node;
                            break;
                        }
                    }

                    if (typeNode == nullptr) {
                        typeNode = courseNode->Nodes->Add(comboMaterialType->Text);
                    }

                    typeNode->Nodes->Add(txtBookTitle->Text);
                    MessageBox::Show("Material added successfully.");
                    ClearForm();
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error adding material: " + ex->Message);
            }
        }

        System::Void btnUpdateMaterial_Click(System::Object^ sender, System::EventArgs^ e) {
            if (treeViewMaterials->SelectedNode == nullptr ||
                treeViewMaterials->SelectedNode->Parent == nullptr ||
                treeViewMaterials->SelectedNode->Parent->Parent == nullptr) {
                MessageBox::Show("Please select a material to update.");
                return;
            }

            try {
                treeViewMaterials->SelectedNode->Text = txtBookTitle->Text;
                MessageBox::Show("Material updated successfully.");
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error updating material: " + ex->Message);
            }
        }

        System::Void btnDeleteMaterial_Click(System::Object^ sender, System::EventArgs^ e) {
            if (treeViewMaterials->SelectedNode == nullptr) {
                MessageBox::Show("Please select a material to delete.");
                return;
            }

            if (MessageBox::Show("Are you sure you want to delete this material?",
                "Confirm Delete",
                MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
                try {
                    treeViewMaterials->SelectedNode->Remove();
                    MessageBox::Show("Material deleted successfully.");
                    ClearForm();
                }
                catch (Exception^ ex) {
                    MessageBox::Show("Error deleting material: " + ex->Message);
                }
            }
        }
    };
}