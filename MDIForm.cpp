#include "MDIForm.h"

namespace university {
	System::Void MDIForm:: registerFacultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Manage_Faculty^ frmManageFaculty = gcnew Manage_Faculty();
		frmManageFaculty->MdiParent = this;
		frmManageFaculty->Show();
	}

	System::Void MDIForm::viewAllDepartmentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Manage_Department^ frmManageDep = gcnew Manage_Department();
		frmManageDep->MdiParent = this;
		frmManageDep->Show();
	}


	System::Void MDIForm::registerCoursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Register_Course^ frmReg = gcnew Register_Course();
		frmReg->MdiParent = this;
		frmReg->Show();
	}
	System::Void MDIForm::viewGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		View_Grade^ frmView = gcnew View_Grade();
		frmView->MdiParent = this;
		frmView->Show();
	}

	System::Void MDIForm::manageProfileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Manage_Profile^ frmMan = gcnew Manage_Profile();
		frmMan->MdiParent = this;
		frmMan->Show();
	}

	System::Void MDIForm::accessClassRostersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Access_Rosters^ frmAccess = gcnew Access_Rosters();
		frmAccess->MdiParent = this;
		frmAccess->Show();
	}

	System::Void MDIForm::enterGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Enter_Grade^ frmEnter = gcnew Enter_Grade(currentFacultyID);
		frmEnter->MdiParent = this;
		frmEnter->Show();
	}

	System::Void MDIForm::manageCourseMaterialsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Manage_Course_Materials^ frmCManage = gcnew Manage_Course_Materials();
		frmCManage->MdiParent = this;
		frmCManage->Show();
	}

	System::Void MDIForm::enrollmentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Enrollment^ frmEnroll = gcnew Enrollment();
		frmEnroll->MdiParent = this;
		frmEnroll->Show();
	}

	System::Void MDIForm::viewAllUsersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		View_All_Students^ frmUsers = gcnew View_All_Students();
		frmUsers->MdiParent = this;
		frmUsers->Show();
	}
	System::Void MDIForm::studentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void MDIForm::courseManagementToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Course_Management^ frmcManage = gcnew Course_Management();
		frmcManage->MdiParent = this;
		frmcManage->Show();
	}

	System::Void MDIForm::registerStudentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Register_User^ frmcRegisterUser = gcnew Register_User();
		frmcRegisterUser->MdiParent = this;
		frmcRegisterUser->Show();
	}


	System::Void MDIForm::viewAllStudentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		View_All_Students^ frmAllStudents = gcnew View_All_Students();
		frmAllStudents->MdiParent = this;
		frmAllStudents->Show();
	}
}


