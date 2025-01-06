#pragma once

#include <iostream>
#include "clsStaticHeaderScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "global.h"
#include <fstream>

class clsLoginScreen :protected clsStaticHeaderScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short LoginTrailCounter = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                LoginTrailCounter++;
                cout << "\nInvlaid Username/Password!\n\n";
            }
            if (LoginTrailCounter == 3)
            {
                 cout << "Login Failed you tried  3 time\a\n";
                 system("color 4e");
                 return false;
            }
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);


       CurrentUser.SaveRegisterLoginsToFile();
        clsMainScreen::ShowMainMenue();
        return true;

    }

    

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t\tLogin Screen";
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        return _Login();

    }

};

