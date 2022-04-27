#pragma once
#include "Triangle.h"

/*
* structure which represents section of function
*/
struct section
{
    float a;
    float b;
    float x_min;
    float x_max;

    section() {};

    section(const vec2& p1, const vec2& p2)
    {
        if (p1.x > p2.x)
        {
            x_min = p2.x;
            x_max = p1.x;
        }
        else
        {
            x_min = p1.x;
            x_max = p2.x;
        }

        a = (p1.y - p2.y) / (p1.x - p2.x);
        b = p1.y - (a * p1.x);
    }
};