#include <libgeometry/geometrylib.h>
#include <libgeometry/parser.h>

#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

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

    ASSERT_EQUAL(expected, result);
}

CTEST(parser_suite, test_1)
{
    // Given
    char str[100 + 1] = "circle(1 2, 3)";
    char* err_msg;
    int err_smb;
    char* c_radius;
    char* c_x;
    char* c_y;

    c_radius = malloc(100 * sizeof(char));
    c_x = malloc(100 * sizeof(char));
    c_y = malloc(100 * sizeof(char));

    // When
    const int result
            = find_circle(str, &err_msg, &err_smb, &c_radius, &c_x, &c_y);

    // Then
    const int expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST(parser_suite, test_2)
{
    // Given
    char str[100 + 1] = "circle(1 2 3)";
    char* err_msg;
    int err_smb;
    char* c_radius;
    char* c_x;
    char* c_y;

    c_radius = malloc(100 * sizeof(char));
    c_x = malloc(100 * sizeof(char));
    c_y = malloc(100 * sizeof(char));

    // When
    const int result
            = find_circle(str, &err_msg, &err_smb, &c_radius, &c_x, &c_y);

    // Then
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(parser_suite, test_3)
{
    // Given
    char str[100 + 1] = "circle(1 2, 3";
    char* err_msg;
    int err_smb;
    char* c_radius;
    char* c_x;
    char* c_y;

    c_radius = malloc(100 * sizeof(char));
    c_x = malloc(100 * sizeof(char));
    c_y = malloc(100 * sizeof(char));

    // When
    const int result
            = find_circle(str, &err_msg, &err_smb, &c_radius, &c_x, &c_y);

    // Then
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(parser_suite, test_4)
{
    // Given
    char str[100 + 1] = "circle(1 2, )";
    char* err_msg;
    int err_smb;
    char* c_radius;
    char* c_x;
    char* c_y;

    c_radius = malloc(100 * sizeof(char));
    c_x = malloc(100 * sizeof(char));
    c_y = malloc(100 * sizeof(char));

    // When
    const int result
            = find_circle(str, &err_msg, &err_smb, &c_radius, &c_x, &c_y);

    // Then
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}

CTEST(parser_suite, test_5)
{
    // Given
    char str[100 + 1] = "circle(-1.7 -2.1, 3.5)";
    char* err_msg;
    int err_smb;
    char* c_radius;
    char* c_x;
    char* c_y;

    c_radius = malloc(100 * sizeof(char));
    c_x = malloc(100 * sizeof(char));
    c_y = malloc(100 * sizeof(char));

    // When
    const int result
            = find_circle(str, &err_msg, &err_smb, &c_radius, &c_x, &c_y);

    // Then
    const int expected = 0;

    ASSERT_EQUAL(expected, result);
}

CTEST(parser_suite, test_6)
{
    // Given
    char str[100 + 1] = "";
    char* err_msg;
    int err_smb;
    char* c_radius;
    char* c_x;
    char* c_y;

    c_radius = malloc(100 * sizeof(char));
    c_x = malloc(100 * sizeof(char));
    c_y = malloc(100 * sizeof(char));

    // When
    const int result
            = find_circle(str, &err_msg, &err_smb, &c_radius, &c_x, &c_y);

    // Then
    const int expected = 1;

    ASSERT_EQUAL(expected, result);
}
