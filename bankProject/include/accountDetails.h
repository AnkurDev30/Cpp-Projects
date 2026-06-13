// File name : accountDetails.h

/*****************************************************
#   File Name   :   accountDetails.h
#   Description :   This define Account data details.
#                   like name, address, account number etc
#   Note        :   None.
*****************************************************/
#ifndef accountDetails_H
#define accountDetails_H

//Header files.
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <fstream>


// Nmaespace Define.
namespace accountDetailsN
{
    class accountDetailsC
    {
        private:
            unsigned int accountNumber;
            unsigned int accountBalance;
            unsigned int accountPinCity;
            long long accountMobileNum;
            std::string accountName;
            std::string accountAddress;
            int generateAccountNumber();
            bool checkAccountNumber(unsigned int readGenratedAccNum);
            bool nameCheck(std::string name);
        public:
            void setData();

            unsigned int    getAccountNumber();
            unsigned int    getAccountBalance();
            unsigned int    getAccountPinCity();
            long long       getAccountMobileNum();
            std::string     getAccountName();
            std::string     getAccountAddress(); 

            void setAccountNumber   (unsigned int);
            void setAccountBalance  (unsigned int);
            void setAccountPinCity  (unsigned int);
            void setAccountMobileNum(long long   );
            void setAccountName     (std::string );
            void setAccountAddress  (std::string ); 

            void updateAccount(int ammount);
    };
}

#endif //accountDetails.h