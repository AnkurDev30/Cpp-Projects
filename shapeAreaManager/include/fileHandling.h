
#ifndef FILEHANDLING_H
#define FILEHANDLING_H
 #include<iostream>
 #include<string>
 #include<sstream>
 #include<iomanip>
 #include<fstream>
 #include"area.h"


 namespace fileWorkN
 {
    class fileWorkC:public areaN::areaC
    {
        private:
            long long count; 
            void writeHeader(std::ofstream &file);
            void lineFun(std::ofstream &file);
        public:
            
            void writeDataOnFile(float areaVal,std::string shapSelection);
            void readDataFromFile(std::string &shapSelection);
            void areaMain(float a,float b);
            float getArea();
    };
 }
#endif