


#include "ScalarConverter.h"



int main()
{
    std::string s = "a";
    try
    {
        {
            double d = std::stod(s);
            std::cout << "Converted:" << d << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    
}