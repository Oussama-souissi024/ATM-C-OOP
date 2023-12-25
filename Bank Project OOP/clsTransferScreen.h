#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDate.h"
#include "Global.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintTransferCard(clsBankClient Client)
	{
		cout << "\n\n____________________________________________\n";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nAcc Number : " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.GetAccountBalance();
		cout << "\n____________________________________________\n\n";
	}

	static clsBankClient _ReadValidAccountNumber(string FromOrTO)
	{
		while (true)
		{
			cout << "\nPlease enter account number to transfer " << FromOrTO << " : ";
			string AccNum = clsInputValidate::ReadString();
			if (clsBankClient::IsClientExist(AccNum))
			{
				return clsBankClient::Find(AccNum);
			}
			else
				cout << "\nClient with Account Number " << AccNum << " is not exist, please try again \n\n";
		}
	}

	static float _ReadAmount(clsBankClient ClientFrom)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > ClientFrom.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}


public :

	static void ShowTransferScreen()
	{
		float AmounttoTransfer = 0;

		_DrawScreenHeader("\t   Transfer Screen");

		clsBankClient clientFrom = _ReadValidAccountNumber("From");
		_PrintTransferCard(clientFrom);

		clsBankClient ClientTo = _ReadValidAccountNumber("To");
		_PrintTransferCard(ClientTo);

		AmounttoTransfer = _ReadAmount(clientFrom);
		cout << "\nAre you sure you want to perform this operation? y/n? ";

		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (clientFrom.Transfer(AmounttoTransfer,ClientTo,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		cout << "\nClient Card :";
		_PrintTransferCard(clientFrom);
		cout << "\nClient Card :";
		_PrintTransferCard(ClientTo);

	}
};

