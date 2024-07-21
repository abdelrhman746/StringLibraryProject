#include <iostream>

using namespace std;

class clsCalCulator
{
private:

	int _Result = 0;
	int buffer;
	short flag = -1;
	enum enOperation { _Add, _Subract, _Multiply, _Divide };

public:

	//Property Set
	void Add(int Number)
	{
		_Result += Number;
		buffer = Number;
		flag = enOperation::_Add;
	}

	void Subtract(int Number)
	{
		_Result -= Number;
		buffer = Number;
		flag = enOperation::_Subract;
	}

	void Multiply(int Number)
	{
		_Result *= Number;
		buffer = Number;
		flag = enOperation::_Multiply;
	}

	void Divide(int Number)
	{
		if (Number == 0)
		{
			Number = 1;
		}
		_Result /= Number;
		buffer = Number;
		flag = enOperation::_Divide;
	}


	//Property Get 
	int GetFinalResult(int Number)
	{
		return _Result;
	}

	void PrintResult()
	{
		cout << "Result After ";
		switch (flag)
		{
		case enOperation::_Add:
			cout << "Adding";
			break;
		case enOperation::_Subract:
			cout << "Subtracting";
			break;
		case enOperation::_Multiply:
			cout << "Multiplying";
			break;
		case enOperation::_Divide:
			cout << "Dividing";
			break;
		}
		cout << " " << buffer << " is: " << _Result << endl;
	}

	void Clear(void)
	{
		_Result = 0;
		buffer = _Result;
	}

};
int main()
{
	clsCalCulator CalCulator1;


	CalCulator1.Clear();

	CalCulator1.Add(10);
	CalCulator1.PrintResult();

	CalCulator1.Multiply(10);
	CalCulator1.PrintResult();

	CalCulator1.Divide(0);
	CalCulator1.PrintResult();

	CalCulator1.Subtract(10);
	CalCulator1.PrintResult();

	CalCulator1.Divide(2);
	CalCulator1.PrintResult();

	CalCulator1.Clear();
	CalCulator1.PrintResult();

	system("pause>0");
}