#include <iostream>
#include "Serializer.hpp"

int main() {
    Data originalData;
    originalData.val = 123;
    originalData.v = "Test Data";

    std::cout << "Original Data:" << std::endl;
    std::cout << "  ID: " << originalData.val << std::endl;
    std::cout << "  Name: " << originalData.v << std::endl;

    uintptr_t raw = serializer::serialize(&originalData);

    Data* deserializedData = serializer::deserialize(raw);

    if (deserializedData == &originalData) {
        std::cout << "Deserialization was successful!" << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "  ID: " << deserializedData->val << std::endl;
    std::cout << "  Name: " << deserializedData->v << std::endl;

    return 0;
}