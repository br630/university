#include "MDIForm.h"

namespace university {
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
		Enter_Grade^ frmEnter = gcnew Enter_Grade();
		frmEnter->MdiParent = this;
		frmEnter->Show();
	}

	System::Void MDIForm::manageCourseMaterialsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Manage_course^ frmCourse = gcnew Manage_course();
		frmCourse->MdiParent = this;
		frmCourse->Show();
	}

	System::Void MDIForm::enrollmentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Enrollment^ frmEnroll = gcnew Enrollment();
		frmEnroll->MdiParent = this;
		frmEnroll->Show();
	}

	System::Void MDIForm::viewAllUsersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		View_All_Users^ frmUsers = gcnew View_All_Users();
		frmUsers->MdiParent = this;
		frmUsers->Show();
	}
	System::Void MDIForm::studentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void MDIForm::createCoursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Create_Courses^ frmCreate = gcnew Create_Courses();
		frmCreate->MdiParent = this;
		frmCreate->Show();
	}
	System::Void MDIForm::courseManagementToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Course_Management^ frmcManage = gcnew Course_Management();
		frmcManage->MdiParent = this;
		frmcManage->Show();
	}
}


