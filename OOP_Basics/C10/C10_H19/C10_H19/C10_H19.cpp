#include <iostream>

using namespace std;

class clsEmployee
{
	short _ID;
	string _FirstName;
	string _LastName;
	string _Title;
	string _Email;
	string _Phone;
	string _Salary;
	string _Department;

public:

	clsEmployee(short ID, string FirstName, string LastName,string Title, string Email, string Phone , string Salary , string Department)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Title = Title;
		_Email = Email;
		_Phone = Phone;
		_Salary = Salary;
		_Department = Department;
	}

	//Read Only Property
	short ID()
	{
		return _ID;
	}

	//Set Property
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	//Get Property
	string FirstName()
	{
		return _FirstName;
	}

	//Set Property
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	//Get Property
	string LastName()
	{
		return _LastName;
	}

	//Set Property
	void SetTitle(string Title)
	{
		_Title = Title;
	}

	//Get Property
	string Title()
	{
		return _Title;
	}

	//Set Property
	void SetEmail(string Email)
	{
		_Email = Email;
	}

	//Get Property
	string Email()
	{
		return _Email;
	}

	//Set Property
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	//Get Property
	string Phone()
	{
		return _Phone;
	}

	//Set Property
	void SetSalary(string Salary)
	{
		_Salary = Salary;
	}

	//Get Property
	string Salary()
	{
		return _Salary;
	}

	//Set Property
	void SetDepartment(string Department)
	{
		_Department = Department;
	}

	//Get Property
	string Department()
	{
		return _Department;
	}

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void Print()
	{
		cout << "\nInfo:\n";
		cout << "_____________________________\n";
		cout << "ID		: " << _ID << endl;
		cout << "FirstName	: " << _FirstName << endl;
		cout << "LastName	: " << _LastName << endl;
		cout << "FullName	: " << FullName() << endl;
		cout << "Title		: " << _Title << endl;
		cout << "Email		: " << _Email << endl;
		cout << "Phone		: " << _Phone << endl;
		cout << "Salary		: " << _Salary << endl;
		cout << "Department	: " << _Department << endl;
		cout << "_____________________________\n";
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email: " << _Email << endl;

		cout << "Subject: " << Subject << endl;

		cout << "Body   : " << Body << endl;
	}

	void SendSMS(string TextMessage)
	{
		cout << "\nThe following message sent successfully to Phone: " << _Phone << endl;

		cout << TextMessage << endl;

	}
};

int main()
{
	clsEmployee Employee1(10, "Abdelrhman", "Fawzy","Engineer", "My@gmail.com", "0122453425","745287","R&D");

	Employee1.Print();

	Employee1.SendEmail("Hi", "How are you ?");

	Employee1.SendSMS("How are you?");

	system("pause>0");
}