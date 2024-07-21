#include <iostream>

using namespace std;

class clsPerson
{
private:
	int Variable1 = 5;

	int Function1()
	{
		return 40;
	}
protected:
	int Variable2 = 100;

	int Function2()
	{
		return 50;
	}

public:
	string FirstName;

	string LastName;

	string FullName()
	{
		return FirstName + " " + LastName;
	}

	float Function3()
	{
		return Function1() * Variable1 * Variable2;
	}

};
int main()
{
	clsPerson Person1;

	Person1.FirstName = "Abdelrhman";
	Person1.LastName = "Fawzy";

	

	cout << Person1.FullName() << endl;

	string S1;

}