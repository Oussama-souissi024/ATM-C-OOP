#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsListeCurrenciesExchange : protected clsScreen
{
private:

    static void _PrintCurrencyExchangeCard(clsCurrency Currency)
    {

        cout << setw(10) << left << "" << "| " << setw(40) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(30) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
    }

  
public:
    static void ShowClientsList()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currency List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") currency(ies).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(10) << left << "" << "| " << left << setw(40) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(30) << "Name";
        cout << "| " << left << setw(10) << "Rate(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency Currency : vCurrencies)
            {

                _PrintCurrencyExchangeCard(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};


