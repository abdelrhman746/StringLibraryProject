#include <iostream>

using namespace std;


//Abstract Class / Interface / Contract.
class clsMobile
{
	virtual void Dial(string PhoneNumber) = 0;
	virtual void SendSMS(string PhoneNumber,string text) = 0;
	virtual void TakePicture() = 0;
};

class clsiPhone:public clsMobile
{
public:
	void Dial(string PhoneNumber)
	{

	}
	void SendSMS(string PhoneNumber, string text)
	{

	}
	void TakePicture()
	{

	}

	void MyOwnMethod()
	{

	}
};

class clsSamsungNote10 :public clsMobile
{
public:
	void Dial(string PhoneNumber)
	{

	}
	void SendSMS(string PhoneNumber, string text)
	{

	}
	void TakePicture()
	{

	}

	void MyOwnMethod()
	{

	}
};
int main()
{

	clsiPhone iPhone1;

	clsSamsungNote10 Note10;
	
	

	system("pause>0");
}