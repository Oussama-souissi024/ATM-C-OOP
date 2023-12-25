#pragma once
#include<iostream>
#include<vector>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum enMode{EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkedForDelete = false;

	 static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

	 static clsBankClient _GetEmptyClientObject()
	 {
		 return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	 }

	 static  vector <clsBankClient> _LoadClientsDataFromFile()
	 {

		 vector <clsBankClient> vClients;

		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {

			 string Line;


			 while (getline(MyFile, Line))
			 {

				 clsBankClient Client = _ConvertLinetoClientObject(Line);

				 vClients.push_back(Client);
			 }

			 MyFile.close();

		 }

		 return vClients;

	 }

	 static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	 {
		 string Result = "";
		 Result += Client.FirstName + Seperator;
		 Result += Client.LastName + Seperator;
		 Result += Client.Email + Seperator;
		 Result += Client.Phone + Seperator;
		 Result += Client.AccountNumber() + Seperator;
		 Result += Client.PinCode + Seperator;
		 Result += to_string(Client.AccountBalance);
		 return Result;
	 }

	 static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	 {

		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out);//overwrite

		 string DataLine;

		 if (MyFile.is_open())
		 {

			 for (clsBankClient C : vClients)
			 {
				 if (C.GetMarkedForDelete() == false)
				 {
					 DataLine = _ConverClientObjectToLine(C);
					 MyFile << DataLine << endl;
				 }
			 }

			 MyFile.close();

		 }

	 }

	 void _Update()
	 {
		 vector <clsBankClient> _vClients;
		 _vClients = _LoadClientsDataFromFile();

		 for (clsBankClient& C : _vClients)
		 {
			 if (C.AccountNumber() == AccountNumber())
			 {
				 C = *this;
				 break;
			 }

		 }

		 _SaveCleintsDataToFile(_vClients);

	 }

	 void _AddNew()
	 {
		 _AddDataLineToFile(_ConverClientObjectToLine(*this));
	 }

	 void _AddDataLineToFile(string  stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {
			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }

	 }

	 string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		 string UserName, string Seperator = "#//#")
	 {
		 string TransferLogRecord = "";
		 TransferLogRecord += clsDate::DateToString(clsDate(),true) + Seperator;
		 TransferLogRecord += AccountNumber() + Seperator;
		 TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		 TransferLogRecord += to_string(Amount) + Seperator;
		 TransferLogRecord += to_string(AccountBalance) + Seperator;
		 TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		 TransferLogRecord += UserName;
		 return TransferLogRecord;
	 }

	 void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	 {

		 string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		 fstream MyFile;
		 MyFile.open("Transfer.txt", ios::app);

		 if (MyFile.is_open())
		 {

			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }

	 }


public:

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	void SetMarkedForDelete(bool Marked )
	{
		_MarkedForDelete = Marked;
	}
	bool GetMarkedForDelete()
	{
		return _MarkedForDelete;
	}
	__declspec(property(get = GetMarkedForDelete, put = SetMarkedForDelete)) bool MarkedForDelete;

	/*void Print()
	{
		cout << "Client Card ";
		cout << "\n_____________________________\n";
		cout << "\nFirst Name  : " << FirstName ;
		cout << "\nLast Name   : " << LastName ;
		cout << "\nFull Name   : " << FullName() ;
		cout << "\nEmail       : " << Email ;
		cout << "\nPhone       : " << Phone ;
		cout << "\nAcc Number  : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode ;
		cout << "\nAcc Balance : " << _AccountBalance ;
		cout << "\n_____________________________\n";
	}*/

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//Read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//Read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0 , svSucceeded = 1, svFaildAccountNumberExists = 2};

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{

				return enSaveResults::svFaildEmptyObject;

			}

		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C.SetMarkedForDelete(true) ;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;

	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients)
		{

			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;

	}

	 void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	 bool Withdraw(double Amount)
	 {
		 if (Amount > _AccountBalance)
		 {
			 return false;
		 }
		 else
		 {
			 _AccountBalance -= Amount;
			 Save();
			 return true;
		 }

	 }

	 bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	 {
		 if (Amount > AccountBalance)
		 {
			 return false;
		 }
		 else
		 {
			 Withdraw(Amount);
			 DestinationClient.Deposit(Amount);
			 _RegisterTransferLog(Amount, DestinationClient, UserName);
			 return true;
		 }
	 }

};

