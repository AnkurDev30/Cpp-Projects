//AppMain.cpp


#include"AppHeader.h"
billing_system::BillingSystem::BillingSystem(int numberOfItem)
{
    pms_Input = new ms_Input[numberOfItem];
    m_numberOfItems = numberOfItem;
}

int main()
{
    int items;
    std::cout<<"enter number of items"<<std::endl;
    std::cin>>items;

    billing_system::BillingSystem object(items);
    int a = object.takingInput();
    int b = object.printOutput( );
    return 0;
}
void billing_system::BillingSystem::printLine()
{
    for(int j=0;j<NUMBER_OF_LINE;j++)
    {
        std::cout<<"-";
    }
    std::cout<<"-";

    std::cout<<"\n";
}
int billing_system::BillingSystem::takingInput()
{
    int numberOfItems = m_numberOfItems;
    for(int i=0;i<numberOfItems;i++)
    {
        std::cout<<"enter name of item"<<std::endl;
        std::cin>>pms_Input[i].name;

        std::cout<<"enter quantity "<<pms_Input[i].name<<" "<<std::endl;
        std::cin>>pms_Input[i].quantity;

        std::cout<<"enter price "<<pms_Input[i].name<<" "<<std::endl;
        std::cin>>pms_Input[i].price;
    }
    return 0;
}

int billing_system::BillingSystem::printOutput()
{
    int numberOfItems = m_numberOfItems;

    std::cout<<"display output"<<std::endl;
    int total = 0;
    int subTotal = 0;
    float finalTotal=0;
    float discount=0;
    float gstAmmount = 0;
    int gstOption =0;
    int discountOpt =0;

    std::cout<<"Gst option 1 for enable or 0 false"<<std::endl;
    std::cin>>gstOption;

    std::cout<<"Discount option 1 for enable or 0 false"<<std::endl;
    std::cin>>discountOpt;

    if(discountOpt == true)
    {
        std::cout<<"How much rupees Discount"<<std::endl;
        std::cin>>discount;
    }

    printLine();

    std::cout<<"|"<<std::left<<std::setw(10)<<"Item"<<"| "<<std::left<<std::setw(3)
    <<"Qty"<<"| "<<std::left<<std::setw(8)<<"Price"<<"| "<<std::left<<std::setw(10)
    <<"Total"<<"|"<<std::endl;

    for(int i=0;i<numberOfItems;i++)
    {
        total = 0;
        printLine();
        total = pms_Input[i].price * pms_Input[i].quantity;

        std::cout<<"|"<<std::left<<std::setw(10)<<pms_Input[i].name<<"| "
        <<std::left<<std::setw(3)<<pms_Input[i].quantity<<"| "
        <<std::left<<std::setw(8)<<pms_Input[i].price<<"| "
        <<std::left<<std::setw(10)<<total<<"|"<<std::endl;

        subTotal+=total;
    
    }
    printLine();
    std::cout<<"|"<<std::left<<std::setw(25)<<"Sub Total"<<"| "<<
    std::left<<std::setw(10)<<subTotal<<"|"<<std::endl;
    printLine();
    finalTotal+=subTotal;
    if(gstOption == true)
    {
        gstAmmount = (float)((subTotal*18)/100.0);

        std::cout<<"|"<<std::left<<std::setw(25)<<"GST(18%)"<<"| "<<
        std::left<<std::setw(10)<<gstAmmount<<"|"<<std::endl;
        printLine();
        finalTotal+=gstAmmount;
    }
    if(discountOpt == true)
    {
        std::cout<<"|"<<std::left<<std::setw(25)<<"Discount"<<"| "<<
        std::left<<std::setw(10)<<discount<<"|"<<std::endl;
        printLine();    
        finalTotal-=discount;    
    }
    std::cout<<"|"<<std::left<<std::setw(25)<<"Final Total"<<"| "<<
    std::left<<std::setw(10)<<finalTotal<<"|"<<std::endl;
    printLine();    

    return 0;
}