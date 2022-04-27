#pragma once
#include <SFML/Graphics.hpp>
#include "Section.h"
#include <array>

/*
* function which check if circuit of 2 triangles are intersecting
* function may not work properly if one of sides will be vertically
* @author Mateusz Niepokoj
* @param rectangle rectangle to be checked
* @param circle circle to be checked
* @return return true if circuit intersest, otherwise false
*/
bool isColliding(const sf::VertexArray& rectangle, const sf::CircleShape& circle);

