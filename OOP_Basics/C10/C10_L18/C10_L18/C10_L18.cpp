#include <iostream>

using namespace std;

class clsPerson
{
	short _ID;
	string _FirstName;
	string _LastName;
	string _FullName;
	string _Email;
	string _Phone;

public:

	clsPerson(short ID, string FirstName,string LastName,string Email,string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_FullName = _FirstName + " " + _LastName;
		_Email = Email;
		_Phone = Phone;
	}
	
	//Set Property
	void SetFirstName(string FirstName)
	{
		_FirstName= FirstName;
		_FullName = _FirstName + " " + _LastName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
		_FullName = _FirstName + " " + _LastName;
	}
	
	void SetEmail(string Email)
	{
		_Email = Email;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	//Get Property

	short ID()
	{
		return _ID;
	}

	string FirstName()
	{
		return _FirstName;
	}

	string LastName()
	{
		return _LastName;
	}

	string Phone()
	{
		return _Phone;
	}

	string Email()
	{
		return _Email;
	}

	void Print()
	{
		cout << "\nInfo\n";
		cout << "_____________________________\n";
		cout << "ID		: " << _ID << endl;
		cout << "FirstName	: " << _FirstName << endl;
		cout << "LastName	: " << _LastName << endl;
		cout << "FullName	: " << _FullName << endl;
		cout << "Email		: " << _Email << endl;
		cout << "Phone		: " << _Phone << endl;
		cout << "_____________________________\n";
	}

	void SendEmail(string Subject,string Body)
	{
		cout << "\nThe following message sent successfully to email: " << _Email << endl;

		cout << "Subject: " << Subject << endl;

		cout << "Body   : " << Body << endl;
	}

	void SendSMS(string SMS)
	{
		cout << "\nThe following message sent successfully to Phone: " << _Phone << endl;

		cout << SMS << endl;

	}
};



int main()
{
	clsPerson Person1(10, "Abdelrhman", "Fawzy", "My@gmail.com", "0122453425");

	Person1.Print();
	
	Person1.SendEmail("Hi","How are you ?");

	Person1.SendSMS("How are you?");

	system("pause>0");
}