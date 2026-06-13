#ifndef CIRCLEAREAHANDLER_H
#define CIRCLEAREAHANDLER_H

#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include"area.h"

#define PI 3.14
namespace circleAreaN
{
    class circleAreaC:public areaN::areaC
    {
        public:
        float area;
        void areaMain(float f1=0,float f2=0);
        float getArea();
    };

}

#endif