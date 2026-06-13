// File name : bankingOperation.h

/*****************************************************
#   File Name   :   bankingOperation.h
#   Description :   This file define banking operations
#                   like withdrawal, deposite, opening 
#                   account and display balance.
#   Note        :   None.
*****************************************************/
#ifndef bankingOperation_H
#define bankingOperation_H

//!< header files included
#include"accountDetails.h"
#include"fileHandling.h"


//!< Namespace define
namespace bankingOperationN
{
    class bankingOperationC
    {
        private:
            void dumyPrintWithDrawal();
            void dumyPrintDeposit();
            void printClintDetails(
                std::vector<accountDetailsN::accountDetailsC>ver,
                int index
            );
            void displayBalanceAcc(std::vector<accountDetailsN::accountDetailsC>ver);
            void displayBalanceMobile(std::vector<accountDetailsN::accountDetailsC>ver);

        public:
            int enterMoney(int flag);
            void withdrawalAmmount();
            void depositAmmount();
            void openingAccount();
            void displayBalance();
            bool validateAcc(
                std::vector<accountDetailsN::accountDetailsC>ver, 
                unsigned int acc,
                int *index
            );
            bool validateMbNumber(
                std::vector<accountDetailsN::accountDetailsC>ver, 
                long long mb,
                int *index
            );
            
            bool validateAccNumAsPerAcc(unsigned int accountNumber);
            int withdrwalOperaionPerform(
                std::vector<accountDetailsN::accountDetailsC>&ver,
                int index
            );
            int depositOperaionPerform(
                std::vector<accountDetailsN::accountDetailsC>&ver,
                int index
            );
            
    };
}
#endif //bankingOperation.h
