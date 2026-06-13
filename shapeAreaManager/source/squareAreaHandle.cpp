#include"squareAreaHandle.h"
void squareN::squareC::areaMain(float f1,float f2)
{
    float area;
    float edge = f1;

    area = f1*f1;
    this->area =area;

    std::cout<<"Edge of Square = "<<edge<<std::endl;
    std::cout<<"Square Area = "<<area<<std::endl;
}
float squareN::squareC::getArea()
{
    return area;
}