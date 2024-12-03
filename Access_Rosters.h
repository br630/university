#pragma once

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Access_Rosters
	/// </summary>
	public ref class Access_Rosters : public System::Windows::Forms::Form
	{
	public:
		Access_Rosters(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Access_Rosters()
		{
			if (components)
			{
				delete components;
			}
		}
    private:
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::ToolStripMenuItem^ homeToolStripMenuItem;
        System::Windows::Forms::GroupBox^ groupBoxCourseSelect;
        System::Windows::Forms::Label^ lblCourse;
        System::Windows::Forms::ComboBox^ comboCourses;
        System::Windows::Forms::Label^ lblSemester;
        System::Windows::Forms::ComboBox^ comboSemester;
        System::Windows::Forms::GroupBox^ groupBoxStudentDetails;
        System::Windows::Forms::Label^ lblStudentID;
        System::Windows::Forms::TextBox^ txtStudentID;
        System::Windows::Forms::Label^ lblUserID;
        System::Windows::Forms::TextBox^ txtUserID;
        System::Windows::Forms::Label^ lblDateOfBirth;
        System::Windows::Forms::DateTimePicker^ datePickerDOB;
        System::Windows::Forms::Label^ lblMajor;
        System::Windows::Forms::TextBox^ txtMajor;
        System::Windows::Forms::Label^ lblEnrollmentDate;
        System::Windows::Forms::DateTimePicker^ datePickerEnrollment;
        System::Windows::Forms::PictureBox^ pictureStudent;
        System::Windows::Forms::Button^ btnAddStudent;
        System::Windows::Forms::Button^ btnRemoveStudent;
        System::Windows::Forms::Button^ btnUpdateStudent;
        System::Windows::Forms::Button^ btnClear;
        System::Windows::Forms::DataGridView^ dataGridStudents;
        System::Windows::Forms::TextBox^ txtSearch;
        System::Windows::Forms::Button^ btnSearch;
        System::ComponentModel::Container^ components;

        

    private:
        System::Void Access_Rosters_Load(System::Object^ sender, System::EventArgs^ e);
        System::Void btnAddStudent_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnRemoveStudent_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnUpdateStudent_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void dataGridStudents_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e);
        System::Void comboCourses_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void comboSemester_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

        // Helper method declarations
        void LoadCourses();
        void SetupDataGridView();
        void LoadStudentRoster();
        void LoadStudentPicture(int studentId);
        void InitializeComponent(void);
    };
}