


#include <iostream>

int main()
{
    try {
    int* p = new int[1000000000000]; // huge allocation
    } catch (const std::bad_alloc& e) {
    std::cout << "Allocation failed: " << e.what() << std::endl;
    }
}