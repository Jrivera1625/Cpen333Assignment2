#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#include "ProgramPreferenceForm.h"
#include "Admin.h"
#include "Course.h"
#include "DeansOffice.h"
#include "President.h"
#include "Program.h"
#include "student.h"
#include "UBCPortal.h"
#include "Transcript.h"
#include "TuitionAndFees.h"
#include "admissionsAdmin.h"

int main() {
	
	// instantiate classes
	UBCPortal Portal;
	Course Elec311("Elec311", "Elec211");
	Course Elec302("Elec302", "Elec301");
	Course Cpen333("Cpen333", "Apsc160");
	Student newStudent(21685169,4,"Elec",80); // student number and year standing
	Student newStudent2(21685134, 1, "First",80); // first year student
	President NewPresident;
	DeansOffice TheDeansOffice;
	Admin TheAdmin;
	AdmissionsAdmin TheAdmissionsAdmin;

	cout << endl << endl;

	//Course Registration and Tuition
	cout << "Course Registration Use Case " << endl;

	// check authentication
	if (Portal.EnterCredentials(newStudent.StudentNumber)) {
		// student must not be banned from registering
		if (newStudent.StudentPermissions == "goodStanding") {

			// add courses
			Elec311.AddCourse(&newStudent);
			Elec302.AddCourse(&newStudent);
			Cpen333.AddCourse(&newStudent); // try to add course that student does not have pre-reqs for

			newStudent.tuition->GetFees(); // get student's fees
			newStudent.tuition->EnterBankDetails(1234890); // enter student's bank details
			newStudent.tuition->SubmitFeePayment(); // submit student's fee payment
		}
	}
	else {
		cout << "Invalid Student Number, please try again" << endl;
	}
	//End of Course Registration and Tuition

	//Student Suspension
	cout << endl << endl;

	cout << "Suspending Cheaters Use Case " << endl;
	// suspend students in Elec 311 who cheates
	NewPresident.GetCourseCheaters(&Elec311, &TheDeansOffice);
	//suspend again to show that cheater now suspended for 2 terms
	cout << endl;
	cout << "Suspend again to show 2 term suspension" << endl;
	NewPresident.GetCourseCheaters(&Elec311, &TheDeansOffice);
	//End of Student Suspension

	//APPLY FOR GRADUATION
	cout << endl << endl;

	cout << "Apply for Graduation Use Case " << endl;
	
	newStudent.ApplyForGraduation(&TheAdmin); // request graduation

	cout << endl;
	cout << "Try graduating with not 4th year standing or correct program" << endl;
	newStudent2.ApplyForGraduation(&TheAdmin);
	//END OF GRADUATION CODE

	//SECOND YEAR ADMITTANCE
	cout << endl << endl;

	cout << "Second Year Admittance Use Case " << endl;
	// student enters choice, writes statement, uploads form
	newStudent2.programPreferenceForm->EnterChoices({"Elec","Cpen","Mech"});
	newStudent2.programPreferenceForm->WritePersonalStatement("This is my statement");
	newStudent2.programPreferenceForm->UploadStudentForm(newStudent2.StudentNumber);
	// admissions admin reviews preferences
	TheAdmissionsAdmin.ReviewPreferences(&newStudent2);
	//END

	return 0;

}