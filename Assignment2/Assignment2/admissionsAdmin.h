#ifndef __AdmissionsAdmin__
#define __AdmissionsAdmin__

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include "student.h"
#include "Program.h"
using namespace std;


class AdmissionsAdmin {
private:

public:
	Program* elec;
	Program* cpen;
	Program* civl;
	Program* first;

	// review student program preferences
	string ReviewPreferences(Student *student) {
		list<string> choices = student->programPreferenceForm->GetStudentChoices(); // get choices from student's form
		string statement = student->programPreferenceForm->GetPersonalStatement();
		int average = student->transcript->GetStudentAverage(); // get average from student's transcript

		int statementAverage = CalculateGradeWithStatement(statement, average);

		// if grade high enough to get in program, admit
		for (auto choice : choices) {
		//	if (state)
			if (choice == "Elec") {
				if (elec->AdmissionsAverage <= statementAverage) {
					elec->AddStudentToProgram(student); // add student to program
					student->Program = "Elec"; // add program to student's attributes
					//break;
					return "Elec";
				}
			}
			else if (choice == "Cpen") {
				if (cpen->AdmissionsAverage <= statementAverage) {
					cpen->AddStudentToProgram(student);
					student->Program = "Cpen";
				//	break;
					return "Cpen";
				}
			}
			else {
				civl->AddStudentToProgram(student); // fialed first year and have to repeat
				student->Program = "First";
			//	break;
				return "First";
			}
		}
	}

	int CalculateGradeWithStatement(string statement, int StudentAverage) {
		// random calculator to add to student's average
		if (statement.size() == 0) { // up to 5% can be added based on personal statement
			return StudentAverage;
		}
		else {
			return StudentAverage + 5;
		}
	};

	AdmissionsAdmin() {
		cout << "AdmissionsAdmin default Constructor being called..." << endl;

		// create new programs
		elec = new Program("Elec",70); // set name and admissions average
		cpen = new Program("Cpen",80);
		civl = new Program("Civl",50);
		first = new Program("First", 0);

	}

	~AdmissionsAdmin() {
		cout << "AdmissionsAdmin destructor is being called.." << endl;

	}


};


#endif 
