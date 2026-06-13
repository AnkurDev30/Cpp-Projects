#include<fstream>
#include<cctype>
#include<string>
#include<sstream>
#include<ctime>
#include<vector>
#include"parkingOperation.h"
#define MONEY_DEBUG 0
void readSlotStatus(int *twoWheeler,int *fourWheeler)
{
    int twoWheelerCount =0;
    int fourWheelerCount =0;
    //clearScreen();//clear the screen.
    //parkingFirmName();//display the header.
    //std::cout<<"Parking Availabilty\n";
    parkingOperationN::parkingOperationC obj;
    std::vector<vehicleDetailsN::vehicleDetailsC> parkStatusVec;

    //read full data from database.
    obj.readFullData(parkStatusVec);

    for(size_t i=0;i<parkStatusVec.size();i++)
    {
        if(parkStatusVec[i].getVehicleType()=="4")
        {
            fourWheelerCount++;
        }
        if(parkStatusVec[i].getVehicleType()=="2")
        {
            twoWheelerCount++;
        }
    }
    #if(DEBUG ==1)
    std::cout<<twoWheelerCount<<" "<<fourWheelerCount<<std::endl;
    std::string ABC;
    getline(std::cin,ABC);
    #endif
    *twoWheeler=twoWheelerCount;
    *fourWheeler=fourWheelerCount;
    //std::cout<<"4 wheeler "<<MAX_4_WHEELER_SLOT-fourWheelerCount
    //<<" Slot Remaining"<<std::endl;
//
    //std::cout<<"2 wheeler "<<MAX_2_WHEELER_SLOT-twoWheelerCount
    //<<" Slot Remaining"<<std::endl;  
}
/******************************************************************************
 * Function Name  : fillAvailableSlot
 * Description    : Update an available parking slot with new vehicle data.
 *
 * Parameters     :
 *      v1    -> Main parking slot vector.
 *      v2    -> New vehicle data vector.
 *      index -> Available slot index.
 *      slt   -> Slot number.
 *
 * Return         : None
 *
 * Author         : Ankur Chourey
 ******************************************************************************/
void parkingOperationN::parkingOperationC::fillAvailableSlot
(
    std::vector<vehicleDetailsN::vehicleDetailsC> &v1,
    std::vector<vehicleDetailsN::vehicleDetailsC> &v2,
    int index,
    std::string slt
)
{

    vehicleDetailsN::vehicleDetailsC lastIndexDataObj;
    
    lastIndexDataObj.readUpdateSlotNumber(slt);
    lastIndexDataObj.readUpdateVehicleNumber(v2[0].getVehicleNumber());
    lastIndexDataObj.readUpdateVehicleOwner(v2[0].getVehicleOwner());
    lastIndexDataObj.readUpdateInTime(v2[0].getInTime());
    lastIndexDataObj.readUpdateOutTime(v2[0].getOutTime());
    lastIndexDataObj.readUpdateMobileNumber(v2[0].getMobileNumber());
    lastIndexDataObj.readUpdateVehicleType(v2[0].getVehicleType());

    v1[index] = lastIndexDataObj;

}
/******************************************************************************
 * Function Name  : readFullData
 * Description    : Read complete parking data from CSV file and store it
 *                  into vector.
 *
 * Parameters     :
 *      vecPark -> Vector used to store parking records.
 *
 * Return         : None
 ******************************************************************************/
void parkingOperationN::parkingOperationC::readFullData
(
    std::vector<vehicleDetailsN::vehicleDetailsC> &vecPark
)
{
    //open file
    std::ifstream file("data/slotFile.csv");
    //local object
    vehicleDetailsN::vehicleDetailsC object;
    //local variable.
    std::string vehicleNumber;
    std::string vehicleOwner;
    std::string inTime;
    std::string outTime;
    std::string mobileNumber;
    std::string vehicleType;
    std::string line;
    std::string slot;
    //if file is open
    if(file.is_open()==true)
    {
        //read line by line
        while(getline(file,line))
        {
            //keep data in ss.vecPark
            std::stringstream ss(line);
            //diffrentiate by ,
            getline(ss,slot,',');
            getline(ss,vehicleNumber,',');
            getline(ss,vehicleOwner,',');
            getline(ss,mobileNumber,',');
            getline(ss,vehicleType,',');
            getline(ss,inTime,',');
            getline(ss,outTime,',');

            //update on object.
            object.readUpdateSlotNumber(slot);
            object.readUpdateVehicleNumber(vehicleNumber);
            object.readUpdateVehicleOwner(vehicleOwner);
            object.readUpdateMobileNumber(mobileNumber);
            object.readUpdateVehicleType(vehicleType);
            object.readUpdateInTime(inTime);
            object.readUpdateOutTime(outTime);
            //update in vector.
            vecPark.push_back(object);

        }
    }
    else
    {

    }
}
/******************************************************************************
 * Function Name  : getBlankSlot
 * Description    : Search first available parking slot marked as XXXXX.
 *
 * Parameters     :
 *      vecPark        -> Parking slot vector.
 *      availableFlag -> Slot available status.
 *      slot          -> Available slot number.
 *
 * Return         :
 *      Index of available slot.
 ******************************************************************************/
int  parkingOperationN::parkingOperationC::getBlankSlot
(
    std::vector<vehicleDetailsN::vehicleDetailsC> &vecPark,
    bool *avaliableFlag,
    std::string *slot
)
{
    int index = 0;
    std::string slt;

    for(size_t i=0;i<vecPark.size();i++)
    {
    #if(DEBUG == 1)
        std::cout<<"vehicle number = "<<vecPark[i].getVehicleNumber()<<std::endl;
    #endif

        if("XXXXX" == vecPark[i].getVehicleNumber())
        {
            index =i;
            slt = vecPark[i].getSlotNum();
            *slot=slt;
            *avaliableFlag = true;
            break;
        }
    }
    return index;
}
/******************************************************************************
 * Function Name  : writeDataEntry
 * Description    : Add new vehicle entry into parking database.
 *
 * Parameters     :
 *      vecPark -> Vehicle data vector.
 *
 * Return         :
 *      true  -> Success
 *      false -> Failure
 ******************************************************************************/
bool parkingOperationN::parkingOperationC::writeDataEntry
(
    std::vector<vehicleDetailsN::vehicleDetailsC> &vecPark
)
{
    bool writeStatus = false;
    bool availableFalg=false;
    
    std::ifstream fileR("data/slotFile.csv");
    std::vector<vehicleDetailsN::vehicleDetailsC> vecReadFull;

    std::string line;
    std::string lastline;
    int slotNumber = 0;
    std::string slotNumberFromAvailFalg;
    readFullData(vecReadFull);

    int index = getBlankSlot(vecReadFull,&availableFalg,&slotNumberFromAvailFalg);
    #if(DEBUG == 1)
        std::cout<<" index = "<<index<<std::endl;
        std::cout<<" availableFalg = "<<availableFalg<<std::endl;
    #endif
    if(availableFalg == true)
    {
        #if(DEBUG == 1)
        std::cout<<"slot available\n";
        #endif
        fillAvailableSlot(vecReadFull,vecPark,index,slotNumberFromAvailFalg);
        pasteData(vecReadFull,slotNumber);
    }
    else
    {
        while(getline(fileR,line))
        {
            if(!line.empty())
            {
                lastline =line;
            }
        }

        std::stringstream st(lastline);
        st>>slotNumber;
        #if(DEBUG == 1)
        std::cout<<"slotNumber = "<<slotNumber<<std::endl;
        #endif
        slotNumber++;

        pasteData1(vecPark,slotNumber);
    }

return writeStatus;
}
/******************************************************************************
 * Function Name  : pasteData1
 * Description    : Append vehicle information into CSV file.
 *
 * Parameters     :
 *      v1  -> Vehicle vector.
 *      slt -> Slot number.
 *
 * Return         : None
 ******************************************************************************/
void parkingOperationN::parkingOperationC::pasteData1
(
    std::vector<vehicleDetailsN::vehicleDetailsC> &v1,
    int slt
)
{
    int  slotNumber = slt;  
    std::string vehicleNumber;
    std::string vehicleOwner;
    std::string inTime;
    std::string outTime;
    std::string mobileNumber;
    std::string vehicleType;
    std::ofstream fileW("data/slotFile.csv",std::ios::app);
    for(size_t i=0;i<v1.size();i++)
    { 
        vehicleNumber   = v1[i].getVehicleNumber();
        vehicleOwner    = v1[i].getVehicleOwner();
        inTime          = v1[i].getInTime();
        outTime         = v1[i].getOutTime(); ;
        mobileNumber    = v1[i].getMobileNumber() ;
        vehicleType     = v1[i].getVehicleType();

        fileW<<slotNumber<<","
        <<vehicleNumber<<","
        <<vehicleOwner<<","
        <<mobileNumber<<","
        <<vehicleType<<","
        <<inTime<<","
        <<outTime<<std::endl;
        
    }
}
/******************************************************************************
 * Function Name  : pasteData
 * Description    : Rewrite complete parking file using vector data.
 *
 * Parameters     :
 *      v1  -> Vehicle vector.
 *      slt -> Slot number.
 *
 * Return         : None
 ******************************************************************************/
void parkingOperationN::parkingOperationC::pasteData
(
    std::vector<vehicleDetailsN::vehicleDetailsC> &v1,
    int slt
)
{
    int  slotNumber = slt;  
    std::string vehicleNumber;
    std::string vehicleOwner;
    std::string inTime;
    std::string outTime;
    std::string mobileNumber;
    std::string vehicleType;

    std::ofstream fileW("data/slotFile.csv");

    for(size_t i=0;i<v1.size();i++)
    { 
        vehicleNumber   = v1[i].getVehicleNumber();
        vehicleOwner    = v1[i].getVehicleOwner();
        inTime          = v1[i].getInTime();
        outTime         = v1[i].getOutTime(); ;
        mobileNumber    = v1[i].getMobileNumber() ;
        vehicleType     = v1[i].getVehicleType();

        std::string  slt = v1[i].getSlotNum();
        std::stringstream st(slt);
        st>>slotNumber;

        fileW<<slotNumber<<","
        <<vehicleNumber<<","
        <<vehicleOwner<<","
        <<mobileNumber<<","
        <<vehicleType<<","
        <<inTime<<","
        <<outTime<<std::endl;

    }
}
/******************************************************************************
 * Function Name  : writeDataFull
 * Description    : Store complete parking vector into CSV file.
 *
 * Parameters     :
 *      vecPark -> Vehicle record vector.
 *
 * Return         :
 *      true  -> Success
 *      false -> Failure
 ******************************************************************************/
bool parkingOperationN::parkingOperationC::writeDataFull
(
    std::vector<vehicleDetailsN::vehicleDetailsC> &vecPark
)
{
    bool writeStatus = false;
    
    std::string vehicleNumber;
    std::string vehicleOwner;
    std::string inTime;
    std::string outTime;
    std::string mobileNumber;
    std::string vehicleType;
    std::string line;
    std::string lastline;
    int slotNumber = 0;
    #if(DEBUG == 1)
    std::cout<<"slotNumber = "<<slotNumber<<std::endl;
    #endif
    std::ofstream fileW("data/slotFile.csv"); 
    if((fileW.is_open())==true)
    {
        for(int i=0;i<(int)vecPark.size();i++)
        {
            vehicleNumber   = vecPark[i].getVehicleNumber();
            vehicleOwner    = vecPark[i].getVehicleOwner();
            inTime          = vecPark[i].getInTime();
            outTime         = vecPark[i].getOutTime(); ;
            mobileNumber    = vecPark[i].getMobileNumber() ;
            vehicleType     = vecPark[i].getVehicleType();
            
            slotNumber++;
            fileW<<slotNumber<<","
            <<vehicleNumber<<","
            <<vehicleOwner<<","
            <<mobileNumber<<","
            <<vehicleType<<","
            <<inTime<<","
            <<outTime<<std::endl;
        }
    }
    else
    {
        writeStatus =false;
    }
return writeStatus;
}
/******************************************************************************
 * Function Name  : vehicleEnrty
 * Description    : Capture vehicle details and allocate parking slot.
 *
 * Parameters     : None
 *
 * Return         : None
 ******************************************************************************/
void parkingOperationN::parkingOperationC::vehicleEnrty()
{
    //vector.
    std::vector<vehicleDetailsN::vehicleDetailsC> vecPark;

    vehicleDetailsN::vehicleDetailsC objectVeh;
    bool two=false;
    bool four=false;

    clearScreen();//clear the screen.
    parkingFirmName();//display the header.

    //take vehicle data.
    enterVehicleDetails(objectVeh,&two,&four);
    std::cout<<"two ="<<two<<std::endl;
    std::cout<<"four ="<<four<<std::endl;
    std::cout<<"p "<<objectVeh.getVehicleType()<<std::endl;
    if(two == true && objectVeh.getVehicleType() == "2")
    {
        clearScreen();//clear the screen.
        parkingFirmName();//display the header.

        std::cout<<"No Space Available for 2 Wheeler\n";
    }
    else if(four == true && objectVeh.getVehicleType() == "4")
    {
        clearScreen();//clear the screen.
        parkingFirmName();//display the header.

        std::cout<<"No Space Available for 4 Wheeler\n";
    }
    else
    {
       // std::cout<<"Hi"<<std::endl;
        vecPark.push_back(objectVeh);
        (void)writeDataEntry(vecPark);
    }

}
/******************************************************************************
 * Function Name  : vehicleExit
 * Description    : Process vehicle exit, calculate charges and free slot.
 *
 * Parameters     : None
 *
 * Return         : None
 ******************************************************************************/
void parkingOperationN::parkingOperationC::vehicleExit()
{
    clearScreen();//clear the screen.
    parkingFirmName();//display the header.
    std::cout<<"Exit Operation\n";
    #if(DEBUG == 1)
    std::cout<<"exit option\n";
    #endif
    int slotNum;
    std::string vehicleNumber;

    std::vector<vehicleDetailsN::vehicleDetailsC> vecPark;
    vehicleDetailsN::vehicleDetailsC objectVeh;
    calculationN::calculationC calObj;
     //enter vehicle number.
    std::cout<<"enter vehicle number\n";
    getline(std::cin,vehicleNumber);

    for(char &ch:vehicleNumber)
    {
        ch =toupper(ch);
    }
    bool checkVehicleNumber = checkNumberAvailableOrNot(vehicleNumber,&slotNum);
    if(checkVehicleNumber)
    {
        readFullData(vecPark);

        for(size_t i=0;i<vecPark.size();i++)
        {
            if(vehicleNumber == vecPark[i].getVehicleNumber())
            { 
                vecPark[i].setOutTime(); 
                #if(MONEY_DEBUG==1)
                    std::cout<<"out time pre = "<<vecPark[i].getOutTime()<<std::endl;
                #endif
                unsigned int money = calObj.moneyCalcAsPerTime
                                    (
                                        vecPark[i].getInTime(),
                                        vecPark[i].getOutTime()
                                    ); 
                #if(MONEY_DEBUG==1)
                    std::cout<<"moeny = "<<money<<std::endl;
                #endif
                 
                std::cout<<"Please pay : "<<money<<"/- INR"<<std::endl;                  
                saveData(vecPark[i],money);
                vecPark[i].readUpdateVehicleNumber("XXXXX");
                vecPark[i].readUpdateVehicleOwner("XXXXX");
                vecPark[i].readUpdateInTime("XXXXX");
                vecPark[i].readUpdateOutTime("XXXXX");
                vecPark[i].readUpdateMobileNumber("XXXXX");
                vecPark[i].readUpdateVehicleType("XXXXX");
                
            }
        }
        writeDataFull(vecPark);
    }
    else
    {
        std::cout<<"no successfully";
    }

}
/******************************************************************************
 * Function Name  : saveData
 * Description    : Save completed parking transaction into history file.
 *
 * Parameters     :
 *      obj   -> Vehicle object.
 *      money -> Parking charge.
 *
 * Return         : None
 ******************************************************************************/
void parkingOperationN::parkingOperationC::saveData
(
    vehicleDetailsN::vehicleDetailsC obj,
    unsigned int money
)
{
    //std::cout<<"data/save data\n";
    std::ofstream fsave("data/saveDta.csv",std::ios::app);
    std::ifstream fread("data/saveDta.csv");
    
    if(fsave.is_open()==true)
    {
       if(fread.peek()==true)
       {
            fsave<<"Slot no"<<","
            <<"Vehicle no"<<","
            <<"Vehicle Owner"<<","
            <<"Vehicle Type"<<","
            <<"In Time"<<","
            <<"Out Time"<<","
            <<"Mobile"<<","
            <<"Money"<<","<<std::endl;
       }

       fsave<<obj.getSlotNum()<<","
       <<obj.getVehicleNumber()<<","
       <<obj.getVehicleOwner()<<","
       <<obj.getVehicleType()<<","
       <<obj.getInTime()<<","
       <<obj.getOutTime()<<","
       <<obj.getMobileNumber()<<","
       <<money<<","<<std::endl;

    }
}
/******************************************************************************
 * Function Name  : checkNumberAvailableOrNot
 * Description    : Verify vehicle number exists in parking database.
 *
 * Parameters     :
 *      vehicleNumber -> Vehicle number.
 *      slot          -> Slot number output.
 *
 * Return         :
 *      true  -> Vehicle found.
 *      false -> Vehicle not found.
 ******************************************************************************/
bool parkingOperationN::parkingOperationC::checkNumberAvailableOrNot
(
    std::string vehicleNumber,
    int *slot
)
{
    bool checkVehicleNum=false;
    std::ifstream file("data/slotFile.csv");
    std::string line;
    int slotNumVar;
    std::string slotNum;
    std::string veh;
    if(file.is_open()==true)
    {
        
        while(getline(file,line))
        {
            std::stringstream ss(line);
            getline(ss,slotNum,',');
            getline(ss,veh,',');
            //std::cout<<"read "<<slotNum<<veh<<std::endl;
            if(veh == vehicleNumber)
            {
                std::stringstream slotR(slotNum);
                checkVehicleNum=true;
                slotR>>slotNumVar;
                *slot=slotNumVar;
            }
        }
    }
    else
    {
        checkVehicleNum=false;
        std::cout<<"file not read successfully\n";
    }
    return checkVehicleNum;
}
void parkingOperationN::parkingOperationC::parkingStatus()
{
    int twoWheelerCount =0;
    int fourWheelerCount =0;
    clearScreen();//clear the screen.
    parkingFirmName();//display the header.
    std::cout<<"Parking Availabilty\n";

    std::vector<vehicleDetailsN::vehicleDetailsC> parkStatusVec;

    //read full data from database.
    readFullData(parkStatusVec);

    for(size_t i=0;i<parkStatusVec.size();i++)
    {
        if(parkStatusVec[i].getVehicleType()=="4")
        {
            fourWheelerCount++;
        }
        if(parkStatusVec[i].getVehicleType()=="2")
        {
            twoWheelerCount++;
        }
    }

    std::cout<<"4 wheeler "<<MAX_4_WHEELER_SLOT-fourWheelerCount
    <<" Slot Remaining"<<std::endl;

    std::cout<<"2 wheeler "<<MAX_2_WHEELER_SLOT-twoWheelerCount
    <<" Slot Remaining"<<std::endl;
}
void parkingOperationN::parkingOperationC::history()
{
    clearScreen();//clear the screen.
    parkingFirmName();//display the header.
    std::cout<<"Records \n";
    std::string line;
    std::vector<vehicleDetailsN::vehicleDetailsC> parkStatusVec;
    //open file
    std::ifstream file("data/saveDta.csv");
    //local object
    vehicleDetailsN::vehicleDetailsC object;
    //local variable.
    std::string vehicleNumber;
    std::string vehicleOwner;
    std::string inTime;
    std::string outTime;
    std::string mobileNumber;
    std::string vehicleType;
    
    std::string slot;
    unsigned int money =0;
    std::string moneyStr ;
    //if file is open
    if(file.is_open()==true)
    {
        //read line by line
        while(getline(file,line))
        {
            //keep data in ss.vecPark
            std::stringstream ss(line);
            //diffrentiate by ,
            getline(ss,slot,',');
            getline(ss,vehicleNumber,',');
            getline(ss,vehicleOwner,',');
            getline(ss,vehicleType,',');
            getline(ss,inTime,',');
            getline(ss,outTime,',');
            getline(ss,mobileNumber,',');
            getline(ss,moneyStr,',');

            std::stringstream st(moneyStr);
            st>>money;

            //update on object.
            object.readUpdateSlotNumber(slot);
            object.readUpdateVehicleNumber(vehicleNumber);
            object.readUpdateVehicleOwner(vehicleOwner);
            object.readUpdateMobileNumber(mobileNumber);
            object.readUpdateVehicleType(vehicleType);
            object.readUpdateInTime(inTime);
            object.readUpdateOutTime(outTime);
            object.readUpdateMoney(money);
            //update in vector.
            parkStatusVec.push_back(object);
        }
    }
    else
    {

    }
    for(size_t i=0;i<parkStatusVec.size();i++)
    {
        if(i==0)
        {
            for(int i=0;i<90;i++)
            std::cout<<"-";

            std::cout<<std::endl;

            std::cout<<std::left<<std::setw(15)<<"Vehicle Number"<<" | "
            <<std::left<<std::setw(25)<<"In Time"<<" | "
            <<std::left<<std::setw(25)<<"Out Time"<<" | "
            <<std::left<<std::setw(15)<<"Money"<<" | "<<std::endl;

            for(int i=0;i<90;i++)
            std::cout<<"-";

            std::cout<<std::endl;
        }
        std::cout<<std::left<<std::setw(15)<<parkStatusVec[i].getVehicleNumber()<<" | "
        <<std::left<<std::setw(25)<<parkStatusVec[i].getInTime()<<" | "
        <<std::left<<std::setw(25)<<parkStatusVec[i].getOutTime()<<" | "
        <<std::left<<std::setw(15)<<parkStatusVec[i].getMoney()<<" | "<<std::endl;
    }
    for(int i=0;i<90;i++)
    std::cout<<"-";

    std::cout<<std::endl;
}
/******************************************************************************
 * Function Name  : moneyCalcAsPerTime
 * Description    : Calculate parking charge using entry and exit time.
 *
 * Parameters     :
 *      inTime  -> Vehicle entry time.
 *      outTime -> Vehicle exit time.
 *
 * Return         :
 *      Calculated parking amount.
 ******************************************************************************/
unsigned int calculationN::calculationC::moneyCalcAsPerTime
(
    std::string inTime,std::string outTime
)
{
    //Sat Jun  6 15:24:14 2026
    unsigned int money ;
    std::string dayNameIn;
    std::string monthNameIn;
    int dayIn;
    std::string timeIn;
    int yearIn;

    std::string dayNameOut;
    std::string monthNameOut;
    int dayOut;
    std::string timeOut;
    int yearOut;

    int hr[2];
    int min[2];

    int hrOutput;
    int minOutput;
    std::stringstream ssIn(inTime);
    ssIn >> dayNameIn >> monthNameIn >> dayIn >> timeIn >> yearIn;
    #if(MONEY_DEBUG==1)
        std::cout<<" dayNameIn "<<dayNameIn<<"\n"
        <<" monthNameIn "<<monthNameIn<<"\n"
        <<" dayIn "<<dayIn<<"\n"
        <<" timeIn "<<timeIn<<"\n"
        <<" yearIn "<<yearIn<<"\n";
    #endif
    std::stringstream ssOut(outTime);
    ssOut >> dayNameOut >> monthNameOut >> dayOut >> timeOut >> yearOut;

    #if(MONEY_DEBUG==1)
        std::cout<<" dayNameOut "<<dayNameOut<<"\n"
        <<" monthNameOut "<<monthNameOut<<"\n"
        <<" dayOut "<<dayOut<<"\n"
        <<" timeOut "<<timeOut<<"\n"
        <<" yearOut "<<yearOut<<"\n";
    #endif

    int noOfDays  ;
    int monthCalc = monthCalcFun(yearIn,yearOut,monthNameIn,monthNameOut);
    std::string hrSS,minSS;
    if(monthCalc == 2)//same  month
    {
        //date diffrence.
        noOfDays = dayOut-dayIn;
        std::stringstream inT(timeIn);
        getline(inT,hrSS,':');
        getline(inT,minSS,':');

        std::stringstream(hrSS)>>hr[0];
        std::stringstream(minSS)>>min[0];

        std::stringstream ouT(timeOut);
        getline(ouT,hrSS,':');
        getline(ouT,minSS,':');
        std::stringstream(hrSS)>>hr[1];
        std::stringstream(minSS)>>min[1];
        if(noOfDays == 0)
        {
            hrOutput    = hr[1] -   hr[0];
            minOutput   = min[1]-   min[0];
            money = moneyCalc(hrOutput,minOutput);
        }
        else
        {
            money = 1000;
        }
    }
    else if(monthCalc == 100)
    {
        money =15000;
    }
    else if(monthCalc<100)//diffrent  month
    {
        if(monthCalc==1)  money=5000;
        else if(monthCalc>=2)  money=6000;
        else if(monthCalc>=3)  money=9000;
        else if(monthCalc>=6)  money=12000;
        else if(monthCalc>11) money=12000;
    }    
    return money;
}
/******************************************************************************
 * Function Name  : monthCalcFun
 * Description    : Calculate month difference between two dates.
 *
 * Parameters     :
 *      y1,y2 -> Years.
 *      m1,m2 -> Months.
 *
 * Return         :
 *      Month difference.
 ******************************************************************************/
int calculationN::calculationC::monthCalcFun
(
    int y1,
    int y2,
    std::string m1,
    std::string m2
)
{
    int mo1 = monthFun(m1);
    int mo2 = monthFun(m2);
    int val=0;
    if(y1==y2)
    {
        if(mo1<mo2)
        {
            val = mo2-mo1;
        }
        else
        {
            if(mo1==mo2)
            {
                 val=2;
            }
        }
    }
    else
    {
        if(y1<y2)   
        {
            val =100;
        }
    }
    return val;
}
/******************************************************************************
 * Function Name  : monthFun
 * Description    : Convert month string into numeric month.
 *
 * Parameters     :
 *      month -> Month string (Jan, Feb, etc.)
 *
 * Return         :
 *      Numeric month value.
 ******************************************************************************/
int calculationN::calculationC::monthFun(std::string month)
{
    int mon =0;

    if(month == "Jan") mon = 1;
    if(month == "Feb") mon = 2;
    if(month == "Mar") mon = 3;
    if(month == "Apr") mon = 4;
    if(month == "May") mon = 5;
    if(month == "Jun") mon = 6;
    if(month == "Jul") mon = 7;
    if(month == "Aug") mon = 8;
    if(month == "Sep") mon = 9;
    if(month == "Oct") mon = 10;
    if(month == "Nov") mon = 11;
    if(month == "Dec") mon = 12;

    return mon;
}
/******************************************************************************
 * Function Name  : moneyCalc
 * Description    : Calculate parking amount based on parking duration.
 *
 * Parameters     :
 *      hr  -> Hours.
 *      min -> Minutes.
 *
 * Return         :
 *      Parking charge.
 ******************************************************************************/
unsigned int calculationN::calculationC::moneyCalc(int hr,int min)
{
    unsigned int money = 0;
    if(hr<1)
    {
        money =50;
    }
    else if(hr>1)
    {
        money =70;
    }
    else if(hr>2)
    {
        money =100;
    }
    else if(hr>6)
    {
        money =200;
    }
    else if(hr>12)
    {
        money =300;
    }
    else if(hr>23)
    {
        money =300;
    }
    return money;
}

//end of file