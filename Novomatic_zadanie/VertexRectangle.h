#pragma once
#include <SFML/Graphics.hpp>


/*
* class representing Rectangle, based on VertexArray
* @author Mateusz Niepokoj
*/
class VertexRectangle : public sf::Drawable
{
private:
	float rotation;
	const sf::Vector2f speed = sf::Vector2f(100.f, 0);
	const float rotationSpeed = 3.;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::VertexArray vertexs;
public:

	VertexRectangle(float a, float b, float x, float y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void rotate(bool direction, float time);
	void move(bool direction ,float time);
	void setColor(sf::Color);
	const sf::VertexArray& getArray() const { return vertexs; }
};

