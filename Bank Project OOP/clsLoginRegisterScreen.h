#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsString.h"
#include "clsUtil.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen 
{
private :
    struct _stUserLogin 
    {
        string Date_Time;
        string LoginUserName;
        string LoginPassword;
        string LoginPermession;
    };

    static _stUserLogin _ConvertLineUserLoginFileToVector(string Line)
    {
        _stUserLogin ULogin;
        vector <string> vString;

        vString = clsString::Split(Line, "#//#");

        ULogin.Date_Time = vString[0];
        ULogin.LoginUserName = vString[1];
        ULogin.LoginPassword = vString[2];
        ULogin.LoginPermession = vString[3];

        return ULogin;
    }

    static vector <_stUserLogin> _LoadLoginFileDateToVector(string FileName = "Login.txt")
    {
        
        _stUserLogin UserLogin;
        vector <_stUserLogin> vUsersLogin;
        fstream MyFile;
        MyFile.open("Login.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                UserLogin = _ConvertLineUserLoginFileToVector(Line);
                vUsersLogin.push_back(UserLogin);
            }
            MyFile.close();
        }
        return vUsersLogin;
    }

    static void _PrintLoginRecordLine(_stUserLogin UserLogin)
    {
        cout << setw(8) << left << "" << "| " << left << setw(40) << UserLogin.Date_Time;
        cout << "| " << left << setw(20) << UserLogin.LoginUserName;
        cout << "| " << left << setw(15) << UserLogin.LoginPassword;
        cout << "| " << left << setw(15) << UserLogin.LoginPermession;
    }
    
public:
    static void ShowLoginRegisterScreen()
    {
        vector <_stUserLogin> vUsersLogin = _LoadLoginFileDateToVector();
        
        string Title = "\t  Login Regester List Screen";
        string SubTitle = "\t    (" + to_string(vUsersLogin.size()) + ") Records(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Dete/Time";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(15) << "Permession";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

         
        if (vUsersLogin.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (_stUserLogin UserLogin : vUsersLogin)
            {

                _PrintLoginRecordLine(UserLogin);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "____________________________________________________\n" << endl;
    
    }
   
};

