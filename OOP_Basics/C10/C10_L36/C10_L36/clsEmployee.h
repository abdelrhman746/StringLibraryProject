#pragma once
#include<iostream>
#include"clsPerson.h"
using namespace std;
class clsEmployee : public clsPerson
{
private:
	string _Title;
	string _Department;
	float _Salary;
public:
	clsEmployee(short ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
		:clsPerson(ID, FirstName, LastName, Email, Phone)
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}
	//Property Set
	void SetTitle(string Title)
	{
		_Title = Title;
	}

	//Property Get
	string Title()
	{
		return _Title;
	}

	//Property Set
	void SetDepartment(string Department)
	{
		_Department = Department;
	}

	//Property Get
	string Department()
	{
		return _Department;
	}

	//Property Set
	void SetSalary(float Salary)
	{
		_Salary = Salary;
	}

	//Property Get
	float Salary()
	{
		return _Salary;
	}

	void Print()
	{
		cout << "\nInfo:\n";
		cout << "_____________________________\n";
		cout << "ID		: " << ID() << endl;
		cout << "FirstName	: " << FirstName() << endl;
		cout << "LastName	: " << LastName() << endl;
		cout << "FullName	: " << FullName() << endl;
		cout << "Email		: " << Email() << endl;
		cout << "Phone		: " << Phone() << endl;

		cout << "Title		: " << _Title << endl;
		cout << "Department	: " << _Department << endl;
		cout << "Sallary		: " << _Salary << endl;

		cout << "_____________________________\n";
	}

};