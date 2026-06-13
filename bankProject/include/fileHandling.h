//File name : fileHandling.h

/*****************************************************
#   File Name   :   fileHandling.h
#   Description :   This file define read and write handling 
#                   for files.
#   Note        :   None.
*****************************************************/
#ifndef fileHandling_h
#define fileHandling_h


//!< include headers
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>

//!< define namespace from another header
    namespace accountDetailsN
    {
        class accountDetailsC;
    }
    
//!< define namespace
    namespace fileHandlingN
    {
        class fileHandlingC
        {
            public:
                bool writeDataInExcel(accountDetailsN::accountDetailsC &Obj);
                bool readFullData(std::vector <accountDetailsN::accountDetailsC> &ver);
                void clearData();
                bool writeFullData(std::vector <accountDetailsN::accountDetailsC> &ver);
        };
    }
#endif