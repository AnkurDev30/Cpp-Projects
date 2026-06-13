//File name : generalOperation.h

/*****************************************************
#   File Name   :   generalOperation.h
#   Description :   This file define general operation
#                   which can use in project
#   Note        :   None.
*****************************************************/
#ifndef generalOperation_H
#define generalOperation_H


//header files
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <fstream>
#include <cctype>
#include <sstream>

//!< header files
#include"accountDetails.h"
#include"fileHandling.h"
#include"bankingOperation.h"
#include"moneyTransfer.h"
#include"transactionHistory.h"


//constant 
#define LOGINID "ASDF1234"
#define PASSKEY 1234
#define WELCOME_MSG "------Welcome to State Bank Of India------"
#define BANKNAME "State Bank Of India"

//general operation Namespace + class
namespace generalOperationN
{
    class generalOperationC
    {
        public:
            void clearScreen();
            void welcomeBank();
            void delay(int sec);
            void cinIgnore();
            bool loginCheck();
            void startUpFun();
            void selectOption(char option);
            unsigned int intIput(std::string str);
            long long longIput(std::string str);
            friend class bankingOperationN::bankingOperationC;
    };
}
#endif