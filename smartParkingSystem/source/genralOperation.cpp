/******************************************************************************
 * File Name    : genralOperation.cpp
 * Description  : Common utility functions, validation functions and
 *                login management implementation for Smart Parking System.
 *
 * Author       : Ankur Chourey
 * Language     : C++14
 ******************************************************************************/
#include"genralOperation.h"
/******************************************************************************
 * Function Name : clearScreen
 * Description   : Clear terminal screen.
 *
 * Parameters    : None
 * Return        : None
 ******************************************************************************/
void genralOperationN::genralOperationC::clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
/******************************************************************************
 * Function Name : lines
 * Description   : Display separator line.
 *
 * Parameters    : None
 * Return        : None
 ******************************************************************************/
void genralOperationN::genralOperationC::lines()
{
    for(int i=0;i<50;i++)
    std::cout<<"-";

    std::cout<<"\n";
}
/******************************************************************************
 * Function Name : parkingFirmName
 * Description   : Display parking company banner and charge information.
 *
 * Parameters    : None
 * Return        : None
 ******************************************************************************/
void genralOperationN::genralOperationC::parkingFirmName()
{
    lines();

    std::cout<<PARKING_NAME<<"\nVehicle Parking System\n";
    std::cout<<"Charge List\n4 wheeler 50/- rs per hour ("<<MAX_4_WHEELER_SLOT<<") \n";
    std::cout<<"2 wheeler 10/- rs per hour ("<<MAX_2_WHEELER<<")\n";

    lines();
}
/******************************************************************************
 * Function Name : checkNameWithSpace
 * Description   : Validate name containing alphabet characters and spaces.
 *
 * Parameters    :
 *      str -> Input string.
 *
 * Return        :
 *      true  -> Valid
 *      false -> Invalid
 ******************************************************************************/
bool genralOperationN::genralOperationC::checkNameWithSpace
(
    std::string str
)
{
    bool retVal=true;

    for(char ch:str)
    {
        if(!((ch>='a' && ch<='z')||(ch==' ')))
        {
            retVal=false;
            break;
        }
    }

    return retVal;
}
/******************************************************************************
 * Function Name : checkVehicalNumber
 * Description   : Validate vehicle registration number.
 *                 Example: MP09WE1234
 *
 * Parameters    :
 *      vehicleNumber -> Vehicle number.
 *
 * Return        :
 *      true  -> Valid
 *      false -> Invalid
 ******************************************************************************/
bool genralOperationN::genralOperationC:: checkVehicalNumber
(
    std::string vehicleNumber
)
{
    bool checkVehicleNumberStatus = false;

    checkVehicleNumberStatus = checkNameAndNumStaus(vehicleNumber);
   // std::cout<<"checkVehicleNumberStatus1 = "<<checkVehicleNumberStatus<<std::endl;
    
    for(char &temp:vehicleNumber)
    {
        temp = tolower(temp);
    }
    if(vehicleNumber.length()!=10)
    {
        return false;
    }
    if(checkVehicleNumberStatus == true)
    {
        if(vehicleNumber[0] >= 'a' && vehicleNumber[0] <= 'z')  
        {
           if(vehicleNumber[1] >= 'a' && vehicleNumber[1] <= 'z')  
            {
                if(vehicleNumber[2] >= '0' && vehicleNumber[2] <= '9') 
                {
                    if(vehicleNumber[3] >= '0' && vehicleNumber[3] <= '9') 
                    {
                        if(vehicleNumber[4] >= 'a' && vehicleNumber[4] <= 'z')
                        {
                            if(vehicleNumber[5] >= 'a' && vehicleNumber[5] <= 'z')
                            {
                                if(vehicleNumber[6] >= '0' && vehicleNumber[6] <= '9')
                                {
                                    if(vehicleNumber[7] >= '0' && vehicleNumber[7] <= '9')
                                    {
                                        if(vehicleNumber[8] >= '0' && vehicleNumber[8] <= '9')
                                        {
                                            if(vehicleNumber[9] >= '0' && vehicleNumber[9] <= '9')
                                            {
                                                checkVehicleNumberStatus=true;
                                            }
                                            else
                                            {
                                                std::cout<<"vehicleNumber[9]"<<std::endl;
                                                checkVehicleNumberStatus = false;
                                            }
                                        }
                                        else
                                        {
                                            std::cout<<"vehicleNumber[8]"<<std::endl;
                                            checkVehicleNumberStatus = false;
                                        }
                                    }
                                    else
                                    {
                                        std::cout<<"vehicleNumber[7]"<<std::endl;
                                        checkVehicleNumberStatus = false;
                                    }
                                }
                                else
                                {
                                    std::cout<<"vehicleNumber[6]"<<std::endl;
                                    checkVehicleNumberStatus = false;
                                }
                            }
                            else
                            {
                                std::cout<<"vehicleNumber[5]"<<std::endl;
                                checkVehicleNumberStatus = false;
                            }
                        }
                        else
                        {
                            std::cout<<"vehicleNumber[4]"<<std::endl;
                            checkVehicleNumberStatus = false;
                        }
                    }
                    else
                    {
                        std::cout<<"vehicleNumber[3]"<<std::endl;
                        checkVehicleNumberStatus = false;
                    }
                }
                else
                {
                    std::cout<<"vehicleNumber[2]"<<std::endl;
                    checkVehicleNumberStatus = false;
                }
            } 
            else
            {
                std::cout<<"vehicleNumber[1]"<<std::endl;
                checkVehicleNumberStatus = false;
            }
        }
        else
        {
            std::cout<<"vehicleNumber[0]"<<std::endl;
            checkVehicleNumberStatus = false;
        }
    }
   // std::cout<<"checkVehicleNumberStatus2 = "<<checkVehicleNumberStatus<<std::endl;
    return checkVehicleNumberStatus;
}
/******************************************************************************
 * Function Name : checkOnlyNumber
 * Description   : Verify string contains digits only.
 *
 * Parameters    :
 *      numberStr -> Numeric string.
 *
 * Return        :
 *      true  -> Valid
 *      false -> Invalid
 ******************************************************************************/
bool genralOperationN::genralOperationC::checkOnlyNumber
(
    std::string numberStr
)
{
    bool checkStatus = true;
    for(char ch:numberStr)
    {
        if((ch>='0' && ch<='9')== 0)
        {
            checkStatus=false;
            break;
        }
    }
    return checkStatus;
}
/******************************************************************************
 * Function Name : checkNameStaus
 * Description   : Verify string contains alphabet characters only.
 *
 * Parameters    :
 *      name -> Input name.
 *
 * Return        :
 *      true  -> Valid
 *      false -> Invalid
 ******************************************************************************/
bool genralOperationN::genralOperationC::checkNameStaus
(
    std::string name
)
{
    bool boNameCheck =false;
    for(char &temp:name)
    {
        temp=tolower(temp);
    }
    for(char ch:name)
    {
        if(ch<='a' && ch>='z')
        {
            boNameCheck = true;
        }
        else
        {
            boNameCheck = false;
            break;
        }
    }
    return boNameCheck;
}
/******************************************************************************
 * Function Name : cinIgnore
 * Description   : Clear input buffer.
 *
 * Parameters    : None
 * Return        : None
 ******************************************************************************/
void genralOperationN::genralOperationC::cinIgnore()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
/******************************************************************************
 * Function Name : checkVehicleType
 * Description   : Validate vehicle type.
 *                 Supported:
 *                 2, two
 *                 4, four
 *
 * Parameters    :
 *      vType -> Vehicle type.
 *
 * Return        :
 *      true  -> Valid
 *      false -> Invalid
 ******************************************************************************/
bool genralOperationN::genralOperationC::checkVehicleType(std::string vType)
{
    bool checkVType = false;
    
    for(char &ch:vType)
    {
        ch = tolower(ch);
    }

    if(vType == "four" || vType == "4" || vType[0]=='4')
    {
        checkVType =true;
      //  *vType="4";
    }
    else if(vType == "two" || vType == "2" || vType[0]=='2')
    {
        checkVType =true;
        //*vType="2";
    }

    return checkVType ;
}
/******************************************************************************
 * Function Name : checkNameAndNumStaus
 * Description   : Validate alpha-numeric string.
 *
 * Parameters    :
 *      nameForCheck -> Input string.
 *
 * Return        :
 *      true  -> Valid
 *      false -> Invalid
 ******************************************************************************/
bool genralOperationN::genralOperationC::checkNameAndNumStaus(std::string nameForCheck)
{
    bool boNameCheck =false;

    for(char &temp:nameForCheck)
    {
        temp=tolower(temp);
    }

    for(char ch:nameForCheck)
    {
        if((ch>='a' && ch<='z')
        ||(ch>='0'&& ch <='9'))
        {
            boNameCheck = true;
        }
        else
        {
            boNameCheck = false;
            break;
        }
    }
  //  std::cout<<"boNameCheck = "<<boNameCheck<<std::endl;
    return boNameCheck;
}
/******************************************************************************
 * Function Name : login
 * Description   : Authenticate user and determine access rights.
 *
 * Parameters    : None
 * Return        : None
 ******************************************************************************/
void loginRightsN::loginRightsC::login()
{

    std::string loginID;
    void clearScreen();
    void parkingFirmName();

    std::cout<<"Sign In: \n";
    std::cout<<"Login ID : ";
    getline(std::cin,loginID);
    
 
    if(loginID == ADMIN_LOGIN)
    {
        std::cout<<"Admin User\n";
        adminUser();
    }
    else if(loginID == OPER_LOGIN)
    {
        std::cout<<"Operator Account:\n";
        operatorUser();
    }

}
/******************************************************************************
 * Function Name : adminUser
 * Description   : Authenticate administrator account.
 *
 * Parameters    : None
 * Return        : None
 ******************************************************************************/
void loginRightsN::loginRightsC::adminUser()
{
    clearScreen();
    parkingFirmName();
    std::string passKey;
    std::cout<<"Admin Passward : \n";
    getline(std::cin,passKey);

    if(passKey == PASS_KEY_ADMIN)
    {
        rightsFlag = 1;
    }
    else
    {
        rightsFlag=0;
    }
}
/******************************************************************************
 * Function Name : operatorUser
 * Description   : Authenticate operator account.
 *
 * Parameters    : None
 * Return        : None
 ******************************************************************************/
void loginRightsN::loginRightsC::operatorUser()
{
    clearScreen();
    parkingFirmName();

    std::string passKey;
    std::cout<<"Operator Passward : \n";
    getline(std::cin,passKey);

    if(passKey == PASS_KEY_OPER)
    {
        rightsFlag = 2;
    }
    else
    {
        rightsFlag=0;
    }
}