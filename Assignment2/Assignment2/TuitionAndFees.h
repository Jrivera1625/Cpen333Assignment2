#ifndef __TuitionAndFees__
#define __TuitionAndFees__

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;


class TuitionAndFees {
private:
	int creditCard;

public:

	int Fees; // attribute

	// add fees for a course
	void AddFees(int courseFee) {
		Fees = Fees + courseFee;
		cout << "Updated fees: " << Fees << endl;
	}

	// get total fees
	int GetFees() {
		cout << "Fees due:" << Fees << endl;
		return Fees;
	}

	// enter bank details
	void EnterBankDetails(int CreditCard) {
		cout << "credit card was " << CreditCard << endl;
		creditCard = CreditCard;
	}

	// submit payment and reset fees to 0
	void SubmitFeePayment() {
		cout << "Fee Payment Submitted" << endl;
		// can now reset fees to 0
		Fees = 0;
	}


	TuitionAndFees() {
		cout << "TuitionAndFees default Constructor being called..." << endl;
		Fees = 0; // initialize fees to 0
	}

	~TuitionAndFees() {
		cout << "TuitionAndFees destructor is being called.." << endl;

	}


};






#endif 


