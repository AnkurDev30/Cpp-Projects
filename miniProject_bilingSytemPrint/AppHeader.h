//AppHeader.h

#include<iostream>
#include<iomanip>
#include<string>

#define NUMBER_OF_LINE 38

namespace billing_system
{
    class BillingSystem 
    {
        private:
            int m_numberOfItems;
            struct ms_Input
            {
                std::string name;
                float price;
                int quantity;
            };
            ms_Input *pms_Input = nullptr;
 
        public:
            BillingSystem(int numberOfItem);
            ~BillingSystem()
            {
                delete[] pms_Input;
                pms_Input =nullptr;
            }
        int takingInput();
        int printOutput();
        void printLine();
    };
}