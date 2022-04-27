#include <SFML/Graphics.hpp>
#include <iostream>
#include "TriangleCollision.h"

float fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

/*
* function for check performance of isCollding function
*/
int performance_test()
{
    triangle t1;
    triangle t2;

    int size = 100000;
    int count_own = 0;
    int count_other = 0;
    float mapsize = 10;
    float trianglesize = 1;

    sf::Clock clock;
    for (int i = 0; i < size; i++)
    {
        vec2 pos = { fRand(0, mapsize), fRand(0, mapsize) };
        t1.points[0] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };
        t1.points[1] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };
        t1.points[2] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };

        pos = { fRand(0, mapsize), fRand(0, mapsize) };
        t2.points[0] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };
        t2.points[1] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };
        t2.points[2] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };

        count_own += isColliding(t1, t2);
    }
    std::cout << "Time: " << clock.restart().asMilliseconds() << "\nCount own: " << count_own << std::endl << "Count other: " << count_other << std::endl;

    return 0;
}

/*
* graphicall representation of isColliding function, using console
* control by arrow buttons
*/
int efficiency_test()
{
    triangle t1;
    triangle t2;
    srand(time(NULL));


    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    float mapsize = 400;
    float trianglesize = 400;

    vec2 pos = { fRand(0, mapsize), fRand(0, mapsize) };
    t1.points[0] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };
    t1.points[1] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };
    t1.points[2] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };

    pos = { fRand(0, mapsize), fRand(0, mapsize) };
    t2.points[0] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };
    t2.points[1] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };
    t2.points[2] = vec2{ pos.x + fRand(0, trianglesize), pos.y + fRand(0, trianglesize) };

    sf::VertexArray v;
    v.setPrimitiveType(sf::Triangles);
    v.append(sf::Vertex(sf::Vector2f(t1.points[0].x, t1.points[0].y), sf::Color::Green));
    v.append(sf::Vertex(sf::Vector2f(t1.points[1].x, t1.points[1].y), sf::Color::Green));
    v.append(sf::Vertex(sf::Vector2f(t1.points[2].x, t1.points[2].y), sf::Color::Green));

    v.append(sf::Vertex(sf::Vector2f(t2.points[0].x, t2.points[0].y), sf::Color::Red));
    v.append(sf::Vertex(sf::Vector2f(t2.points[1].x, t2.points[1].y), sf::Color::Red));
    v.append(sf::Vertex(sf::Vector2f(t2.points[2].x, t2.points[2].y), sf::Color::Red));
    std::cout << isColliding(t1, t2);

    float delta = 10;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == event.KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Down)
                {
                    v[3].position.y += delta;
                    v[4].position.y += delta;
                    v[5].position.y += delta;
                    t2.points[0].y += delta;
                    t2.points[1].y += delta;
                    t2.points[2].y += delta;
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    v[3].position.y -= delta;
                    v[4].position.y -= delta;
                    v[5].position.y -= delta;
                    t2.points[0].y -= delta;
                    t2.points[1].y -= delta;
                    t2.points[2].y -= delta;
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    v[3].position.x += delta;
                    v[4].position.x += delta;
                    v[5].position.x += delta;
                    t2.points[0].x += delta;
                    t2.points[1].x += delta;
                    t2.points[2].x += delta;
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    v[3].position.x -= delta;
                    v[4].position.x -= delta;
                    v[5].position.x -= delta;
                    t2.points[0].x -= delta;
                    t2.points[1].x -= delta;
                    t2.points[2].x -= delta;
                }
                std::cout << isColliding(t1, t2) << std::endl;
            }
        }
        
        window.clear();
        window.draw(v);
        window.display();
    }


    return 0;
}

int main()
{
    efficiency_test();
}