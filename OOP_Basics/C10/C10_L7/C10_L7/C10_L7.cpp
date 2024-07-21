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
	int GetID()
	{
		return _ID;
	}

	//Property Get 
	string GetFirstName()
	{
		return _FirstName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	string GetFullName()
	{
		return _FirstName + " " + _LastName;
	}
	 
	__declspec(property(get = GetFirstName, put = setFirstName))string FirstName;

	__declspec(property(get = GetLastName, put = setLastName))string LastName;

	
};
int main()
{
	clsPerson Person1;


	Person1.setFirstName("Abdelrhman");
	cout << Person1.GetFirstName() << endl;
	
	//instead of the above we only write this
	Person1.FirstName = "Abdelrhman";
	cout << Person1.FirstName;


	string S1;

}