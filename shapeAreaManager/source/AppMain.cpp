//AppMain.cpp
#include"AppMain.h"
int main(int argc,char *argv[])
{
    areaN::areaC *basePointer;
    fileWorkN::fileWorkC fileObj;
    
    std::string shape;
    float areaCal;
    //std::cout<<argc<<std::endl;
    if(argc<2)
    {
        std::cout<<"Please give shape name correctly\n";
        return 0;
    }

    std::cout<<"Calculating Area\n";

    shape = argv[1];
    
    for(char &ch:shape)
    {
        ch = tolower(ch);
    }

    std::cout<<shape<<std::endl;

    if(shape == "circle")
    {
        float radius = 0;
        circleAreaN::circleAreaC circleObj;
        basePointer = &circleObj;
        std::cout<<"Area Of Circle Selected\n";
        std::cout<<"Enter Radius :\n";
        std::cin>>radius;
        basePointer->areaMain(radius);

        areaCal = basePointer->getArea();
        fileObj.writeDataOnFile(areaCal,"Circle")  ;
    }
    else if(shape == "rectangle")
    {
        ractangelN::ractangelC ractObj;
        basePointer = &ractObj;
        std::cout<<"Area Of Rectangle Selected\n";
        float l1;
        float w1;
        std::cout<<"Enter Length :\n";
        std::cin>>l1;
        std::cout<<"Enter Width :\n";
        std::cin>>w1;  
        basePointer->areaMain(l1,w1);     
        
        areaCal = basePointer->getArea();
        fileObj.writeDataOnFile(areaCal,"Rectangle")  ;
    }
    else if(shape == "square")
    {
        squareN::squareC sqObj;
        basePointer = &sqObj;
        std::cout<<"Area Of Square Selected\n";
        float edge;
        std::cout<<"Enter Edge of square :\n";
        std::cin>>edge;
 
        basePointer->areaMain(edge);  
        
        areaCal = basePointer->getArea();
        fileObj.writeDataOnFile(areaCal,"square")  ;  
    }
    else if(shape == "triangle")
    {
        tringleN::tringleC triObj;
        basePointer = &triObj;
        std::cout<<"Area Of Triangle Selected\n";
        float h;
        float b;
        std::cout<<"Enter Height :\n";
        std::cin>>h;
        std::cout<<"Enter Base :\n";
        std::cin>>b;  
        basePointer->areaMain(h,b);   
        
        areaCal = basePointer->getArea();
        fileObj.writeDataOnFile(areaCal,"triangle")  ;
    }
    else
    {
        std::cout<<"Wrong Option Select\n";
    }

}
