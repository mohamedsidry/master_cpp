#include "Serializer.hpp"



/**
 * @brief Serializer::serialize interprate block of memory as uintptr_t .
 * @param [in] ptr pointer to data .
 * @return value of that pointer as uintptr_t .
*/
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Serializer::deserialize interprate value as pointer to Data .
 * @param [in] raw raw uintptr_t .
 * @return pointer to Data .
*/
Data * Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

