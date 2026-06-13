/*****************************************************
#   File Name   :   bankingOperation.cpp
#   Description :   This define Account data details.
#                   like name, address, account number etc
#   Note        :   None.
*****************************************************/


//include the headers 
#include"generalOperation.h"
#include"bankingOperation.h"
#include "transactionHistory.h"
#include <ctime>

/*****************************************************
#   Function Name   :   openingAccount
#   Description     :   handle the opening account functionality.
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::openingAccount()
{
    //!< object creation
    generalOperationN::generalOperationC genObj;

    //!< init the flag.
    bool checkStatus=false;

    //!< clear the screen.
    genObj.clearScreen();
    genObj.welcomeBank();
   
    //!< application form entry.
    std::cout<<"Opening New Account Department\n";
    std::cout<<"Fill Application Form\n";

    //!< object creation.
    accountDetailsN::accountDetailsC obj;
    fileHandlingN::fileHandlingC fileObj;


    //!< taking entry from user
    obj.setData();

    //!< write data in file.
    checkStatus = fileObj.writeDataInExcel(obj);

    //!< if write successfull then save data.
    if(checkStatus == true)
    {
        genObj.clearScreen();
        std::cout<<"Wait For Sometime\n";
        genObj.delay(2);
        genObj.clearScreen();
        std::cout<<"Save Data Successfull\n";
    }
}
/*****************************************************
#   Function Name   :   depositAmmount
#   Description     :   handle the deposite ammount functionality.
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::depositAmmount()
{
    //!< object creation.
    accountDetailsN::accountDetailsC obj;
    fileHandlingN::fileHandlingC fileObj;
    generalOperationN::generalOperationC genObj;
    transHistN::transHistC trxnObj;

    //!< local variable for account number.
    unsigned int accountNum=0;

    //!< vector creation
    std::vector<transHistN::transHistC>vecTxn;
    //!< local variable for indexing.
    int index;
    //!< vector for account data reading.
    std::vector<accountDetailsN::accountDetailsC>ver;

    //!< reading time.
    std::time_t now = std::time(0);

    //!< clear screen and welcome message
    genObj.clearScreen();
    genObj.welcomeBank();

    std::cout<<"Deposit Money \n";

    //!< read data from file.
    bool boStatus = fileObj.readFullData(ver);

    //!< if read not successfull return from funtion.
    if(boStatus!=true)
    {
        std::cout<<"Read Not Successfull\n";
        return;
    }
   
    //!< ask account number.
    accountNum = genObj.intIput("Account Number For Deposit Money :");

    //!< validate account number.
    bool boAccountValid = validateAcc(ver,accountNum,&index);

    //!< if account number is valid then 
    if(boAccountValid)
    {
        //!< print headers and client details.
        dumyPrintDeposit();
        printClintDetails(ver,index);

        //!<time collect.
        std::string dt = std::ctime(&now);

        //!< save data for transaction history.
        trxnObj.creditDebitVar = 'C';
        trxnObj.timeDate = dt;
        trxnObj.accoutNum = accountNum;
        trxnObj.ammount = depositOperaionPerform(ver,index);

        //!< fill data in vector.
        vecTxn.push_back(trxnObj);
        //!< write data in transaction history file.
        bool retTxn = trxnObj.writeTxnHistory(vecTxn);
        if(retTxn == true)
        {
            std::cout<<"Data Saved!"<<std::endl;
            genObj.delay(2);
        }
        //!< write data in accountdetails file.
        fileObj.clearData();
        bool ret = fileObj.writeFullData(ver);
        if(ret==true)
        {
            std::cout<<"Write Data Successfully\n";
        }
    }
    else
    {
        std::cout<<"Account Number Not Found\n";
    }
}
/*****************************************************
#   Function Name   :   withdrawalAmmount
#   Description     :   handle the withdrawal ammount operations.
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::withdrawalAmmount()
{
    //!< Local objects
    accountDetailsN::accountDetailsC obj;
    fileHandlingN::fileHandlingC fileObj;
    generalOperationN::generalOperationC genObj;
    transHistN::transHistC trxnObj;

    //!< Local vector
    std::vector<transHistN::transHistC>vecTxn;
    std::vector<accountDetailsN::accountDetailsC>ver;

    //!< Local Variable
    unsigned int accountNum=0;
    int index;

    //!< for time creation.
    std::time_t now = std::time(0);

    //!< clear screen and bank message
    genObj.clearScreen();
    genObj.welcomeBank();
   
    std::cout<<"Withdrawal Money \n";

    //!< read data from AccountDetails.csv
    bool boStatus = fileObj.readFullData(ver);

    if(boStatus!=true)
    {//!<if read fail
        std::cout<<"Read Not Successfully\n";
        return;
    }
    //!< taking account number from user.
    accountNum = genObj.intIput("Account Number For Withdrawal Money : ");

    //!< validate account number.
    bool boAccountValid = validateAcc(ver,accountNum,&index);

    //!< if account number is valid.
    if(boAccountValid)
    {
        //!< print header and client details.
        dumyPrintWithDrawal();
        printClintDetails(ver,index);
        //!< time collect.
        std::string dt = std::ctime(&now);

        //!< save data for transaction history file.
        trxnObj.creditDebitVar = 'D';
        trxnObj.timeDate = dt;
        trxnObj.accoutNum = accountNum;
        trxnObj.ammount = withdrwalOperaionPerform(ver,index);

        //!< save data in vector.
        vecTxn.push_back(trxnObj);
        //!< write data in TransactionHistory.csv
        bool retTxn = trxnObj.writeTxnHistory(vecTxn);

        if(retTxn == true)
        {//!< if write successfully
            std::cout<<"Data Saved!"<<std::endl;
            genObj.delay(2);
        }
        //!< clear data because of updatation.
        fileObj.clearData();
        //!< write data in AccountDetails.csv.
        bool ret = fileObj.writeFullData(ver);
        if(ret==true)
        {//!< if write successfully.
            std::cout<<"Write Data Successfully\n";
        }
    }
    else
    {//if account number is not found.
        std::cout<<"Account Number Not Found\n";
    }
}
/*****************************************************
#   Function Name   :   printClintDetails
#   Description     :   this function print the client details
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::printClintDetails
(
    std::vector<accountDetailsN::accountDetailsC>ver,
    int index
)
{
    //!< local object
    generalOperationN::generalOperationC genObj;
    //!< clear screen and bank name.
    genObj.clearScreen();
    genObj.welcomeBank();
    std::cout<<"Client Details : \n";

    //!< collect account details.
    unsigned int accountNumber      =ver[index].getAccountNumber();
    unsigned int accountBalance     =ver[index].getAccountBalance();
    unsigned int accountPinCity     =ver[index].getAccountPinCity();
    long long    accountMobileNum   =ver[index].getAccountMobileNum();
    std::string  accountName        =ver[index].getAccountName();
    std::string  accountAddress     =ver[index].getAccountAddress();   
    //!< print Account details.
    std::cout<<"Account Holder Name     :- "<<accountName<<std::endl;
    std::cout<<"Account Holder Address  :- "<<accountAddress<<std::endl;
    std::cout<<"Account Holder Pin Code :- "<<accountPinCity<<std::endl;
    std::cout<<"Account Number          :- "<<accountNumber<<std::endl;
    std::cout<<"Account Mobile          :- "<<accountMobileNum<<std::endl;
    std::cout<<"Account Balance         :- "<<accountBalance<<std::endl;
    
}
/*****************************************************
#   Function Name   :   dumyPrintDeposit
#   Description     :   this function print the basic messages 
#                       related to deposit functionality.
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::dumyPrintDeposit()
{
    generalOperationN::generalOperationC genObj;
    genObj.clearScreen();
    genObj.welcomeBank();
    std::cout<<"Deposit Money Section\n";
    std::cout<<"Finding Account Details\n";
    genObj.delay(2);
}
/*****************************************************
#   Function Name   :   dumyPrintWithDrawal
#   Description     :   this function print the basic messages 
#                       related to withdrawal functionality.
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::dumyPrintWithDrawal()
{
    generalOperationN::generalOperationC genObj;
    genObj.clearScreen();
    genObj.welcomeBank();
    std::cout<<"Withdrawal Money Section\n";
    std::cout<<"Finding Account Details\n";
    genObj.delay(2);
}
/*****************************************************
#   Function Name   :   validateAcc
#   Description     :   this function print the basic messages 
#                       related to withdrawal functionality.
#   Note            :   None.
*****************************************************/
bool bankingOperationN::bankingOperationC::validateAcc
(
    std::vector<accountDetailsN::accountDetailsC>ver, 
    unsigned int acc,
    int *index
)
{
    //!< local variable.
    bool validate =false;
    unsigned int accountNumVer=0;

    //!< treverse the vector and check account number
    //!< is available or not.
    for(int i=0;i<(int)ver.size();i++)
    {
        //!< collect account number.
        accountNumVer = ver[i].getAccountNumber();
        if(acc==accountNumVer)
        {
            validate=true;
            *index =i;
            break;
        }
    }
    return validate;
}
/*****************************************************
#   Function Name   :   enterMoney
#   Description     :   this function take money from 
#                       user, based on
#                       1. deposit operation
#                       2. withdrawal operation
#                       3. transfer operation
#   Note            :   None.
*****************************************************/
int bankingOperationN::bankingOperationC::enterMoney(int flag)
{
    generalOperationN::generalOperationC genObj;
    int money;
    do
    {
        if(flag==0)//for deposit ammount
        {
            money = genObj.intIput("Enter Deposit Money : ");
        }
        else if(flag==1)//for deposit ammount
        {
            money = genObj.intIput("Enter Withdrawal Money: ");
        }
        else if(flag==2)//for deposit ammount
        {
            money = genObj.intIput("Enter Transfer Money: ");
        } 
    }while(money<0);

    return money;
}
/*****************************************************
#   Function Name   :   depositOperaionPerform
#   Description     :   this function perform deposite
#                       operations, addition to
#                       bank balance.
#   Note            :   None.
*****************************************************/
int bankingOperationN::bankingOperationC::depositOperaionPerform(
    std::vector<accountDetailsN::accountDetailsC>&ver,
    int index
)
{
    //!< local variables
    int money;
    int balance;
    std::cout<<"---------------------------------\n";

    money = enterMoney(0);

    balance = ver[index].getAccountBalance();

    //!< add amount in bank balance.
    int newBalance = balance + money;
    ver[index].updateAccount(newBalance);
    std::cout<<"New Balance :- "<<ver[index].getAccountBalance()<<std::endl;
    return money;
}
/*****************************************************
#   Function Name   :   withdrwalOperaionPerform
#   Description     :   this function perform withdrawal
#                       operations, substract from
#                       bank balance.
#   Note            :   None.
*****************************************************/
int bankingOperationN::bankingOperationC::withdrwalOperaionPerform(
    std::vector<accountDetailsN::accountDetailsC>&ver,
    int index
)
{
    int money;
    int balance;
    std::cout<<"---------------------------------\n";
    

    money = enterMoney(1);
    balance = ver[index].getAccountBalance();

    if(balance<money)
    {
        std::cout<<"Insufficiant balance\n";
    }
    else
    {
        //!< withdrawal operations
        int newBalance = balance - money;
        ver[index].updateAccount(newBalance);
        std::cout<<"New Balance :- "<<ver[index].getAccountBalance()<<std::endl;
    }
    return money;
}
/*****************************************************
#   Function Name   :   displayBalance
#   Description     :   this function perform display
#                       balance operations.
#                       as per mobile and as per account
#                       number.
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::displayBalance()
{
    //!< local objects.
    accountDetailsN::accountDetailsC obj;
    fileHandlingN::fileHandlingC fileObj;
    generalOperationN::generalOperationC genObj;

    //!< local vector.
    std::vector<accountDetailsN::accountDetailsC>ver;
    //!< local variable.
    int displayBalanceOpt = 0;

    //!< clear screen and bank name display.
    genObj.clearScreen();
    genObj.welcomeBank();
    
    //!< read data from file AccountDetails.csv
    bool boStatus = fileObj.readFullData(ver);

    if(boStatus == true)
    {   
        //!< take option from user. 
        displayBalanceOpt = genObj.intIput
                            (
                                "Display Balnce\n1) As Per Account Number\n2) As Per Mobile Number"
                            );
        //!< collect data.
        switch(displayBalanceOpt)
        {
            case 1:
                //!< display data as per account number.
                displayBalanceAcc(ver);
            break;
            case 2:
                //!< display data as per mobile number.
                displayBalanceMobile(ver);
            break;
            default:
                //!< if wrong option selected.
                std::cout<<"Wrong Option Selected\n";
            break;
        }
    }
}
/*****************************************************
#   Function Name   :   displayBalanceAcc
#   Description     :   this function print the balance
#                       as per account number.
#            
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::displayBalanceAcc
(
    std::vector<accountDetailsN::accountDetailsC>ver
)
{
    generalOperationN::generalOperationC genObj;
    int acc = 0;
    int index=0;
    int accVer=0;
    genObj.clearScreen();
    genObj.welcomeBank();

    acc = genObj.intIput("Enter Account Number For Display Balance : ");

    bool boAccountValid = validateAcc(ver,acc,&index);
    if(boAccountValid == true)
    {
        for(int i=0;i<(int)ver.size();i++)
        {
            accVer = ver[i].getAccountNumber();
            if(acc == accVer)
            {
                genObj.clearScreen();
                genObj.welcomeBank();
                std::cout<<"Account Number = "<<accVer<<std::endl;
                std::cout<<"Current Balance = "<<ver[i].getAccountBalance()<<std::endl;
                break;
            }
        }
    }
}
/*****************************************************
#   Function Name   :   displayBalanceMobile
#   Description     :   this function print the balance
#                       as per Mobile number.
#            
#   Note            :   None.
*****************************************************/
void bankingOperationN::bankingOperationC::displayBalanceMobile(std::vector<accountDetailsN::accountDetailsC>ver)
{
    generalOperationN::generalOperationC genObj;
    long long mb    =   0;
    int index       =   0;
    long long mbVer    =   0;
    genObj.clearScreen();
    genObj.welcomeBank();
    
    mb = genObj.longIput("Enter Mobile Number For Display Balance : ");

    bool boAccountValid = validateMbNumber(ver,mb,&index);
    if(boAccountValid == true)
    {
        for(int i=0;i<(int)ver.size();i++)
        {
            mbVer = ver[i].getAccountMobileNum();
            if(mb == mbVer)
            {
                genObj.clearScreen();
                genObj.welcomeBank();
                std::cout<<"Mobile Number = "<<mbVer<<std::endl;
                std::cout<<"Current Balance = "<<ver[i].getAccountBalance()<<std::endl;
                break;
            }
        }
    }
}
/*****************************************************
#   Function Name   :   validateMbNumber
#   Description     :   this function validate mobile number 
#                       is available or not in data.
#            
#   Note            :   None.
*****************************************************/
bool bankingOperationN::bankingOperationC::validateMbNumber
(
    std::vector<accountDetailsN::accountDetailsC>ver, 
    long long mb,
    int *index
)
{
    generalOperationN::generalOperationC genObj;
    bool validate =false;
    long long mbNumVer=0;

    genObj.welcomeBank();
   
    for(int i=0;i<(int)ver.size();i++)
    {
        mbNumVer = ver[i].getAccountMobileNum();
        if(mb == mbNumVer)
        {
            std::cout<<"Validate Mobile Number Successfully\n";
            validate=true;
            *index =i;
            break;
        }
    }
    return validate;
}
/*****************************************************
#   Function Name   :   validateAccNumAsPerAcc
#   Description     :   this function validate acc number 
#                       is available or not in data.
#            
#   Note            :   None.
*****************************************************/
bool bankingOperationN::bankingOperationC::validateAccNumAsPerAcc
(
    unsigned int accountNumber
)
{
    bool retVal = false;

    accountDetailsN::accountDetailsC obj;
    fileHandlingN::fileHandlingC fileObj;

    std::vector<accountDetailsN::accountDetailsC>ver;

    bool boStatus = fileObj.readFullData(ver);
    unsigned int temAcc;
    if(boStatus == true)
    {
        for(int i=0;i<(int)ver.size();i++)
        {
            temAcc = ver[i].getAccountNumber();
            if(accountNumber == temAcc)
            {
                retVal = true;
                break;
            }
        }
    }
    return retVal;
}