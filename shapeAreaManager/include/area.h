#ifndef AREA_H
#define AREA_H

#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

namespace areaN
{
    class areaC
    {
        public:
            float area;
            virtual void areaMain(float f1=0,float f2=0)=0;
            virtual float getArea()=0;
    };
}
#endif

