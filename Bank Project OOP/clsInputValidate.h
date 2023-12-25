#pragma once
#include<iostream>
#include "clsDate.h"
#include "clsBankClient.h"

using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	};

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	};

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	};

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	};

	static bool IsDateBetween(clsDate DateToCheck, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1BeforeDate2(DateFrom, DateTo))
		{
			return  ((clsDate::IsDate1AfterDate2(DateToCheck, DateFrom) || clsDate::IsDate1EqualDate2(DateToCheck,DateFrom )) &&
				(clsDate::IsDate1BeforeDate2(DateToCheck, DateTo) || clsDate::IsDate1EqualDate2(DateToCheck,DateTo)));
		}
		else return  ((clsDate::IsDate1AfterDate2(DateToCheck, DateTo) || clsDate::IsDate1EqualDate2(DateToCheck,DateTo)) &&
			    (clsDate::IsDate1BeforeDate2(DateToCheck, DateFrom) || clsDate::IsDate1EqualDate2(DateToCheck,DateFrom)));
	};

	static int ReadIntNumber(string ErorMessage = "Invalid Number , enter again \n")
	{
		int Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErorMessage;
		}
		return Number;
	};

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumber(string ErorMessage = "Invalid Number , enter again \n")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErorMessage;
		}
		return Number;
	};

	static float ReadFloatNumber(string ErorMessage = "Invalid Number , enter again \n")
	{
		float Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErorMessage;
		}
		return Number;
	};
	
	static int ReadNumberBetween(int From, int To)
	{
		int Number; 
		do
		{
			Number = ReadIntNumber();
		} while (!IsNumberBetween(Number, From, To));
		return Number;
	};

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}
	
	static double ReadDblBetwenn(double From, double To)
	{
		double Number;
		do
		{
			Number = ReadIntNumber();

		} while (!IsNumberBetween(Number, From, To));
		return Number;
	};

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}


};

