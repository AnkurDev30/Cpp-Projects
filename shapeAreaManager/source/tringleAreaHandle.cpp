//
#include"tringleAreaHandle.h"
void tringleN::tringleC::areaMain(float f1,float f2)
{
    float base =f1;
    float height =f2;
    std::cout<<"Base of Triangle = "<<base<<std::endl;
    std::cout<<"Height of Triangle = "<<height<<std::endl;
    float area = ((base*height)/2);
    this->area =area;
    std::cout<<"Area of Triangle = "<<area<<std::endl;
}
float tringleN::tringleC::getArea()
{
    return area;
}