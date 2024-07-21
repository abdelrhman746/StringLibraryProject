#include <iostream>

using namespace std;

class clsPerson
{
private:
	int _ID = 10;

	string _FirstName;
	string _LastName;

public:

	//Property Set
	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}

	//Property Get, this is read only property because we don't have a set function call
	int ID()
	{
		return _ID;
	}

	//Property Get 
	string FirstName()
	{
		return _FirstName;
	}

	string LastName()
	{
		return _LastName;
	}

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}


};
int main()
{
	clsPerson Person1;

	
	Person1.setFirstName("Abdelrhman");
	Person1.setLastName("Fawzy");
	

	cout << "ID :" << Person1.ID() << endl;
	cout << "First Name:" << Person1.FirstName() << endl;
	cout << "Last Name:" << Person1.LastName() << endl;
	cout << "Full Name:" << Person1.FullName() << endl;


	string S1;

}