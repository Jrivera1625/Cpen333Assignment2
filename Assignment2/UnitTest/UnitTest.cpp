#include "pch.h"
#include "CppUnitTest.h"
#include "..//Assignment2/admissionsAdmin.h"
#include "..//Assignment2/student.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			AdmissionsAdmin TheAdmin;

			Assert::AreEqual(TheAdmin.CalculateGradeWithStatement(string(""), 80), 80);
			Assert::AreEqual(TheAdmin.CalculateGradeWithStatement(string("I want to be in this program because..."), 80), 85);


			Student newStudent2(21685134, 1, "First", 80); // first year student
			newStudent2.programPreferenceForm->EnterChoices({ "Elec","Cpen","Mech" });
			newStudent2.programPreferenceForm->WritePersonalStatement("This is my statement");
			newStudent2.programPreferenceForm->UploadStudentForm(newStudent2.StudentNumber);

			Assert::AreEqual(TheAdmin.ReviewPreferences(&newStudent2), string("Elec"));

			Student newStudent3(21685134, 1, "First", 70); // first year student
			newStudent3.programPreferenceForm->EnterChoices({ "Cpen","Elec","Mech" });
			newStudent3.programPreferenceForm->WritePersonalStatement("This is my statement");
			newStudent3.programPreferenceForm->UploadStudentForm(newStudent2.StudentNumber);

			Assert::AreEqual(TheAdmin.ReviewPreferences(&newStudent3), string("Elec"));

			Student newStudent4(21685134, 1, "First", 60); // first year student
			newStudent4.programPreferenceForm->EnterChoices({ "Cpen","Elec","Mech" });
			newStudent4.programPreferenceForm->WritePersonalStatement("This is my statement");
			newStudent4.programPreferenceForm->UploadStudentForm(newStudent2.StudentNumber);

			Assert::AreEqual(TheAdmin.ReviewPreferences(&newStudent4), string("First"));


		}
	};
}
