#include <iostream>

using namespace std;

class clsA
{
private:
	int _Var1;
	void Function1()
	{
		cout << "Function 1" << endl;
	}
protected:
	int _Var2;
	void Function2()
	{
		cout << "Function 2" << endl;
	}
public:
	int _Var3;
	void Function3()
	{
		cout << "Function 3" << endl;
	}
};

class clsB :public clsA
{
public:
	void Func1()
	{
		clsA::Function2();
	}
};

int main()
{
	clsA A;
	clsB B;

	B.Func1();


	system("pause>0");
}