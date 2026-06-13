//File name : moneyTransfer.h

/*****************************************************
#   File Name   :   moneyTransfer.h
#   Description :   This file define money transfer
#                   realated functions
#   Note        :   None.
*****************************************************/
#ifndef moneyTransfer_H
#define moneyTransfer_H

//header include.
#include<iostream>
#include<string>

#include"accountDetails.h"
#include"bankingOperation.h"
#include"fileHandling.h"


//!< define namespace and call.
namespace moneyTransN
{
    class moneyTransC
    {
        public:
            void moneyTransferFun();
            bool moneyValidFun(
                std::vector<accountDetailsN::accountDetailsC>ver, 
                int money,
                int index
            );
    };
}



#endif