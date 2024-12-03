#include "Generate_Report.h"
#include "db_conn.h"
#include <exception>
using namespace System::IO;

namespace university {
    void Generate_Report::Form_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadStudentData();
        LoadFacultyData();
    }

    void Generate_Report::LoadStudentData() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ query = "SELECT s.studentID, CONCAT(u.firstName, ' ', u.lastName) as StudentName, "
                "s.major, s.currentYR as Year, "
                "(SELECT COUNT(*) * 3 FROM enrollments e "  // Assuming each course is 3 credits
                "WHERE e.studentID = s.studentID AND e.status = 'Completed') as TotalCredits, "
                "(SELECT AVG(grade) FROM enrollments e "
                "WHERE e.studentID = s.studentID AND e.status = 'Completed') as GPA "
                "FROM students s "
                "INNER JOIN users u ON s.userID = u.userID "
                "ORDER BY s.studentID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ table = gcnew DataTable();
            adapter->Fill(table);

            // Format columns
            if (table->Columns->Contains("studentID"))
                table->Columns["studentID"]->ColumnName = "Student ID";
            if (table->Columns->Contains("StudentName"))
                table->Columns["StudentName"]->ColumnName = "Student Name";
            if (table->Columns->Contains("major"))
                table->Columns["major"]->ColumnName = "Major";
            if (table->Columns->Contains("Year"))
                table->Columns["Year"]->ColumnName = "Current Year";
            if (table->Columns->Contains("TotalCredits"))
                table->Columns["TotalCredits"]->ColumnName = "Total Credits";
            if (table->Columns->Contains("GPA"))
                table->Columns["GPA"]->ColumnName = "GPA";

            dgvStudents->DataSource = table;

            // Format GPA column to show 2 decimal places
            if (dgvStudents->Columns["GPA"] != nullptr) {
                dgvStudents->Columns["GPA"]->DefaultCellStyle->Format = "N2";
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading student data: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Generate_Report::LoadFacultyData() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ query = "SELECT f.facultyID, CONCAT(u.firstName, ' ', u.lastName) as FacultyName, "
                "f.department, "
                "CASE WHEN d.HeadOfDepartment = f.facultyID THEN 'Yes' ELSE 'No' END as isDeptHead "
                "FROM faculty f "
                "INNER JOIN users u ON f.userID = u.userID "
                "LEFT JOIN departments d ON f.department = d.DepartmentName "
                "ORDER BY f.facultyID";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ table = gcnew DataTable();
            adapter->Fill(table);

            // Format columns
            if (table->Columns->Contains("facultyID"))
                table->Columns["facultyID"]->ColumnName = "Faculty ID";
            if (table->Columns->Contains("FacultyName"))
                table->Columns["FacultyName"]->ColumnName = "Faculty Name";
            if (table->Columns->Contains("department"))
                table->Columns["department"]->ColumnName = "Department";
            if (table->Columns->Contains("isDeptHead"))
                table->Columns["isDeptHead"]->ColumnName = "Department Head";

            dgvFaculty->DataSource = table;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading faculty data: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Generate_Report::FilterStudents(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (dgvStudents->DataSource) {
                DataTable^ dt = safe_cast<DataTable^>(dgvStudents->DataSource);
                String^ searchText = txtStudentSearch->Text;

                if (String::IsNullOrWhiteSpace(searchText)) {
                    dt->DefaultView->RowFilter = "";
                }
                else {
                    // Search across multiple columns
                    dt->DefaultView->RowFilter = String::Format("([Student Name] LIKE '%{0}%' OR "
                        "[Student ID] LIKE '%{0}%' OR "
                        "Major LIKE '%{0}%')",
                        searchText->Replace("'", "''"));
                }
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error filtering student data: " + ex->Message);
        }
    }

    void Generate_Report::FilterFaculty(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (dgvFaculty->DataSource) {
                DataTable^ dt = safe_cast<DataTable^>(dgvFaculty->DataSource);
                String^ searchText = txtFacultySearch->Text;

                if (String::IsNullOrWhiteSpace(searchText)) {
                    dt->DefaultView->RowFilter = "";
                }
                else {
                    // Search across multiple columns
                    dt->DefaultView->RowFilter = String::Format("([Faculty Name] LIKE '%{0}%' OR "
                        "[Faculty ID] LIKE '%{0}%' OR "
                        "Department LIKE '%{0}%')",
                        searchText->Replace("'", "''"));
                }
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error filtering faculty data: " + ex->Message);
        }
    }

    void Generate_Report::ExportToExcel(DataGridView^ dgv, String^ filePath) {
        try {
            StreamWriter^ sw = gcnew StreamWriter(filePath);

            // Write headers
            for (int i = 0; i < dgv->Columns->Count; i++) {
                sw->Write(dgv->Columns[i]->HeaderText);
                if (i < dgv->Columns->Count - 1)
                    sw->Write(",");
            }
            sw->WriteLine();

            // Write data
            for (int i = 0; i < dgv->Rows->Count; i++) {
                for (int j = 0; j < dgv->Columns->Count; j++) {
                    if (dgv->Rows[i]->Cells[j]->Value != nullptr) {
                        String^ value = dgv->Rows[i]->Cells[j]->Value->ToString();
                        // Escape commas in the value
                        if (value->Contains(","))
                            value = "\"" + value + "\"";
                        sw->Write(value);
                    }
                    if (j < dgv->Columns->Count - 1)
                        sw->Write(",");
                }
                sw->WriteLine();
            }

            sw->Close();
            MessageBox::Show("Report exported successfully!");
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error exporting data: " + ex->Message);
        }
    }

    void Generate_Report::ExportStudents(System::Object^ sender, System::EventArgs^ e) {
        if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            ExportToExcel(dgvStudents, saveFileDialog1->FileName);
        }
    }

    void Generate_Report::ExportFaculty(System::Object^ sender, System::EventArgs^ e) {
        if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            ExportToExcel(dgvFaculty, saveFileDialog1->FileName);
        }
    }
}