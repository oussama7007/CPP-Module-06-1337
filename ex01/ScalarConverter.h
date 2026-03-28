
#include <iostream>

class ScalarConverter 
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &obj);
        ScalarConverter(const ScalarConverter &obj);    

        static void  convert()
};
