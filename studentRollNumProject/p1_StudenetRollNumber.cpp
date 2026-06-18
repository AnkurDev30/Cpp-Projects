//Program 1: Student Roll Lookup

#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
int main()
{
    std::map<int,std::string>m;
    std::string str;
    std::string rollnumber;
    std::string name;
    int roll;
    //read data from roll number file.
    std::ifstream f("rollnumber.csv");
    if(f.is_open()==true)
    {
        while(getline(f,str))
        {
            std::stringstream ss(str);
            getline(ss,rollnumber,',');
            getline(ss,name,',');

            std::stringstream rn(rollnumber);
            rn>>roll;
            m.insert({roll,name});
        }
    }

    std::cout<<"Enter rollnumber for display name:\n";
    getline(std::cin,rollnumber);
    std::stringstream rtTorn(rollnumber);
    rtTorn>>roll;

    auto stData = m.find(roll);
    if(stData!=m.end())
    {
        std::cout<<"roll number : "<<stData->first<<std::endl;
        std::cout<<"name : "<<stData->second<<std::endl;
    }
}