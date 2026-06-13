#ifndef PARKINGOPERATION_H
#define PARKINGOPERATION_H

/******************************************************************************
 * File Name    : parkingOperation.h
 * Description  : Parking Management System Operations
 * Author       : Ankur Chourey
 * Language     : C++14
 ******************************************************************************/

#include<iostream>
#include<fstream>
#include<ctime>
#include<cctype>
#include<string>
#include<vector>

#include"vehicleDetails.h"
#include"genralOperation.h"

#define DEBUG 0


void readSlotStatus(int *twoWheeler,int *fourWheeler);
/******************************************************************************
 * Namespace Name : parkingOperationN
 * Description    : Contains parking operation related classes and functions.
 ******************************************************************************/
namespace parkingOperationN
{
    /**************************************************************************
     * Class Name    : parkingOperationC
     * Description   : Handles vehicle entry, exit, slot allocation,
     *                 parking status and history management.
     **************************************************************************/
    class parkingOperationC : public vehicleDetailsN::vehicleDetailsC
    {
        private:

            /******************************************************************
             * Store new vehicle data into parking file.
             ******************************************************************/
            bool writeDataEntry
            (
                std::vector<vehicleDetailsN::vehicleDetailsC> &vecPark
            );

            /******************************************************************
             * Rewrite complete parking database.
             ******************************************************************/
            bool writeDataFull
            (
                std::vector<vehicleDetailsN::vehicleDetailsC> &vecPark
            );

            /******************************************************************
             * Find first available parking slot.
             ******************************************************************/
            int getBlankSlot
            (
                std::vector<vehicleDetailsN::vehicleDetailsC> &vecPark,
                bool *boflag,
                std::string *slot
            );

            /******************************************************************
             * Update available slot with vehicle information.
             ******************************************************************/
            void fillAvailableSlot
            (
                std::vector<vehicleDetailsN::vehicleDetailsC> &v1,
                std::vector<vehicleDetailsN::vehicleDetailsC> &v2,
                int index,
                std::string slt
            );

            /******************************************************************
             * Append parking data into CSV file.
             ******************************************************************/
            void pasteData1
            (
                std::vector<vehicleDetailsN::vehicleDetailsC> &v1,
                int slt
            );

            /******************************************************************
             * Rewrite CSV file using vector data.
             ******************************************************************/
            void pasteData
            (
                std::vector<vehicleDetailsN::vehicleDetailsC> &v1,
                int slt
            );

        public:
            //friend function.
            friend void readSlotStatus(int *twoWheeler,int *fourWheeler);
            /******************************************************************
             * Read complete parking data from file.
             ******************************************************************/
            void readFullData
            (
                std::vector<vehicleDetailsN::vehicleDetailsC> &vecPark
            );

            /******************************************************************
             * Handle vehicle entry operation.
             ******************************************************************/
            void vehicleEnrty();

            /******************************************************************
             * Handle vehicle exit operation.
             ******************************************************************/
            void vehicleExit();

            /******************************************************************
             * Display current parking status.
             ******************************************************************/
            void parkingStatus();

            /******************************************************************
             * Display parking history.
             ******************************************************************/
            void history();

            /******************************************************************
             * Save completed parking transaction.
             ******************************************************************/
            void saveData
            (
                vehicleDetailsN::vehicleDetailsC obj,
                unsigned int money
            );

            /******************************************************************
             * Check whether vehicle exists in parking database.
             ******************************************************************/
            bool checkNumberAvailableOrNot
            (
                std::string veh,
                int *slot
            );
            
    };
}

/******************************************************************************
 * Namespace Name : calculationN
 * Description    : Parking charge calculation utilities.
 ******************************************************************************/
namespace calculationN
{
    /**************************************************************************
     * Class Name   : calculationC
     * Description  : Calculates parking charges based on duration.
     **************************************************************************/
    class calculationC
    {
        public:

            unsigned int espondHours;
            unsigned int money;

            /**************************************************************
             * Calculate amount using entry and exit time.
             **************************************************************/
            unsigned int moneyCalcAsPerTime
            (
                std::string inTime,
                std::string outTime
            );

            /**************************************************************
             * Calculate amount using hours and minutes.
             **************************************************************/
            unsigned int moneyCalc
            (
                int hr,
                int min
            );

            /**************************************************************
             * Calculate month difference between two dates.
             **************************************************************/
            int monthCalcFun
            (
                int a1,
                int a2,
                std::string m1,
                std::string m2
            );

            /**************************************************************
             * Convert month string to month number.
             **************************************************************/
            int monthFun
            (
                std::string month
            );
    };
}

#endif