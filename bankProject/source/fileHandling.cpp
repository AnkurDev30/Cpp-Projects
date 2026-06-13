/*****************************************************
#   File Name   :   fileHandling.cpp
#   Description :   This define Account data details.
#                   like name, address, account number etc
#   Note        :   None.
*****************************************************/

//!< include headers.
#include"fileHandling.h"
#include <sstream>
#include"accountDetails.h"

/*****************************************************
#   Function Name   :   writeDataInExcel
#   Description     :   this function write data in AccountDetails.csv
#                       file.
#   Note            :   None.
*****************************************************/
bool fileHandlingN::fileHandlingC:: writeDataInExcel
(
    accountDetailsN::accountDetailsC &Obj
)
{
    //!< local variables
    bool checkStatus =false;
    unsigned int accountNumber = Obj.getAccountNumber();
    unsigned int accountBalance= Obj.getAccountBalance();
    unsigned int accountPinCity= Obj.getAccountPinCity();
    long long accountMobileNum = Obj.getAccountMobileNum();
    std::string accountName    = Obj.getAccountName();
    std::string accountAddress = Obj.getAccountAddress(); 

    //!open file in append mode.bankProject/
    std::ofstream file3("data/AccountDetails.csv",std::ios::app);

    //!open file in read mode.
    std::ifstream file4("data/AccountDetails.csv",std::ios::in);

    //!< if file is open 
    if(file3.is_open()==true)
    {
        if(file4.is_open()==true)
        {
            if(file4.peek() == EOF)
            {
                //!< headers write.
                file3<<"Balance Sheet"<<std::endl;
                file3<<"Account Number"<<","<<"Account Balance"<<","<<"Name"<<","<<"Address"<<","<<"Pin Code"<<","<<"Mobile"<<","<<std::endl;
            }
        }
        else
        {
            std::cout<<"read file not open\n";
        }
        //!< write data.
        file3<<accountNumber<<","<<accountBalance<<","<<accountName<<","<<accountAddress<<","<<accountPinCity<<","<<accountMobileNum<<","<<std::endl;        
        checkStatus = true;
    }
    else
    {
        std::cout<<"write file not open\n";
    }
    return checkStatus;
}
/*****************************************************
#   Function Name   :   readFullData
#   Description     :   this function read full data from
#                       AccountDetails.csv
#                       file.
#   Note            :   None.
*****************************************************/
bool fileHandlingN::fileHandlingC::readFullData
(
    std::vector <accountDetailsN::accountDetailsC> &ver
)
{
    //!< local variables
    bool ret;
    accountDetailsN::accountDetailsC obj;

    //!< read file.
    std::ifstream file1("data/AccountDetails.csv");
    //!< string for read.
    std::string line;

    //!< if file is open successfully.
    if(file1.is_open()==true)
    {
        getline(file1, line);//!< first balnce sheet ignore.
        getline(file1, line);//!< header ignore.
        while(getline(file1,line))
        {//!< read full data.
            std::stringstream ss(line);

            std::string accountNumber       ;
            std::string accountBalance      ;
            std::string accountName         ;
            std::string accountAddress      ; 
            std::string accountPinCity      ; 
            std::string accountMobileNum    ;
       
            getline(ss,accountNumber   ,',');
            getline(ss,accountBalance  ,',');
            getline(ss,accountName     ,',');
            getline(ss,accountAddress  ,',');
            getline(ss,accountPinCity  ,',');
            getline(ss,accountMobileNum,',');

            unsigned int tempAccountNumber       = 0;
            unsigned int tempAccountBalance      = 0;
            unsigned int tempAccountPinCity      = 0;
            long long    tempAccountMobileNum    = 0;

            std::stringstream(accountNumber) >> tempAccountNumber;
            std::stringstream(accountBalance) >> tempAccountBalance;
            std::stringstream(accountPinCity) >> tempAccountPinCity;
            std::stringstream(accountMobileNum) >> tempAccountMobileNum;

            obj.setAccountNumber   (tempAccountNumber);
            obj.setAccountBalance  (tempAccountBalance);
            obj.setAccountPinCity  (tempAccountPinCity);
            obj.setAccountMobileNum(tempAccountMobileNum);
            obj.setAccountName     (accountName );
            obj.setAccountAddress  (accountAddress ); 

            //!< update vector.
            ver.push_back(obj);
            ret = true;
        }
    }
    else
    {
        ret=false;
    }
    return ret;
}
/*****************************************************
#   Function Name   :   clearData
#   Description     :   make empty the file.
#   Note            :   None.
*****************************************************/
void fileHandlingN::fileHandlingC::clearData()
{
    std::ofstream file("data/AccountDetails.csv", std::ios::trunc);
    file.close();
}
/*****************************************************
#   Function Name   :   writeFullData
#   Description     :   write full vector data function.
#   Note            :   None.
*****************************************************/
bool fileHandlingN::fileHandlingC::writeFullData
(
    std::vector <accountDetailsN::accountDetailsC> &ver
)
{
    bool ret;
    std::ofstream file1("data/AccountDetails.csv",std::ios::out);

    std::string line;

    if(file1.is_open()==true)
    {
        file1<<"Balance Sheet"<<std::endl;
        file1<<"Account Number"<<","
            <<"Account Balance"<<","
            <<"Name"<<","
            <<"Address"<<","
            <<"Pin Code"<<","
            <<"Mobile"<<","
            <<std::endl;      

        for(int i=0;i<(int)ver.size();i++)
        {
            unsigned int accountNumber      =ver[i].getAccountNumber();
            unsigned int accountBalance     =ver[i].getAccountBalance();
            unsigned int accountPinCity     =ver[i].getAccountPinCity();
            long long    accountMobileNum   =ver[i].getAccountMobileNum();
            std::string  accountName        =ver[i].getAccountName();
            std::string  accountAddress     =ver[i].getAccountAddress(); 

            file1<<accountNumber<<","
            <<accountBalance<<","
            <<accountName<<","
            <<accountAddress<<","
            <<accountPinCity<<","
            <<accountMobileNum<<","
            <<std::endl;                   
        } 
        ret=true; 
    }
    else
    {
        ret=false;
    }
    return ret;
}