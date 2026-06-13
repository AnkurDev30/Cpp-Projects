/******************************************************************************
 * File Name    : genralOperation.h
 * Description  : Common utility functions, validation functions,
 *                login handling and system configuration macros
 *                used throughout the Smart Parking System.
 *
 * Author       : Ankur Chourey
 * Language     : C++14
 ******************************************************************************/

#ifndef GENRALOPERATION_H
#define GENRALOPERATION_H

#include<iostream>
#include<string>
#include<ctime>
#include<cctype>
#include<limits>
#include<iomanip>
/******************************************************************************
 * Parking System Configuration
 ******************************************************************************/
#define PARKING_NAME "RAMA PARKING"

#define MAX_2_WHEELER 3
#define MAX_4_WHEELER 3

/******************************************************************************
 * Login Credentials
 ******************************************************************************/
#define ADMIN_LOGIN "ADMIN1234"
#define OPER_LOGIN  "OPER1234"

#define PASS_KEY_ADMIN "1234"
#define PASS_KEY_OPER  "5678"

/******************************************************************************
 * Parking Slot Configuration
 ******************************************************************************/
#define MAX_4_WHEELER_SLOT 50
#define MAX_2_WHEELER_SLOT 100

/******************************************************************************
 * Namespace Name : genralOperationN
 * Description    : Contains utility and validation functions used
 *                  throughout the application.
 ******************************************************************************/
namespace genralOperationN
{
    /**************************************************************************
     * Class Name   : genralOperationC
     * Description  : Provides common helper functions such as:
     *                - Screen handling
     *                - Input validation
     *                - Display formatting
     *                - Vehicle validation
     **************************************************************************/
    class genralOperationC
    {
        public:

            /**************************************************************
             * Clear terminal screen.
             **************************************************************/
            void clearScreen();

            /**************************************************************
             * Display parking company header.
             **************************************************************/
            void parkingFirmName();

            /**************************************************************
             * Display separator line.
             **************************************************************/
            void lines();

            /**************************************************************
             * Validate alphanumeric string.
             **************************************************************/
            bool checkNameAndNumStaus(std::string name);

            /**************************************************************
             * Validate alphabetic string.
             **************************************************************/
            bool checkNameStaus(std::string name);

            /**************************************************************
             * Validate vehicle registration number.
             **************************************************************/
            bool checkVehicalNumber(std::string vehicleNumber);

            /**************************************************************
             * Validate numeric string.
             **************************************************************/
            bool checkOnlyNumber(std::string numberStr);

            /**************************************************************
             * Validate name containing spaces.
             **************************************************************/
            bool checkNameWithSpace(std::string str);

            /**************************************************************
             * Validate vehicle type.
             * Example:
             *      2 Wheeler
             *      4 Wheeler
             **************************************************************/
            bool checkVehicleType(std::string vType);

            /**************************************************************
             * Clear input buffer.
             **************************************************************/
            void cinIgnore();
    };
}

/******************************************************************************
 * Namespace Name : loginRightsN
 * Description    : Contains login and access control functionality.
 ******************************************************************************/
namespace loginRightsN
{
    /**************************************************************************
     * Class Name   : loginRightsC
     * Description  : Handles authentication and user role management.
     *
     * Inheritance  :
     *      genralOperationC
     **************************************************************************/
    class loginRightsC : public genralOperationN::genralOperationC
    {
        public:

            /**************************************************************
             * Store user access level.
             * Example:
             *      0 -> No Access
             *      1 -> Operator
             *      2 -> Administrator
             **************************************************************/
            int rightsFlag;

            /**************************************************************
             * Perform login authentication.
             **************************************************************/
            void login();

            /**************************************************************
             * Administrator access operations.
             **************************************************************/
            void adminUser();

            /**************************************************************
             * Operator access operations.
             **************************************************************/
            void operatorUser();
    };
}

#endif