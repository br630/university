// Enrollment.cpp
#include "Enrollment.h"

namespace university {
    void Enrollment::LoadAvailableCourses() {
        try {
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.courseID, c.courseName, c.credits, c.semester "
                "FROM courses c "
                "WHERE c.courseID NOT IN ( "
                "    SELECT e.courseID FROM enrollment e "
                "    WHERE e.studentID = @studentID "
                ")";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentID", studentID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            comboCourses->Items->Clear();
            while (reader->Read()) {
                String^ courseInfo = String::Format("{0} - {1} ({2} credits) - {3}",
                    reader["courseID"]->ToString(),
                    reader["courseName"]->ToString(),
                    reader["credits"]->ToString(),
                    reader["semester"]->ToString());
                comboCourses->Items->Add(courseInfo);
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading courses: " + ex->Message);
        }
    }

    void Enrollment::LoadCurrentEnrollments() {
        try {
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.courseID, c.courseName, c.credits, e.semester, e.grade "
                "FROM enrollment e "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.studentID = @studentID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentID", studentID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridEnrollment->Rows->Clear();
            while (reader->Read()) {
                dataGridEnrollment->Rows->Add(
                    reader["courseID"]->ToString(),
                    reader["courseName"]->ToString(),
                    reader["credits"]->ToString(),
                    reader["semester"]->ToString(),
                    reader["grade"]->ToString()
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading enrollments: " + ex->Message);
        }
    }

    void Enrollment::LoadCourseMaterials(int courseID) {
        try {
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT materialType, title, author, description, isRequired "
                "FROM course_materials "
                "WHERE courseID = @courseID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@courseID", courseID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            gridMaterials->Rows->Clear();
            while (reader->Read()) {
                gridMaterials->Rows->Add(
                    reader["materialType"]->ToString(),
                    reader["title"]->ToString(),
                    reader["author"]->ToString(),
                    reader["description"]->ToString(),
                    Convert::ToBoolean(reader["isRequired"]) ? "Yes" : "No"
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading course materials: " + ex->Message);
        }
    }

    void Enrollment::SetupGridColumns() {
        // Setup Current Enrollments Grid
        dataGridEnrollment->ColumnCount = 5;
        array<String^>^ enrollmentColumns = {
            "Course ID",
            "Course Name",
            "Credits",
            "Semester",
            "Grade"
        };

        for (int i = 0; i < enrollmentColumns->Length; i++) {
            dataGridEnrollment->Columns[i]->Name = enrollmentColumns[i];
            dataGridEnrollment->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
        }

        // Setup Materials Grid
        gridMaterials->ColumnCount = 5;
        array<String^>^ materialColumns = {
            "Material Type",
            "Title",
            "Author",
            "Description",
            "Required"
        };

        for (int i = 0; i < materialColumns->Length; i++) {
            gridMaterials->Columns[i]->Name = materialColumns[i];
            gridMaterials->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
        }

        // Setup Transcript Grid
        gridTranscript->ColumnCount = 6;
        array<String^>^ transcriptColumns = {
            "Course ID",
            "Course Name",
            "Credits",
            "Grade",
            "Semester",
            "Year"
        };

        for (int i = 0; i < transcriptColumns->Length; i++) {
            gridTranscript->Columns[i]->Name = transcriptColumns[i];
            gridTranscript->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
        }
    }

    void Enrollment::EnrollInCourse() {
        if (comboCourses->SelectedIndex == -1) {
            MessageBox::Show("Please select a course to enroll in.");
            return;
        }

        try {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            // First check if already enrolled
            String^ checkQuery = "SELECT COUNT(*) FROM enrollment WHERE studentID = @studentID AND courseID = @courseID";
            MySqlCommand^ checkCmd = gcnew MySqlCommand(checkQuery, conn);
            checkCmd->Parameters->AddWithValue("@studentID", studentID);
            checkCmd->Parameters->AddWithValue("@courseID", courseID);

            int existingEnrollments = Convert::ToInt32(checkCmd->ExecuteScalar());
            if (existingEnrollments > 0) {
                MessageBox::Show("You are already enrolled in this course.");
                dbManager->CloseConnection();
                return;
            }

            // Get semester from selected course
            String^ semesterQuery = "SELECT semester FROM courses WHERE courseID = @courseID";
            MySqlCommand^ semesterCmd = gcnew MySqlCommand(semesterQuery, conn);
            semesterCmd->Parameters->AddWithValue("@courseID", courseID);
            String^ semester = Convert::ToString(semesterCmd->ExecuteScalar());

            // Proceed with enrollment
            String^ enrollQuery = "INSERT INTO enrollment (studentID, courseID, semester) VALUES (@studentID, @courseID, @semester)";
            MySqlCommand^ enrollCmd = gcnew MySqlCommand(enrollQuery, conn);
            enrollCmd->Parameters->AddWithValue("@studentID", studentID);
            enrollCmd->Parameters->AddWithValue("@courseID", courseID);
            enrollCmd->Parameters->AddWithValue("@semester", semester);

            enrollCmd->ExecuteNonQuery();
            MessageBox::Show("Successfully enrolled in the course!");

            dbManager->CloseConnection();

            // Refresh the UI
            LoadAvailableCourses();
            LoadCurrentEnrollments();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error enrolling in course: " + ex->Message);
        }
    }

    void Enrollment::LoadTranscriptData() {
        try {
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.courseID, c.courseName, c.credits, e.grade, e.semester, "
                "YEAR(CURRENT_DATE()) as year "
                "FROM enrollment e "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.studentID = @studentID AND e.grade IS NOT NULL "
                "ORDER BY e.semester, c.courseID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentID", studentID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            gridTranscript->Rows->Clear();
            double totalPoints = 0;
            int totalCredits = 0;

            while (reader->Read()) {
                String^ grade = reader["grade"]->ToString();
                int credits = Convert::ToInt32(reader["credits"]);

                gridTranscript->Rows->Add(
                    reader["courseID"]->ToString(),
                    reader["courseName"]->ToString(),
                    credits.ToString(),
                    grade,
                    reader["semester"]->ToString(),
                    reader["year"]->ToString()
                );

                // Calculate GPA points
                if (!String::IsNullOrEmpty(grade)) {
                    double points = 0;
                    if (grade == "A") points = 4.0;
                    else if (grade == "A-") points = 3.7;
                    else if (grade == "B+") points = 3.3;
                    else if (grade == "B") points = 3.0;
                    else if (grade == "B-") points = 2.7;
                    else if (grade == "C+") points = 2.3;
                    else if (grade == "C") points = 2.0;
                    else if (grade == "C-") points = 1.7;
                    else if (grade == "D+") points = 1.3;
                    else if (grade == "D") points = 1.0;
                    else if (grade == "F") points = 0.0;

                    totalPoints += points * credits;
                    totalCredits += credits;
                }
            }

            // Update GPA display
            double gpa = totalCredits > 0 ? totalPoints / totalCredits : 0.0;
            lblGPA->Text = String::Format("GPA: {0:F2}", gpa);
            lblCreditsEarned->Text = String::Format("Credits Earned: {0}", totalCredits);

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading transcript: " + ex->Message);
        }
    }

    void Enrollment::LoadStudentData() {
        try {
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT u.firstName, u.lastName, s.major, s.enrollmentDate "
                "FROM students s "
                "INNER JOIN users u ON s.userID = u.userID "
                "WHERE s.studentID = @studentID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentID", studentID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                label1->Text = String::Format("{0} {1}",
                    reader["firstName"]->ToString(),
                    reader["lastName"]->ToString());
                txt_admission->Text = "Student ID: STD" + studentID.ToString("D6");
                txt_Department->Text = "Major: " + reader["major"]->ToString();
                txt_Admission_Year->Text = "Enrolled: " + Convert::ToDateTime(reader["enrollmentDate"]).ToString("MMMM yyyy");
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading student data: " + ex->Message);
        }
    }

    System::Void Enrollment::btnEnroll_Click(System::Object^ sender, System::EventArgs^ e) {
        EnrollInCourse();
    }

    System::Void Enrollment::comboCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        if (comboCourses->SelectedIndex != -1) {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());
            LoadCourseMaterials(courseID);
        }
    }

    System::Void Enrollment::Enrollment_Load(System::Object^ sender, System::EventArgs^ e) {
        SetupGridColumns();
        LoadStudentData();
        LoadAvailableCourses();
        LoadCurrentEnrollments();
        LoadTranscriptData();
    }
    void Enrollment::CalculateGPA() {
        try {
            dbManager->ConnectToDatabase();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.credits, e.grade "
                "FROM enrollment e "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.studentID = @studentID AND e.grade IS NOT NULL";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentID", studentID);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            double totalPoints = 0;
            int totalCredits = 0;

            while (reader->Read()) {
                String^ grade = reader["grade"]->ToString();
                int credits = Convert::ToInt32(reader["credits"]);

                if (!String::IsNullOrEmpty(grade)) {
                    double points = 0;
                    if (grade == "A") points = 4.0;
                    else if (grade == "A-") points = 3.7;
                    else if (grade == "B+") points = 3.3;
                    else if (grade == "B") points = 3.0;
                    else if (grade == "B-") points = 2.7;
                    else if (grade == "C+") points = 2.3;
                    else if (grade == "C") points = 2.0;
                    else if (grade == "C-") points = 1.7;
                    else if (grade == "D+") points = 1.3;
                    else if (grade == "D") points = 1.0;
                    else if (grade == "F") points = 0.0;

                    totalPoints += points * credits;
                    totalCredits += credits;
                }
            }

            // Calculate and display GPA
            double gpa = totalCredits > 0 ? totalPoints / totalCredits : 0.0;
            lblGPA->Text = String::Format("GPA: {0:F2}", gpa);
            lblCreditsEarned->Text = String::Format("Credits Earned: {0}", totalCredits);

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error calculating GPA: " + ex->Message);
        }
    }
}