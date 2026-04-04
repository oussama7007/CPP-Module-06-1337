


#pragma once 

#include "Data.h"
#include <iostream>
#include <stdint.h>


class   Srializer
{
    private:
        Srializer();
        Srializer(const  Srializer &obj);
        Srializer&  operator=(const Srializer &obj);
        ~Srializer();
    public:
        static  uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
}