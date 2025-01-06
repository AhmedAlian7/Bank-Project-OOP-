#pragma once
#include <iostream>
#include "clsStaticHeaderScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientsScreen : protected clsStaticHeaderScreen
{
private:

  static void PrintClientRecord(clsBankClient Client)
    {

        cout << "|     " << setw(11) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.getPhoneNum();
        cout << "| " << setw(20) << left << Client.getEmail();
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance << endl;
    }

public:
   static void ShowClientsList()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\tERROR, No Clients Available In the System!";
        }
        else
        {
            for (clsBankClient& C : vClients)
            {
                PrintClientRecord(C);
            }
        }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }


};

