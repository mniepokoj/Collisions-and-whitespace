#pragma once

#include <array>
#include "Triangle.h"
#include "Section.h"

/*
* function which check if circuit of 2 triangles are intersecting
* function may not work properly if one of sides will be vertically
* @author Mateusz Niepokoj
* @param triangle1 triangle to be checked
* @param triangle1 triangle to be checked
* @return return true if CIRCUIT intersest, otherwise false
*/
bool isColliding(const triangle& triangle1, const triangle& triangle2);