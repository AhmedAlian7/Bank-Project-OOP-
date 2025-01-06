#pragma once
#include "clsStaticHeaderScreen.h"
#include"clsInputValidate.h"
#include "clsCurrency.h"
#include <iostream>


class clsCurrencyCalculater : protected clsStaticHeaderScreen
{
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

	static float _CalculateCurrencyExchange(clsCurrency currency1, clsCurrency currency2, float amount)
	{
		float Exchange = 0;
		Exchange = amount / currency1.Rate();
		Exchange *= currency2.Rate();
		return Exchange;
	}
	 
public:

	static void ShowCurrencyCalculaterScreen()
	{
		_DrawScreenHeader("       Currency Calculater");

		cout << "Enter Currencies Code:\n";
		cout << "\nConvert From: ";
		string Currency1Code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Currency1Code))
		{
			cout << "Currency Code doesn't exist, choose another one:\n\n ";
			Currency1Code = clsInputValidate::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);

		cout << "\nConvert To: ";
		string Currency2Code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Currency2Code))
		{
			cout << "Currency Code doesn't exist, choose another one:\n\n ";
			Currency2Code = clsInputValidate::ReadString();
		}
		clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);

		cout << "\nEnter Amount to Exchange: ";
		float Amount = clsInputValidate::ReadFloatNumber();
		float Exchange = _CalculateCurrencyExchange(Currency1, Currency2, Amount);
		cout <<endl<< Amount << " " << Currency1.CurrencyCode() << " "
			<< " = " << Exchange  << " " << Currency2.CurrencyCode();

	}

};

 