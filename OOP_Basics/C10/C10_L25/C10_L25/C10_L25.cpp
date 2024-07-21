#include <iostream>

using namespace std;

class clsA
{
private:
	int _Var1;
	int Func1()
	{
		return 1;
	}
protected:
	int _Var2;
	int Func2()
	{
		return 2;
	}
public:
	int _Var3;
	int Func3()
	{
		return 3;
	}
};

class clsB :protected clsA
{
public:
	int Func4()
	{
		
		return 4;
	}
};

class clsC :public clsB
{
public:
	int Func5()
	{
		return 5;
	}
};

int main()
{
	clsA A1;
	clsB B1;
	clsC C1;
	
	A1;
	B1;
	C1;

	system("pause>0");
}