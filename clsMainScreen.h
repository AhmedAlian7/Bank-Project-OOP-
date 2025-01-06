#pragma once
#include <iostream>
#include "clsStaticHeaderScreen.h"
#include "clsInputValidate.h"
#include "clsClientsScreen.h"
#include "clsAddNewClients.h"
#include "clsDeleteCLient.h"
#include "clsUpateClients.h"
#include "clsFindClient.h"
#include "clsTransactions.h"
#include "clsManageUsersMenue.h"
#include "clsCurrencyExchangeScreen.h"
#include "clsRegisterHistory.h"
#include "global.h"
using namespace std;


class clsMainScreen :protected clsStaticHeaderScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 11, Logout = 10, Register = 8, Currency = 9
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 11]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 11, "Enter Number between 1 to 11? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        if (!CheckAccessRight(1))
            return;
        clsClientsScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
        if (!CheckAccessRight(2))
            return;
        clsAddNewClients::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        if (!CheckAccessRight(4))
            return;
        clsDeleteCLient::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        if (!CheckAccessRight(8))
            return;
        clsUpdateClients::ShowUpdateClientScreen();


    }

    static void _ShowFindClientScreen()
    {
        if (!CheckAccessRight(16))
            return;
        clsFindClient::ShowFindClientScreen();


    }

    static void _ShowTransactionsMenue()
    {
        if (!CheckAccessRight(32))
            return;
        clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
        if (!CheckAccessRight(64))
            return;
        clsManageUsersScreen::ShowManageUsersMenue();
    }
    static void _ShowRegisterHistory()
    {
        if (!CheckAccessRight(64*2))
            return;
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrencyScreen()
    {
        //if (!CheckAccessRight(128 * 2))
        //    return;
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }

      static void _ShowEndScreen()
      {
          system("cls");

          cout << "\t\t\t\t\t______________________________________";
          cout << "\n\n\t\t\t\t\t\tProgram Ended :-(";
          cout << "\n\t\t\t\t\t______________________________________\n\n";
          End = true;

      }

    static void _Logout()
    {

       CurrentUser = clsUser::Find("", "");
        //then it will go back to main function.
    }


    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::Register:
            system("cls");
            _ShowRegisterHistory();
            _GoBackToMainMenue();
        case enMainMenueOptions::Currency:
            system("cls");
            _ShowCurrencyScreen();
            _GoBackToMainMenue();
        case enMainMenueOptions::Logout:
            system("cls");
            _Logout();
            break;
        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
            break;
        }

    }


public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[01] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[02] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[03] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[04] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[05] Find Client.\n";
        cout << setw(37) << left << "" << "\t[06] Transactions.\n";
        cout << setw(37) << left << "" << "\t[07] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[08] Login Registers History.\n";
        cout << setw(37) << left << "" << "\t[09] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "\t[11] Exit.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }


};

