#ifndef __UBCPortal__
#define __UBCPortal__

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

class UBCPortal {
private:
	list<int> validStudentNumbers;

public:

	// enter credentials
	bool EnterCredentials(int studentNumber) {
		cout << "Credentials Entered were " << studentNumber << endl;
		return AuthenticateCredentials(studentNumber);
	}

	// authenticate credentials
	bool AuthenticateCredentials(int studentNumber) {
		// check credentials
		if (find(validStudentNumbers.begin(), validStudentNumbers.end(), studentNumber) != validStudentNumbers.end()) {
			return true;
		}
		else {
			return false;
		}
	}

	UBCPortal() {
		cout << "UBCPortal default Constructor being called..." << endl;
		validStudentNumbers = { 21685169 ,21685134 };

	}

	~UBCPortal() {
		cout << "UBCPortal destructor is being called.." << endl;

	}


};






#endif 



