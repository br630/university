#include "Register_Course.h"
#include "db_conn.h"
#include <string>

namespace university {
    System::Void Register_Course::Register_Course_Load(System::Object^ sender, System::EventArgs^ e) {
        comboBox2->Items->Add("Year1");
        comboBox2->Items->Add("Year2");
        comboBox2->Items->Add("Year3");
        comboBox2->Items->Add("Year4");
        comboBox2->SelectedIndex = 0;
        LoadAvailableCourses();
    }

    void Register_Course::LoadAvailableCourses() {
        MySqlDataReader^ reader = nullptr;
        try {
            for each (Control ^ control in this->Controls) {
                if (Button^ btn = dynamic_cast<Button^>(control)) {
                    if (btn != nullptr && btn->Name->StartsWith("courseBtn_")) {
                        this->Controls->Remove(btn);
                        delete btn;
                    }
                }
            }

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ sql = "SELECT c.courseID, c.courseName FROM courses c "
                "LEFT JOIN enrollments_new e ON c.courseID = e.courseID AND e.studentID = @studentID "
                "WHERE (e.studentID IS NULL OR e.Status = 'Rejected') "
                "AND c.semester = @semester "
                "AND c.course_yr = @year";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
            cmd->Parameters->AddWithValue("@studentID", studentId);
            cmd->Parameters->AddWithValue("@semester", comboBox1->Text);
            cmd->Parameters->AddWithValue("@year", comboBox2->Text);

            dbManager->ConnectToDatabase();
            reader = cmd->ExecuteReader();

            int buttonXPosition = 226;
            int buttonYPosition = 152;
            int buttonWidth = 280;
            int buttonHeight = 53;
            int horizontalSpacing = 387;
            int verticalSpacing = 280;
            int buttonCount = 0;

            while (reader->Read()) {
                Button^ courseButton = gcnew Button();
                int courseId = reader->GetInt32("courseID");
                String^ courseName = reader->GetString("courseName");

                int row = buttonCount / 3;
                int col = buttonCount % 3;
                int xPos = buttonXPosition + (col * horizontalSpacing);
                int yPos = buttonYPosition + (row * verticalSpacing);

                courseButton->Location = System::Drawing::Point(xPos, yPos);
                courseButton->Name = "courseBtn_" + courseId;
                courseButton->Size = System::Drawing::Size(buttonWidth, buttonHeight);
                courseButton->Text = courseName;
                courseButton->Tag = courseId;
                courseButton->UseVisualStyleBackColor = true;
                courseButton->Click += gcnew System::EventHandler(this, &Register_Course::Course_Button_Click);

                this->Controls->Add(courseButton);
                buttonCount++;
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading courses: " + ex->Message);
        }
        finally {
            if (reader != nullptr) reader->Close();
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    bool Register_Course::HasCompletedPrerequisites(int courseId) {
        MySqlDataReader^ reader = nullptr;
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ sql = "SELECT prerequisiteID FROM course_prerequisites WHERE courseID = @courseId";
            MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
            cmd->Parameters->AddWithValue("@courseId", courseId);

            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int prerequisiteId = reader->GetInt32(0);
                reader->Close();

                sql = "SELECT COUNT(*) FROM enrollments_new "
                    "WHERE studentID = @studentId AND courseID = @prerequisiteId "
                    "AND Status = 'Completed' AND Grade >= 50";

                cmd = gcnew MySqlCommand(sql, conn);
                cmd->Parameters->AddWithValue("@studentId", studentId);
                cmd->Parameters->AddWithValue("@prerequisiteId", prerequisiteId);

                int completed = Convert::ToInt32(cmd->ExecuteScalar());
                if (completed == 0) return false;
            }
            return true;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error checking prerequisites: " + ex->Message);
            return false;
        }
        finally {
            if (reader != nullptr) reader->Close();
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    bool Register_Course::IsAlreadyEnrolled(int courseId) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ sql = "SELECT COUNT(*) FROM enrollments_new "
                "WHERE studentID = @studentId AND courseID = @courseId "
                "AND Status IN ('Pending', 'Enrolled', 'Completed')";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
            cmd->Parameters->AddWithValue("@studentId", studentId);
            cmd->Parameters->AddWithValue("@courseId", courseId);

            dbManager->ConnectToDatabase();
            int count = Convert::ToInt32(cmd->ExecuteScalar());

            return count > 0;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error checking enrollment: " + ex->Message);
            return true;
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Register_Course::RegisterForCourse(int courseId, String^ courseName) {
        if (String::IsNullOrEmpty(comboBox1->Text)) {
            MessageBox::Show("Please select a semester first.");
            return;
        }

        try {
            if (IsAlreadyEnrolled(courseId)) {
                MessageBox::Show("You already have a pending or active enrollment for this course.");
                return;
            }

            if (!HasCompletedPrerequisites(courseId)) {
                MessageBox::Show("You must complete all prerequisites before enrolling in this course.");
                return;
            }

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ sql = "INSERT INTO enrollments_new (studentID, courseID, semester, academic_year, status, enrollment_date) "
                "VALUES (@studentId, @courseId, @semester, @academicYear, 'Pending', NOW())";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
            cmd->Parameters->AddWithValue("@studentId", studentId);
            cmd->Parameters->AddWithValue("@courseId", courseId);
            cmd->Parameters->AddWithValue("@semester", comboBox1->Text);
            cmd->Parameters->AddWithValue("@academicYear", comboBox2->Text);

            cmd->ExecuteNonQuery();

            MessageBox::Show("Enrollment request submitted for " + courseName + ". Waiting for approval.");
            LoadAvailableCourses();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error submitting enrollment request: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Register_Course::LoadCurrentEnrollments() {
        MySqlDataReader^ reader = nullptr;
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ sql = "SELECT c.courseName, e.semester, e.Status, e.Grade "
                "FROM enrollments_new e "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.studentID = @studentId";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
            cmd->Parameters->AddWithValue("@studentId", studentId);

            dbManager->ConnectToDatabase();
            reader = cmd->ExecuteReader();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading enrollments: " + ex->Message);
        }
        finally {
            if (reader != nullptr) reader->Close();
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Register_Course::Course_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        Button^ clickedButton = safe_cast<Button^>(sender);
        if (clickedButton->Tag != nullptr) {
            int courseId = safe_cast<int>(clickedButton->Tag);
            RegisterForCourse(courseId, clickedButton->Text);
        }
    }

    System::Void Register_Course::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ searchTerm = textBox1->Text->ToLower();
        for each (Control ^ control in this->Controls) {
            if (Button^ btn = dynamic_cast<Button^>(control)) {
                if (btn->Name->StartsWith("courseBtn_")) {
                    btn->Visible = btn->Text->ToLower()->Contains(searchTerm);
                }
            }
        }
    }

    System::Void Register_Course::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        LoadAvailableCourses();
    }
}