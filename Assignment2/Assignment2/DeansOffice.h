#ifndef __DeansOffice__
#define __DeansOffice__

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
using namespace std;


class DeansOffice {
private:
	list<string> CheatingOffences;

public:
	// record cheating incident in dean's office
	void RecordIncidentInDeansOffice(int studentNumber, string suspensionLength) {
		cout << "Recording student " << studentNumber << "to Deans Office with suspension length: "+ suspensionLength << endl;
		CheatingOffences.push_back(to_string(studentNumber) + ": " + suspensionLength);
	}

	DeansOffice() {
		cout << "DeansOffice default Constructor being called..." << endl;

	}

	~DeansOffice() {
		cout << "DeansOffice destructor is being called.." << endl;

	}


};






#endif 




