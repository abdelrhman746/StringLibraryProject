#include <iostream>

using namespace std;


class clsPerson
{
public:
	class clsAddress
	{
	public:
		string AddressLine1;
		string AddressLine2;
		string City;
		string Coountry;
		void Print()
		{
			cout << "\nAddress:\n";
			cout << AddressLine1 << endl;
			cout << AddressLine2 << endl;
			cout << City << endl;
			cout << Coountry << endl;
		}

	};

	string FullName;
	clsAddress Address;

	clsPerson()
	{
		FullName = "Abdelrhman Fawzy";
		Address.AddressLine1 = "Building 10";
		Address.AddressLine2 = "Bnfsg street";
		Address.City = "Cairo";
		Address.Coountry = "Egypt";
	}

	
};


int main()
{
	clsPerson clsPerson;

	clsPerson.Address.Print();


	system("pause>0");
}