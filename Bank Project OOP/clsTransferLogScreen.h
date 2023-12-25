#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsString.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:

	struct _stTransferLog
	{
		string Date_Time;
		string Source_AccountNumber;
		string Destination_AccountNumber;
		string Amount_To_Transfer;
		string Source_Balance;
		string Destination_Balance;
		string UserName;
	};

	static  _stTransferLog _ConvertLineTransferLogToVector(string Line)
	{
		_stTransferLog TransferLog;
		vector <string> vString;
		vString = clsString::Split(Line, "#//#");
		TransferLog.Date_Time = vString[0];
		TransferLog.Source_AccountNumber = vString[1];
		TransferLog.Destination_AccountNumber = vString[2];
		TransferLog.Amount_To_Transfer = vString[3];
		TransferLog.Source_Balance = vString[4];
		TransferLog.Destination_Balance = vString[5];
		TransferLog.UserName = vString[6];
		return TransferLog;
	}

	static vector <_stTransferLog> _LoadDataFileTransferLogToVector(string FileName = "Transfer.txt")
	{
		_stTransferLog TransferLog;
		vector <_stTransferLog> vTransferLog;
		fstream MyFile;
		MyFile.open("Transfer.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				TransferLog = _ConvertLineTransferLogToVector(Line);
				vTransferLog.push_back(TransferLog);
			}
			MyFile.close();
		}
		return vTransferLog;
	}

	static void _PrintTransferRecordLine(_stTransferLog TransferLog)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << TransferLog.Date_Time;
		cout << "| " << left << setw(20) << TransferLog.Source_AccountNumber;
		cout << "| " << left << setw(15) << TransferLog.Destination_AccountNumber;
		cout << "| " << left << setw(15) << TransferLog.Amount_To_Transfer;
		cout << "| " << left << setw(15) << TransferLog.Source_Balance;
		cout << "| " << left << setw(15) << TransferLog.Destination_Balance;
		cout << "| " << left << setw(15) << TransferLog.UserName;
	}

public:

	static void ShowTransferLogScreen()
	{
		vector <_stTransferLog> vTransferLog = _LoadDataFileTransferLogToVector();

		string Title = "\t  Transfer Register List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLog.size()) + ") Records(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Dete/Time";
		cout << "| " << left << setw(20) << "S.Acc";
		cout << "| " << left << setw(15) << "D.Acc";
		cout << "| " << left << setw(15) << "Amount";
		cout << "| " << left << setw(15) << "S.Balance";
		cout << "| " << left << setw(15) << "D.Balance";
		cout << "| " << left << setw(15) << "UserName";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________________________________________\n" << endl;


		if (vTransferLog.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (_stTransferLog TransferLog : vTransferLog)
			{

				_PrintTransferRecordLine(TransferLog);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________________________________________\n" << endl;

	}

};

