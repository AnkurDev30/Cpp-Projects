/******************************************************************************
 * File Name    : moneyTransfer.cpp
 * Description  :
 * This file contains the implementation of money transfer operations
 * between bank accounts.
 *
 * Functionalities:
 *  - Sender and receiver account validation
 *  - Balance verification
 *  - Money debit and credit operations
 *  - Transaction history handling
 *  - File/database update handling
 *
 * Module Name  : Money Transfer Module
 * Project      : Banking Management System
 ******************************************************************************/

#include "moneyTransfer.h"
//#include "AppMain.h"
#include "generalOperation.h"
#include <ctime>

/******************************************************************************
 * Function Name : moneyTransferFun
 * Description   :
 * Performs money transfer operation between two valid accounts.
 *
 * Flow:
 *  1. Read all account data
 *  2. Validate sender account
 *  3. Validate receiver account
 *  4. Validate available balance
 *  5. Debit sender balance
 *  6. Credit receiver balance
 *  7. Store transaction history
 *  8. Update account database/file
 *
 * Parameters    : None
 * Return Type   : void
 ******************************************************************************/
void moneyTransN::moneyTransC::moneyTransferFun()
{
    generalOperationN::generalOperationC genObj;
    fileHandlingN::fileHandlingC fileObj;
    bankingOperationN::bankingOperationC bankObj;

    std::vector<accountDetailsN::accountDetailsC> accVect;

    /* Transaction object for credit entry */
    transHistN::transHistC txnObjCre;
    std::vector<transHistN::transHistC> vecTxnCre;

    /* Transaction object for debit entry */
    transHistN::transHistC txnObjDeb;
    std::vector<transHistN::transHistC> vecTxnDeb;   

    /* Current system time */
    std::time_t now = std::time(0);

    genObj.clearScreen();
    genObj.welcomeBank();

    std::cout<<"Money Transfer Section\n";

    unsigned int accountNumberS = 0;
    unsigned int accountNumberR = 0;

    int ammount = 0;

    int index1;
    int index2;

    int balanceR;
    int balanceS;

    /**********************************************************************
     * Sender Account Input
     **********************************************************************/
    accountNumberS = genObj.intIput
    (
        "Enter Sender Account Number : "
    );

    /**********************************************************************
     * Read Complete Account Data
     **********************************************************************/
    bool boStatus = fileObj.readFullData(accVect);

    if(boStatus != true)
    {
        std::cout<<"Read Fail\n";
        return;
    }

    /**********************************************************************
     * Validate Sender Account
     **********************************************************************/
    bool accValid = bankObj.validateAcc
    (
        accVect,
        accountNumberS,
        &index1
    );

    bool moneyValid = false;

    if(accValid == true)
    {
        /******************************************************************
         * Receiver Account Input
         ******************************************************************/
        accountNumberR = genObj.intIput
        (
            "Enter Receiver Account Number : "
        );

        /******************************************************************
         * Validate Receiver Account
         ******************************************************************/
        accValid = bankObj.validateAcc
        (
            accVect,
            accountNumberR,
            &index2
        );

        if(accValid == true)
        {
            /**************************************************************
             * Enter Transfer Amount
             **************************************************************/
            ammount = bankObj.enterMoney(2);

            /**************************************************************
             * Validate Sufficient Balance
             **************************************************************/
            moneyValid = moneyValidFun
            (
                accVect,
                ammount,
                index1
            );

            if(moneyValid == true)
            {
                /**********************************************************
                 * Debit Amount From Sender Account
                 **********************************************************/
                balanceS = accVect[index1].getAccountBalance();

                balanceS = balanceS - ammount;

                accVect[index1].updateAccount(balanceS);

                /**********************************************************
                 * Store Debit Transaction History
                 **********************************************************/
                std::string dt = std::ctime(&now);

                txnObjDeb.creditDebitVar  = 'D';
                txnObjDeb.timeDate        = dt;
                txnObjDeb.accoutNum       = accountNumberS;
                txnObjDeb.ammount         = ammount;

                vecTxnDeb.push_back(txnObjDeb);

                bool writeTxnFileDeb =
                txnObjDeb.writeTxnHistory(vecTxnDeb);

                if(writeTxnFileDeb == false)
                {
                    std::cout<<"Data Not Saved!\n";
                }

                /**********************************************************
                 * Credit Amount To Receiver Account
                 **********************************************************/
                balanceR = accVect[index2].getAccountBalance();

                balanceR = balanceR + ammount;

                accVect[index2].updateAccount(balanceR);

                /**********************************************************
                 * Store Credit Transaction History
                 **********************************************************/
                std::string dt1 = std::ctime(&now);

                txnObjCre.creditDebitVar  = 'C';
                txnObjCre.timeDate        = dt1;
                txnObjCre.accoutNum       = accountNumberR;
                txnObjCre.ammount         = ammount;

                vecTxnCre.push_back(txnObjCre);

                bool writeTxnFileCre =
                txnObjCre.writeTxnHistory(vecTxnCre);

                if(writeTxnFileCre == false)
                {
                    std::cout<<"Data Not Saved!\n";
                }

                /**********************************************************
                 * Clear Old Data And Update New Data
                 **********************************************************/
                fileObj.clearData();

                boStatus = fileObj.writeFullData(accVect);

                if(boStatus == true)
                {
                    std::cout
                    <<"Money Transfer Done!"
                    <<std::endl;
                }
                else
                {
                    std::cout
                    <<"Money Transfer Fail!"
                    <<std::endl;
                }
            }
        }
    }
}

/******************************************************************************
 * Function Name : moneyValidFun
 * Description   :
 * Checks whether sender account has sufficient balance for
 * requested money transfer.
 *
 * Parameters    :
 *  ver   -> Vector containing account details
 *  money -> Requested transfer amount
 *  index -> Sender account index
 *
 * Return Type   :
 *  true  -> Sufficient balance available
 *  false -> Insufficient balance
 ******************************************************************************/
bool moneyTransN::moneyTransC::moneyValidFun
(
    std::vector<accountDetailsN::accountDetailsC> ver,
    int money,
    int index
)
{
    bool ret = false;

    int balance = ver[index].getAccountBalance();

    if(balance > money)
    {
        ret = true;
    }
    else
    {
        std::cout<<"Insufficiant Balance \n";
    }

    return ret;
}