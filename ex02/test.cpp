



#include <iostream>


class   Base
{
    public:
    int     level;
    Base() : level(505){}
    void    print_f()
    {
            std::cout << "level = " << this->level << std::endl;
    }
};

class derived : public Base
{
    public :
        int test;
        derived() : test(55) {}
        void print_f()
        {
            std::cout << "test =" << this->test << std::endl;
        }
};
int main()
{
    Base * b = new Base;
    derived * c = dynamic_cast<derived*>(b);
    if(c)
        c->print_f();
    else
        std::cout << "Cast failed\n";

}