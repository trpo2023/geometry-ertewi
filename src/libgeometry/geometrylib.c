#include "geometrylib.h"

#include <math.h>

float count_perimeter(float rad)
{
    return (2 * M_PI * rad);
}

float count_area(float rad)
{
    return (M_PI * rad * rad);
}
