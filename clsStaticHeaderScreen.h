#pragma once
#include <iostream>
#include "global.h"
#include "clsDate.h"
using namespace std;

class clsStaticHeaderScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t\tHello " << CurrentUser.FullName() << endl;
        clsDate Date =  clsDate::GetSystemDate();
        cout << "\t\t\t\t\t\tDate:" << Date.DateToString() << "\n\n";

    }

    static bool CheckAccessRight(short Permission)
    {
        if (!CurrentUser.CheckUserPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};