#include"fileHandling.h"
void fileWorkN::fileWorkC::lineFun(std::ofstream &file)
{
    for(int i=0;i<50;i++)
    file<<"-";

    file<<"\n";
}
void fileWorkN::fileWorkC::writeHeader(std::ofstream &file)
{
    lineFun(file);
    file<<"\n";

    file<<"Shape Record History\n";

    lineFun(file);
    file<<"\n";

}
void fileWorkN::fileWorkC::writeDataOnFile
(
    float areaVal,
    std::string shapSelection
)
{
    float area = areaVal;
    long long tempC =0;

   
    std::ifstream fileCountR("data/countSave.txt");

    if(fileCountR.is_open()==true)
    {
        if(fileCountR.peek()!=EOF)
        {
            fileCountR>>tempC;
            tempC++;
        }
        else
        {
            
            tempC = 0;
        }
    }

    std::ofstream file("data/shapeCalaculationSave.txt",std::ios::app);
    std::ifstream fileRead("data/shapeCalaculationSave.txt",std::ios::in);
    if(file.is_open()==true)
    {
        if(fileRead.is_open()==true)
        {
            //count++;
            if(fileRead.peek()==EOF)
            {
                writeHeader(file);
            }
            file<<tempC<<"). Area of "<<shapSelection<<std::endl;
            file<<area<<std::endl;
            lineFun(file);
            std::ofstream fileCountW("data/countSave.txt");
            fileCountW<<tempC;
        }
    } 
}
void fileWorkN::fileWorkC::readDataFromFile(std::string &shapSelection)
{

}
void fileWorkN::fileWorkC:: areaMain(float a,float b)
{

}
float fileWorkN::fileWorkC:: getArea()
{
    float f=0;
    return f;
}