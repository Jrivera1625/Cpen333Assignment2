#ifndef __ProgramPreferenceForm__
#define __ProgramPreferenceForm__

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;


class ProgramPreferenceForm {
private:
	list<string> StudentChoices;
	string StudentPersonalStatement;

public:
	// enter choices
	void EnterChoices(list<string> choices) {
		StudentChoices = choices;
		
	}

	//write persoanl statement
	void WritePersonalStatement(string statement) {
		StudentPersonalStatement = statement;
		cout << "Personal Statement:" << StudentPersonalStatement << endl;

	}

	// get student choices
	list<string> GetStudentChoices() {
		cout << "Received following student choices: " << endl;
		for (auto v : StudentChoices)
			std::cout << v << "\n";

		return StudentChoices;
	}

	// get personal statement
	string GetPersonalStatement() {
		cout << "Receiving the following personal statement: " << StudentPersonalStatement << endl;
		return StudentPersonalStatement;
	}

	// upload student preference form
	void UploadStudentForm(int studentNumber) {
		cout << "Program preference form has been submitted for " << studentNumber << endl;

	}







	ProgramPreferenceForm() {
		cout << "ProgramPreferenceForm default Constructor being called..." << endl;
		StudentPersonalStatement = "This is my personal statement....";

	}

	~ProgramPreferenceForm() {
		cout << "ProgramPreferenceForm destructor is being called.." << endl;

	}


};






#endif 
