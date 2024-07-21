#include <iostream>

using namespace std;

class clsPerson
{
public:
	string FullName = "Abdelrhman Fawzy";
};

class clsEmployee:public clsPerson
{
public:
	string Title = "CEO";
};



int main()
{
	clsEmployee Employee1;
	cout << Employee1.FullName << endl;
	
	//upcasting
	clsPerson * Person1 = &Employee1;
	cout << Person1->FullName << endl;
	
	clsPerson Person2;
	cout << Person2.FullName << endl;

	//downcasting
	clsEmployee* Employee2 = & Person2;

	system("pause>0");
}