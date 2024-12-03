#pragma once
#include "Register_Course.h";
#include "Manage_Profile.h";
#include "Access_Rosters.h";
#include "Enter_Grade.h";
#include "View_Grade.h";
#include "Enrollment.h";
#include "View_All_Students.h";
#include "Course_Management.h";
#include "Manage_Course_Materials.h";
#include "Register_User.h"
#include "Register_Course.h"
#include "Manage_Faculty.h"
#include "Manage_Department.h"
#include "Manage_Enrollments.h"
#include "View_Grade.h"
#include "Generate_Report.h"
#include "Manage_Faculty_Profile.h"

namespace university {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MDIForm
	/// </summary>
	public ref class MDIForm : public System::Windows::Forms::Form
	{
	private:
		int studentID;
	private: System::Windows::Forms::ToolStripMenuItem^ manageFacProfileToolStripMenuItem1;

		   int currentFacultyID;
	public:
		void SetFacultyID(int facultyID) {
			this->currentFacultyID = facultyID;
		}

		void SetStudentID(int studID) {  
			this->studentID = studID;
		}
	public:
		MDIForm(void)
		{
			InitializeComponent();
		}
		void SetUserAccess(String^ userType) {
			// First disable all menu items
			studentsToolStripMenuItem->Enabled = false;
			facultyToolStripMenuItem->Enabled = false;
			adminToolStripMenuItem1->Enabled = false;

			// Make all menus visible but disabled by default
			studentsToolStripMenuItem->Visible = true;
			facultyToolStripMenuItem->Visible = true;
			adminToolStripMenuItem1->Visible = true;

			// Convert userType to lowercase for case-insensitive comparison
			userType = userType->ToLower();

			if (userType == "student") {
				studentsToolStripMenuItem->Enabled = true;
				// Enable student-specific menu items
				registerCoursesToolStripMenuItem->Enabled = true;
				viewGradesToolStripMenuItem->Enabled = true;
				manageProfileToolStripMenuItem->Enabled = true;
				enrollmentToolStripMenuItem->Enabled = true;
			}
			else if (userType == "faculty") {
				facultyToolStripMenuItem->Enabled = true;
				// Enable faculty-specific menu items
				accessClassRostersToolStripMenuItem->Enabled = true;
				enterGradesToolStripMenuItem->Enabled = true;
				manageCourseMaterialsToolStripMenuItem->Enabled = true; 
			}
			else if (userType == "administrator") {
				adminToolStripMenuItem1->Enabled = true;
				// Enable admin-specific functionalities
				viewAllStudentsToolStripMenuItem->Enabled = true;
				registerStudentsToolStripMenuItem->Enabled = true;
				viewAllCoursesToolStripMenuItem->Enabled = true;
				registerFacultyToolStripMenuItem->Enabled = true;
				generateReportToolStripMenuItem->Enabled = true;
			}

			// Set the appearance for disabled menu items
			menuStrip1->ForeColor = System::Drawing::Color::Black;
			for each (ToolStripMenuItem ^ menu in menuStrip1->Items) {
				if (!menu->Enabled) {
					menu->ForeColor = System::Drawing::Color::Gray;
				}
			}
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MDIForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ studentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerCoursesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageProfileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enrollmentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ accessClassRostersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageCourseMaterialsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ adminToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ viewAllStudentsToolStripMenuItem;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ viewAllCoursesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registerStudentsToolStripMenuItem;






	private: System::Windows::Forms::ToolStripMenuItem^ registerFacultyToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ generateReportToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ viewAllDepartmentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageEnrollmentsToolStripMenuItem;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MDIForm::typeid));
			this->studentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageProfileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enrollmentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->accessClassRostersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageCourseMaterialsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageEnrollmentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageFacProfileToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adminToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewAllStudentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerStudentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewAllCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateReportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewAllDepartmentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// studentsToolStripMenuItem
			// 
			this->studentsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->registerCoursesToolStripMenuItem,
					this->viewGradesToolStripMenuItem, this->manageProfileToolStripMenuItem, this->enrollmentToolStripMenuItem
			});
			this->studentsToolStripMenuItem->Name = L"studentsToolStripMenuItem";
			this->studentsToolStripMenuItem->Size = System::Drawing::Size(97, 29);
			this->studentsToolStripMenuItem->Text = L"Students";
			this->studentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::studentsToolStripMenuItem_Click);
			// 
			// registerCoursesToolStripMenuItem
			// 
			this->registerCoursesToolStripMenuItem->Name = L"registerCoursesToolStripMenuItem";
			this->registerCoursesToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->registerCoursesToolStripMenuItem->Text = L"Register Courses";
			this->registerCoursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::registerCoursesToolStripMenuItem_Click);
			// 
			// viewGradesToolStripMenuItem
			// 
			this->viewGradesToolStripMenuItem->Name = L"viewGradesToolStripMenuItem";
			this->viewGradesToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->viewGradesToolStripMenuItem->Text = L"View Grades";
			this->viewGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::viewGradesToolStripMenuItem_Click);
			// 
			// manageProfileToolStripMenuItem
			// 
			this->manageProfileToolStripMenuItem->Name = L"manageProfileToolStripMenuItem";
			this->manageProfileToolStripMenuItem->Size = System::Drawing::Size(245, 34);
			this->manageProfileToolStripMenuItem->Text = L"Manage Profile";
			this->manageProfileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::manageProfileToolStripMenuItem_Click);
			// 
			// enrollmentToolStripMenuItem
			// 
			this->enrollmentToolStripMenuItem->Name = L"enrollmentToolStripMenuItem";
			this->enrollmentToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->enrollmentToolStripMenuItem->Text = L"Enrollment";
			this->enrollmentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::enrollmentToolStripMenuItem_Click);
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->accessClassRostersToolStripMenuItem,
					this->enterGradesToolStripMenuItem, this->manageCourseMaterialsToolStripMenuItem, this->manageEnrollmentsToolStripMenuItem, this->manageFacProfileToolStripMenuItem1
			});
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(82, 29);
			this->facultyToolStripMenuItem->Text = L"Faculty";
			// 
			// accessClassRostersToolStripMenuItem
			// 
			this->accessClassRostersToolStripMenuItem->Name = L"accessClassRostersToolStripMenuItem";
			this->accessClassRostersToolStripMenuItem->Size = System::Drawing::Size(314, 34);
			this->accessClassRostersToolStripMenuItem->Text = L"Access Class Rosters";
			this->accessClassRostersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::accessClassRostersToolStripMenuItem_Click);
			// 
			// enterGradesToolStripMenuItem
			// 
			this->enterGradesToolStripMenuItem->Name = L"enterGradesToolStripMenuItem";
			this->enterGradesToolStripMenuItem->Size = System::Drawing::Size(314, 34);
			this->enterGradesToolStripMenuItem->Text = L"Enter Grades";
			this->enterGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::enterGradesToolStripMenuItem_Click);
			// 
			// manageCourseMaterialsToolStripMenuItem
			// 
			this->manageCourseMaterialsToolStripMenuItem->Name = L"manageCourseMaterialsToolStripMenuItem";
			this->manageCourseMaterialsToolStripMenuItem->Size = System::Drawing::Size(314, 34);
			this->manageCourseMaterialsToolStripMenuItem->Text = L"Manage Course Materials";
			this->manageCourseMaterialsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::manageCourseMaterialsToolStripMenuItem_Click);
			// 
			// manageEnrollmentsToolStripMenuItem
			// 
			this->manageEnrollmentsToolStripMenuItem->Name = L"manageEnrollmentsToolStripMenuItem";
			this->manageEnrollmentsToolStripMenuItem->Size = System::Drawing::Size(314, 34);
			this->manageEnrollmentsToolStripMenuItem->Text = L"Manage Enrollments";
			this->manageEnrollmentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::manageEnrollmentsToolStripMenuItem_Click);
			// 
			// manageFacProfileToolStripMenuItem1
			// 
			this->manageFacProfileToolStripMenuItem1->Name = L"manageFacProfileToolStripMenuItem1";
			this->manageFacProfileToolStripMenuItem1->Size = System::Drawing::Size(314, 34);
			this->manageFacProfileToolStripMenuItem1->Text = L"Manage Faculty Profile";
			this->manageFacProfileToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MDIForm::manageFacProfileToolStripMenuItem1_Click);
			// 
			// adminToolStripMenuItem1
			// 
			this->adminToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->viewAllStudentsToolStripMenuItem,
					this->registerStudentsToolStripMenuItem, this->viewAllCoursesToolStripMenuItem, this->registerFacultyToolStripMenuItem, this->generateReportToolStripMenuItem,
					this->viewAllDepartmentsToolStripMenuItem
			});
			this->adminToolStripMenuItem1->Name = L"adminToolStripMenuItem1";
			this->adminToolStripMenuItem1->Size = System::Drawing::Size(81, 29);
			this->adminToolStripMenuItem1->Text = L"Admin";
			// 
			// viewAllStudentsToolStripMenuItem
			// 
			this->viewAllStudentsToolStripMenuItem->Name = L"viewAllStudentsToolStripMenuItem";
			this->viewAllStudentsToolStripMenuItem->Size = System::Drawing::Size(278, 34);
			this->viewAllStudentsToolStripMenuItem->Text = L"View All Students";
			this->viewAllStudentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::viewAllStudentsToolStripMenuItem_Click);
			// 
			// registerStudentsToolStripMenuItem
			// 
			this->registerStudentsToolStripMenuItem->Name = L"registerStudentsToolStripMenuItem";
			this->registerStudentsToolStripMenuItem->Size = System::Drawing::Size(278, 34);
			this->registerStudentsToolStripMenuItem->Text = L"Register Students";
			this->registerStudentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::registerStudentsToolStripMenuItem_Click);
			// 
			// viewAllCoursesToolStripMenuItem
			// 
			this->viewAllCoursesToolStripMenuItem->Name = L"viewAllCoursesToolStripMenuItem";
			this->viewAllCoursesToolStripMenuItem->Size = System::Drawing::Size(278, 34);
			this->viewAllCoursesToolStripMenuItem->Text = L"Manage Course";
			this->viewAllCoursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::courseManagementToolStripMenuItem_Click);
			// 
			// registerFacultyToolStripMenuItem
			// 
			this->registerFacultyToolStripMenuItem->Name = L"registerFacultyToolStripMenuItem";
			this->registerFacultyToolStripMenuItem->Size = System::Drawing::Size(278, 34);
			this->registerFacultyToolStripMenuItem->Text = L"Manage Faculty";
			this->registerFacultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::registerFacultyToolStripMenuItem_Click);
			// 
			// generateReportToolStripMenuItem
			// 
			this->generateReportToolStripMenuItem->Name = L"generateReportToolStripMenuItem";
			this->generateReportToolStripMenuItem->Size = System::Drawing::Size(278, 34);
			this->generateReportToolStripMenuItem->Text = L"Generate Report";
			this->generateReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::generateReportToolStripMenuItem_Click);
			// 
			// viewAllDepartmentsToolStripMenuItem
			// 
			this->viewAllDepartmentsToolStripMenuItem->Name = L"viewAllDepartmentsToolStripMenuItem";
			this->viewAllDepartmentsToolStripMenuItem->Size = System::Drawing::Size(278, 34);
			this->viewAllDepartmentsToolStripMenuItem->Text = L"Manage Department";
			this->viewAllDepartmentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::viewAllDepartmentsToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->studentsToolStripMenuItem,
					this->facultyToolStripMenuItem, this->adminToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1198, 33);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MDIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1198, 522);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MDIForm";
			this->Text = L"MDIForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MDIForm::MDIForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void registerCoursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void viewGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void manageProfileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void accessClassRostersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void enterGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void manageCourseMaterialsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void enrollmentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void viewAllUsersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void studentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void courseManagementToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MDIForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void editProfileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void viewAllStudentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void registerStudentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void registerFacultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void viewAllDepartmentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void manageEnrollmentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void manageFacProfileToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void generateReportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
