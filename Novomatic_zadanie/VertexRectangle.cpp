#include "VertexRectangle.h"

VertexRectangle::VertexRectangle(float A, float B, float X, float Y) : 
	size(A, B), 
	position(X, Y), 
	rotation(0.01), 
	vertexs(sf::PrimitiveType::TrianglesStrip)
{
	sf::Vertex v;
	v.color = sf::Color::Red;
	vertexs.append(sf::Vertex(position + sf::Vector2f(-A / 2, -B / 2), sf::Color::Red));
	vertexs.append(sf::Vertex(position + sf::Vector2f(-A / 2, +B / 2), sf::Color::Red));
	vertexs.append(sf::Vertex(position + sf::Vector2f(+A / 2, -B / 2), sf::Color::Red));
	vertexs.append(sf::Vertex(position + sf::Vector2f(+A / 2, +B / 2), sf::Color::Red));
	rotate(0, 0.);
}


void VertexRectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(vertexs);
}

void VertexRectangle::rotate(bool direction, float time)
{
	rotation += rotationSpeed * time * (direction ? 1 : -1);

	vertexs[0].position.x = position.x + (-size.x / 2.) * cos(rotation) - (-size.y / 2) * sin(rotation);
	vertexs[0].position.y = position.y + (-size.x / 2.) * sin(rotation) + (-size.y / 2) * cos(rotation);

	vertexs[1].position.x = position.x + (-size.x / 2.) * cos(rotation) - (+size.y / 2) * sin(rotation);
	vertexs[1].position.y = position.y + (-size.x / 2.) * sin(rotation) + (+size.y / 2) * cos(rotation);

	vertexs[2].position.x = position.x + (+size.x / 2.) * cos(rotation) - (-size.y / 2) * sin(rotation);
	vertexs[2].position.y = position.y + (+size.x / 2.) * sin(rotation) + (-size.y / 2) * cos(rotation);

	vertexs[3].position.x = position.x + (+size.x / 2.) * cos(rotation) - (+size.y / 2) * sin(rotation);
	vertexs[3].position.y = position.y + (+size.x / 2.) * sin(rotation) + (+size.y / 2) * cos(rotation);
}


void VertexRectangle::move(bool direction, float time)
{
	sf::Vector2f delta = speed * (time * (direction ? -1.f : 1.f));
	position += delta;
	for (int i = 0; i < vertexs.getVertexCount(); i++)
	{
		vertexs[i].position += delta;
	}
}

void VertexRectangle::setColor(sf::Color color)
{
	for (int i = 0; i < vertexs.getVertexCount(); i++)
	{
		vertexs[i].color = color;
	}
}