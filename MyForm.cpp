#include "MyForm.h"
#include "Signup.h"
#include "MDIForm.h"
#include "db_conn.h"
#include "student.h"
#include "faculty.h"
#include "admin.h"


namespace university {
    MyForm::MyForm(void)
    {
        // FOR Bryan: Created a class "DatabaseManager" found in db_conn.h which takes care of all the connections to
        // the Mysql server.
        InitializeComponent();
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

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM users WHERE email = @email AND password = @password;", conn);
            cmd->Parameters->AddWithValue("@email", email);
            cmd->Parameters->AddWithValue("@password", password);

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
                        currentFaculty->SetUserID(userID);
                        currentFaculty->SetFirstName(firstName);
                        currentFaculty->SetLastName(lastName);
                        currentFaculty->SetEmail(email);
                        currentFaculty->SetRole(role);
                        currentFaculty->SetFacultyID(Convert::ToInt32(reader["facultyID"]));
                        currentFaculty->SetDepartment(reader["department"]->ToString());
                        currentFaculty->SetDateOfAppointment(Convert::ToDateTime(reader["dateOfAppointment"]));

                        MessageBox::Show("Welcome Faculty " + currentFaculty->GetFullName() + "!", "Success",
                            MessageBoxButtons::OK, MessageBoxIcon::Information);

                        mdiParent->SetUserAccess(currentFaculty->GetRole());
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

    System::Void MyForm::linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        Signup^ signupForm = gcnew Signup();
        signupForm->Show();
        this->Hide();
    }

    System::Void MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        Application::ExitThread();
    }
}