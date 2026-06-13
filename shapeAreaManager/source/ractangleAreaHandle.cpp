//
#include"ractangleAreaHandle.h"
void ractangelN::ractangelC::areaMain(float f1,float f2)
{
    float length  = f1;
    float width   = f2;
    float area = width*length;
    this->area =area;
    std::cout<<"Length is ="<<length<<std::endl;
    std::cout<<"Width is ="<<width<<std::endl;
    std::cout<<"Area Of Rectangle = "<<area<<std::endl;
}
float ractangelN::ractangelC::getArea()
{
    return area;
}