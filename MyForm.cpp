#include "MyForm.h"
#include "Signup.h"
#include "MDIForm.h"
#include "db_conn.h"
#include "student.h"
#include "faculty.h"
#include "admin.h"
#include "PasswordHasher.h"


namespace university {
	void MyForm::InitializeComponent(void)
	{
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->txtuserName = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_Signup = (gcnew System::Windows::Forms::LinkLabel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(294, 326);
			this->btnCancel->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(232, 58);
			this->btnCancel->TabIndex = 0;
			this->btnCancel->Text = L"Cancel ";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &MyForm::btnCancel_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(63, 326);
			this->btnLogin->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(219, 58);
			this->btnLogin->TabIndex = 1;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MyForm::btnLogin_Click);
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Location = System::Drawing::Point(59, 93);
			this->Username->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(48, 20);
			this->Username->TabIndex = 2;
			this->Username->Text = L"Email";
			this->Username->Click += gcnew System::EventHandler(this, &MyForm::Username_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(59, 194);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(397, 278);
			this->linkLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(129, 20);
			this->linkLabel1->TabIndex = 4;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Forgot Password";
			// 
			// txtuserName
			// 
			this->txtuserName->Location = System::Drawing::Point(63, 138);
			this->txtuserName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtuserName->Name = L"txtuserName";
			this->txtuserName->Size = System::Drawing::Size(463, 26);
			this->txtuserName->TabIndex = 5;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(63, 230);
			this->txtPassword->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(463, 26);
			this->txtPassword->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(270, 36);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Login";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 23);
			this->label3->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 421);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btn_Signup);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtuserName);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->btnCancel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
	}

    System::Void MyForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }

	System::Void MyForm::btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ email = txtuserName->Text;
			String^ password = txtPassword->Text;

			if (String::IsNullOrEmpty(email) || String::IsNullOrEmpty(password)) {
				MessageBox::Show("Please enter both email and password!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Hash the entered password before comparison
			String^ hashedPassword = PasswordHasher::HashPassword(password);

			DatabaseManager^ dbManager = DatabaseManager::GetInstance();
			MySqlConnection^ conn = dbManager->GetConnection();

			MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM users WHERE email = @email AND password = @password;", conn);
			cmd->Parameters->AddWithValue("@email", email);
			cmd->Parameters->AddWithValue("@password", hashedPassword);  // Now comparing hashed passwords

			dbManager->ConnectToDatabase();
			MySqlDataReader^ reader = cmd->ExecuteReader();

			if (reader->Read()) {
				String^ role = reader["role"]->ToString();
				int userID = Convert::ToInt32(reader["userID"]);
				String^ firstName = reader["firstName"]->ToString();
				String^ lastName = reader["lastName"]->ToString();

				reader->Close();
				MDIForm^ mdiParent = gcnew MDIForm();

                if (role == "Student") {
                    cmd = gcnew MySqlCommand("SELECT * FROM students WHERE userID = @userID;", conn);
                    cmd->Parameters->AddWithValue("@userID", userID);
                    reader = cmd->ExecuteReader();

                    if (reader->Read()) {
                        Student^ currentStudent = Student::GetInstance();
                        currentStudent->SetUserID(userID);
                        currentStudent->SetFirstName(firstName);
                        currentStudent->SetLastName(lastName);
                        currentStudent->SetEmail(email);
                        currentStudent->SetRole(role);
                        currentStudent->SetStudentID(Convert::ToInt32(reader["studentID"]));
                        currentStudent->SetDateOfBirth(Convert::ToDateTime(reader["dateOfBirth"]));
                        currentStudent->SetMajor(reader["major"]->ToString());
                        currentStudent->SetEnrollmentDate(Convert::ToDateTime(reader["enrollmentDate"]));

                        if (!reader->IsDBNull(reader->GetOrdinal("picture"))) {
                            array<Byte>^ pic = (array<Byte>^)reader["picture"];
                            currentStudent->SetPicture(pic);
                        }

                        MessageBox::Show("Welcome Student " + currentStudent->GetFullName() + "!", "Success",
                            MessageBoxButtons::OK, MessageBoxIcon::Information);

                        mdiParent->SetUserAccess(currentStudent->GetRole());
                    }
                }
                else if (role == "Faculty") {
                    cmd = gcnew MySqlCommand("SELECT * FROM faculty WHERE userID = @userID;", conn);
                    cmd->Parameters->AddWithValue("@userID", userID);
                    reader = cmd->ExecuteReader();

                    if (reader->Read()) {
                        Faculty^ currentFaculty = Faculty::GetInstance();
                        int facultyID = Convert::ToInt32(reader["facultyID"]);
                        currentFaculty->SetUserID(userID);
                        currentFaculty->SetFirstName(firstName);
                        currentFaculty->SetLastName(lastName);
                        currentFaculty->SetEmail(email);
                        currentFaculty->SetRole(role);
                        currentFaculty->SetFacultyID(facultyID);
                        currentFaculty->SetDepartment(reader["department"]->ToString());
                        // currentFaculty->SetDateOfAppointment(Convert::ToDateTime(reader["dateOfAppointment"]));

                        MessageBox::Show("Welcome Faculty " + currentFaculty->GetFullName() + "!", "Success",
                            MessageBoxButtons::OK, MessageBoxIcon::Information);
                        mdiParent->SetUserAccess(currentFaculty->GetRole());
                        mdiParent->SetFacultyID(facultyID);
                    }
                }
                else if (role == "Administrator") {
                    cmd = gcnew MySqlCommand("SELECT * FROM administrators WHERE userID = @userID;", conn);
                    cmd->Parameters->AddWithValue("@userID", userID);
                    reader = cmd->ExecuteReader();

                    if (reader->Read()) {
                        Administrator^ currentAdmin = Administrator::GetInstance();
                        currentAdmin->SetUserID(userID);
                        currentAdmin->SetFirstName(firstName);
                        currentAdmin->SetLastName(lastName);
                        currentAdmin->SetEmail(email);
                        currentAdmin->SetRole(role);
                        currentAdmin->SetAdminID(Convert::ToInt32(reader["adminID"]));

                        MessageBox::Show("Welcome Administrator " + currentAdmin->GetFullName() + "!", "Success",
                            MessageBoxButtons::OK, MessageBoxIcon::Information);

                        mdiParent->SetUserAccess(currentAdmin->GetRole());
                    }
                }

				reader->Close();
				dbManager->CloseConnection();
				mdiParent->Show();
				this->Hide();
			}
			else {
				reader->Close();
				dbManager->CloseConnection();
				MessageBox::Show("Invalid email or password!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		DatabaseManager::GetInstance()->CloseConnection();
	}
}

    System::Void MyForm::Username_Click(System::Object^ sender, System::EventArgs^ e) {
    }

    System::Void MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }

    System::Void MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        Application::ExitThread();
    }
}