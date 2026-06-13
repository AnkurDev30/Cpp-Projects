/******************************************************************************
 * File Name    : transactionHistory.cpp
 * Description  :
 * This file contains implementation of transaction history handling
 * for the Banking Management System.
 *
 * Functionalities:
 *  - Store transaction history into CSV file
 *  - Read transaction history from CSV file
 *  - Display transaction history for a specific account
 *  - Print formatted transaction history table
 *
 * Module Name  : Transaction History Module
 * Project      : Banking Management System
 ******************************************************************************/

#include "transactionHistory.h"
#include <sstream>
//#include "AppMain.h"
#include "generalOperation.h"
#include <iomanip>

/******************************************************************************
 * Function Name : writeTxnHistory
 * Description   :
 * Writes transaction history records into CSV file.
 *
 * File Format:
 * AccountNumber,Amount,Credit/Debit,DateTime
 *
 * Parameters    :
 * wrTxnVec -> Vector containing transaction history records
 *
 * Return Type   :
 * true  -> Data written successfully
 * false -> File open/write failed
 ******************************************************************************/
bool transHistN::transHistC::writeTxnHistory
(
    std::vector<transHistN::transHistC> &wrTxnVec
)
{
    std::ofstream file
    (
        "data/TransactionHistory.csv",
        std::ios::app
    );

    bool ret = false;

    if(file.is_open() == true)
    {
        for(int i=0; i<(int)wrTxnVec.size(); i++)
        {
            file << wrTxnVec[i].accoutNum      << ","
                 << wrTxnVec[i].ammount        << ","
                 << wrTxnVec[i].creditDebitVar << ","
                 << wrTxnVec[i].timeDate;
        }

        ret = true;
    }
    else
    {
        ret = false;
    }

    return ret;
}

/******************************************************************************
 * Function Name : readTxnHistory
 * Description   :
 * Reads transaction history data from CSV file and stores
 * it into vector.
 *
 * Parameters    :
 * wrTxnVec -> Vector used to store transaction history records
 *
 * Return Type   :
 * true  -> Data read successfully
 * false -> File open/read failed
 ******************************************************************************/
bool transHistN::transHistC::readTxnHistory
(
    std::vector<transHistN::transHistC> &wrTxnVec
)
{
    std::ifstream file1
    (
        "data/TransactionHistory.csv",
        std::ios::in
    );

    transHistN::transHistC obj;

    std::string line;

    bool ret = false;

    int acn;
    int acMoney;

    if(file1.is_open() == true)
    {
        while(getline(file1,line))
        {
            std::stringstream ss(line);

            std::string accNumber;
            std::string accMoney;
            std::string creDebVar;
            std::string timeDate;

            /**************************************************************
             * Read CSV Data
             **************************************************************/
            getline(ss,accNumber,',');
            getline(ss,accMoney,',');
            getline(ss,creDebVar,',');
            getline(ss,timeDate,',');

            /**************************************************************
             * Store Character And Date Information
             **************************************************************/
            obj.creditDebitVar = creDebVar[0];

            obj.timeDate = timeDate;

            /**************************************************************
             * Convert String To Integer
             **************************************************************/
            std::stringstream(accNumber) >> acn;

            std::stringstream(accMoney) >> acMoney;

            /**************************************************************
             * Store Final Data Into Object
             **************************************************************/
            obj.accoutNum = acn;

            obj.ammount = acMoney;

            ret = true;

            wrTxnVec.push_back(obj);
        }
    }
    else
    {
        ret = false;
    }

    return ret;
}

/******************************************************************************
 * Function Name : transactionHistory
 * Description   :
 * Displays transaction history for entered account number.
 *
 * Features:
 *  - Reads transaction history file
 *  - Filters transactions based on account number
 *  - Displays formatted transaction table
 *
 * Parameters    : None
 * Return Type   : void
 ******************************************************************************/
void transHistN::transHistC::transactionHistory()
{
    generalOperationN::generalOperationC genObj;

    genObj.clearScreen();

    genObj.welcomeBank();

    int printHandl = 0;

    int accountNum = 0;

    bool flagCheck = false;

    std::vector<transHistN::transHistC> readVec;

    std::cout<<"Transaction History : \n";

    /**********************************************************************
     * User Input For Account Number
     **********************************************************************/
    accountNum = genObj.intIput
    (
        "Enter Account Number :"
    );

    /**********************************************************************
     * Read Transaction History File
     **********************************************************************/
    bool readValid = readTxnHistory(readVec);

    if(readValid == true)
    {
        genObj.clearScreen();

        //genObj.welcomeBank();

        for(int i=0; i<(int)readVec.size(); i++)
        {
            /**************************************************************
             * Match Account Number
             **************************************************************/
            if(readVec[i].accoutNum == accountNum)
            {
                /**********************************************************
                 * Print Header Only One Time
                 **********************************************************/
                if(printHandl == 0)
                {
                    printTranxHistoryHrader(accountNum);

                    printHandl++;
                }

                flagCheck = true;

                /**********************************************************
                 * Print Transaction Record
                 **********************************************************/
                std::cout<<"| "
                <<std::left<<std::setw(14)
                <<readVec[i].ammount

                <<"| "
                <<std::left<<std::setw(14)
                <<readVec[i].creditDebitVar

                <<"| "
                <<std::left<<std::setw(25)
                <<readVec[i].timeDate

                <<std::endl;
            }
        }

        /******************************************************************
         * No Transaction Available
         ******************************************************************/
        if(flagCheck == false)
        {
            std::cout<<"Account Number :"
            <<accountNum
            <<" Have Not Any Transaction Hisory\n";
        }

        /******************************************************************
         * Print Footer Line
         ******************************************************************/
        for(int i=0; i<58; i++)
        {
            std::cout<<"-";
        }

        std::cout<<std::endl;
    }
}

/******************************************************************************
 * Function Name : printTranxHistoryHrader
 * Description   :
 * Prints formatted transaction history table header.
 *
 * Parameters    :
 * accountNum -> Account number whose transaction history is displayed
 *
 * Return Type   : void
 ******************************************************************************/
void transHistN::transHistC::printTranxHistoryHrader(int accountNum)
{
    /**********************************************************************
     * Print Top Border
     **********************************************************************/
    for(int i=0; i<58; i++)
    {
        std::cout<<"-";
    }

    std::cout<<std::endl;

    /**********************************************************************
     * Print Account Information
     **********************************************************************/
    std::cout
    <<"Transaction History Account Number : "
    <<accountNum
    <<std::endl;

    for(int i=0; i<58; i++)
    {
        std::cout<<"-";
    }

    std::cout<<std::endl;

    /**********************************************************************
     * Print Table Column Header
     **********************************************************************/
    std::cout<<"| "
             <<std::left<<std::setw(14)
             <<"Amount"

             <<"| "
             <<std::left<<std::setw(14)
             <<"Credit/ Debit"

             <<"| "
             <<std::left<<std::setw(25)
             <<"Date &Time"

             <<std::endl;

    /**********************************************************************
     * Print Bottom Border
     **********************************************************************/
    for(int i=0; i<58; i++)
    {
        std::cout<<"-";
    }

    std::cout<<std::endl;
}