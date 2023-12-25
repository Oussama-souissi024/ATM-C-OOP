#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsUtil.h"

class clsLoginScreen :protected clsScreen
{

private:

    static string _ConverUserLoginObjectToLine()
    {
        string Datenow = clsDate::DateToString(clsDate(), true);
        Datenow += "#//#" + CurrentUser.UserName + "#//#";
        Datenow += CurrentUser.Password + "#//#";
        Datenow += to_string(CurrentUser.Permissions);
        return Datenow;
    }

    static void _RegisterLogin()
    {
        fstream MyFile;
        MyFile.open("Login.txt", ios::app);

        if (MyFile.is_open())
        {
            string Line = _ConverUserLoginObjectToLine();
            MyFile << Line << endl;
        }

        MyFile.close();
    }

    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short Faild = 2;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You Have " << Faild << " Terials To Login\n\n";
                Faild--;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? "; 
            cin >> Password;
            Password = (Password);
            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (!(LoginFaild == false || Faild == 0));


        if (Faild == 0)
        {
            cout << "\n\n You are locked afeter 3 trials ";
            return false;
        }
      
        _RegisterLogin();
        return true;
      
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
      _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

