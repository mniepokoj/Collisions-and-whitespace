#pragma once
#include "Triangle.h"
#include <limits>

/*
* structure which represents section of function
*/
struct section
{
    float a;
    float b;
    float x_min;
    float x_max;

    section() : a(), b(), x_min(), x_max() {};

    section(const vec2& p1, const vec2& p2) : a(), b(), x_min(), x_max()
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
        if (p1.x != p2.x)
        {
            a = (p1.y - p2.y) / (p1.x - p2.x);
            b = p1.y - (a * p1.x);
        }
        else
        {
            x_min -= FLT_EPSILON;
            x_max += FLT_EPSILON;
            a = (p1.y - p2.y) / (p1.x - p2.x + FLT_EPSILON * 2);
            b = p1.y - (a * p1.x);
        }
    }
};