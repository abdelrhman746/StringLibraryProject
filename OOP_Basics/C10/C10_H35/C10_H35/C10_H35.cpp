#include <iostream>

using namespace std;


class clsPerson
{
private:
	string _FullName;
public:
	class clsAddress
	{
	private:
		string _AddressLine1;
		string _AddressLine2;
		string _City;
		string _Country;
	public:
		clsAddress(string AddressLine1, string AddressLine2, string City, string Country)
		{
			_AddressLine1=AddressLine1 ;
			_AddressLine2 = AddressLine2;
			_City = City;
			_Country = Country;
		}
		
		//Set Property
		void SetAddressLine1(string AddressLine1)
		{
			_AddressLine1 = AddressLine1;
		}

		//Get Property	
		string AddressLine1()
		{
			return _AddressLine1;
		}

		//Set Property
		void SetAddressLine2(string AddressLine2)
		{
			_AddressLine2 = AddressLine2;
		}

		//Get Property	
		string AddressLine2()
		{
			return _AddressLine2;
		}

		//Set Property
		void SetCity(string City)
		{
			_City = City;
		}

		//Get Property	
		string City()
		{
			return _City;
		}

		//Set Property
		void SetCountry(string Country)
		{
			_Country = Country;
		}

		//Get Property	
		string Country()
		{
			return _Country;
		}

		void Print()
		{
			cout << "\nAddress:\n";
			cout << _AddressLine1 << endl;
			cout << _AddressLine2 << endl;
			cout << _City << endl;
			cout << _Country << endl;
		}
	};

	//Set Property
	void SetFullName(string FullName)
	{
		_FullName = FullName;
	}

	//Get Property	
	string FullName()
	{
		return _FullName;
	}
	
	clsAddress Address;
	clsPerson(string FullName,string AddressLine1, string AddressLine2, string City, string Country)
		:Address(AddressLine1, AddressLine2, City, Country)
	{
		_FullName = FullName;
	}

	void Print()
	{
		cout << _FullName << endl;
		Address.Print();
	}
};


int main()
{
	clsPerson Person1("Abdelrhman Fawzy", "Building 10", "Queen  Street", "Cairo", "Egypt");
	Person1.Print();


	system("pause>0");
}

