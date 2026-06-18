//Program 2: Mobile Directory
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<vector>

class mdData
{
    private:
    public:
        std::string name;
        std::string mbStr;
        long long mobileIntNum;
};
int main()
{
    std::ifstream mb("mobile_contacts_1000.csv");
    std::vector<mdData> vectMd;
    mdData object;
    std::map<std::string,long long>mapMobil;

    std::string ipString;
    if(mb.is_open()==true)
    {
        std::string str;
        while(getline(mb,str))
        {
            std::stringstream ss(str);
            getline(ss,object.name,',');
            getline(ss,object.mbStr,',');

            std::stringstream tt(object.mbStr);
            tt>>object.mobileIntNum;

            vectMd.push_back(object);
        }
        //insert data on map.
        for(size_t i = 0;i<vectMd.size();i++)
        {
            mapMobil.insert({vectMd[i].name,vectMd[i].mobileIntNum});
        }
        //input name.
        std::cout<<"Please give name for finding mobile number\n";
        getline(std::cin,ipString);

        auto mbIt = mapMobil.find(ipString);

        if(mbIt!=mapMobil.end())
        {
            std::cout<<"Mobile Number = "<<mbIt->second<<std::endl;
        }
        else
        {
            std::cout<<"Wrong name :\n";
        }
    }
}