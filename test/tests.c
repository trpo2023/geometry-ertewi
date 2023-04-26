#include <libgeometry/geometrylib.h>
#include <libgeometry/parser.h>

#include <ctest.h>
#include <stdio.h>

CTEST(geometry_suite, perimeter_1)
{
    // Given
    const float a = 1.5;

    // When
    const float result = count_perimeter(a);

    // Then
    const float expected = 9.424778;

    ASSERT_EQUAL(expected, result);
}

CTEST(geometry_suite, perimeter_2)
{
    // Given
    const float a = 1;

    // When
    const float result = count_perimeter(a);

    // Then
    const float expected = 6.283185;

    ASSERT_EQUAL(expected, result);
}

CTEST(geometry_suite, perimeter_3)
{
    // Given
    const float a = 0;

    // When
    const float result = count_perimeter(a);

    // Then
    const float expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST(geometry_suite, perimeter_4)
{
    // Given
    const float a = -1;

    // When
    const float result = count_perimeter(a);

    // Then
    const float expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST(geometry_suite, area_1)
{
    // Given
    const float a = -1;

    // When
    const float result = count_area(a);

    // Then
    const float expected = 0;

    printf("%f", count_area(a));
    ASSERT_EQUAL(expected, result);
}

CTEST(geometry_suite, area_2)
{
    // Given
    const float a = 0;

    // When
    const float result = count_area(a);

    // Then
    const float expected = 0;

    printf("%f", count_area(a));
    ASSERT_EQUAL(expected, result);
}

CTEST(geometry_suite, area_3)
{
    // Given
    const float a = 1;

    // When
    const float result = count_area(a);

    // Then
    const float expected = 3.141593;

    printf("%f", count_area(a));
    ASSERT_EQUAL(expected, result);
}

CTEST(geometry_suite, area_4)
{
    // Given
    const float a = 1.5;

    // When
    const float result = count_area(a);

    // Then
    const float expected = 7.068583;

    printf("%f", count_area(a));
    ASSERT_EQUAL(expected, result);
}