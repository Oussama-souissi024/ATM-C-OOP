#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsString.h"

using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrencyExchangeCard(clsCurrency Currency)
	{

		cout << "\n________________________________________________\n";
		cout << "\nCountry     :" << Currency.Country();
		cout << "\nCode        :" << Currency.CurrencyCode();
		cout << "\nName        :" << Currency.CurrencyName();
		cout << "\nRate        :" << Currency.Rate();
		cout << "\n________________________________________________\n";
	}
public:
	static void showFindCurrencyScreen()
	{
		string Title = "\t  Find Currency Screen";

		_DrawScreenHeader(Title);

		short FindBy = 0;
		cout << "\nFind By : [1] Code or [2] Country ? 2 ";
		FindBy = clsInputValidate::ReadNumberBetween(1, 2);
		if (FindBy == 1)
		{
			cout << "\nPlease enter the code  ";
			string Code = "";
			getline(cin >> ws, Code);
			Code = clsString::Upper_All_Letters_Of_Word(Code);
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			if (Currency.IsEmpty())
			{
				cout << "This Currency IS Not Found  ";
			}
			else
			{
				_PrintCurrencyExchangeCard(Currency);
			}
			}
		else
		{
			cout << "\nPlase enter the Country  ";
			string Country = "";
			getline(cin >> ws, Country);
			Country = clsString::Upper_All_Letters_Of_Word(Country);
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			if (Currency.IsEmpty())
			{
				cout << "This Currency IS Not Found";
			}
			else
			{
				_PrintCurrencyExchangeCard(Currency);
			}
		}
		

	}
};

