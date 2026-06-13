/******************************************************************************
 * File Name    : vehicleDetails.cpp
 * Description  : Vehicle information management module.
 *                Handles vehicle data entry, validation, update and display.
 *
 * Author       : Ankur Chourey
 * Language     : C++14
 ******************************************************************************/
#include"vehicleDetails.h"
#include<vector>
#include<fstream>
#include<sstream>
//!< global variable.
extern void readSlotStatus(int *twoWheeler,int *fourWheeler);
/******************************************************************************
 * Function Name : readUpdateVehicleNumber
 * Description   : Update vehicle registration number.
 *
 * Parameters    :
 *      vn -> Vehicle Number
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::readUpdateVehicleNumber(std::string vn)
{
    vehicleNumber = vn;
}
/******************************************************************************
 * Function Name : readUpdateVehicleOwner
 * Description   : Update vehicle owner name.
 *
 * Parameters    :
 *      ow -> Owner Name
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::readUpdateVehicleOwner(std::string ow)
{
    vehicleOwner = ow;
}
/******************************************************************************
 * Function Name : readUpdateInTime
 * Description   : Update vehicle entry time.
 *
 * Parameters    :
 *      it -> Entry Time
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::readUpdateInTime(std::string it)
{
    inTime= it;
}
/******************************************************************************
 * Function Name : readUpdateOutTime
 * Description   : Update vehicle exit time.
 *
 * Parameters    :
 *      ot -> Exit Time
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::readUpdateOutTime(std::string ot)
{
    outTime = ot;
}
/******************************************************************************
 * Function Name : readUpdateMobileNumber
 * Description   : Update mobile number.
 *
 * Parameters    :
 *      mb -> Mobile Number
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::readUpdateMobileNumber(std::string mb)
{
    mobileNumber = mb;
}
void vehicleDetailsN::vehicleDetailsC::readUpdateVehicleType(std::string vt)
{
    vehicleType = vt;
}
void vehicleDetailsN::vehicleDetailsC::readUpdateSlotNumber(std::string st)
{
    slotNum =st;
}
/******************************************************************************
 * Function Name : enterVehicleDetails
 * Description   : Capture complete vehicle information from user.
 *
 * Parameters    :
 *      obj -> Vehicle object.
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::enterVehicleDetails
(
    vehicleDetailsN::vehicleDetailsC &obj,
    bool *twoW,
    bool *fourW
)
{
    //!< clear screen.
    clearScreen();
    parkingFirmName();//!< parking company name.
    int twoWheeler;
    int fourWheeler;

    readSlotStatus(&twoWheeler,&fourWheeler);

    //!< set vehicle details. 
    obj.setVehicleType();

    if(fourWheeler > (MAX_4_WHEELER-1) && obj.getVehicleType()=="4")
    {
      *fourW = true;
       std::cout<<"No Space for 4 Wheeler\n";
    }
    else if(twoWheeler > (MAX_2_WHEELER-1) && obj.getVehicleType()=="2")
    {
      std::cout<<"No Space for 2 Wheeler\n";
      *twoW = true;
    }
    else
    {
      obj.setVehicleNumber();
      obj.setVehicleOwner();
      obj.setInTime();
      obj.readUpdateOutTime("------");
      obj.setMobileNumber();   
      obj.setSlotNumber();
    }
    std::cout<<"*twoW = "<<*twoW<<std::endl;
}
/******************************************************************************
 * Function Name : setVehicleType
 * Description   : Capture and validate vehicle type.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::setVehicleType()
{
    bool retVal = false;
    std::string wrongopt;

    do
    {
        clearScreen();
        parkingFirmName();

        std::cout<<"Vehicle Type \n";
        getline(std::cin,vehicleType);
        
        retVal = checkVehicleType(vehicleType);

        if(retVal==false)
        {
            std::cout<<"Parking for 2 wheeler or 4 wheeler \n";
            std::cout<<"Press Any Key For Re-Enter \n";
            getline(std::cin,wrongopt);
        }
        else
        {
            for(char &ch : vehicleType)
            {
                ch = tolower(ch);
            }
            if(vehicleType == "four" ||  vehicleType == "4" || vehicleType[0]=='4')
            {
                vehicleType = "4";
            }
            else if(vehicleType == "two" || vehicleType == "2" || vehicleType[0]=='2')
            {

                vehicleType = "2";
            }
        }   
    }
    while(retVal==false );
}
/******************************************************************************
 * Function Name : getMoney
 * Description   : Return money.
 *
 * Parameters    : None
 *
 * Return        :
 *      Money
 ******************************************************************************/
unsigned int vehicleDetailsN::vehicleDetailsC:: getMoney()
{
    return money;
}
/******************************************************************************
 * Function Name : getVehicleType
 * Description   : Return vehicle type.
 *
 * Parameters    : None
 *
 * Return        :
 *      Vehicle Type
 ******************************************************************************/
std::string vehicleDetailsN::vehicleDetailsC::getVehicleType()
{
    return vehicleType;
}
std::string vehicleDetailsN::vehicleDetailsC::getVehicleNumber()
{
    return vehicleNumber;
}
std::string vehicleDetailsN::vehicleDetailsC::getVehicleOwner()
{
    return vehicleOwner;
}
std::string vehicleDetailsN::vehicleDetailsC::getInTime()
{
    return inTime;
}
std::string vehicleDetailsN::vehicleDetailsC::getOutTime()
{
    return outTime;
}
std::string vehicleDetailsN::vehicleDetailsC::getMobileNumber()
{
    return mobileNumber;
}
/******************************************************************************
 * Function Name : readUpdateMoney
 * Description   : Copy current money data into another object.
 *
 * Parameters    :
 *      obj -> Destination object.
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::readUpdateMoney(unsigned int m)
{
    money =m;
}
/******************************************************************************
 * Function Name : readDataFromVehicleData
 * Description   : Copy current vehicle object data into another object.
 *
 * Parameters    :
 *      obj -> Destination object.
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::readDataFromVehicleData
(
    vehicleDetailsN::vehicleDetailsC &obj
)
{
    obj.vehicleNumber = getVehicleNumber();
    obj.vehicleOwner = getVehicleOwner();
    obj.inTime = getInTime();
    obj.outTime = getOutTime();
    obj.mobileNumber = getMobileNumber();
    obj.vehicleType = getVehicleType();
    
}
std::string vehicleDetailsN::vehicleDetailsC::getSlotNum()
{
    return slotNum;
}
/******************************************************************************
 * Function Name : setSlotNumber
 * Description   : Read last allocated slot from file and assign slot.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::setSlotNumber()
{
    std::string slot;
    std::ifstream file("data/slotFile.csv");
    std::string line;
    std::string lastline;
    
    if(file.is_open()==true)
    {

        if(file.peek()==true)
        {
            slotNum="1";
        }
        else
        {
            while(getline(file,line))
            {
                if(!line.empty())
                {
                    lastline =line;
                }
            }      
            std::stringstream st(lastline);
            
            getline(st,slotNum,',');      
        }

        std::cout<<"slotNumber = "<<slotNum<<std::endl;
    }
}
/******************************************************************************
 * Function Name : setVehicleNumber
 * Description   : Capture and validate vehicle registration number.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::setVehicleNumber()
{
    bool retVal =false;
    std::string wrongEnt;
    do
    {
        clearScreen();
        parkingFirmName();

        std::cout<<"Vehicle Number \n";
        getline(std::cin,vehicleNumber);

        //check number is valid or not.
        retVal = checkVehicalNumber(vehicleNumber);
        //std::cout<<"retVal = "<<retVal<<std::endl;

        int length = vehicleNumber.length();
        //std::cout<<"length = "<<length<<std::endl;


        if(length!=10)
        {
            retVal = false;
        }

        if(retVal == false)
        {
            std::cout<<"Please Entered Vehicle Number In Correct Format\n";
            std::cout<<"Example : MP09WE1234\n";
            std::cout<<"Press Any Key For Re-Enter\n";
            getline(std::cin,wrongEnt);
        }
        else
        {
            for(char &ch:vehicleNumber)
            {
                ch = toupper(ch);
            }
            break;
        }
    }
    while(retVal==false );
}
/******************************************************************************
 * Function Name : setVehicleOwner
 * Description   : Capture and validate vehicle owner name.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::setVehicleOwner()
{
    bool retVal =false;
    std::string wrongopt;
    do
    {
        clearScreen();
        parkingFirmName();

        std::cout<<"Driver Name \n";
        getline(std::cin,vehicleOwner);

        retVal = checkNameWithSpace(vehicleOwner);

        if(retVal==false)
        {
            std::cout<<"Driver Name Should Be Combination of UperCase and LowerCase No Special Symbole \n";
            std::cout<<"Press any key for Re-Enter\n";
            getline(std::cin,wrongopt);
        }
    }
    while(retVal==false );
}
/******************************************************************************
 * Function Name : setInTime
 * Description   : Store current system time as vehicle entry time.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::setInTime()
{
    std::time_t now = std::time(0);
    inTime = std::ctime(&now);
    inTime.pop_back();

}
/******************************************************************************
 * Function Name : setOutTime
 * Description   : Store current system time as vehicle exit time.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::setOutTime()
{
    std::time_t now = std::time(0);
    outTime = std::ctime(&now);
    outTime.pop_back();
}
/******************************************************************************
 * Function Name : updateOutTime
 * Description   : Update vehicle exit time.
 *
 * Parameters    :
 *      oT -> Exit Time
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::updateOutTime(std::string oT)
{
    outTime = oT;
}
/******************************************************************************
 * Function Name : setMobileNumber
 * Description   : Capture and validate driver mobile number.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::setMobileNumber()
{
    bool validFlag = false;
    int length;
    std::string wrongOpt;
    do
    {
        clearScreen();
        parkingFirmName();

        std::cout<<"Driver Mobile Number\n";
        getline(std::cin,mobileNumber);

        validFlag = checkOnlyNumber(mobileNumber);
        length = mobileNumber.length();
        if(length!=10)
        {
           validFlag=false; 
        }
        if(validFlag == false)
        {
            std::cout<<"Mobile Number Should Not Contain, Letters\n";
            std::cout<<"Press Any Key for Re-Enter\n";
            getline(std::cin,wrongOpt);
        }
    }while(validFlag == false);
}
/******************************************************************************
 * Function Name : displayVehicalDetails
 * Description   : Display complete vehicle information.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void vehicleDetailsN::vehicleDetailsC::displayVehicalDetails()
{
    clearScreen();
    parkingFirmName();

    std::cout<<"Vehicle Number      : "<<getVehicleNumber()<<std::endl;
    std::cout<<"Driver Name         : "<<getVehicleOwner()<<std::endl;
    std::cout<<"In Time             : "<<getInTime();
    std::cout<<"Mobile Number       : "<<getMobileNumber()<<std::endl;
    lines();
}