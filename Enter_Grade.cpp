// Enter_Grade.cpp
#include "Enter_Grade.h"

namespace university {
    void Enter_Grade::Enter_Grade_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadCourses();
        SetupDataGridView();
        btnSubmit->Enabled = false;
        btnUpdate->Enabled = false;
    }

    void Enter_Grade::SetupDataGridView() {
        dataGridGrades->Columns->Add("StudentID", "Student ID");
        dataGridGrades->Columns->Add("StudentName", "Student Name");
        dataGridGrades->Columns->Add("Grade", "Grade");
        dataGridGrades->Columns->Add("SubmissionDate", "Submission Date");
        dataGridGrades->Columns->Add("Notes", "Notes");
    }

    System::Void Enter_Grade::dataGridGrades_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            txtStudentID->Text = dataGridGrades->Rows[e->RowIndex]->Cells["StudentID"]->Value->ToString();
            txtStudentName->Text = dataGridGrades->Rows[e->RowIndex]->Cells["StudentName"]->Value->ToString();
            if (dataGridGrades->Rows[e->RowIndex]->Cells["Grade"]->Value != nullptr) {
                txtGrade->Text = dataGridGrades->Rows[e->RowIndex]->Cells["Grade"]->Value->ToString();
            }
            else {
                txtGrade->Clear();
            }
            if (dataGridGrades->Rows[e->RowIndex]->Cells["Notes"]->Value != nullptr) {
                txtNotes->Text = dataGridGrades->Rows[e->RowIndex]->Cells["Notes"]->Value->ToString();
            }
            else {
                txtNotes->Clear();
            }
        }
    }

    void Enter_Grade::LoadCourses() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.courseID, c.courseName FROM courses c "
                "INNER JOIN facultycourses fc ON c.courseID = fc.courseID "
                "WHERE fc.facultyID = @facultyID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@facultyID", currentFacultyID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            comboCourses->Items->Clear();
            while (reader->Read()) {
                String^ courseInfo = String::Format("{0} - {1}",
                    reader["courseID"]->ToString(),
                    reader["courseName"]->ToString());
                comboCourses->Items->Add(courseInfo);
            }

            reader->Close();

            comboSemester->Items->Clear();
            comboSemester->Items->Add("Semester1");
            comboSemester->Items->Add("Semester2");

            dbManager->CloseConnection();
        }
        catch (MySqlException^ ex) {
            MessageBox::Show(ex->Message);
        }
    }

    void Enter_Grade::LoadStudentGrades() {
        if (!ValidateSelections()) return;

        try {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT e.studentID, CONCAT(u.firstName, ' ', u.lastName) as studentName, "
                "e.grade, e.submissionDate, e.notes FROM enrollment e "
                "INNER JOIN students s ON e.studentID = s.studentID "
                "INNER JOIN users u ON s.userID = u.userID "
                "WHERE e.courseID = @courseID AND e.semester = @semester";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridGrades->Rows->Clear();
            while (reader->Read()) {
                dataGridGrades->Rows->Add(
                    reader["studentID"]->ToString(),
                    reader["studentName"]->ToString(),
                    reader["grade"]->ToString(),
                    reader["submissionDate"]->ToString(),
                    reader["notes"]->ToString()
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (MySqlException^ ex) {
            MessageBox::Show(ex->Message);
        }
    }

    bool Enter_Grade::ValidateSelections() {
        if (comboCourses->SelectedItem == nullptr) {
            MessageBox::Show("Please select a course first.");
            return false;
        }
        if (comboSemester->SelectedItem == nullptr) {
            MessageBox::Show("Please select a semester.");
            return false;
        }
        return true;
    }

    void Enter_Grade::SubmitGrade() {
        if (String::IsNullOrEmpty(txtStudentID->Text) || String::IsNullOrEmpty(txtGrade->Text)) {
            MessageBox::Show("Please select a student and enter a grade.");
            return;
        }

        try {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "UPDATE enrollment SET grade = @grade, notes = @notes, "
                "submissionDate = NOW(), assignedBy = @facultyID "
                "WHERE studentID = @studentID AND courseID = @courseID AND semester = @semester";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@grade", txtGrade->Text);
            cmd->Parameters->AddWithValue("@notes", txtNotes->Text);
            cmd->Parameters->AddWithValue("@facultyID", currentFacultyID);
            cmd->Parameters->AddWithValue("@studentID", Int32::Parse(txtStudentID->Text));
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            int rowsAffected = cmd->ExecuteNonQuery();
            if (rowsAffected > 0) {
                MessageBox::Show("Grade submitted successfully!");
                LoadStudentGrades();
                ClearForm();
            }
            else {
                MessageBox::Show("No matching record found to update.");
            }

            dbManager->CloseConnection();
        }
        catch (MySqlException^ ex) {
            MessageBox::Show(ex->Message);
        }
    }

    void Enter_Grade::UpdateGrade() {
        if (String::IsNullOrEmpty(txtStudentID->Text) || String::IsNullOrEmpty(txtGrade->Text)) {
            MessageBox::Show("Please select a student and enter a grade.");
            return;
        }

        try {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "UPDATE enrollment SET grade = @grade, notes = @notes, "
                "submissionDate = NOW(), assignedBy = @facultyID "
                "WHERE studentID = @studentID AND courseID = @courseID AND semester = @semester";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@grade", txtGrade->Text);
            cmd->Parameters->AddWithValue("@notes", txtNotes->Text);
            cmd->Parameters->AddWithValue("@facultyID", currentFacultyID);
            cmd->Parameters->AddWithValue("@studentID", Int32::Parse(txtStudentID->Text));
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            int rowsAffected = cmd->ExecuteNonQuery();
            if (rowsAffected > 0) {
                MessageBox::Show("Grade updated successfully!");
                LoadStudentGrades();
                ClearForm();
            }
            else {
                MessageBox::Show("No matching record found to update.");
            }

            dbManager->CloseConnection();
        }
        catch (MySqlException^ ex) {
            MessageBox::Show(ex->Message);
        }
    }

    void Enter_Grade::ClearForm() {
        txtStudentID->Clear();
        txtStudentName->Clear();
        txtGrade->Clear();
        txtNotes->Clear();
    }

    System::Void Enter_Grade::btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
        SubmitGrade();
    }

    System::Void Enter_Grade::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
        UpdateGrade();
    }

    System::Void Enter_Grade::btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
        ClearForm();
    }

    System::Void Enter_Grade::comboCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        btnSubmit->Enabled = (comboCourses->SelectedIndex != -1 && comboSemester->SelectedIndex != -1);
        btnUpdate->Enabled = btnSubmit->Enabled;

        if (btnSubmit->Enabled) {
            LoadStudentGrades();
        }
    }

    System::Void Enter_Grade::comboSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        btnSubmit->Enabled = (comboCourses->SelectedIndex != -1 && comboSemester->SelectedIndex != -1);
        btnUpdate->Enabled = btnSubmit->Enabled;

        if (btnSubmit->Enabled) {
            LoadStudentGrades();
        }
    }

    System::Void Enter_Grade::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        if (!ValidateSelections()) return;

        try {
            String^ searchTerm = txtSearch->Text->Trim();
            if (String::IsNullOrEmpty(searchTerm)) {
                LoadStudentGrades();
                return;
            }

            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT e.studentID, CONCAT(u.firstName, ' ', u.lastName) as studentName, "
                "e.grade, e.submissionDate, e.notes FROM enrollment e "
                "INNER JOIN students s ON e.studentID = s.studentID "
                "INNER JOIN users u ON s.userID = u.userID "
                "WHERE e.courseID = @courseID AND e.semester = @semester "
                "AND (u.firstName LIKE @search OR u.lastName LIKE @search OR e.studentID LIKE @search)";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);
            cmd->Parameters->AddWithValue("@search", "%" + searchTerm + "%");

            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridGrades->Rows->Clear();
            while (reader->Read()) {
                dataGridGrades->Rows->Add(
                    reader["studentID"]->ToString(),
                    reader["studentName"]->ToString(),
                    reader["grade"]->ToString(),
                    reader["submissionDate"]->ToString(),
                    reader["notes"]->ToString()
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (MySqlException^ ex) {
            MessageBox::Show(ex->Message);
        }
    }
};

