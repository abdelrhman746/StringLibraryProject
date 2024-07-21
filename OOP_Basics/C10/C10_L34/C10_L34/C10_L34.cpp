#include <iostream>

using namespace std;


class clsPerson
{
	struct stAddress
	{
		string AddressLine1;
		string AddressLine2;
		string City;
		string Coountry;

	};

public:

	string FullName;
	stAddress Address;

	clsPerson()
	{
		FullName = "Abdelrhman Fawzy";
		Address.AddressLine1 = "Building 10";
		Address.AddressLine2 = "Bnfsg street";
		Address.City = "Cairo";
		Address.Coountry = "Egypt";
	}

	void PrintAddress()
	{
		cout << "\nAddress:";
		cout << Address.AddressLine1 << endl;
		cout << Address.AddressLine2 << endl;
		cout << Address.City << endl;
		cout << Address.Coountry << endl;
	}
};


int main()
{

	clsPerson Person1;
	
	Person1.PrintAddress();
	

	system("pause>0");
}