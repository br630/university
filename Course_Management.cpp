#include "Course_Management.h"
#include "db_conn.h"

namespace university {
    ref class ComboboxItem {
    public:
        String^ Text;
        String^ Value;

        ComboboxItem(String^ text, String^ value) {
            Text = text;
            Value = value;
        }

        virtual String^ ToString() override {
            return Text;
        }
    };
    void Course_Management::LoadDepartments() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT DepartmentID, DepartmentName FROM departments ORDER BY DepartmentName";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            comboDepartment->Items->Clear();
            comboDepartment->Items->Add(gcnew ComboboxItem("-- Select Department --", "0"));

            while (reader->Read()) {
                String^ deptName = reader["DepartmentName"]->ToString();
                String^ deptId = reader["DepartmentID"]->ToString();
                comboDepartment->Items->Add(gcnew ComboboxItem(deptName, deptId));
            }

            comboDepartment->SelectedIndex = 0;
            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading departments: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }


    // Modify Form_Load:
    System::Void Course_Management::Course_Management_Load(System::Object^ sender, System::EventArgs^ e) {
        comboSemester->Items->Add("Semester1");
        comboSemester->Items->Add("Semester2");
        comboSemester->SelectedIndex = 0;

        LoadDepartments();
        SetupDataGridView();
        LoadCourses();
    }

    // Add department validation in ValidateInput:
    bool Course_Management::ValidateInput() {
        if (String::IsNullOrWhiteSpace(txtCourseName->Text)) {
            MessageBox::Show("Please enter a course name.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }
        if (comboDepartment->SelectedIndex == 0) {
            MessageBox::Show("Please select a department.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }
        return true;
    }

    // Update ClearForm:
    void Course_Management::ClearForm() {
        txtCourseID->Clear();
        txtCourseName->Clear();
        numCredits->Value = numCredits->Minimum;
        comboSemester->SelectedIndex = 0;
        chkAvailability->Checked = true;
        comboDepartment->SelectedIndex = 0;
    }


    void Course_Management::SetupDataGridView() {
        dataGridCourses->AutoGenerateColumns = false;
        dataGridCourses->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dataGridCourses->Columns->Clear();

        array<String^>^ columns = {
            "CourseID", "CourseName", "Credits", "Semester", "Department", "Available"
        };

        for each (String ^ col in columns) {
            DataGridViewColumn^ column = gcnew DataGridViewTextBoxColumn();
            column->HeaderText = col;
            column->Name = col;
            column->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            dataGridCourses->Columns->Add(column);
        }
    }

    void Course_Management::LoadCourses() {
        MySqlDataReader^ reader = nullptr;
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.*, d.DepartmentName FROM courses c "
                "JOIN departments d ON c.DepartmentID = d.DepartmentID";


            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            dbManager->ConnectToDatabase();
            reader = cmd->ExecuteReader();
            dataGridCourses->Rows->Clear();

            while (reader->Read()) {
                dataGridCourses->Rows->Add(
                    reader["courseID"]->ToString(),
                    reader["courseName"]->ToString(),
                    reader["credits"]->ToString(),
                    reader["semester"]->ToString(),
                    reader["DepartmentName"]->ToString(),
                    Convert::ToBoolean(reader["availability"]) ? "Yes" : "No"
                );
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

    System::Void Course_Management::btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput()) return;

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "INSERT INTO courses (courseName, credits, semester, DepartmentID, availability) "
                "VALUES (@name, @credits, @semester, @deptId, @available)";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            ComboboxItem^ selectedDept = safe_cast<ComboboxItem^>(comboDepartment->SelectedItem);
            cmd->Parameters->AddWithValue("@name", txtCourseName->Text);
            cmd->Parameters->AddWithValue("@credits", Convert::ToInt32(numCredits->Value));
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);
            cmd->Parameters->AddWithValue("@available", chkAvailability->Checked);
            cmd->Parameters->AddWithValue("@deptId", Convert::ToInt32(selectedDept->Value));

            dbManager->ConnectToDatabase();
            cmd->ExecuteNonQuery();
            dbManager->CloseConnection();

            MessageBox::Show("Course added successfully!");
            LoadCourses();
            ClearForm();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error adding course: " + ex->Message);
        }
    }


    System::Void Course_Management::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput() || String::IsNullOrEmpty(txtCourseID->Text)) return;

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "UPDATE courses SET courseName=@name, credits=@credits, "
                "semester=@semester, DepartmentID=@deptId, availability=@available WHERE courseID=@id";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            ComboboxItem^ selectedDept = safe_cast<ComboboxItem^>(comboDepartment->SelectedItem);
            cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtCourseID->Text));
            cmd->Parameters->AddWithValue("@name", txtCourseName->Text);
            cmd->Parameters->AddWithValue("@credits", Convert::ToInt32(numCredits->Value));
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);
            cmd->Parameters->AddWithValue("@deptId", Convert::ToInt32(selectedDept->Value));
            cmd->Parameters->AddWithValue("@available", chkAvailability->Checked);

            dbManager->ConnectToDatabase();
            cmd->ExecuteNonQuery();
            dbManager->CloseConnection();

            MessageBox::Show("Course updated successfully!");
            LoadCourses();
            ClearForm();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating course: " + ex->Message);
        }
    }


    System::Void Course_Management::btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (String::IsNullOrEmpty(txtCourseID->Text)) return;

            if (MessageBox::Show("Are you sure you want to delete this course?", "Confirm Delete",
                MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) {

                DatabaseManager^ dbManager = DatabaseManager::GetInstance();
                MySqlConnection^ conn = dbManager->GetConnection();

                String^ query = "DELETE FROM courses WHERE courseID=@id";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

                cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtCourseID->Text));

                dbManager->ConnectToDatabase();
                cmd->ExecuteNonQuery();
                dbManager->CloseConnection();

                MessageBox::Show("Course deleted successfully!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);

                LoadCourses();
                ClearForm();
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error deleting course: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void Course_Management::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ searchText = txtSearch->Text;
            String^ query = "SELECT * FROM courses WHERE courseName LIKE @search";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@search", "%" + searchText + "%");

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridCourses->Rows->Clear();

            while (reader->Read()) {
                dataGridCourses->Rows->Add(
                    reader["courseID"]->ToString(),
                    reader["courseName"]->ToString(),
                    reader["credits"]->ToString(),
                    reader["semester"]->ToString()
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error searching courses: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void Course_Management::btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
        ClearForm();
    }


    System::Void Course_Management::dataGridCourses_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            txtCourseID->Text = dataGridCourses->Rows[e->RowIndex]->Cells["CourseID"]->Value->ToString();
            txtCourseName->Text = dataGridCourses->Rows[e->RowIndex]->Cells["CourseName"]->Value->ToString();
            numCredits->Value = Convert::ToDecimal(dataGridCourses->Rows[e->RowIndex]->Cells["Credits"]->Value);
            comboSemester->Text = dataGridCourses->Rows[e->RowIndex]->Cells["Semester"]->Value->ToString();
            chkAvailability->Checked = dataGridCourses->Rows[e->RowIndex]->Cells["Available"]->Value->ToString() == "Yes";

            String^ deptName = dataGridCourses->Rows[e->RowIndex]->Cells["Department"]->Value->ToString();
            for (int i = 0; i < comboDepartment->Items->Count; i++) {
                ComboboxItem^ item = safe_cast<ComboboxItem^>(comboDepartment->Items[i]);
                if (item->Text == deptName) {
                    comboDepartment->SelectedIndex = i;
                    break;
                }
            }
        }
    }
}