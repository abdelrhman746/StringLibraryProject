#pragma once
#include<iostream>
#include"clsEmployee.h"
using namespace std;
class clsDeveloper :public clsEmployee
{
private:
	string _MainProgrammingLanguage;
public:
	clsDeveloper(short ID, string FirstName, string LastName, string Email, string Phone, string Title,
		string Department, float Salary, string MainProgrammingLanguage)
		:clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary)
	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}
	//Set Porperty	
	void SetMainProgrammingLanguage(string MainProgrammingLanguage)
	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	//Get Property
	string MainProgrammingLanguage()
	{
		return _MainProgrammingLanguage;
	}

	void Print()
	{
		cout << "\nInfo:\n";
		cout << "_____________________________\n";
		cout << "ID			: " << ID() << endl;
		cout << "FirstName		: " << FirstName() << endl;
		cout << "LastName		: " << LastName() << endl;
		cout << "FullName		: " << FullName() << endl;
		cout << "Email			: " << Email() << endl;
		cout << "Phone			: " << Phone() << endl;

		cout << "Title			: " << Title() << endl;
		cout << "Department		: " << Department() << endl;
		cout << "Sallary			: " << Salary() << endl;

		cout << "MainProgrammingLanguage : " << _MainProgrammingLanguage << endl;

		cout << "_____________________________\n";
	}
};