// Enter_Grade.h
#pragma once
#include "db_conn.h"

namespace university {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class Enter_Grade : public System::Windows::Forms::Form {
    private:
        int currentFacultyID;

    public:
        Enter_Grade(int facultyID) {
            InitializeComponent();
            this->currentFacultyID = facultyID;
        }

    protected:
        ~Enter_Grade() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::GroupBox^ groupBoxCourseSelect;
        System::Windows::Forms::Label^ lblCourse;
        System::Windows::Forms::ComboBox^ comboCourses;
        System::Windows::Forms::Label^ lblSemester;
        System::Windows::Forms::ComboBox^ comboSemester;
        System::Windows::Forms::GroupBox^ groupBoxGradeInput;
        System::Windows::Forms::Label^ lblStudentID;
        System::Windows::Forms::TextBox^ txtStudentID;
        System::Windows::Forms::Label^ lblStudentName;
        System::Windows::Forms::TextBox^ txtStudentName;
        System::Windows::Forms::Label^ lblGrade;
        System::Windows::Forms::TextBox^ txtGrade;
        System::Windows::Forms::Label^ lblNotes;
        System::Windows::Forms::RichTextBox^ txtNotes;
        System::Windows::Forms::Button^ btnSubmit;
        System::Windows::Forms::Button^ btnUpdate;
        System::Windows::Forms::Button^ btnClear;
        System::Windows::Forms::DataGridView^ dataGridGrades;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void);
        void LoadCourses();
        void LoadStudentGrades();
        void SubmitGrade();
        void UpdateGrade();
        void ClearForm();
        void SetupDataGridView();
        bool ValidateSelections();

        System::Void Enter_Grade_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void comboCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void comboSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void dataGridGrades_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
    };
}