#include <iostream>

using namespace std;

class clsCalCulator
{
private:
	
	float _Result = 0;
	float _LastNumber=0;
	string _LastOperation ="Clear";
	float _PreviousResult = 0;

	bool _IsZero(float Number)
	{
		return (Number == 0);
	}

public:


	void Add(float Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation="Adding";
		_Result += _LastNumber;
	}

	void Subtract(float Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Subtracting";
		_Result -= _LastNumber;
	}

	void Multiply(float Number)
	{
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Multiplying";
		_Result *= _LastNumber;
	}

	void Divide(float Number)
	{
		if (_IsZero(Number))
		{
			Number = 1;
		}
		_LastNumber = Number;
		_PreviousResult = _Result;
		_LastOperation = "Dividing";
		_Result /= _LastNumber;
	}

	void Clear(void)
	{
		_LastNumber = 0;
		_PreviousResult = 0;
		_LastOperation = "Clear";
		_Result = 0;
	}

	float GetFinalResult(float Number)
	{
		return _Result;
	}

	void PrintResult()
	{
		cout << "Result After ";
		cout << _LastOperation << " " << _LastNumber << " is: " << _Result << endl;
	}

	void CancelLastOperation(void)
	{
		_LastNumber = 0;
		_LastOperation = "Canceling Last Operation";
		_Result = _PreviousResult;
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

	CalCulator1.CancelLastOperation();
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