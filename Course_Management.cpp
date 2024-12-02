#include "Course_Management.h"
#include "db_conn.h"

namespace university {
    System::Void Course_Management::Course_Management_Load(System::Object^ sender, System::EventArgs^ e) {
        // Setup semester combo box
        comboSemester->Items->Add("Semester1");
        comboSemester->Items->Add("Semester2");
        comboSemester->SelectedIndex = 0;

        SetupDataGridView();
        // Load courses
        LoadCourses();
    }

    void Course_Management::SetupDataGridView() {
        dataGridCourses->AutoGenerateColumns = false;
        dataGridCourses->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

        // Clear existing columns
        dataGridCourses->Columns->Clear();

        // Add columns
        dataGridCourses->Columns->Add("CourseID", "Course ID");
        dataGridCourses->Columns->Add("CourseName", "Course Name");
        dataGridCourses->Columns->Add("Credits", "Credits");
        dataGridCourses->Columns->Add("Semester", "Semester");

        // Set column properties
        for each (DataGridViewColumn ^ column in dataGridCourses->Columns) {
            column->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
        }

        // Event handler for cell click
        dataGridCourses->CellClick += gcnew DataGridViewCellEventHandler(this, &Course_Management::dataGridCourses_CellClick);
    }

    void Course_Management::LoadCourses() {
        MySqlDataReader^ reader = nullptr;
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT * FROM courses";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            dbManager->ConnectToDatabase();
            reader = cmd->ExecuteReader();

            dataGridCourses->Rows->Clear();

            while (reader->Read()) {
                dataGridCourses->Rows->Add(
                    reader["courseID"]->ToString(),
                    reader["courseName"]->ToString(),
                    reader["credits"]->ToString(),
                    reader["semester"]->ToString()
                );
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading courses: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
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

            String^ query = "INSERT INTO courses (courseName, credits, semester) VALUES (@name, @credits, @semester)";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@name", txtCourseName->Text);
            cmd->Parameters->AddWithValue("@credits", Convert::ToInt32(numCredits->Value));
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            dbManager->ConnectToDatabase();
            cmd->ExecuteNonQuery();
            dbManager->CloseConnection();

            MessageBox::Show("Course added successfully!", "Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            LoadCourses();
            ClearForm();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error adding course: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void Course_Management::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput() || String::IsNullOrEmpty(txtCourseID->Text)) return;

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "UPDATE courses SET courseName=@name, credits=@credits, semester=@semester WHERE courseID=@id";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtCourseID->Text));
            cmd->Parameters->AddWithValue("@name", txtCourseName->Text);
            cmd->Parameters->AddWithValue("@credits", Convert::ToInt32(numCredits->Value));
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            dbManager->ConnectToDatabase();
            cmd->ExecuteNonQuery();
            dbManager->CloseConnection();

            MessageBox::Show("Course updated successfully!", "Success",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            LoadCourses();
            ClearForm();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating course: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
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

    void Course_Management::ClearForm() {
        txtCourseID->Clear();
        txtCourseName->Clear();
        numCredits->Value = numCredits->Minimum;
        comboSemester->SelectedIndex = 0;
    }

    bool Course_Management::ValidateInput() {
        if (String::IsNullOrWhiteSpace(txtCourseName->Text)) {
            MessageBox::Show("Please enter a course name.", "Validation Error",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return false;
        }
        return true;
    }

    System::Void Course_Management::dataGridCourses_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            txtCourseID->Text = dataGridCourses->Rows[e->RowIndex]->Cells["CourseID"]->Value->ToString();
            txtCourseName->Text = dataGridCourses->Rows[e->RowIndex]->Cells["CourseName"]->Value->ToString();
            numCredits->Value = Convert::ToDecimal(dataGridCourses->Rows[e->RowIndex]->Cells["Credits"]->Value);
            comboSemester->Text = dataGridCourses->Rows[e->RowIndex]->Cells["Semester"]->Value->ToString();
        }
    }
}