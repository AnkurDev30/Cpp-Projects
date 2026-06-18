//Program 3: Product Price List
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<sstream>

#define DEBUG 1
class productList
{
    private:
        std::string productName;
        float price;
    public:
        void setData();
        float getPrice();
        std::string getProductName();
        void updateName(std::string);
        void updatePrice(std::string);
        bool nameCheck(std::string);
        bool priceCheck(std::string);
};

bool productList::nameCheck(std::string str)
{
    bool valid =true;

    for(char &ch:str)
    {
        ch = toupper(ch);
    }

    for(char ch:str)
    {
        if(!((ch>='A' && ch<='Z')))
        {
            valid=false;
            break;
        }
    }

    return valid;
}
bool productList::priceCheck(std::string str)
{
    bool valid =true;
    int count =0;
    for(char &ch:str)
    {
        ch = toupper(ch);
    }

    for(char ch:str)
    {
        if(!((ch>='0' && ch<='9')||(ch=='.')))
        {
            valid=false;
            break;
        }
        if(ch=='.')
        {
            count++;
        }
    }
    if(count>1)
    {
        valid =false;
    }

    return valid;
}

void productList::setData()
{
    std::string temp;
    std::string tempPrice;
    float num;
    std::cout<<"Product Name : "<<std::endl;
    getline(std::cin,temp);

    bool nameValid = nameCheck(temp);
    if(nameValid ==true)
    {
        productName = temp;
        
        std::cout<<productName<<" Price  : "<<std::endl;
        getline(std::cin,tempPrice);
        bool priceValid = priceCheck(tempPrice);
        if(priceValid == true)
        {
            std::stringstream ss(tempPrice);
            ss>>num;
            price = num;
        #if(DEBUG==1)
            std::cout<<price<<std::endl;
        #endif
        }
        else
        {
            std::cout<<"add correct price, example : 100.90\n";
        }
    }
    else
    {
        std::cout<<"add correct product name, avoid numbers and special symbole\n";
    }
    //display data.
   // system("clear");
    std::cout<<"Product : "<<productName<<std::endl;
    std::cout<<"Price   : "<<price<<std::endl;
}
float productList::getPrice()
{
    return price;
}
std::string productList::getProductName()
{
    return productName;
}
void productList::updateName(std::string str) 
{
    bool namaVlaidc = nameCheck(str);
    if(namaVlaidc == true)
    {
        productName = str;
    }
    else
    {
        std::cout<<"Enterd Name Wrong\n";
    }
}
void productList::updatePrice(std::string str)
{
    bool namaVlaidc = priceCheck(str);
    if(namaVlaidc == true)
    {
        std::stringstream ss(str);
        float ft;
        ss>>ft;
        price = ft;
    }
    else
    {
        std::cout<<"Enterd Price Wrong\n";
    }
}
class operation:public productList
{
    public:
        void opertionStart();
        void display();
        void addItem();
        void deleteData();
        void displayIndvisualIemPrice();
        bool checkOpt(std::string op);
};
void operation::deleteData()
{
    //read data
    std::map<std::string,float >mp;
    std::string proPrice,proName,data;
    float proPriceF;

    std::ifstream fi("groceryShopData.csv",std::ios::in);
    if(fi.is_open())
    {
        while(getline(fi,data))
        {
            std:: stringstream ss(data);
            getline(ss,proName,',');
            getline(ss,proPrice,',');

            std:: stringstream ft(proPrice);
            ft>>proPriceF;

            mp.insert({proName,proPriceF});
        }
    }
    //find data
    std::string deleteProdName;
    std::cout<<"Give Product Name for Delete\n";
    getline(std::cin,deleteProdName);
    if(mp.count(deleteProdName))
    {
        std::cout<<"Available Product Name\n";
        mp.erase(deleteProdName);
    }
    //delete data
    if(mp.count(deleteProdName)!=true)
    {
        std::cout<<"Delete Product\n";
    }
    //write data
    std::ofstream file("groceryShopData.csv",std::ios::out);
    if(file.is_open()==true)
    {
        for(auto &m:mp)
        {
            file<<m.first<<","<<m.second<<","<<std::endl;
        }
    }
}
void operation:: display()
{
    std::map<std::string,float>mpDisplay;

    std::string data;
    std::ifstream f("groceryShopData.csv");
    std::string proN,proPrice;
    float proPr;
    if(f.is_open() == true)
    {
        std::cout<<"file is open \n";
        while(getline(f,data))
        {
            std::stringstream ss(data);
            getline(ss,proN,',');
            getline(ss,proPrice,',');

            std::stringstream ft(proPrice);
            ft>>proPr;

            mpDisplay.insert({proN,proPr});

        }
        //using iterartors
        for(auto &mapT:mpDisplay)
        {
            std::cout<<"Product Name : "<<mapT.first
            <<" "<<",Price : "<<mapT.second<<std::endl;
        }
    }

}
bool operation::checkOpt(std::string op)
{
    int length = op.length();
    bool vaild =false;
    if(length==1 && op[0]>='0' && op[0]<='9')
    {
        vaild = true;
    }

    return vaild;
}
void operation::addItem()
{
    std::string productNm;
    float pricePro;

    setData();

    productNm = getProductName();
    pricePro = getPrice();

    std::ofstream f("groceryShopData.csv",std::ios::app);

    if(f.is_open() == true)
    {
        f<<productNm<<","<<pricePro<<","<<std::endl;
        std::cout<<"Save Data\n";
    }
    else
    {
        std::cout<<"File not open\n";
    }
}
void operation::displayIndvisualIemPrice()
{
    std::map<std::string,float>mpDisplay;

    std::string data;
    std::ifstream f("groceryShopData.csv");
    std::string proN,proPrice;
    float proPr;
    if(f.is_open() == true)
    {
        std::cout<<"file is open \n";
        while(getline(f,data))
        {
            std::stringstream ss(data);
            getline(ss,proN,',');
            getline(ss,proPrice,',');

            std::stringstream ft(proPrice);
            ft>>proPr;

            mpDisplay.insert({proN,proPr});

        }

        std::string productName;
        std::cout<<"Product Name : "<<std::endl;
        getline(std::cin,productName);

        if(mpDisplay.count(productName))
        {
            auto displayIndItemPrice = mpDisplay.find(productName);
            std::cout<<"Product price = "<<displayIndItemPrice->second<<std::endl;
        }
        else
        {
            std::cout<<"product not found\n";
        }
    }
}
void operation::opertionStart()
{
    std::string opt;
    int optInt;

    std::cout<<"Select Option\n1) Add Item\n2) Display Full Item List\n";
    std::cout<<"3) Delete Item\n4) Display Indivisual Item Price\n";
    getline(std::cin,opt);

    bool valid = checkOpt(opt);

    if(valid == true)
    {
        std::stringstream ss(opt);
        ss>>optInt;

        switch(optInt)
        {
            case 1:
                addItem();
            break;
            case 2:
                display();
            break;
            case 3:
                deleteData();
            break;
            case 4:
                displayIndvisualIemPrice();
            break;
            default:
            break;
        }
    }
}
int main()
{
    operation obj;
    obj.opertionStart();
}