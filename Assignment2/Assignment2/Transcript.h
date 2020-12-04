#ifndef __Transcript__
#define __Transcript__

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
using namespace std;


class Transcript {
private:
	int AdmissionAverage;

public:
	list<string> CoursesPassed;
	list<string> incidents;
	list<string> CurrentCourses;

	// get student's admission average
	int GetStudentAverage() {
		cout << "Student average is " << AdmissionAverage << endl;
		return AdmissionAverage;
	}

	// check if student has pre-reqs for course
	bool CheckPrereqs(string preReq) {

		if ((find(CoursesPassed.begin(), CoursesPassed.end(), preReq) != CoursesPassed.end())) {
			cout << "Student passes prereqs" << endl;
			return true;
		}
		else {
			cout << "Student does not pass prereqs" << endl;
			return false;
		}
		
	}

	// president records incident on transcript
	void EnterIncidentOnTranscript(string failedCourse) {
		cout << "Incident entered on transcript for course: " << failedCourse << endl;
		incidents.push_back(failedCourse);
	}

	Transcript(int average) {
		// initialize class attributes
		AdmissionAverage = average;
		CoursesPassed = { "Elec211","Elec301" };
		incidents = {};
		cout << "Transcript default Constructor being called..." << endl;
	}

	~Transcript() {
		cout << "Transcript destructor is being called.." << endl;

	}


};


#endif 





