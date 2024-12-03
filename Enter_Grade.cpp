#include "Enter_Grade.h"
#include "db_conn.h"

namespace university {
    void Enter_Grade::Enter_Grade_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadFacultyCourses();
    }

    void Enter_Grade::txtSearch_Enter(System::Object^ sender, System::EventArgs^ e) {
        // When the textbox gets focus, if it contains the default text, clear it and change color
        if (txtSearch->Text == L"Search by student name...") {
            txtSearch->Text = L"";
            txtSearch->ForeColor = System::Drawing::Color::Black;
        }
    }

    void Enter_Grade::txtSearch_Leave(System::Object^ sender, System::EventArgs^ e) {
        // When the textbox loses focus, if it's empty, restore the default text and color
        if (String::IsNullOrWhiteSpace(txtSearch->Text)) {
            txtSearch->Text = L"Search by student name...";
            txtSearch->ForeColor = System::Drawing::Color::Gray;
        }
    }

    void Enter_Grade::LoadFacultyCourses() {
        try {
            String^ query = "SELECT DISTINCT c.courseID, c.courseName FROM courses c "
                "INNER JOIN facultycourses fc ON c.courseID = fc.courseID "
                "WHERE fc.facultyID = @facultyID";

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@facultyID", facultyInstance->GetFacultyID());

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ coursesTable = gcnew DataTable();
            adapter->Fill(coursesTable);

            cmbCourses->DisplayMember = "courseName";
            cmbCourses->ValueMember = "courseID";
            cmbCourses->DataSource = coursesTable;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading courses: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Enter_Grade::LoadEnrollments() {
        if (cmbCourses->SelectedValue == nullptr) return;

        try {
            String^ query = "SELECT e.enrollmentID, CONCAT(u.firstName, ' ', u.lastName) as StudentName, "
                "c.courseName, e.status, e.grade, s.currentYR, e.semester, e.academic_year "
                "FROM enrollments e "
                "INNER JOIN students s ON e.studentID = s.studentID "
                "INNER JOIN users u ON s.userID = u.userID "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.courseID = @courseID AND e.status = 'Enrolled'";

            if (cmbSemester->SelectedIndex > 0) {
                query += " AND e.semester = @semester";
            }
            if (cmbYear->SelectedIndex > 0) {
                query += " AND s.currentYR = @year";
            }

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@courseID", cmbCourses->SelectedValue);

            if (cmbSemester->SelectedIndex > 0) {
                cmd->Parameters->AddWithValue("@semester", cmbSemester->SelectedItem->ToString());
            }
            if (cmbYear->SelectedIndex > 0) {
                cmd->Parameters->AddWithValue("@year", cmbYear->SelectedItem->ToString());
            }

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ enrollmentsTable = gcnew DataTable();
            adapter->Fill(enrollmentsTable);
            dgvEnrollments->DataSource = enrollmentsTable;

            // Configure column headers
            dgvEnrollments->Columns["enrollmentID"]->HeaderText = "Enrollment ID";
            dgvEnrollments->Columns["StudentName"]->HeaderText = "Student Name";
            dgvEnrollments->Columns["courseName"]->HeaderText = "Course";
            dgvEnrollments->Columns["status"]->HeaderText = "Status";
            dgvEnrollments->Columns["grade"]->HeaderText = "Grade";
            dgvEnrollments->Columns["currentYR"]->HeaderText = "Year";
            dgvEnrollments->Columns["semester"]->HeaderText = "Semester";
            dgvEnrollments->Columns["academic_year"]->HeaderText = "Academic Year";
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading enrollments: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Enter_Grade::FilterChanged(System::Object^ sender, System::EventArgs^ e) {
        LoadEnrollments();
    }

    void Enter_Grade::SearchTextChanged(System::Object^ sender, System::EventArgs^ e) {
        DataTable^ dt = safe_cast<DataTable^>(dgvEnrollments->DataSource);
        if (dt != nullptr) {
            dt->DefaultView->RowFilter = String::Format("StudentName LIKE '%{0}%'", txtSearch->Text);
        }
    }

    void Enter_Grade::EnrollmentSelected(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            DataGridViewRow^ row = dgvEnrollments->Rows[e->RowIndex];
            lblStudentName->Text = "Student: " + row->Cells["StudentName"]->Value->ToString();
            lblCourse->Text = "Course: " + row->Cells["courseName"]->Value->ToString();
            pnlGradeEntry->Visible = true;
            txtGrade->Clear();
            txtGrade->Focus();
        }
    }

    void Enter_Grade::SubmitGrade(System::Object^ sender, System::EventArgs^ e) {
        if (dgvEnrollments->SelectedRows->Count == 0) {
            MessageBox::Show("Please select a student enrollment.");
            return;
        }

        double grade;
        if (!Double::TryParse(txtGrade->Text, grade) || grade < 0 || grade > 100) {
            MessageBox::Show("Please enter a valid grade between 0 and 100.");
            txtGrade->Focus();
            return;
        }

        try {
            int enrollmentID = Convert::ToInt32(dgvEnrollments->SelectedRows[0]->Cells["enrollmentID"]->Value);

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ query = "UPDATE enrollments SET grade = @grade, status = 'Completed' "
                "WHERE enrollmentID = @enrollmentID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@grade", grade);
            cmd->Parameters->AddWithValue("@enrollmentID", enrollmentID);

            int result = cmd->ExecuteNonQuery();
            if (result > 0) {
                MessageBox::Show("Grade submitted successfully.");
                pnlGradeEntry->Visible = false;
                LoadEnrollments();
            }
            else {
                MessageBox::Show("Failed to submit grade. Please try again.");
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error submitting grade: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Enter_Grade::CancelGradeEntry(System::Object^ sender, System::EventArgs^ e) {
        pnlGradeEntry->Visible = false;
        txtGrade->Clear();
    }
}