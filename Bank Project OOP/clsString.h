#pragma once
#include<iostream>
#include<vector>

using namespace std;

class clsString
{
private:
	string _Value;
public:
	clsString() {};
	clsString(string Value)
	{
		this->_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	void Pint()
	{
		cout << "Value of String1 : " << _Value;
	};

	static void Print_First_Letter(string sentence)
	{
		bool IsFirstLetter = true;

		cout << "\nFirst letters of  string " << sentence << endl;;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ' && IsFirstLetter) cout << sentence.at(i) << endl;

			IsFirstLetter = (sentence[i] == ' ') ? true : false;

		}
	};
	void Print_First_Letter()
	{
		Print_First_Letter(_Value);
	};

	static string Upper_First_Letter_Of_Word(string sentence)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ' && IsFirstLetter)  sentence[i] = toupper(sentence[i]);

			IsFirstLetter = (sentence[i] == ' ') ? true : false;

		}
		return sentence;
	};
	void Upper_First_Letter_Of_Word()
	{
		_Value =  Upper_First_Letter_Of_Word(_Value);
	};

	static string Lower_First_Letter_Of_Word(string sentence)
	{
		bool IsFirstLetter = true;



		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ' && IsFirstLetter)  sentence[i] = tolower(sentence[i]);

			IsFirstLetter = (sentence[i] == ' ') ? true : false;

		}
		return sentence;
	};
	void Lower_First_Letter_Of_Word()
	{
		_Value = Lower_First_Letter_Of_Word(_Value);
	};

	static string Lower_All_Letters_Of_Word(string sentence)
	{
		for (short i = 0; i < sentence.length(); i++)
		{
			sentence[i] = tolower(sentence[i]);
		}
		return sentence;
	};
	void Lower_All_Letters_Of_Word()
	{
		_Value = Lower_All_Letters_Of_Word(_Value);
	};

	static string Upper_All_Letters_Of_Word(string sentence)
	{
		for (short i = 0; i < sentence.length(); i++)
		{
			sentence[i] = toupper(sentence[i]);
		}
		return sentence;
	};
	void Upper_All_Letters_Of_Word()
	{
		_Value = Upper_All_Letters_Of_Word(_Value);
	};

	static char Invert_caractar_Case(char C)
	{

		return (isupper(C)) ? tolower(C) : toupper(C);
	};
	
	static string Print_Word_After_Inverting(string Word)
	{
		for (short i = 0; i <= Word.length(); i++)
		{
			Word[i] = Invert_caractar_Case(Word[i]);
		}
		return Word;
	};
	string Print_Word_After_Inverting()
	{
		return Print_Word_After_Inverting(_Value);
	};

	static short Count_Capital_Letters_In_String(string S1)
	{
		short count = 0;
		for (short i = 0; i <= S1.length(); i++)
		{
			if (isupper(S1[i]))  count++;
		}
		return count;
	};
	short Count_Capital_Letters_In_String()
	{
		return Count_Capital_Letters_In_String(_Value);
	};

	static short Count_Lower_Letters_In_String(string S1)
	{
		short count = 0;
		for (short i = 0; i <= S1.length(); i++)
		{
			if (islower(S1[i]))  count++;
		}
		return count;
	};
	short Count_Lower_Letters_In_String()
	{
		return Count_Lower_Letters_In_String(_Value);
	};

	static short CountLetters(string S1, char C)
	{
		short count = 0;

		for (short i = 0; i <= S1.length(); i++)
		{
			if ((S1[i]) == C)  count++;
		}
		return count;
	};
	short CountLetters(char C)
	{
		return CountLetters(_Value,C);
	}

	static short Count_C_Letters_In_String(string S1, char C, bool MatchCase = true)
	{
		short count = 0;

		for (short i = 0; i <= S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == C)  count++;
			}


			else
			{
				if (toupper(S1[i]) == toupper(C))  count++;
			}
		}
		return count;
	};
	short Count_C_Letters_In_String(char C)
	{
		return Count_C_Letters_In_String(_Value, C);
	};

	static bool Is_Vowel_Character(char C)
	{
		char VowelArray[5] = { 'a','e','u','i','o' };
		for (char count : VowelArray)
		{
			if (count == C) return true;
		}
		return false;
	};

	static short Count_Vowels_In_String(string S1)
	{
		short count = 0;
		for (short i = 0; i <= S1.length(); i++)
		{
			if (Is_Vowel_Character(S1[i])) count++;
		}
		return count;
	};
	short Count_Vowels_In_String()
	{
		return Count_Vowels_In_String(_Value);
	};

	static void Print_Vowels_In_String(string S1)
	{
		for (short i = 0; i <= S1.length(); i++)
		{
			if (Is_Vowel_Character(S1[i])) cout << " " << S1[i] << " ";
		}
		cout << endl;
	};
	void Print_Vowels_In_String()
	{
		Print_Vowels_In_String(_Value);
	};

	static void Print_Word_Of_String(string S1)
	{
		for (short i = 0; i <= S1.length(); i++)
		{
			if (S1[i] != ' ') cout << S1[i];
			else cout << endl;
		}
		cout << endl;
	};
	void Print_Word_Of_String()
	{
		Print_Word_Of_String(_Value);
	};

	static short Count_Word_Of_String(string S1)
	{
		string Word, delim = " ";
		short Pos = 0, count = 0;
		while ((Pos = S1.find(delim)) != std::string::npos)
		{
			Word = S1.substr(0, Pos);
			if (Word != "") count++;
			S1.erase(0, Pos + delim.length());
		}
		if (S1 != "") count++;
		return count;
	};
	short Count_Word_Of_String()
	{
		return Count_Word_Of_String(_Value);
	};

	static string Trim_Left_String(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);

			}

		}
		return "";
	};
	void  Trim_Left_String()
	{
		_Value = Trim_Left_String(_Value);
	};

	static string Trim_Rigth_String(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);

			}

		}
		return "";
	};
	void Trim_Rigth_String()
	{
		_Value = Trim_Rigth_String(_Value);
	};

	static string Trim_String(string S1)
	{


		return (Trim_Left_String(Trim_Rigth_String(S1)));
	};
	void Trim_String()
	{
		_Value = Trim_String(_Value);
	};

	static string Invers_String(string S1)
	{
		string Invers = "";
		int Long_Ch = S1.length();
		for (int i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] == ' ')
			{
				Invers += S1.substr(i + 1, Long_Ch - i) + ' ';
				Long_Ch = i;
			}
		}
		Invers += S1.substr(0, Long_Ch);
		return Invers;
	};
	void Invers_String()
	{
		_Value = Invers_String(_Value);
	};

	static string Replace_Word_String(string S1, string Word_Erase, string  Word_Insert)
	{
		short pos = S1.find(Word_Erase);
		while (pos != std::string::npos)
		{
			S1.replace(pos, Word_Erase.length(), Word_Insert);
			pos = S1.find(Word_Erase);
		}
		return S1;
	};
	void Replace_Word_String(string Word_Erase, string  Word_Insert)
	{
		_Value = Replace_Word_String(_Value, Word_Erase, Word_Insert);
	};

	static	bool Is_Paunctuations(char C)
	{
		C = toupper(C);
		if (C == ' ' || isupper(C) || isdigit(C))
			return false;
		else return true;
	};

	static string Remove_Paunctuations_From_String(string S1)
	{
		string Result = "";
		for (char C : S1)
		{
			if (!Is_Paunctuations(C)) Result += C;

		}
		return Result;
	};
	void Remove_Paunctuations_From_String()
	{
		_Value = Remove_Paunctuations_From_String(_Value);
	};

	static 	vector <string> Split(string S1, string delim)
	{
		vector <string> vString;
		string Word;
		short Pos = 0;
		while ((Pos = S1.find(delim)) != std::string::npos)
		{
			Word = S1.substr(0, Pos);
			if (Word != "") vString.push_back(Word);
			S1.erase(0, Pos + delim.length());
		}
		if (S1 != "") vString.push_back(S1);
		return vString;
	}
	vector <string> Split(string delim)
	{
		vector <string> vString;
		string Word;
		short Pos = 0;
		while ((Pos = _Value.find(delim)) != std::string::npos)
		{
			Word = _Value.substr(0, Pos);
			if (Word != "") vString.push_back(Word);
			_Value.erase(0, Pos + delim.length());
		}
		if (_Value != "") vString.push_back(_Value);
		return vString;

	};

	static string Join_String(vector <string>& vString, string delim)
	{
		string S1 = "";
		for (string vCount : vString)
		{
			S1 += vCount;
			S1 += delim;
		}
		return S1.substr(0, S1.length() - 1);
	}
	static string Join_String(string Array_String[4], string delim)
	{
		string S1 = "";
		for (short aCount = 0; aCount < 4; aCount++)
		{
			S1 += Array_String[aCount];
			S1 += delim;
		}
		return S1.substr(0, S1.length() - 1);
	}

	
};

