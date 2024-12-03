#include "Enter_Grade.h";
#include "db_conn.h";

namespace university {
    void Enter_Grade::LoadCourses() {
    try {
        DatabaseManager^ dbManager = DatabaseManager::GetInstance();
        dbManager->ConnectToDatabase();
        MySqlConnection^ conn = dbManager->GetConnection();

        // First check user role and get faculty info
        String^ userQuery = "SELECT u.userID, f.facultyID "
                          "FROM users u "
                          "INNER JOIN faculty f ON u.userID = f.userID "
                          "WHERE u.role = 'Faculty' AND f.facultyID = @facultyID";

        MySqlCommand^ userCmd = gcnew MySqlCommand(userQuery, conn);
        userCmd->Parameters->AddWithValue("@facultyID", currentFacultyID);

        MySqlDataReader^ userReader = userCmd->ExecuteReader();
        
        if (!userReader->Read()) {
            MessageBox::Show("Invalid faculty credentials or insufficient permissions.");
            userReader->Close();
            dbManager->CloseConnection();
            return;
        }

        int facultyID = Convert::ToInt32(userReader["facultyID"]);
        userReader->Close();

        // Now get the courses for this faculty
        String^ courseQuery = "SELECT DISTINCT c.courseID, c.courseName "
                            "FROM courses c "
                            "INNER JOIN facultycourses fc ON c.courseID = fc.courseID "
                            "WHERE fc.facultyID = @facultyID";

        MySqlCommand^ courseCmd = gcnew MySqlCommand(courseQuery, conn);
        courseCmd->Parameters->AddWithValue("@facultyID", facultyID);

        MySqlDataReader^ courseReader = courseCmd->ExecuteReader();
        
        comboCourses->Items->Clear();
        bool hasItems = false;
        
        while (courseReader->Read()) {
            String^ courseInfo = String::Format("{0} - {1}",
                courseReader["courseID"]->ToString(),
                courseReader["courseName"]->ToString());
            comboCourses->Items->Add(courseInfo);
            hasItems = true;
        }

        courseReader->Close();

        if (!hasItems) {
            MessageBox::Show("No courses found for this faculty member.");
        }

        // Set up semesters
        comboSemester->Items->Clear();
        comboSemester->Items->Add("Semester1");
        comboSemester->Items->Add("Semester2");

        dbManager->CloseConnection();
    }
    catch (MySqlException^ ex) {
        MessageBox::Show("Database error: " + ex->Message);
    }
    catch (Exception^ ex) {
        MessageBox::Show("An error occurred: " + ex->Message);
    }
}

    void Enter_Grade::LoadStudentGrades() {
        if (comboCourses->SelectedIndex == -1 || comboSemester->SelectedIndex == -1) return;

        try {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT e.studentID, CONCAT(u.firstName, ' ', u.lastName) as studentName, "
                "e.grade FROM enrollment e "
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
                    reader["grade"]->ToString()
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (MySqlException^ ex) {
            MessageBox::Show(ex->Message);
        }
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

            String^ query = "UPDATE enrollment SET grade = @grade, assignedBy = @facultyID "
                "WHERE studentID = @studentID AND courseID = @courseID AND semester = @semester";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@grade", txtGrade->Text);
            cmd->Parameters->AddWithValue("@facultyID", currentFacultyID);
            cmd->Parameters->AddWithValue("@studentID", Int32::Parse(txtStudentID->Text));
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            cmd->ExecuteNonQuery();
            MessageBox::Show("Grade submitted successfully!");

            dbManager->CloseConnection();
            LoadStudentGrades();
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

            String^ query = "UPDATE enrollment SET grade = @grade, assignedBy = @facultyID "
                "WHERE studentID = @studentID AND courseID = @courseID AND semester = @semester";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@grade", txtGrade->Text);
            cmd->Parameters->AddWithValue("@facultyID", currentFacultyID);
            cmd->Parameters->AddWithValue("@studentID", Int32::Parse(txtStudentID->Text));
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            int rowsAffected = cmd->ExecuteNonQuery();
            if (rowsAffected > 0) {
                MessageBox::Show("Grade updated successfully!");
                LoadStudentGrades();
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
        if (comboSemester->SelectedIndex != -1) {
            LoadStudentGrades();
        }
    }

    System::Void Enter_Grade::comboSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        if (comboCourses->SelectedIndex != -1) {
            LoadStudentGrades();
        }
    }
    System::Void Enter_Grade::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
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

            String^ userQuery = "SELECT u.userID, f.facultyID "
                          "FROM users u "
                          "INNER JOIN faculty f ON u.userID = f.userID "
                          "WHERE u.role = 'Faculty' AND f.facultyID = @facultyID";

            MySqlCommand^ cmd = gcnew MySqlCommand(userQuery, conn);
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);
            cmd->Parameters->AddWithValue("@search", "%" + searchTerm + "%");

            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridGrades->Rows->Clear();
            while (reader->Read()) {
                dataGridGrades->Rows->Add(
                    reader["studentID"]->ToString(),
                    reader["studentName"]->ToString(),
                    reader["grade"]->ToString()
                );
            }

            reader->Close();
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
}

