/******************************************************************************
 * File Name    : appMain.h
 * Description  : Application entry header.
 *                Contains menu class declaration and global objects used
 *                by the Smart Parking System.
 *
 * Author       : Ankur Chourey
 * Language     : C++14
 ******************************************************************************/

#ifndef APPMAIN_H
#define APPMAIN_H

#include<iostream>
#include<ctime>

#include"vehicleDetails.h"
#include"genralOperation.h"

/******************************************************************************
 * Login configuration
 * 0 -> Login disabled
 * 1 -> Login enabled
 ******************************************************************************/
#define LOGIN 0

/******************************************************************************
 * Global vehicle object.
 * Used to store temporary vehicle information.
 ******************************************************************************/
extern vehicleDetailsN::vehicleDetailsC obj;

/******************************************************************************
 * Namespace Name : menuN
 * Description    : Contains menu related classes and functions.
 ******************************************************************************/
namespace menuN
{
    /**************************************************************************
     * Class Name    : menuC
     * Description   : Handles main menu operations of the
     *                 Smart Parking System.
     *
     * Inheritance   :
     *      genralOperationC
     **************************************************************************/
    class menuC : public genralOperationN::genralOperationC
    {
        public:

            /**************************************************************
             * Function Name : menuFun
             * Description   : Display menu and process user selection.
             *
             * Parameters    : None
             * Return        : None
             **************************************************************/
            void menuFun();
    };
}

#endif