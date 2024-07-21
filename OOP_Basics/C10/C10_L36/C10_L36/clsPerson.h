#pragma once		//to avoid mutiple inclusion
#include<iostream>
using namespace std;
class clsPerson
{
	short _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(short ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
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
		cout << "Email		: " << _Email << endl;
		cout << "Phone		: " << _Phone << endl;
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
