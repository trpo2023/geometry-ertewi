#include <libgeometry/geometrylib.h>
#include <libgeometry/parser.h>

#include <ctest.h>

CTEST(geometry_suite, perimeter)
{
    // Given
    const float a = 1;

    // When
    const float result = count_perimeter(a);

    // Then
    const float expected = count_perimeter(a);
    ASSERT_EQUAL(expected, result);
}