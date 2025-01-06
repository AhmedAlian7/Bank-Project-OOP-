#pragma once
#include "clsStaticHeaderScreen.h"
#include"clsInputValidate.h"
#include "clsCurrency.h"
#include <iostream>

class clsFindCurrency : protected clsStaticHeaderScreen
{
	enum enFindBy { CurrencyCode = 1, CountryName = 2 };

	static string _ReadCurrencyCode()
	{
		cout << "\nEnter the Currency Code: ";
		string CC;
		cin >> CC;
		return CC;
	}
	static string _ReadCountryName()
	{
		cout << "\nEnter the Country Name: ";
		string CN;
		cin >> CN;
		return CN;
	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "__________________________________\n";
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCurrency Code: " << Currency.CurrencyCode();
		cout << "\nCurrency Name: " << Currency.CurrencyName();
		cout << "\nRate(1$)     : " << Currency.Rate();
		cout << "\n__________________________________\n";

	}

	static enFindBy _ReadFindType()
	{
		short F;
		cout << "Search By:\n";
		cout << "Country Code [1]";
		cout << "\nCountry Name [2]";
		

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 2, "ERROR, Enter your choise (1 or 2): ");
		return  enFindBy(Choice);
	}

	static void FindByCurrencyCode()
	{
		string CurrencyCode = _ReadCurrencyCode();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency Code doesn't exist, choose another one:\n\n ";
			CurrencyCode = _ReadCurrencyCode();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrencyCard(Currency);
		

	}
	static void FindByCountryName()
	{
		string CountryName = _ReadCountryName();
		while (!clsCurrency::IsCurrencyExistByName(CountryName))
		{
			cout << "Country Name doesn't exist, choose another one: \n\n";
			CountryName = _ReadCurrencyCode();
		}
		clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

		_PrintCurrencyCard(Currency);


	}


public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		enFindBy Choise = _ReadFindType();

		switch (Choise)
		{
		case enFindBy::CurrencyCode:
			FindByCurrencyCode();
			break;
		case clsFindCurrency::CountryName:
			FindByCountryName();
			break;
		}
	}


};

