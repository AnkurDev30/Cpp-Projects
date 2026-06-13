//
#include"circleAreaHandle.h"

void circleAreaN::circleAreaC::areaMain(float f1,float f2)
{
    float radius  = f1;
    float area = (PI*radius*radius);
    this->area =area;
    std::cout<<"Radius is ="<<radius<<std::endl;
    std::cout<<"Area Of Circle = "<<area<<std::endl;
}
float circleAreaN::circleAreaC::getArea()
{
    return area;
}