#ifndef __Course__
#define __Course__

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include "student.h"
using namespace std;

class Course {

private:
	list<Student*> Students;
	list<Student*> Cheaters;
	string PreReq;

public:
	int studentGrade;
	string CourseName;

	// add student to a course
	void AddCourse(Student* student) {

		cout << "Adding course: " << CourseName << endl;
		//  check if student has pre-reqs and program requirements
		bool passed = student->transcript->CheckPrereqs(PreReq);
		bool Program = student->CheckProgram();

		// if student has pre-reqs and is in right program
		if (passed == true && Program == true) {
			// add student to course
			cout << "Adding student to course " << CourseName << " as they pass pre-reqs & are in correct program" << endl;
			Students.push_back(student);
			// update fees with this course
			student->tuition->AddFees(500);
		}
		else{
			cout << "Cannot add student to course " << CourseName << " as student does not meet pre-reqs" << endl;
		}

	}

	list<Student*> GetCourseCheaters() {
		cout << "Student Cheaters:" << endl;
		for (auto v : Cheaters)
			cout << v->StudentNumber << "\n";
		return Cheaters;
	}

	void EnterGradeofZero(int studentNumber) {

		cout << "Entered Grade of Zero for student#" << studentNumber << "in course: " << CourseName << endl;

	}

	Course(string Name, string preReq) {
		cout << "Course default Constructor being called..." << endl;
		// initialize course attributes
		CourseName = Name;
		Cheaters = { new Student(21685169,3,"Cpen",80), new Student(2123123,4,"Elec",80) };
		PreReq = preReq;

	}

	~Course() {
		cout << "Course destructor is being called.." << endl;

	}


};






#endif 








