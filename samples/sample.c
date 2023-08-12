#include "sample.h"

uint8_t getSum( uint8_t u8_a, uint8_t u8_b )
{
    if ( u8_a >= UINT8_MAX || u8_b >= UINT8_MAX )
    {
        // Handle overflow
        return UINT8_MAX;
    }

    return u8_a + u8_b;
}
