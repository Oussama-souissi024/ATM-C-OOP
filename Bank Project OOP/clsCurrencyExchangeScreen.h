#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsListeCurrenciesExchange.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;
class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrencyExchangeOptions {
        enListeCurrencies = 1, enFindCurrency = 2, enUpdateCurrency = 3, enCalculator = 4, enMainMenu = 5 
    };

    static short _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackCurrencyExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _ShowListeCurrenciesExchangeScreen()
    {
        clsListeCurrenciesExchange::ShowClientsList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::showFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyScreen()
    {
        clsUpdateCurrencyScreen::ShowUpdateCurrency();
    }

    static void _ShowCalculatorCurrencyScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeOptions CurrencyOption)
    {
        switch (CurrencyOption)
        {
        case enCurrencyExchangeOptions::enListeCurrencies:
        {
            system("cls");
            _ShowListeCurrenciesExchangeScreen();
            _GoBackCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeOptions::enFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeOptions::enUpdateCurrency:
        {
            system("cls");
            _ShowUpdateCurrencyScreen();
            _GoBackCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeOptions::enCalculator:
        {
            system("cls");
            _ShowCalculatorCurrencyScreen();
            _GoBackCurrencyExchangeMenue();
            break;
        }
        case enCurrencyExchangeOptions::enMainMenu:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:

	static void ShowCurrencyExchangeMenue()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        _DrawScreenHeader("\t Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenueOption((enCurrencyExchangeOptions)_ReadManageUsersMenueOption());
	}

};

