#include "RectangleCircleCollision.h"
#include <iostream>

float dist2(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	float x = v2.x - v1.x;
	float y = v2.y - v1.y;
	return x * x + y * y;
}

inline float calculate_x1(float a, float b, float c, float d, float r)
{
	return (-sqrt(-a * a * c * c + a * a * r * r - 2 * a * b * c + 2 * a * c * d - b * b + 2 * b * d - d * d + r * r) - a * b + a * d + c) / (a * a + 1);
}

inline float calculate_x2(float a, float b, float c, float d, float r)
{
	return (sqrt(-a * a * c * c + a * a * r * r - 2 * a * b * c + 2 * a * c * d - b * b + 2 * b * d - d * d + r * r) - a * b + a * d + c) / (a * a + 1);
}

bool isColliding(const sf::VertexArray& rectangle, const sf::CircleShape& circle)
{
	sf::Vector2f pos = circle.getPosition();

	std::array<std::pair<float, int>,4> r;

	//finding 2 the closest points
	for (int i = 0; i < 4; i++)
	{
		r[i] = std::make_pair(dist2(pos, rectangle[i].position), i);
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 2; j < 4; j++)
		{
			if(r[i].first > r[j].first)
				std::swap(r[i], r[j]);
		}
	}

	//check is the closest point is inside circle
	if (r[0].first < circle.getRadius() * circle.getRadius())
		return true;


	section s(	vec2{ rectangle[0].position.x, rectangle[0].position.y },
				vec2{ rectangle[1].position.x, rectangle[1].position.y });
	float x1 = calculate_x1(s.a, s.b, circle.getPosition().x, circle.getPosition().y, circle.getRadius());
	if (x1 >= s.x_min && x1 <= s.x_max)
		return true;
	float x2 = calculate_x2(s.a, s.b, circle.getPosition().x, circle.getPosition().y, circle.getRadius());
	if (x2 >= s.x_min && x2 <= s.x_max)
		return true;


	s = section(vec2{ rectangle[0].position.x, rectangle[0].position.y },
		vec2{ rectangle[3].position.x, rectangle[3].position.y });
	x1 = calculate_x1(s.a, s.b, circle.getPosition().x, circle.getPosition().y, circle.getRadius());
	if (x1 >= s.x_min && x1 <= s.x_max)
		return true;
	x2 = calculate_x2(s.a, s.b, circle.getPosition().x, circle.getPosition().y, circle.getRadius());
	if (x2 >= s.x_min && x2 <= s.x_max)
		return true;

	s = section(vec2{ rectangle[2].position.x, rectangle[2].position.y },
		vec2{ rectangle[3].position.x, rectangle[3].position.y });
	x1 = calculate_x1(s.a, s.b, circle.getPosition().x, circle.getPosition().y, circle.getRadius());
	if (x1 >= s.x_min && x1 <= s.x_max)
		return true;
	x2 = calculate_x2(s.a, s.b, circle.getPosition().x, circle.getPosition().y, circle.getRadius());
	if (x2 >= s.x_min && x2 <= s.x_max)
		return true;


	s = section(vec2{ rectangle[1].position.x, rectangle[1].position.y },
		vec2{ rectangle[2].position.x, rectangle[2].position.y });
	x1 = calculate_x1(s.a, s.b, circle.getPosition().x, circle.getPosition().y, circle.getRadius());
	if (x1 >= s.x_min && x1 <= s.x_max)
		return true;
	x2 = calculate_x2(s.a, s.b, circle.getPosition().x, circle.getPosition().y, circle.getRadius());
	if (x2 >= s.x_min && x2 <= s.x_max)
		return true;


	return false;
}