#ifndef SQUAREAREAHANDLE_H
#define SQUAREAREAHANDLE_H
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include"area.h"

namespace squareN
{
    class squareC:public areaN::areaC
    {
        public:
        float area;
        void areaMain(float f1=0,float f2=0); 
        float getArea();
    };
}

#endif