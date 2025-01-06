#pragma once
#include <iostream>
#include "clsStaticHeaderScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"

class clsTransferHistory : protected clsStaticHeaderScreen
{




private:

    static void PrintTransferRegisterRecordLine(clsUser::stTransferRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(7) << left << LoginRegisterRecord.From_AccNum;
        cout << "| " << setw(7) << left << LoginRegisterRecord.To_AccNum;
        cout << "| " << setw(7) << left << LoginRegisterRecord.Amount;
        cout << "| " << setw(8) << left << LoginRegisterRecord.From_AccBalance_AfterTransfer;
        cout << "| " << setw(8) << left << LoginRegisterRecord.To_AccBalance_AfterTransfer;
        cout << "| " << setw(7) << left << LoginRegisterRecord.User;

    }




public:
    static void ShowLoginRegisterScreen()
    {

        vector <clsUser::stTransferRecord> vTransferRegisterRecord = clsUser::GetTransferRegisterList();

        string Title = "\Transfer Register History Screen";
        string SubTitle = "\t\t(" + to_string(vTransferRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(7) << "From";
        cout << "| " << left << setw(7) << "To";
        cout << "| " << left << setw(7) << "Amount";
        cout << "| " << left << setw(7) << "Balance1";
        cout << "| " << left << setw(7) << "Balance2";
        cout << "| " << left << setw(7) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________\n" << endl;

        if (vTransferRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stTransferRecord& Record : vTransferRegisterRecord)
            {

                PrintTransferRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________\n" << endl;

    }

};

