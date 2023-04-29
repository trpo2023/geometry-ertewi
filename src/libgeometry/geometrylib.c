#include "geometrylib.h"

#include <math.h>

float count_perimeter(float rad)
{
    if (rad > 0)
        return (2 * M_PI * rad);

    return 0;
}

float count_area(float rad)
{
    if (rad > 0)
        return (M_PI * rad * rad);

    return 0;
}
