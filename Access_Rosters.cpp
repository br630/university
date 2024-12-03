#include "Access_Rosters.h"
#include "db_conn.h"
#include "faculty.h"
#include "student.h"

namespace university {
    void Access_Rosters::InitializeComponent(void) {
        System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Access_Rosters::typeid));
        this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
        this->homeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
        this->groupBoxCourseSelect = (gcnew System::Windows::Forms::GroupBox());
        this->lblCourse = (gcnew System::Windows::Forms::Label());
        this->comboCourses = (gcnew System::Windows::Forms::ComboBox());
        this->lblSemester = (gcnew System::Windows::Forms::Label());
        this->comboSemester = (gcnew System::Windows::Forms::ComboBox());
        this->groupBoxStudentDetails = (gcnew System::Windows::Forms::GroupBox());
        this->lblStudentID = (gcnew System::Windows::Forms::Label());
        this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
        this->lblUserID = (gcnew System::Windows::Forms::Label());
        this->txtUserID = (gcnew System::Windows::Forms::TextBox());
        this->lblDateOfBirth = (gcnew System::Windows::Forms::Label());
        this->datePickerDOB = (gcnew System::Windows::Forms::DateTimePicker());
        this->lblMajor = (gcnew System::Windows::Forms::Label());
        this->txtMajor = (gcnew System::Windows::Forms::TextBox());
        this->lblEnrollmentDate = (gcnew System::Windows::Forms::Label());
        this->datePickerEnrollment = (gcnew System::Windows::Forms::DateTimePicker());
        this->pictureStudent = (gcnew System::Windows::Forms::PictureBox());
        this->btnAddStudent = (gcnew System::Windows::Forms::Button());
        this->btnRemoveStudent = (gcnew System::Windows::Forms::Button());
        this->btnUpdateStudent = (gcnew System::Windows::Forms::Button());
        this->btnClear = (gcnew System::Windows::Forms::Button());
        this->txtSearch = (gcnew System::Windows::Forms::TextBox());
        this->btnSearch = (gcnew System::Windows::Forms::Button());
        this->dataGridStudents = (gcnew System::Windows::Forms::DataGridView());
        this->groupBoxCourseSelect->SuspendLayout();
        this->groupBoxStudentDetails->SuspendLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureStudent))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridStudents))->BeginInit();
        this->SuspendLayout();

        this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
        this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
        this->menuStrip1->Location = System::Drawing::Point(0, 0);
        this->menuStrip1->Name = L"menuStrip1";
        this->menuStrip1->Size = System::Drawing::Size(1552, 24);
        this->menuStrip1->TabIndex = 0;

        this->homeToolStripMenuItem->Name = L"homeToolStripMenuItem";
        this->homeToolStripMenuItem->Size = System::Drawing::Size(32, 19);

        this->groupBoxCourseSelect->Controls->Add(this->lblCourse);
        this->groupBoxCourseSelect->Controls->Add(this->comboCourses);
        this->groupBoxCourseSelect->Controls->Add(this->lblSemester);
        this->groupBoxCourseSelect->Controls->Add(this->comboSemester);
        this->groupBoxCourseSelect->Location = System::Drawing::Point(18, 62);
        this->groupBoxCourseSelect->Size = System::Drawing::Size(600, 154);
        this->groupBoxCourseSelect->Text = L"Course Selection";

        this->lblCourse->Location = System::Drawing::Point(30, 46);
        this->lblCourse->Size = System::Drawing::Size(150, 35);
        this->lblCourse->Text = L"Course:";

        this->comboCourses->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->comboCourses->Location = System::Drawing::Point(150, 42);
        this->comboCourses->Size = System::Drawing::Size(373, 28);

        this->lblSemester->Location = System::Drawing::Point(30, 92);
        this->lblSemester->Size = System::Drawing::Size(150, 35);
        this->lblSemester->Text = L"Semester:";

        this->comboSemester->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
        this->comboSemester->Location = System::Drawing::Point(150, 88);
        this->comboSemester->Size = System::Drawing::Size(373, 28);

        // Initialize group box for student details
        this->groupBoxStudentDetails->Controls->Add(this->lblStudentID);
        this->groupBoxStudentDetails->Controls->Add(this->txtStudentID);
        this->groupBoxStudentDetails->Controls->Add(this->lblUserID);
        this->groupBoxStudentDetails->Controls->Add(this->txtUserID);
        this->groupBoxStudentDetails->Controls->Add(this->lblDateOfBirth);
        this->groupBoxStudentDetails->Controls->Add(this->datePickerDOB);
        this->groupBoxStudentDetails->Controls->Add(this->lblMajor);
        this->groupBoxStudentDetails->Controls->Add(this->txtMajor);
        this->groupBoxStudentDetails->Controls->Add(this->lblEnrollmentDate);
        this->groupBoxStudentDetails->Controls->Add(this->datePickerEnrollment);
        this->groupBoxStudentDetails->Controls->Add(this->pictureStudent);
        this->groupBoxStudentDetails->Controls->Add(this->btnAddStudent);
        this->groupBoxStudentDetails->Controls->Add(this->btnRemoveStudent);
        this->groupBoxStudentDetails->Controls->Add(this->btnUpdateStudent);
        this->groupBoxStudentDetails->Controls->Add(this->btnClear);
        this->groupBoxStudentDetails->Location = System::Drawing::Point(18, 231);
        this->groupBoxStudentDetails->Size = System::Drawing::Size(600, 615);
        this->groupBoxStudentDetails->Text = L"Student Details";

        // Set up DataGridView
        this->dataGridStudents->AllowUserToAddRows = false;
        this->dataGridStudents->AllowUserToDeleteRows = false;
        this->dataGridStudents->ColumnHeadersHeight = 34;
        this->dataGridStudents->Location = System::Drawing::Point(645, 69);
        this->dataGridStudents->MultiSelect = false;
        this->dataGridStudents->ReadOnly = true;
        this->dataGridStudents->RowHeadersWidth = 62;
        this->dataGridStudents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
        this->dataGridStudents->Size = System::Drawing::Size(870, 777);

        // Set up search controls
        this->txtSearch->Location = System::Drawing::Point(645, 18);
        this->txtSearch->Size = System::Drawing::Size(298, 26);

        this->btnSearch->Location = System::Drawing::Point(960, 15);
        this->btnSearch->Size = System::Drawing::Size(120, 40);
        this->btnSearch->Text = L"Search";

        // Wire up event handlers
        this->Load += gcnew System::EventHandler(this, &Access_Rosters::Access_Rosters_Load);
        this->btnAddStudent->Click += gcnew System::EventHandler(this, &Access_Rosters::btnAddStudent_Click);
        this->btnRemoveStudent->Click += gcnew System::EventHandler(this, &Access_Rosters::btnRemoveStudent_Click);
        this->btnUpdateStudent->Click += gcnew System::EventHandler(this, &Access_Rosters::btnUpdateStudent_Click);
        this->btnSearch->Click += gcnew System::EventHandler(this, &Access_Rosters::btnSearch_Click);
        this->btnClear->Click += gcnew System::EventHandler(this, &Access_Rosters::btnClear_Click);
        this->dataGridStudents->CellClick += gcnew DataGridViewCellEventHandler(this, &Access_Rosters::dataGridStudents_CellClick);
        this->comboCourses->SelectedIndexChanged += gcnew System::EventHandler(this, &Access_Rosters::comboCourses_SelectedIndexChanged);
        this->comboSemester->SelectedIndexChanged += gcnew System::EventHandler(this, &Access_Rosters::comboSemester_SelectedIndexChanged);

        // Form properties
        this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(1552, 888);
        this->Controls->Add(this->menuStrip1);
        this->Controls->Add(this->groupBoxCourseSelect);
        this->Controls->Add(this->groupBoxStudentDetails);
        this->Controls->Add(this->txtSearch);
        this->Controls->Add(this->btnSearch);
        this->Controls->Add(this->dataGridStudents);
        this->MaximizeBox = false;
        this->MinimizeBox = false;
        this->Name = L"Access_Rosters";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
        this->Text = L"Access Rosters";

        this->groupBoxCourseSelect->ResumeLayout(false);
        this->groupBoxStudentDetails->ResumeLayout(false);
        this->groupBoxStudentDetails->PerformLayout();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureStudent))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridStudents))->EndInit();
        this->ResumeLayout(false);
        this->PerformLayout();
    }

    System::Void Access_Rosters::Access_Rosters_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadCourses();
        SetupDataGridView();
    }

    void Access_Rosters::LoadCourses() {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT c.courseID, c.courseName "
                "FROM courses c "
                "INNER JOIN facultycourses fc ON c.courseID = fc.courseID "
                "WHERE fc.facultyID = @facultyID "
                "ORDER BY c.courseName";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@facultyID", Faculty::GetInstance()->GetFacultyID());

            dbManager->ConnectToDatabase();
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
        catch (Exception^ ex) {
            MessageBox::Show("Error loading courses: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void Access_Rosters::SetupDataGridView() {
        dataGridStudents->Columns->Clear();

        array<String^>^ columns = {
            "Student ID",
            "First Name",
            "Last Name",
            "Email",
            "Major",
            "Enrollment Date"
        };

        for each (String ^ column in columns) {
            DataGridViewColumn^ newColumn = gcnew DataGridViewTextBoxColumn();
            newColumn->HeaderText = column;
            newColumn->Name = column->Replace(" ", "");
            dataGridStudents->Columns->Add(newColumn);
        }
    }

    void Access_Rosters::LoadStudentRoster() {
        if (comboCourses->SelectedIndex == -1 || comboSemester->SelectedIndex == -1) return;

        try {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT s.studentID, u.firstName, u.lastName, u.email, s.major, "
                "DATE_FORMAT(s.enrollmentDate, '%Y-%m-%d') as enrollmentDate "
                "FROM enrollment e "
                "INNER JOIN students s ON e.studentID = s.studentID "
                "INNER JOIN users u ON s.userID = u.userID "
                "WHERE e.courseID = @courseID AND e.semester = @semester "
                "ORDER BY u.lastName, u.firstName";

            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            dataGridStudents->Rows->Clear();

            while (reader->Read()) {
                dataGridStudents->Rows->Add(
                    reader["studentID"]->ToString(),
                    reader["firstName"]->ToString(),
                    reader["lastName"]->ToString(),
                    reader["email"]->ToString(),
                    reader["major"]->ToString(),
                    reader["enrollmentDate"]->ToString()
                );
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading student roster: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void Access_Rosters::LoadStudentPicture(int studentId) {
        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "SELECT picture FROM students WHERE studentID = @studentID";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentID", studentId);

            dbManager->ConnectToDatabase();
            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read() && !reader->IsDBNull(0)) {
                array<Byte>^ imageData = (array<Byte>^)reader["picture"];
                System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(imageData);
                pictureStudent->Image = Image::FromStream(ms);
            }
            else {
                pictureStudent->Image = nullptr;
            }

            reader->Close();
            dbManager->CloseConnection();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error loading student picture: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void Access_Rosters::btnAddStudent_Click(System::Object^ sender, System::EventArgs^ e) {
        if (comboCourses->SelectedIndex == -1 || comboSemester->SelectedIndex == -1) {
            MessageBox::Show("Please select a course and semester first.");
            return;
        }

        if (String::IsNullOrEmpty(txtStudentID->Text)) {
            MessageBox::Show("Please select a student to add.");
            return;
        }

        try {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ checkQuery = "SELECT COUNT(*) FROM enrollment WHERE studentID = @studentID AND courseID = @courseID AND semester = @semester";
            MySqlCommand^ checkCmd = gcnew MySqlCommand(checkQuery, conn);
            checkCmd->Parameters->AddWithValue("@studentID", Int32::Parse(txtStudentID->Text));
            checkCmd->Parameters->AddWithValue("@courseID", courseID);
            checkCmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            dbManager->ConnectToDatabase();
            int existingEnrollments = Convert::ToInt32(checkCmd->ExecuteScalar());

            if (existingEnrollments > 0) {
                MessageBox::Show("Student is already enrolled in this course for the selected semester.");
                dbManager->CloseConnection();
                return;
            }

            String^ insertQuery = "INSERT INTO enrollment (studentID, courseID, semester) VALUES (@studentID, @courseID, @semester)";
            MySqlCommand^ insertCmd = gcnew MySqlCommand(insertQuery, conn);
            insertCmd->Parameters->AddWithValue("@studentID", Int32::Parse(txtStudentID->Text));
            insertCmd->Parameters->AddWithValue("@courseID", courseID);
            insertCmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            insertCmd->ExecuteNonQuery();
            dbManager->CloseConnection();

            MessageBox::Show("Student added to course successfully!");
            LoadStudentRoster();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error adding student to course: " + ex->Message);
        }
    }

    System::Void Access_Rosters::btnRemoveStudent_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrEmpty(txtStudentID->Text)) {
            MessageBox::Show("Please select a student to remove.");
            return;
        }

        try {
            String^ selectedCourse = comboCourses->SelectedItem->ToString();
            int courseID = Int32::Parse(selectedCourse->Split('-')[0]->Trim());

            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "DELETE FROM enrollment WHERE studentID = @studentID AND courseID = @courseID AND semester = @semester";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@studentID", Int32::Parse(txtStudentID->Text));
            cmd->Parameters->AddWithValue("@courseID", courseID);
            cmd->Parameters->AddWithValue("@semester", comboSemester->Text);

            dbManager->ConnectToDatabase();
            int rowsAffected = cmd->ExecuteNonQuery();
            dbManager->CloseConnection();

            if (rowsAffected > 0) {
                MessageBox::Show("Student removed from course successfully!");
                LoadStudentRoster();
                btnClear_Click(nullptr, nullptr);
            }
            else {
                MessageBox::Show("No enrollment found for this student in the selected course and semester.");
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error removing student from course: " + ex->Message);
        }
    }

    System::Void Access_Rosters::btnSearch_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ searchText = txtSearch->Text->Trim();
        if (String::IsNullOrEmpty(searchText)) {
            LoadStudentRoster();
            return;
        }

        for each (DataGridViewRow ^ row in dataGridStudents->Rows) {
            bool visible = false;
            for each (DataGridViewCell ^ cell in row->Cells) {
                if (cell->Value != nullptr &&
                    cell->Value->ToString()->ToLower()->Contains(searchText->ToLower())) {
                    visible = true;
                    break;
                }
            }
            row->Visible = visible;
        }
    }

    System::Void Access_Rosters::btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
        txtStudentID->Clear();
        txtUserID->Clear();
        datePickerDOB->Value = DateTime::Now;
        txtMajor->Clear();
        datePickerEnrollment->Value = DateTime::Now;
        pictureStudent->Image = nullptr;
    }

    System::Void Access_Rosters::dataGridStudents_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0) {
            txtStudentID->Text = dataGridStudents->Rows[e->RowIndex]->Cells["StudentID"]->Value->ToString();
            txtMajor->Text = dataGridStudents->Rows[e->RowIndex]->Cells["Major"]->Value->ToString();
            LoadStudentPicture(Int32::Parse(txtStudentID->Text));
        }
    }

    System::Void Access_Rosters::btnUpdateStudent_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrEmpty(txtStudentID->Text)) {
            MessageBox::Show("Please select a student to update.");
            return;
        }

        try {
            DatabaseManager^ dbManager = DatabaseManager::GetInstance();
            MySqlConnection^ conn = dbManager->GetConnection();

            String^ query = "UPDATE students SET major = @major WHERE studentID = @studentID";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@major", txtMajor->Text);
            cmd->Parameters->AddWithValue("@studentID", Int32::Parse(txtStudentID->Text));

            dbManager->ConnectToDatabase();
            int rowsAffected = cmd->ExecuteNonQuery();
            dbManager->CloseConnection();

            if (rowsAffected > 0) {
                MessageBox::Show("Student information updated successfully!");
                LoadStudentRoster();
            }
            else {
                MessageBox::Show("No student found with the given ID.");
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error updating student information: " + ex->Message);
        }
    }

    System::Void Access_Rosters::comboCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        if (comboSemester->SelectedIndex != -1) {
      
        }
    }

    System::Void Access_Rosters::comboSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        if (comboCourses->SelectedIndex != -1) {
            LoadStudentRoster();
        }
    }
}