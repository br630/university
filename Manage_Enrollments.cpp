#include "Manage_Enrollments.h"
#include "db_conn.h"

namespace university {
    System::Void Manage_Enrollments::Manage_Enrollments_Load(System::Object^ sender, System::EventArgs^ e) {
        InitializeDataGrids();
        SetupSearchFilters();
        LoadPendingEnrollments();
        LoadEnrollmentHistory();
    }

    void Manage_Enrollments::InitializeDataGrids() {
        // Configure Pending DataGrid
        dataGridPending->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
        dataGridPending->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dataGridPending->MultiSelect = false;
        dataGridPending->AllowUserToAddRows = false;
        dataGridPending->ReadOnly = true;

        // Configure History DataGrid
        dataGridHistory->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
        dataGridHistory->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dataGridHistory->MultiSelect = false;
        dataGridHistory->AllowUserToAddRows = false;
        dataGridHistory->ReadOnly = true;
    }

    void Manage_Enrollments::LoadPendingEnrollments() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ sql = "SELECT e.enrollmentID, u.firstName, u.lastName, c.courseName, "
                "e.semester, e.academic_year, e.enrollment_date "
                "FROM enrollments_new e "
                "INNER JOIN students s ON e.studentID = s.studentID "
                "INNER JOIN users u ON s.userID = u.userID "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.status = 'Pending' AND c.DepartmentID = ("
                "SELECT DepartmentID FROM faculty WHERE facultyID = @facultyId)";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
            cmd->Parameters->AddWithValue("@facultyId", facultyId);

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ table = gcnew DataTable();
            adapter->Fill(table);
            dataGridPending->DataSource = table;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading pending enrollments: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Manage_Enrollments::LoadEnrollmentHistory() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ sql = "SELECT e.enrollmentID, u.firstName, u.lastName, c.courseName, "
                "e.semester, e.academic_year, e.status, e.assignedBy, e.enrollment_date "
                "FROM enrollments_new e "
                "INNER JOIN students s ON e.studentID = s.studentID "
                "INNER JOIN users u ON s.userID = u.userID "
                "INNER JOIN courses c ON e.courseID = c.courseID "
                "WHERE e.status IN ('Enrolled', 'Rejected') "
                "AND e.assignedBy = @facultyId "
                "ORDER BY e.enrollment_date DESC";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
            cmd->Parameters->AddWithValue("@facultyId", facultyId);

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ table = gcnew DataTable();
            adapter->Fill(table);
            dataGridHistory->DataSource = table;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading enrollment history: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Manage_Enrollments::HandleApproval(bool isApproved) {
        if (dataGridPending->SelectedRows->Count == 0) {
            MessageBox::Show("Please select an enrollment to process.");
            return;
        }

        try {
            int enrollmentId = Convert::ToInt32(dataGridPending->SelectedRows[0]->Cells["enrollmentID"]->Value);
            String^ newStatus = isApproved ? "Enrolled" : "Rejected";

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            String^ sql = "UPDATE enrollments_new SET status = @status, assignedBy = @facultyId "
                "WHERE enrollmentID = @enrollmentId";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
            cmd->Parameters->AddWithValue("@status", newStatus);
            cmd->Parameters->AddWithValue("@facultyId", facultyId);
            cmd->Parameters->AddWithValue("@enrollmentId", enrollmentId);

            cmd->ExecuteNonQuery();
            MessageBox::Show("Enrollment " + (isApproved ? "approved" : "rejected") + " successfully.");

            RefreshData();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error processing enrollment: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    void Manage_Enrollments::RefreshData() {
        LoadPendingEnrollments();
        LoadEnrollmentHistory();
    }

    void Manage_Enrollments::SetupSearchFilters() {
        cmbSemester->Items->Add("All Semesters");
        cmbSemester->Items->Add("Semester1");
        cmbSemester->Items->Add("Semester2");
        cmbSemester->SelectedIndex = 0;

        cmbYear->Items->Add("All Years");
        cmbYear->Items->Add("Year1");
        cmbYear->Items->Add("Year2");
        cmbYear->Items->Add("Year3");
        cmbYear->Items->Add("Year4");
        cmbYear->SelectedIndex = 0;
    }

    System::Void Manage_Enrollments::btnApprove_Click(System::Object^ sender, System::EventArgs^ e) {
        HandleApproval(true);
    }

    System::Void Manage_Enrollments::btnReject_Click(System::Object^ sender, System::EventArgs^ e) {
        HandleApproval(false);
    }

    System::Void Manage_Enrollments::btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
        RefreshData();
    }

    System::Void Manage_Enrollments::txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        DataTable^ dt = safe_cast<DataTable^>(dataGridPending->DataSource);
        if (dt != nullptr) {
            dt->DefaultView->RowFilter = String::Format("courseName LIKE '%{0}%' OR firstName LIKE '%{0}%' OR lastName LIKE '%{0}%'",
                txtSearch->Text);
        }
    }

    System::Void Manage_Enrollments::cmbSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        LoadPendingEnrollments();
    }

    System::Void Manage_Enrollments::cmbYear_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        LoadPendingEnrollments();
    }

    System::Void Manage_Enrollments::dataGridPending_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            btnApprove->Enabled = true;
            btnReject->Enabled = true;
        }
    }
}