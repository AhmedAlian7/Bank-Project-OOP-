#pragma once
#include <iostream>
#include "clsStaticHeaderScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsTransferScreen : protected clsStaticHeaderScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber(string M)
    {
        string AccountNumber = "";
        cout << M;
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");

        string AccountNumber1 = _ReadAccountNumber("Enter Account Number That Tranfer From: ");
        while (!clsBankClient::IsClientExist(AccountNumber1))
        {
            cout << "\nClient with [" << AccountNumber1 << "] does not exist.\n";
            AccountNumber1 = _ReadAccountNumber("Enter Account Number That Tranfer From: ");
        }
        clsBankClient ClientTranferFrom = clsBankClient::Find(AccountNumber1);
        _PrintClient(ClientTranferFrom);

        string AccountNumber2 = _ReadAccountNumber("Enter Account Number That Tranfer To: ");
        while (!clsBankClient::IsClientExist(AccountNumber2))
        {
            cout << "\nClient with [" << AccountNumber2 << "] does not exist.\n";
            AccountNumber2 = _ReadAccountNumber("Enter Account Number That Tranfer To: ");
        }
        clsBankClient ClientTranferTo = clsBankClient::Find(AccountNumber2);
        _PrintClient(ClientTranferTo);

        ClientTranferFrom.Transfer(ClientTranferFrom, ClientTranferTo);

        cout << "\nTransfer done successfully.\n\n";
        _PrintClient(ClientTranferFrom);
        _PrintClient(ClientTranferTo);

    }
};

