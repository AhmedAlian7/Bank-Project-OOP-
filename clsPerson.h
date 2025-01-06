#pragma once
#include <iostream>
#include<string>
using namespace std;

class clsPerson
{
private:
	string _FirstName, _LastName, _Email, _PhoneNum;
public:
	clsPerson(string FirstName, string LastName, string Email, string PhoneNum)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNum = PhoneNum;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string getFirstName()
	{
		return _FirstName;
	}

	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	string getLastName()
	{
		return _LastName;
	}

	void setEmail(string Email)
	{
		_Email = Email;
	}
	string getEmail()
	{
		return _Email;
	}

	void setPhoneNum(string PhoneNum)
	{
		_PhoneNum = PhoneNum;
	}
	string getPhoneNum()
	{
		return _PhoneNum;
	}

	string FullName()
	{
		return getFirstName() + " " + getLastName();
	}
};

