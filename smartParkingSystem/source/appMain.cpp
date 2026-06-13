/******************************************************************************
 * File Name    : appMain.cpp
 * Description  : Application entry point for Smart Parking System.
 *                Displays menu and routes user requests to
 *                parking operations.
 *
 * Author       : Ankur Chourey
 * Language     : C++14
 ******************************************************************************/

#include"appMain.h"
#include<sstream>
#include"genralOperation.h"
#include"parkingOperation.h"

/******************************************************************************
 * Global Vehicle Object
 ******************************************************************************/
vehicleDetailsN::vehicleDetailsC obj;

/******************************************************************************
 * Function Name : main
 * Description   : Application starting point.
 *
 * Arguments     :
 *      argc -> Argument count.
 *      argv -> Argument vector.
 *
 * Return        :
 *      0 -> Success
 ******************************************************************************/
int main(int argc, char *argv[])
{
    /* Get Current System Time */
    std::time_t now = std::time(0);

    /* Convert Time To String */
    std::string dt = std::ctime(&now);

    /* Menu Object */
    menuN::menuC obj;

    /* Basic Argument Validation */
    if(argc < 1)
    {
        std::cout << "error!\n";
    }
    else
    {
        obj.menuFun();
    }
}

/******************************************************************************
 * Function Name : menuFun
 * Description   : Display application menu and perform
 *                 requested parking operation.
 *
 * Parameters    : None
 *
 * Return        : None
 ******************************************************************************/
void menuN::menuC::menuFun()
{
    std::string option;

    /* Login Handling Object */
    loginRightsN::loginRightsC loginObj;

    /* Parking Operation Object */
    parkingOperationN::parkingOperationC obj;

    clearScreen();
    parkingFirmName();

    std::string ss;
    int opt;

#if(LOGIN == 1)

    /* User Authentication */
    loginObj.login();

#else

    /* Bypass Login During Development */
    loginObj.rightsFlag = 1;

#endif

    if(loginObj.rightsFlag != 0)
    {
        std::cout << "Select Option:\n";
        std::cout << "Press 1: for Vehicle Entry\n";
        std::cout << "Press 2: for Vehicle Exit\n";
        std::cout << "Press 3: for Parking Status\n";

        if(loginObj.rightsFlag == 1)
        {
            std::cout << "Press 4: For History\n";
        }

        getline(std::cin, option);

        std::stringstream ss(option);
        ss >> opt;

        switch(opt)
        {
            case 1:
                obj.vehicleEnrty();
                break;

            case 2:
                obj.vehicleExit();
                break;

            case 3:
                obj.parkingStatus();
                break;

            case 4:
                if(loginObj.rightsFlag == 1)
                {
                     obj.history();
                }
                break;

            default:
                std::cout << "Invalid Option\n";
                break;
        }
    }
}