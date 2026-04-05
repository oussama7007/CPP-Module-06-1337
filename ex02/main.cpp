



#include "Base.h"
#include <iostream>
#include <cstdlib> // For srand()
#include <ctime>   // For time()


// Function prototypes so main knows they exist
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    // Seed the random number generator once
    srand(time(NULL));

    std::cout << "--- Generating 3 random objects ---" << std::endl;
    
    for (int i = 0; i < 3; i++) {
        Base* obj = generate();
        
        std::cout << "Test " << i + 1 << ":" << std::endl;
        
        std::cout << "Identify via pointer:   ";
        identify(obj);
        
        std::cout << "Identify via reference: ";
        identify(*obj);
        
        std::cout << "-----------------------------------" << std::endl;
        
        // Don't forget to free the memory!
        delete obj;
    }
    return 0;
}