#ifndef __President__
#define __President__

#include <stdio.h>
#include <iostream>
#include <list>
#include "Course.h"
#include "DeansOffice.h"
using namespace std;


class President {
private:
	Course* aCourse;
	Transcript* aTranscript;
	DeansOffice* TheDeansOffice;
	list <Student*> Cheaters;


public:
	// function to evaluate how long suspension should be
	string EvaluateLengthOfSuspension(Student *student) {
		string lengthofSuspension;

		if (student->transcript->incidents.size() == 0) {
			lengthofSuspension = "1 term"; // set suspension length
		}
		// repeat offender
		else if (student->transcript->incidents.size() == 1) {
			lengthofSuspension = "2 terms"; // set suspension length
		}
		// more than 1 offence
		else {
			lengthofSuspension = "indefinitely"; // set suspension length
		}
		
		cout << "Student " << student->StudentNumber << " is suspended for " << lengthofSuspension << endl;
		student->StudentPermissions = "suspended: " + lengthofSuspension; // set student's permissions to suspended
		return lengthofSuspension;
	}

	// get course cheaters
	void GetCourseCheaters(Course *CoursePtr, DeansOffice *DeansOfficePtr) {

		TheDeansOffice = DeansOfficePtr;
		aCourse = CoursePtr;

		list <Student*> Cheaters;
		Cheaters = aCourse->GetCourseCheaters();
		for (auto cheater : Cheaters) {
			// evaluate length of suspension and add to student permissions for registration
			string suspensionLength = EvaluateLengthOfSuspension(cheater);
			aCourse->EnterGradeofZero(cheater->StudentNumber); // enter grade of 0 in course
			// enter incident on student's transcript
			cheater->transcript->EnterIncidentOnTranscript(aCourse->CourseName);
			// record the incident in the dean's office
			TheDeansOffice->RecordIncidentInDeansOffice(cheater->StudentNumber, suspensionLength);

		}

	}


	President() {
		cout << "President default Constructor being called..." << endl;

	}

	~President() {
		cout << "President destructor is being called.." << endl;

	}


};






#endif 







