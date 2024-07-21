#include <iostream>

using namespace std;

class clsA
{
public:

	clsA()
	{

	}

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
	short NumberOfObjects = 5;

	//allocating dynamic array
	//of size NumberOfObjects using new keyword

	clsA* arrA = new clsA[NumberOfObjects];

	//Calling constructor
	//for each index of array
	for (int i = 0; i < NumberOfObjects; i++)
	{
		arrA[i] = clsA(i);
	}

	for (int i = 0; i < NumberOfObjects; i++)
	{
		arrA[i].Print();
	}

	delete arrA;
	system("pause>0");
}

