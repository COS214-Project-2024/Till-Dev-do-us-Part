#include "Commercial.h"

/**
 * @brief Constructs a Commercial building with a specified type.
 *
 * This constructor initializes the Commercial building with the provided type,
 * using the base Building constructor to set the type.
 *
 * @param type The type or designation of the commercial building.
 */
Commercial::Commercial(string type) : Building(type)
{
    // Constructor body (empty, as it just initializes the type)
}
