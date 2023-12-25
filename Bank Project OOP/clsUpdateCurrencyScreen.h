#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsUpdateCurrencyScreen : protected clsScreen
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

	static void ShowUpdateCurrency()
	{
		string Title = "\t  Update Currency Screen";
		_DrawScreenHeader(Title);

		cout << "\nPlease Enter Currency Code :  ";
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
				cout << "\n\nAre you sure you want to update the Rate of this currency y/n ";
				char Answer = 'n';
				cin >> ws >> Answer;
				if(toupper(Answer)== 'Y')
				{
					cout << "\n\nUpdate Currency Rate";
					cout << "\n________________________________";
					cout << "\nEnter New Rate :\n";
					float Rate;
					cin >> ws >> Rate;
					Currency.UpdateRate(Rate);
					cout << "\nCurrency Update Successfully :-) \nCurrency Card";
					_PrintCurrencyExchangeCard(Currency);
			    }
		    }
	}
};

