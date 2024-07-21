#include <iostream>

using namespace std;

class clsAddress
{
private:

	string _AddressLine1;
	string _AddressLine2;
	string _POBox;
	string _ZipCode;

public:

	//Constuctor
	clsAddress(string AddresLine1,string AddressLine2,string POBox,string ZipCode)
	{
		_AddressLine1= AddresLine1;
		_AddressLine2 = AddressLine2;
		_POBox = POBox;
		_ZipCode = ZipCode;
	}


	void SetAddressLine1(string AddressLine1)
	{
		_AddressLine1 = AddressLine1;
	}

	string AddressLine1()
	{
		return _AddressLine1 ;
	}

	void SetAddressLine2(string AddressLine2)
	{
		_AddressLine2 = AddressLine2;
	}

	string AddressLine2()
	{
		return _AddressLine2;
	}

	void SetPOBox(string POBox)
	{
		_POBox = POBox;
	}

	string POBox()
	{
		return _POBox;
	}

	void SetZipCode(string ZipCode)
	{
		_ZipCode = ZipCode;
	}

	string ZipCode()
	{
		return _ZipCode;
	}

	void Print()
	{
		cout << "\nAddress Details:";
		cout << "\n---------------------";
		cout << "\nAddress Line1:" << _AddressLine1 << endl;
		cout << "\nAddress Line2:" << _AddressLine2 << endl;
		cout << "\nPOBox:" << _POBox << endl;
		cout << "\nZipCode:" << _ZipCode << endl;
	}
};

int main()
{
	clsAddress Address1("Cairo","Egypt","13342","33221");
	Address1.Print();



	
	system("pause>0");
}