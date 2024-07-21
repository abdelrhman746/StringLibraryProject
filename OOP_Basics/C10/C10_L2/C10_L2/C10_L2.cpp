#include <iostream>

using namespace std;

class clsPerson
{

	int x;
public:
	string FirstName;

	string LastName;
	
	string FullName()
	{
		return FirstName +" " + LastName;
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
