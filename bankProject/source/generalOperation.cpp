/******************************************************************************
 * File Name    : generalOperation.cpp
 * Description  : 
 * This file contains the implementation of general banking utility operations.
 * It handles:
 *  - User login validation
 *  - Menu display and startup flow
 *  - Screen clearing utilities
 *  - Delay functionality
 *  - Integer and long integer validated input handling
 *  - Banking operation menu selection
 *
 * Module Name  : General Operations Module
 * Project      : Banking Management System
 ******************************************************************************/

#include "generalOperation.h"

/******************************************************************************
 * Function Name : cinIgnore
 * Description   : Clears the input buffer to avoid unwanted newline issues.
 * Parameters    : None
 * Return Type   : void
 ******************************************************************************/
void generalOperationN::generalOperationC::cinIgnore()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/******************************************************************************
 * Function Name : clearScreen
 * Description   : Clears terminal/console screen based on operating system.
 * Parameters    : None
 * Return Type   : void
 ******************************************************************************/
void generalOperationN::generalOperationC::clearScreen()
{
    #ifdef _WIN32
        system("cls");     // Windows
    #else
        system("clear");   // Linux/Ubuntu
    #endif
}

/******************************************************************************
 * Function Name : welcomeBank
 * Description   : Displays bank welcome banner/message.
 * Parameters    : None
 * Return Type   : void
 ******************************************************************************/
void generalOperationN::generalOperationC::welcomeBank()
{
    std::cout<<"------------------------------------------\n";
    std::cout<<WELCOME_MSG<<std::endl;
    std::cout<<"------------------------------------------\n";
}

/******************************************************************************
 * Function Name : delay
 * Description   : Provides delay for specified seconds.
 * Parameters    : sec -> Delay time in seconds
 * Return Type   : void
 ******************************************************************************/
void generalOperationN::generalOperationC::delay(int sec)
{
    std::this_thread::sleep_for
    (
        std::chrono::seconds(sec)
    );
}

/******************************************************************************
 * Function Name : loginCheck
 * Description   : Validates login ID and password entered by user.
 * Parameters    : None
 * Return Type   : bool
 *                  true  -> Login successful
 *                  false -> Login failed
 ******************************************************************************/
bool generalOperationN::generalOperationC::loginCheck()
{
    std::string loginID;
    int passKey=0;
    bool boStatusLogin = false;

    std::cout<<"enter login Id : "<<std::endl;
    getline(std::cin,loginID);

    passKey = (int)intIput("enter passward  : ");

    if(loginID == LOGINID)
    {
        if(passKey == PASSKEY)
        {
            boStatusLogin= true;
        }
        else
        {
            std::cout<<"check passward\n";
            boStatusLogin= false;
        }
    }

    return boStatusLogin;
}

/******************************************************************************
 * Function Name : startUpFun
 * Description   : Main startup function for banking system.
 *                 Handles login, menu display and user operation flow.
 * Parameters    : None
 * Return Type   : void
 ******************************************************************************/
void generalOperationN::generalOperationC::startUpFun()
{
    generalOperationN::generalOperationC objGen;

    objGen.clearScreen();
    objGen.welcomeBank();

    char exitChar ='n'; 
    char option;

    bool boEntry = objGen.loginCheck();

    if(boEntry == true)
    {
        objGen.clearScreen();
        objGen.welcomeBank();

        std::cout<<"Waiting For Some Time\n";

        objGen.delay(5);

        std::cout<<"Login Successfull...\n";

        objGen.delay(2);

        do
        {
            objGen.clearScreen();
            objGen.welcomeBank();

            std::cout<<"Select The Option\n";
            std::cout<<"1) Opening New Account\t";
            std::cout<<"2) Withdrawl Ammount\n";
            std::cout<<"3) Deposit Ammount\t";
            std::cout<<"4) Display Balance\n";
            std::cout<<"5) Money Transfer\t";
            std::cout<<"6) Transaction History\n";

            std::cin>>option;

            cinIgnore();

            selectOption(option);

            std::cout<<"For Exit Press y\n";

            std::cin>>exitChar;

        }while(exitChar!='y'&& exitChar!='Y');

        objGen.clearScreen();

        std::cout<<"Thank You For Using "<<BANKNAME<<std::endl;
    }
    else
    {
        std::cout<<"Incorrect Id/ Passward\nRetry\n";
    }
}

/******************************************************************************
 * Function Name : selectOption
 * Description   : Performs banking operation based on selected menu option.
 * Parameters    : option -> User selected menu option
 * Return Type   : void
 ******************************************************************************/
void generalOperationN::generalOperationC::selectOption(char option)
{
    bankingOperationN::bankingOperationC bankObj;
    moneyTransN::moneyTransC objMoney;
    transHistN::transHistC txnOb;

    switch(option)
    {
        case '1':
        {
            bankObj.openingAccount();
        }
        break;

        case '2':
        {
            bankObj.withdrawalAmmount();
        }
        break;

        case '3':
        {
            bankObj.depositAmmount();
        }
        break;

        case '4':
        {
            bankObj.displayBalance();
        }
        break;

        case '5':
        {
            // Money transfer operation
            objMoney.moneyTransferFun();
        }
        break;

        case '6':
        {
            // Transaction history operation
            txnOb.transactionHistory();
        }
        break;

        default:
        {
            std::cout<<"Please Select Correct Option\n";
        }
        break;
    }

    std::cout<<"Thank you!"<<std::endl;
}

/******************************************************************************
 * Function Name : intIput
 * Description   : Accepts validated unsigned integer input from user.
 *                 Rejects non-numeric characters.
 * Parameters    : str -> Input prompt message
 * Return Type   : unsigned int
 ******************************************************************************/
unsigned int generalOperationN::generalOperationC::intIput(std::string str)
{
    std::string strInp;
    bool boValidCHeck=true;
    unsigned int num = 0;

    do
    {
        boValidCHeck=true;

        std::cout<<str<<std::endl;

        getline(std::cin,strInp);

        for(int i=0;i<(int)strInp.length();i++)
        {
            if(!isdigit(strInp[i]))
            {
                boValidCHeck=false;
                break;
            }
        }

        if(boValidCHeck==true)
        {
            std::stringstream ss(strInp);
            ss>>num;
        }
        else
        {
            std::cout<<"Only Numbers Are Allowed\n";
        }

    }while(boValidCHeck==false);

    return num; 
}

/******************************************************************************
 * Function Name : longIput
 * Description   : Accepts validated long long integer input from user.
 *                 Rejects non-numeric characters.
 * Parameters    : str -> Input prompt message
 * Return Type   : long long
 ******************************************************************************/
long long generalOperationN::generalOperationC::longIput(std::string str)
{
    std::string strInp;
    bool boValidCHeck=true;
    long long num = 0;

    do
    {
        std::cout<<str<<std::endl;

        getline(std::cin,strInp);

        for(int i=0;i<(int)strInp.length();i++)
        {
            if(!isdigit(strInp[i]))
            {
                boValidCHeck=false;
                break;
            }
        }

        if(boValidCHeck==true)
        {
            std::stringstream ss(strInp);
            ss>>num;
        }
        else
        {
            std::cout<<"Only Numbers Are Allowed\n";
        }

    }while(boValidCHeck==false);

    return num; 
}