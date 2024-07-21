#include <iostream>
#include"clsPerson.h"
#include"clsEmployee.h"
#include"clsDeveloper.h"

using namespace std;

int main()
{
	clsDeveloper Developer1(10, "Abdelrhman", "Fawzy", "A@a.com", "01940978516", "CEO", "Programing", 5000, "C++");

	Developer1.Print();

	Developer1.SendSMS("Hi mr Developer :-)");


	system("pause>0");
}