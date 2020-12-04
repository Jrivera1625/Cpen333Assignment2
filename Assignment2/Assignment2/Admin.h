#ifndef __Admin__
#define __Admin__

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

class Admin {
private:

public:

	// review student's graduation form
	bool ReviewGraduationRequest(int studentNumber,list<string> passedCourses, string program, int standing) {

		cout << "Reviewing graduation request for " << studentNumber << endl;
		// check pre-req is met for graduation (course taken or student currently enrolled
		if (find(passedCourses.begin(), passedCourses.end(), "Elec301") != passedCourses.end()
			|| find(passedCourses.begin(), passedCourses.end(), "Elec301") != passedCourses.end()) {
			cout << "Graduation pre-reqs met" << endl;
			// check department is correct for graduation
			if (program == "Elec") {
				cout << "Program requirements met" << endl;
				// check standing for gradution
				if (standing == 4) {
					cout << "Student has 4th year standing" << endl;
					// all requirements met so set graduation status to true
					cout << "Graduation request approved." << endl;
					return true;
				}
			}
			else {
				cout << "Program requirements not met" << endl;
				return false;
			}
		}
		else {
			cout << "Graduation pre-reqs not met" << endl;
			return false;
		}
		
	};


	Admin() {
		cout << "Admin default Constructor being called..." << endl;

	}

	~Admin() {
		cout << "Admin destructor is being called.." << endl;

	}

};

#endif 
