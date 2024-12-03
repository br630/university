#include "Course_Management.h"
#include "db_conn.h"

namespace university {
    // Helper class for ComboBox items
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

    System::Void Course_Management::Course_Management_Load(System::Object^ sender, System::EventArgs^ e) {
        comboSemester->Items->Add("Semester1");
        comboSemester->Items->Add("Semester2");
        comboSemester->SelectedIndex = 0;

        LoadDepartments();
        LoadCoursePrerequisites();
        SetupDataGridView();
        LoadCourses();
    }

    // Update ClearForm:
    void Course_Management::ClearForm() {
        txtCourseID->Clear();
        txtCourseName->Clear();
        numCredits->Value = numCredits->Minimum;
        comboSemester->SelectedIndex = 0;
        chkAvailability->Checked = true;
        comboDepartment->SelectedIndex = 0;
        comboYear->SelectedIndex = 0;
    }

    System::Void Course_Management::btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
        ClearForm();
    }

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
            MessageBox::Show("Error loading departments: " + ex->Message);
        }
    }

    void Course_Management::LoadCoursePrerequisites() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.courseID, c.courseName FROM courses c WHERE c.courseID != @currentCourse";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);

            if (!String::IsNullOrEmpty(txtCourseID->Text)) {
                cmd->Parameters->AddWithValue("@currentCourse", Convert::ToInt32(txtCourseID->Text));
            }
            else {
                cmd->Parameters->AddWithValue("@currentCourse", 0);
            }

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            comboPrerequisites->Items->Clear();
            comboPrerequisites->Items->Add(gcnew ComboboxItem("-- Select Prerequisite --", "0"));

            while (reader->Read()) {
                String^ courseName = reader["courseName"]->ToString();
                String^ courseId = reader["courseID"]->ToString();
                comboPrerequisites->Items->Add(gcnew ComboboxItem(courseName, courseId));
            }

            comboPrerequisites->SelectedIndex = 0;
            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading prerequisites: " + ex->Message);
        }
    }

    void Course_Management::LoadCoursePrerequisitesList(int courseId) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.courseID, c.courseName FROM courses c "
                "JOIN course_prerequisites p ON c.courseID = p.prerequisiteID "
                "WHERE p.courseID = @courseId";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@courseId", courseId);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            listPrerequisites->Items->Clear();

            while (reader->Read()) {
                String^ courseName = reader["courseName"]->ToString();
                String^ courseId = reader["courseID"]->ToString();
                listPrerequisites->Items->Add(gcnew ComboboxItem(courseName, courseId));
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading prerequisites list: " + ex->Message);
        }
    }

    void Course_Management::SetupDataGridView() {
        dataGridCourses->AutoGenerateColumns = false;
        dataGridCourses->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dataGridCourses->Columns->Clear();

        array<String^>^ columns = {
            "CourseID", "CourseName", "Credits", "Semester", "Department", "Available", "Prerequisites"
        };

        for each (String ^ col in columns) {
            DataGridViewColumn^ column = gcnew DataGridViewTextBoxColumn();
            column->HeaderText = col;
            column->Name = col;
            column->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
            dataGridCourses->Columns->Add(column);
        }
    }

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


    void Course_Management::LoadCourses() {
        MySqlDataReader^ reader = nullptr;
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.*, d.DepartmentName, c.course_yr, "
                "(SELECT GROUP_CONCAT(p.courseName) FROM course_prerequisites cp "
                "JOIN courses p ON cp.prerequisiteID = p.courseID "
                "WHERE cp.courseID = c.courseID) as prerequisites "
                "FROM courses c JOIN departments d ON c.DepartmentID = d.DepartmentID";

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
                    Convert::ToBoolean(reader["availability"]) ? "Yes" : "No",
                    reader->IsDBNull(reader->GetOrdinal("prerequisites")) ?
                    "None" : reader["prerequisites"]->ToString()
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

    void Course_Management::SavePrerequisites(int courseId) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            dbManager->ConnectToDatabase();
            MySqlTransaction^ transaction = conn->BeginTransaction();

            try {
                // Delete existing prerequisites
                String^ deleteQuery = "DELETE FROM course_prerequisites WHERE courseID = @courseId";
                MySqlCommand^ deleteCmd = gcnew MySqlCommand(deleteQuery, conn);
                deleteCmd->Transaction = transaction;
                deleteCmd->Parameters->AddWithValue("@courseId", courseId);
                deleteCmd->ExecuteNonQuery();

                // Insert new prerequisites
                if (listPrerequisites->Items->Count > 0) {
                    String^ insertQuery = "INSERT INTO course_prerequisites (courseID, prerequisiteID) VALUES (@courseId, @prereqId)";
                    MySqlCommand^ insertCmd = gcnew MySqlCommand(insertQuery, conn);
                    insertCmd->Transaction = transaction;

                    for each (ComboboxItem ^ item in listPrerequisites->Items) {
                        insertCmd->Parameters->Clear();
                        insertCmd->Parameters->AddWithValue("@courseId", courseId);
                        insertCmd->Parameters->AddWithValue("@prereqId", Convert::ToInt32(item->Value));
                        insertCmd->ExecuteNonQuery();
                    }
                }

                transaction->Commit();
            }
            catch (Exception^ ex) {
                transaction->Rollback();
                throw ex;
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error saving prerequisites: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Course_Management::btnAddPrerequisite_Click(System::Object^ sender, System::EventArgs^ e) {
        ComboboxItem^ selectedCourse = safe_cast<ComboboxItem^>(comboPrerequisites->SelectedItem);
        if (selectedCourse->Value == "0") return;

        // Check if already added
        for each (ComboboxItem ^ item in listPrerequisites->Items) {
            if (item->Value == selectedCourse->Value) return;
        }

        listPrerequisites->Items->Add(selectedCourse);
        comboPrerequisites->SelectedIndex = 0;
    }

    System::Void Course_Management::btnRemovePrerequisite_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listPrerequisites->SelectedIndex != -1) {
            listPrerequisites->Items->RemoveAt(listPrerequisites->SelectedIndex);
        }
    }

    System::Void Course_Management::btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput()) return;

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            // Start transaction
            MySqlTransaction^ transaction = conn->BeginTransaction();

            try {
                String^ query = "INSERT INTO courses (courseName, credits, semester, DepartmentID, availability, course_yr) "
                    "VALUES (@name, @credits, @semester, @deptId, @available, @year)";

                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Transaction = transaction;

                ComboboxItem^ selectedDept = safe_cast<ComboboxItem^>(comboDepartment->SelectedItem);
                cmd->Parameters->AddWithValue("@name", txtCourseName->Text);
                cmd->Parameters->AddWithValue("@credits", Convert::ToInt32(numCredits->Value));
                cmd->Parameters->AddWithValue("@semester", comboSemester->Text);
                cmd->Parameters->AddWithValue("@deptId", Convert::ToInt32(selectedDept->Value));
                cmd->Parameters->AddWithValue("@available", chkAvailability->Checked);
                cmd->Parameters->AddWithValue("@year", comboYear->Text);

                int courseId = Convert::ToInt32(cmd->ExecuteScalar());

                // Save prerequisites
                if (listPrerequisites->Items->Count > 0) {
                    String^ prereqQuery = "INSERT INTO course_prerequisites (courseID, prerequisiteID) VALUES (@courseId, @prereqId)";
                    MySqlCommand^ prereqCmd = gcnew MySqlCommand(prereqQuery, conn);
                    prereqCmd->Transaction = transaction;

                    for each (ComboboxItem ^ item in listPrerequisites->Items) {
                        prereqCmd->Parameters->Clear();
                        prereqCmd->Parameters->AddWithValue("@courseId", courseId);
                        prereqCmd->Parameters->AddWithValue("@prereqId", Convert::ToInt32(item->Value));
                        prereqCmd->ExecuteNonQuery();
                    }
                }

                transaction->Commit();
                MessageBox::Show("Course added successfully!");
                LoadCourses();
                ClearForm();
            }
            catch (Exception^ ex) {
                transaction->Rollback();
                throw ex;
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error adding course: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    // Continue with your existing methods...
    // Include btnUpdate_Click, btnDelete_Click, btnSearch_Click, btnClear_Click, and dataGridCourses_CellClick
    // Just update them to handle prerequisites as needed
    System::Void Course_Management::btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (!ValidateInput() || String::IsNullOrEmpty(txtCourseID->Text)) {
                MessageBox::Show("Please select a course to update.", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();
            dbManager->ConnectToDatabase();

            MySqlTransaction^ transaction = conn->BeginTransaction();

            try {
                // Update course details
                String^ query = "UPDATE courses SET courseName=@name, credits=@credits, "
                    "semester=@semester, DepartmentID=@deptId, availability=@available, course_yr=@year "
                    "WHERE courseID=@id";

                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Transaction = transaction;

                ComboboxItem^ selectedDept = safe_cast<ComboboxItem^>(comboDepartment->SelectedItem);
                cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtCourseID->Text));
                cmd->Parameters->AddWithValue("@name", txtCourseName->Text);
                cmd->Parameters->AddWithValue("@credits", Convert::ToInt32(numCredits->Value));
                cmd->Parameters->AddWithValue("@semester", comboSemester->Text);
                cmd->Parameters->AddWithValue("@deptId", Convert::ToInt32(selectedDept->Value));
                cmd->Parameters->AddWithValue("@available", chkAvailability->Checked);
                cmd->Parameters->AddWithValue("@year", comboYear->Text);

                cmd->ExecuteNonQuery();

                // Update prerequisites
                String^ deleteQuery = "DELETE FROM course_prerequisites WHERE courseID = @courseId";
                MySqlCommand^ deleteCmd = gcnew MySqlCommand(deleteQuery, conn);
                deleteCmd->Transaction = transaction;
                deleteCmd->Parameters->AddWithValue("@courseId", Convert::ToInt32(txtCourseID->Text));
                deleteCmd->ExecuteNonQuery();

                if (listPrerequisites->Items->Count > 0) {
                    String^ prereqQuery = "INSERT INTO course_prerequisites (courseID, prerequisiteID) VALUES (@courseId, @prereqId)";
                    MySqlCommand^ prereqCmd = gcnew MySqlCommand(prereqQuery, conn);
                    prereqCmd->Transaction = transaction;

                    for each (ComboboxItem ^ item in listPrerequisites->Items) {
                        prereqCmd->Parameters->Clear();
                        prereqCmd->Parameters->AddWithValue("@courseId", Convert::ToInt32(txtCourseID->Text));
                        prereqCmd->Parameters->AddWithValue("@prereqId", Convert::ToInt32(item->Value));
                        prereqCmd->ExecuteNonQuery();
                    }
                }

                transaction->Commit();
                MessageBox::Show("Course updated successfully!");
                LoadCourses();
                ClearForm();
            }
            catch (Exception^ ex) {
                transaction->Rollback();
                throw ex;
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating course: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Course_Management::btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (String::IsNullOrEmpty(txtCourseID->Text)) {
                MessageBox::Show("Please select a course to delete.", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            if (MessageBox::Show("Are you sure you want to delete this course?\nThis will also remove all prerequisites.",
                "Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes) {

                DatabaseManager^ dbManager = DatabaseManager::GetInstance();
                MySqlConnection^ conn = dbManager->GetConnection();
                dbManager->ConnectToDatabase();

                MySqlTransaction^ transaction = conn->BeginTransaction();

                try {
                    // Delete prerequisites first
                    String^ deletePrereqQuery = "DELETE FROM course_prerequisites WHERE courseID = @id OR prerequisiteID = @id";
                    MySqlCommand^ prereqCmd = gcnew MySqlCommand(deletePrereqQuery, conn);
                    prereqCmd->Transaction = transaction;
                    prereqCmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtCourseID->Text));
                    prereqCmd->ExecuteNonQuery();

                    // Then delete the course
                    String^ query = "DELETE FROM courses WHERE courseID = @id";
                    MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                    cmd->Transaction = transaction;
                    cmd->Parameters->AddWithValue("@id", Convert::ToInt32(txtCourseID->Text));
                    cmd->ExecuteNonQuery();

                    transaction->Commit();
                    MessageBox::Show("Course deleted successfully!");
                    LoadCourses();
                    ClearForm();
                }
                catch (Exception^ ex) {
                    transaction->Rollback();
                    throw ex;
                }
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error deleting course: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Course_Management::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.*, d.DepartmentName, "
                "(SELECT GROUP_CONCAT(p.courseName) FROM course_prerequisites cp "
                "JOIN courses p ON cp.prerequisiteID = p.courseID "
                "WHERE cp.courseID = c.courseID) as prerequisites "
                "FROM courses c "
                "JOIN departments d ON c.DepartmentID = d.DepartmentID "
                "WHERE c.courseName LIKE @search";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@search", "%" + txtSearch->Text + "%");

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridCourses->Rows->Clear();

            while (reader->Read()) {
                dataGridCourses->Rows->Add(
                    reader["courseID"]->ToString(),
                    reader["courseName"]->ToString(),
                    reader["credits"]->ToString(),
                    reader["semester"]->ToString(),
                    reader["DepartmentName"]->ToString(),
                    Convert::ToBoolean(reader["availability"]) ? "Yes" : "No",
                    reader->IsDBNull(reader->GetOrdinal("prerequisites")) ?
                    "None" : reader["prerequisites"]->ToString()
                );
            }

            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error searching courses: " + ex->Message);
        }
        finally {
            DatabaseManager::GetInstance()->CloseConnection();
        }
    }

    System::Void Course_Management::dataGridCourses_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            txtCourseID->Text = dataGridCourses->Rows[e->RowIndex]->Cells["CourseID"]->Value->ToString();
            txtCourseName->Text = dataGridCourses->Rows[e->RowIndex]->Cells["CourseName"]->Value->ToString();
            numCredits->Value = Convert::ToDecimal(dataGridCourses->Rows[e->RowIndex]->Cells["Credits"]->Value);
            comboSemester->Text = dataGridCourses->Rows[e->RowIndex]->Cells["Semester"]->Value->ToString();
            chkAvailability->Checked = dataGridCourses->Rows[e->RowIndex]->Cells["Available"]->Value->ToString() == "Yes";
            comboYear->Text = dataGridCourses->Rows[e->RowIndex]->Cells["Year"]->Value->ToString();

            String^ deptName = dataGridCourses->Rows[e->RowIndex]->Cells["Department"]->Value->ToString();
            for (int i = 0; i < comboDepartment->Items->Count; i++) {
                ComboboxItem^ item = safe_cast<ComboboxItem^>(comboDepartment->Items[i]);
                if (item->Text == deptName) {
                    comboDepartment->SelectedIndex = i;
                    break;
                }
            }

            // Load prerequisites for selected course
            int courseId = Convert::ToInt32(txtCourseID->Text);
            LoadCoursePrerequisites();
            LoadCoursePrerequisitesList(courseId);
        }
    }
}