#include <iostream>

using namespace std;

class clsPerson
{

public:
	string FullName;
	//This is Constructor will be called when object is built.
	clsPerson()
	{
		FullName = "Abdelrhman Fawzy";
		cout << "\nHi, I'm Constructor";
	}
	
	//This is Destructor will be called when object is destroyed.
	~clsPerson()
	{
		cout << "\nHi, I'm Destructor";
	}
};

void Fun1()
{
	clsPerson Person1;

}
void Fun2()
{
	clsPerson* Person2 = new clsPerson;
	delete Person2;
}
int main()
{
	Fun1();

	Fun2();
	

	system("pause>0");
}