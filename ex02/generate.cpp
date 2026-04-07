



#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>

Base* generate(void) {
    int randomValue = rand() % 3;
    
    if (randomValue == 0)
        return new A();
    else if (randomValue == 1)
        return new B();
    else
        return new C();
}