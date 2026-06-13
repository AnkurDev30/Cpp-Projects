/******************************************************************************
 * File Name    : vehicleDetails.h
 * Description  : Vehicle information management module.
 *                Stores vehicle details and provides interfaces
 *                to update, retrieve and display vehicle data.
 *
 * Author       : Ankur Chourey
 * Language     : C++14
 ******************************************************************************/

#ifndef VEHICLEDETAILS_H
#define VEHICLEDETAILS_H

#include<iostream>
#include<ctime>
#include<cctype>

#include"genralOperation.h"

#define DEBUG1 0
/******************************************************************************
 * Namespace Name : vehicleDetailsN
 * Description    : Contains vehicle related classes and operations.
 ******************************************************************************/
namespace vehicleDetailsN
{
    /**************************************************************************
     * Class Name   : vehicleDetailsC
     * Description  : Stores and manages vehicle information such as:
     *                - Vehicle Number
     *                - Owner Name
     *                - Entry Time
     *                - Exit Time
     *                - Mobile Number
     *                - Vehicle Type
     *                - Parking Slot Number
     *
     * Inheritance  :
     *      genralOperationC
     **************************************************************************/
    class vehicleDetailsC : public genralOperationN::genralOperationC
    {
        private:

            /* Parking Slot Number */
            std::string slotNum;

            /* Vehicle Registration Number */
            std::string vehicleNumber;

            /* Vehicle Owner Name */
            std::string vehicleOwner;

            /* Vehicle Entry Time */
            std::string inTime;

            /* Vehicle Exit Time */
            std::string outTime;

            /* Mobile Number */
            std::string mobileNumber;

            /* Vehicle Category (2W / 4W) */
            std::string vehicleType;

            /* Money  */
            unsigned int money ;
        public:

            /**************************************************************
             * Capture vehicle registration number.
             **************************************************************/
            void setVehicleNumber();

            /**************************************************************
             * Capture vehicle owner name.
             **************************************************************/
            void setVehicleOwner();

            /**************************************************************
             * Store current system time as entry time.
             **************************************************************/
            void setInTime();

            /**************************************************************
             * Store current system time as exit time.
             **************************************************************/
            void setOutTime();

            /**************************************************************
             * Capture owner mobile number.
             **************************************************************/
            void setMobileNumber();

            /**************************************************************
             * Capture vehicle type.
             **************************************************************/
            void setVehicleType();

            /**************************************************************
             * Assign parking slot number.
             **************************************************************/
            void setSlotNumber();
            /**************************************************************
             * Update money  from database.
             **************************************************************/
            void readUpdateMoney(unsigned int m);
            /**************************************************************
             * Update vehicle number from file/database.
             **************************************************************/
            void readUpdateVehicleNumber(std::string a);

            /**************************************************************
             * Update owner name from file/database.
             **************************************************************/
            void readUpdateVehicleOwner(std::string a);

            /**************************************************************
             * Update entry time from file/database.
             **************************************************************/
            void readUpdateInTime(std::string a);

            /**************************************************************
             * Update exit time from file/database.
             **************************************************************/
            void readUpdateOutTime(std::string a);

            /**************************************************************
             * Update mobile number from file/database.
             **************************************************************/
            void readUpdateMobileNumber(std::string a);

            /**************************************************************
             * Update vehicle type from file/database.
             **************************************************************/
            void readUpdateVehicleType(std::string a);

            /**************************************************************
             * Update slot number from file/database.
             **************************************************************/
            void readUpdateSlotNumber(std::string a);
            /**************************************************************
             * Return Money .
             **************************************************************/
            unsigned int getMoney();
            /**************************************************************
             * Return vehicle number.
             **************************************************************/
            std::string getVehicleNumber();

            /**************************************************************
             * Return owner name.
             **************************************************************/
            std::string getVehicleOwner();

            /**************************************************************
             * Return entry time.
             **************************************************************/
            std::string getInTime();

            /**************************************************************
             * Return exit time.
             **************************************************************/
            std::string getOutTime();

            /**************************************************************
             * Return mobile number.
             **************************************************************/
            std::string getMobileNumber();

            /**************************************************************
             * Return vehicle type.
             **************************************************************/
            std::string getVehicleType();

            /**************************************************************
             * Return slot number.
             **************************************************************/
            std::string getSlotNum();

            /**************************************************************
             * Update vehicle exit time.
             **************************************************************/
            void updateOutTime(std::string oT);

            /**************************************************************
             * Display vehicle information.
             **************************************************************/
            void displayVehicalDetails();

            /**************************************************************
             * Capture complete vehicle details.
             **************************************************************/
            void enterVehicleDetails
            (
                vehicleDetailsN::vehicleDetailsC &obj,
                bool *p,
                bool *q
            );

            /**************************************************************
             * Copy current object data into another object.
             **************************************************************/
            void readDataFromVehicleData
            (
                vehicleDetailsN::vehicleDetailsC &obj
            );
    };
}

#endif