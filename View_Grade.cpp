#include "View_Grade.h"
#include "db_conn.h"

namespace university {
    void View_Grade::Form_Load(System::Object^ sender, System::EventArgs^ e) {
        cmbSemester->SelectedIndex = 0; // "All"
        cmbYear->SelectedIndex = 0;     // "All"
        LoadGrades();
        CalculateGPA();
        CalculateTotalCredits();
    }

    void View_Grade::LoadGrades() {
        try {
            String^ query = "SELECT c.courseName, c.credits, e.semester, c.course_yr, "
                "e.grade, e.status, e.enrollment_date "
                "FROM enrollments e "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.studentID = @studentId "
                "AND e.status IN ('Completed', 'Failed')";

            // Add filters if selected
            if (cmbSemester->SelectedIndex > 0) { // Not "All"
                query += " AND e.semester = @semester";
            }
            if (cmbYear->SelectedIndex > 0) { // Not "All"
                query += " AND c.course_yr = @year";
            }

            query += " ORDER BY e.enrollment_date DESC";

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentId", studentId);

            if (cmbSemester->SelectedIndex > 0) {
                cmd->Parameters->AddWithValue("@semester", cmbSemester->Text);
            }
            if (cmbYear->SelectedIndex > 0) {
                cmd->Parameters->AddWithValue("@year", cmbYear->Text);
            }

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ table = gcnew DataTable();
            adapter->Fill(table);

            // Format the columns
            if (table->Columns->Contains("courseName"))
                table->Columns["courseName"]->ColumnName = "Course";
            if (table->Columns->Contains("credits"))
                table->Columns["credits"]->ColumnName = "Credits";
            if (table->Columns->Contains("semester"))
                table->Columns["semester"]->ColumnName = "Semester";
            if (table->Columns->Contains("course_yr"))
                table->Columns["course_yr"]->ColumnName = "Year";
            if (table->Columns->Contains("grade"))
                table->Columns["grade"]->ColumnName = "Grade";
            if (table->Columns->Contains("status"))
                table->Columns["status"]->ColumnName = "Status";
            if (table->Columns->Contains("enrollment_date"))
                table->Columns["enrollment_date"]->ColumnName = "Completion Date";

            dgvGrades->DataSource = table;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading grades: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void View_Grade::CalculateGPA() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ query = "SELECT AVG(e.grade) as gpa "
                "FROM enrollments e "
                "WHERE e.studentID = @studentId "
                "AND e.status = 'Completed'";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentId", studentId);

            Object^ result = cmd->ExecuteScalar();
            if (result != DBNull::Value) {
                double gpa = Convert::ToDouble(result);
                lblGPA->Text = String::Format("Cumulative GPA: {0:F2}", gpa);
            }
            else {
                lblGPA->Text = "Cumulative GPA: N/A";
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error calculating GPA: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void View_Grade::CalculateTotalCredits() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ query = "SELECT SUM(c.credits) as totalCredits "
                "FROM enrollments e "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.studentID = @studentId "
                "AND e.status = 'Completed'";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentId", studentId);

            Object^ result = cmd->ExecuteScalar();
            if (result != DBNull::Value) {
                int totalCredits = Convert::ToInt32(result);
                lblCredits->Text = String::Format("Total Credits: {0}", totalCredits);
            }
            else {
                lblCredits->Text = "Total Credits: 0";
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error calculating total credits: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void View_Grade::FilterGrades(System::Object^ sender, System::EventArgs^ e) {
        LoadGrades();
    }

    void View_Grade::SearchGrades(System::Object^ sender, System::EventArgs^ e) {
        if (dgvGrades->DataSource) {
            DataTable^ dt = safe_cast<DataTable^>(dgvGrades->DataSource);
            if (String::IsNullOrWhiteSpace(txtSearch->Text)) {
                dt->DefaultView->RowFilter = "";
            }
            else {
                dt->DefaultView->RowFilter = String::Format("Course LIKE '%{0}%'",
                    txtSearch->Text->Replace("'", "''"));
            }
        }
    }
}