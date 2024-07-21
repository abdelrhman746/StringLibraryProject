#include <iostream>

using namespace std;

class clsA
{
public:

	
	clsA(int value)
	{
		x = value;
	}
	int x;

	void Print()
	{
		cout << "The value of x=" << x << endl;
	}
};

int main()
{
	
	//Initiallizing 3 array Objects with functioon calls of
	//Paramterized constructor  as elements of that array
	clsA obj[] = { clsA(10),clsA(20),clsA(30) };

	//using print method for each of three elements.
	for (int i = 0; i < 3; i++)
	{
		obj[i].Print();
	}

	system("pause>0");
}

