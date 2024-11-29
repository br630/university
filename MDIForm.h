#pragma once
#include "Register_Course.h";
#include "Manage_course.h";
#include "Manage_Profile.h";
#include "Access_Rosters.h";
#include "Enter_Grade.h";
#include "View_Grade.h";
#include "Enrollment.h";
#include "View_All_Users.h";
#include "Create_Courses.h";
#include "Course_Management.h";

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
	public:
		MDIForm(void)
		{
			InitializeComponent();
		}
		void SetUserAccess(String^ userType) {
			if (String::Compare(userType, "student", true) == 0) {
				// Show student menu, hide faculty and admin
				studentsToolStripMenuItem->Visible = true;
				facultyToolStripMenuItem->Visible = false;
				adminToolStripMenuItem1->Visible = false;
			}
			else if (String::Compare(userType, "faculty", true) == 0) {
				// Show faculty menu, hide student and admin
				studentsToolStripMenuItem->Visible = false;
				facultyToolStripMenuItem->Visible = true;
				adminToolStripMenuItem1->Visible = false;
			}
			else if (String::Compare(userType, "admin", true) == 0) {
				// Show all menus for admin
				studentsToolStripMenuItem->Visible = true;
				facultyToolStripMenuItem->Visible = true;
				adminToolStripMenuItem1->Visible = true;
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












	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
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
	private: System::Windows::Forms::ToolStripMenuItem^ viewAllUsersToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ createCoursesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ courseManagementToolStripMenuItem;






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
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->studentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageProfileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enrollmentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->accessClassRostersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageCourseMaterialsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adminToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewAllUsersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->courseManagementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton1,
					this->toolStripButton2
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 33);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1198, 33);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(34, 28);
			this->toolStripButton1->Text = L"toolStripButton1";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(34, 28);
			this->toolStripButton2->Text = L"toolStripButton2";
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
			this->registerCoursesToolStripMenuItem->Size = System::Drawing::Size(245, 34);
			this->registerCoursesToolStripMenuItem->Text = L"Register Courses";
			this->registerCoursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::registerCoursesToolStripMenuItem_Click);
			// 
			// viewGradesToolStripMenuItem
			// 
			this->viewGradesToolStripMenuItem->Name = L"viewGradesToolStripMenuItem";
			this->viewGradesToolStripMenuItem->Size = System::Drawing::Size(245, 34);
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
			this->enrollmentToolStripMenuItem->Size = System::Drawing::Size(245, 34);
			this->enrollmentToolStripMenuItem->Text = L"Enrollment";
			this->enrollmentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::enrollmentToolStripMenuItem_Click);
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->accessClassRostersToolStripMenuItem,
					this->enterGradesToolStripMenuItem, this->manageCourseMaterialsToolStripMenuItem
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
			// adminToolStripMenuItem1
			// 
			this->adminToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->viewAllUsersToolStripMenuItem,
					this->createCoursesToolStripMenuItem, this->courseManagementToolStripMenuItem
			});
			this->adminToolStripMenuItem1->Name = L"adminToolStripMenuItem1";
			this->adminToolStripMenuItem1->Size = System::Drawing::Size(81, 29);
			this->adminToolStripMenuItem1->Text = L"Admin";
			// 
			// viewAllUsersToolStripMenuItem
			// 
			this->viewAllUsersToolStripMenuItem->Name = L"viewAllUsersToolStripMenuItem";
			this->viewAllUsersToolStripMenuItem->Size = System::Drawing::Size(279, 34);
			this->viewAllUsersToolStripMenuItem->Text = L"View All Users";
			this->viewAllUsersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::viewAllUsersToolStripMenuItem_Click);
			// 
			// createCoursesToolStripMenuItem
			// 
			this->createCoursesToolStripMenuItem->Name = L"createCoursesToolStripMenuItem";
			this->createCoursesToolStripMenuItem->Size = System::Drawing::Size(279, 34);
			this->createCoursesToolStripMenuItem->Text = L"Create Courses";
			this->createCoursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::createCoursesToolStripMenuItem_Click);
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
			// courseManagementToolStripMenuItem
			// 
			this->courseManagementToolStripMenuItem->Name = L"courseManagementToolStripMenuItem";
			this->courseManagementToolStripMenuItem->Size = System::Drawing::Size(279, 34);
			this->courseManagementToolStripMenuItem->Text = L"Course Management";
			this->courseManagementToolStripMenuItem->Click += gcnew System::EventHandler(this, &MDIForm::courseManagementToolStripMenuItem_Click);
			// 
			// MDIForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1198, 522);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MDIForm";
			this->Text = L"MDIForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
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
	private: System::Void createCoursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void courseManagementToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
