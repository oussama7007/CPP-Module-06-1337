


#include "Serializer.h"



int main() {
    Data myData;
    myData.value = 42;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized: " << raw << std::endl;

    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Deserialized value: " << recovered->value << std::endl;

    if (recovered == &myData)
        std::cout << "✅ Success: pointers match" << std::endl;
    else
        std::cout << "❌ Error: pointers do not match" << std::endl;

    return 0;
}