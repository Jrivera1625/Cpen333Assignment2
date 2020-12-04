#ifndef __Program__
#define __Program__

#include <stdio.h>
#include <iostream>
#include <list>
#include "student.h"
using namespace std;


class Program {
private:
	list<Student*> Students;

public:
	string ProgramName;
	int AdmissionsAverage;

	// function to add student to program
	void AddStudentToProgram(Student* student) {
		cout << "Adding student " << student->StudentNumber << "to program: " << ProgramName << endl;
		Students.push_back(student); // add student to program
	}
	
	Program(string programName, int admissionsAvg) {
		cout << "Program default Constructor being called..." << endl;
		// class attributes
		ProgramName = programName;
		AdmissionsAverage = admissionsAvg;
	}

	~Program() {
		cout << "Program destructor is being called.." << endl;

	}


};






#endif 

