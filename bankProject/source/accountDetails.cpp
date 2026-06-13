//accountDetails.cpp

/*****************************************************
#   File Name   :   accountDetails.cpp
#   Description :   This define Account data details.
#                   like name, address, account number etc
#   Note        :   None.
*****************************************************/

//!< include headers
#include"accountDetails.h"
#include"generalOperation.h"

/*****************************************************
#   Function Name   :   cinIgnore
#   Description     :   this function handle the buffer
#                       after cin input.
#   Note            :   None.
*****************************************************/
void cinIgnore()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
/*****************************************************
#   Function Name   :   clearScreen
#   Description     :   this function clear the screen
#   Note            :   None.
*****************************************************/
void clearScreen()
{
    #ifdef _WIN32
        system("cls");     // Windows
    #else
        system("clear");   // Linux/Ubuntu
    #endif
}
/*****************************************************
#   Function Name   :   setAccountNumber
#   Description     :   this function set the accounter number
#   Note            :   None.
*****************************************************/
void accountDetailsN::accountDetailsC::setAccountNumber   (unsigned int acc)
{
    accountNumber = acc;
}
/*****************************************************
#   Function Name   :   setAccountBalance
#   Description     :   this function set the accounter balance
#   Note            :   None.
*****************************************************/
void accountDetailsN::accountDetailsC::setAccountBalance  (unsigned int acc)
{
    accountBalance= acc;
}
/*****************************************************
#   Function Name   :   setAccountPinCity
#   Description     :   this function set the pin code of user
#   Note            :   None.
*****************************************************/
void accountDetailsN::accountDetailsC::setAccountPinCity  (unsigned int acc)
{
    accountPinCity = acc;
}
/*****************************************************
#   Function Name   :   setAccountMobileNum
#   Description     :   this function set the mobile number of user
#   Note            :   None.
*****************************************************/
void accountDetailsN::accountDetailsC::setAccountMobileNum(long long   mb)
{
    accountMobileNum = mb;
}
/*****************************************************
#   Function Name   :   setAccountName
#   Description     :   this function set the name of user
#   Note            :   None.
*****************************************************/
void accountDetailsN::accountDetailsC::setAccountName     (std::string name)
{
    accountName = name;
}
/*****************************************************
#   Function Name   :   setAccountAddress
#   Description     :   this function set the address of user
#   Note            :   None.
*****************************************************/
void accountDetailsN::accountDetailsC::setAccountAddress  (std::string add)
{
    accountAddress = add;
}
/*****************************************************
#   Function Name   :   getAccountNumber
#   Description     :   this function provide the Account Number
#   Note            :   None.
*****************************************************/
unsigned int accountDetailsN::accountDetailsC:: getAccountNumber()
{
    return accountNumber;
}
/*****************************************************
#   Function Name   :   getAccountBalance
#   Description     :   this function provide the Account Balance
#   Note            :   None.
*****************************************************/
unsigned int accountDetailsN::accountDetailsC::getAccountBalance()
{
    return accountBalance;
}
/*****************************************************
#   Function Name   :   getAccountPinCity
#   Description     :   this function provide the Pin Code of user 
#   Note            :   None.
*****************************************************/
unsigned int accountDetailsN::accountDetailsC::getAccountPinCity()
{
    return accountPinCity;
}
/*****************************************************
#   Function Name   :   getAccountMobileNum
#   Description     :   this function provide the Mobile number
#                       of user 
#   Note            :   None.
*****************************************************/
long long accountDetailsN::accountDetailsC::getAccountMobileNum()
{
    return accountMobileNum;
}
/*****************************************************
#   Function Name   :   getAccountName
#   Description     :   this function provide the Name
#                       of user 
#   Note            :   None.
*****************************************************/
std::string accountDetailsN::accountDetailsC::getAccountName()
{
    return accountName;
}
/*****************************************************
#   Function Name   :   getAccountAddress
#   Description     :   this function provide the address
#                       of user 
#   Note            :   None.
*****************************************************/
std::string accountDetailsN::accountDetailsC::getAccountAddress()       
{
    return accountAddress;
} 
/*****************************************************
#   Function Name   :   nameCheck
#   Description     :   function check enterd name is 
#                       valid or not.
#                       name includes  uppercase, lower case and 
                        space
#   Note            :   None.
*****************************************************/
bool accountDetailsN::accountDetailsC::nameCheck(std::string name)
{
    bool nameOk=false;
    for(unsigned int i=0;i<name.length();i++)
    {
        if((name[i]>='a' && name[i]<='z')||
        (name[i]>='A' && name[i]<='Z')||(name[i]==' '))
        {
            nameOk=true;
        }
        else
        {
            nameOk=false;
            break;
        }
    }
    return nameOk;
}
/*****************************************************
#   Function Name   :   checkAccountNumber
#   Description     :   function check generated account number is 
#                       valid or not.
#                       account number is 4 digit and should 
#                       not duplicated
#   Note            :   None.
*****************************************************/
bool accountDetailsN::accountDetailsC::checkAccountNumber(unsigned int readGenratedAccNum)
{
    bool flag=false;
    unsigned int readAcctemp=0;
    std::ifstream file2("data/AccountNumSave.txt",std::ios::in);

    while(file2>>readAcctemp)
    {
        if(readAcctemp == readGenratedAccNum)
        {
            std::cout<<"account number available \n";
            flag=true;
            break;
        }
    }
    return flag;
}
/*****************************************************
#   Function Name   :   generateAccountNumber
#   Description     :   this function can generate the Acc Number
#                       Account number should be 4 digits.
#   Note            :   None.
*****************************************************/
int accountDetailsN::accountDetailsC::generateAccountNumber()
{
    unsigned int randomAccNum; 
    bool checkAcc;
    char charExp;
    do
    {
        std::cout<<"account number generating....\n";
        srand(time(0)); 

        std::ofstream file1("data/AccountNumSave.txt",std::ios::app);
        if(file1.is_open()==true)
        {
            randomAccNum = rand() % 9000 + 1000;
            
            checkAcc = checkAccountNumber(randomAccNum);

            if(checkAcc==true)
            {
                std::cout<<"need to genrate new account number\n";
                std::cout<<randomAccNum<<" is already available\n";
                std::cout<<"press y for new account number\n";
                std::cin>>charExp;

            }
            else
            {
                std::cout<<"generated account number : "<<randomAccNum<<std::endl;
                file1<<randomAccNum<<std::endl;
            }
            
        }
        file1.close();
    }while(checkAcc==true);

    return randomAccNum;
}
/*****************************************************
#   Function Name   :   setData
#   Description     :   this function take inforamation from user
#   Note            :   None.
*****************************************************/
void accountDetailsN::accountDetailsC::setData()
{
    bool nameCheckBool=false;
    generalOperationN::generalOperationC genObj;
    //name 
    do
    {
        std::cout<<"Enter Account Holder Name : \n";
        getline(std::cin,accountName);
        nameCheckBool = nameCheck(accountName);

        if(nameCheckBool == false)
        {
            std::cout<<"Name Should Be Upercase, Lowercase Or Space Only\n";
        }

    }while(nameCheckBool==false);

    //address
    std::cout<<"Enter Address : \n";
    getline(std::cin,accountAddress);

    //pin code
    do
    {
        accountPinCity = genObj.intIput("Enter Pin Code :");
        if(accountPinCity<100000)
        {
            std::cout<<"Pin Code Shoild Be 6 Digit \n";
        }
    }while(accountPinCity<100000);

    //mobile
    do
    {
        accountMobileNum = genObj.longIput("Enter Mobile Number :");
        if(accountMobileNum<=999999999)
        {
            std::cout<<"Mobile Numbner Shoild Be 10 Digit \n";
        }
    }while(accountMobileNum<=999999999);

    //generate Account number.
    accountNumber = generateAccountNumber();
 
    //enter balance
    do
    {
        accountBalance = genObj.intIput("Enter Account Opening Balance :");
        if(accountBalance<1000)
        {
            std::cout<<"Please Use Minimum Ammount 1000/- Rs\n";
        }
    }while(accountBalance<1000);

}
/*****************************************************
#   Function Name   :   updateAccount
#   Description     :   this function update the account balance.
#   Note            :   None.
*****************************************************/
void accountDetailsN::accountDetailsC::updateAccount(int ammount)
{
    accountBalance = ammount;
}