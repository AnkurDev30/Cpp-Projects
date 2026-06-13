#ifndef RACTANGLEAREAHANDLE_H
#define RACTANGLEAREAHANDLE_H
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include"area.h"

namespace ractangelN
{
    class ractangelC:public areaN::areaC
    {
        public:
        float area;
        void areaMain(float f1=0,float f2=0); 
        float getArea();
    };
}

#endif