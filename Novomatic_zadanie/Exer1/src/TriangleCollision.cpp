#include "TriangleCollision.h"




/*
* function which check if 2 section are intersecting
*/
bool checkCollision(const section& s1, const section& s2)
{
    float x = (s2.b - s1.b) / (s1.a - s2.a);
    return (x >= s1.x_min && x >= s2.x_min && x <= s1.x_max && x <= s2.x_max);
}

bool isColliding(const triangle& triangle1, const triangle& triangle2)
{
    std::array<section, 3> s1, s2;
    s1[0] = section(triangle1.points[0], triangle1.points[1]);
    s1[1] = section(triangle1.points[0], triangle1.points[2]);
    s1[2] = section(triangle1.points[2], triangle1.points[1]);
    s2[0] = section(triangle2.points[0], triangle2.points[1]);
    s2[1] = section(triangle2.points[0], triangle2.points[2]);
    s2[2] = section(triangle2.points[2], triangle2.points[1]);

    bool flag;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            flag = checkCollision(s1[i], s2[j]);
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return flag;
}