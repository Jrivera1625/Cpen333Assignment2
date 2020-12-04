#ifndef __Student__
#define __Student__

#include <stdio.h>
#include <iostream>
#include <string>
#include "Admin.h"
#include "ProgramPreferenceForm.h"
#include "TuitionAndFees.h"
#include "Transcript.h"
using namespace std;

class Course;

class Student {
	Admin* TheAdmin;
private:

public:
	int StudentNumber;
	int Standing;
	string Program;
	string StudentPermissions; // whether thee student is suspended or can register
	
	Transcript* transcript; // each student has a transcript
	TuitionAndFees* tuition; // each student has tuition and fees
	ProgramPreferenceForm* programPreferenceForm; // each student has a programPreferenceForm
	bool graduationStatus;

	bool CheckProgram() {
		if (Program == "Elec") {
			return true;
		}
		else return false;


	}
	// student applying for graduation
	void ApplyForGraduation(Admin* TheAdminPtr ) {
		TheAdmin = TheAdminPtr;

		// send graduation request to admin with passed courses, program, standing
		 bool gradAccepted = TheAdmin->ReviewGraduationRequest(StudentNumber,transcript->CoursesPassed, Program, Standing);

		 // if graduation accepted, approve request
		if (gradAccepted) {
			cout << "Student has 4th year Standing and Prerequisites" << endl;
			ApproveGraduationRequest();
		}
		else {
			cout << "Student does NOT have 4th year Standing and/or Prerequisites" << endl;
			DenyGraduationRequest();

		}


	}
	void DenyGraduationRequest() {
		cout << "Graduation request denied" << endl;

	}
	void ApproveGraduationRequest() {
		cout << "Graduation Request approved" << endl;
		graduationStatus = true; // update graduation status to true
	}

	// constructor
	Student(int studentNumber, int standing, string program, int average) {
		cout << "Student default Constructor being called..." << endl;
		// initialize class parameters
		StudentNumber = studentNumber;
		transcript = new Transcript(average); // create transcript for student
		Program = program;
		Standing = standing;
		graduationStatus = false;
		StudentPermissions = "goodStanding";
		tuition = new TuitionAndFees(); // create tuition and fees fro student
		// if student is in first year, create programPreferenceForm
		if (standing == 1) {
			programPreferenceForm = new ProgramPreferenceForm(); // create programPreferenceForm for student
		}
	}

	~Student() {
		cout << "Student destructor is being called.." << endl;

	}


};






#endif 