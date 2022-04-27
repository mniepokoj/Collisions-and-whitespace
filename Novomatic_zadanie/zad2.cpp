#include "zad2.h"

int simulate_circle_rectangle()
{

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    sf::CircleShape circle;
    circle.setRadius(100);
    circle.setOrigin(100, 100);
    circle.setPosition(500, 500);
    circle.setFillColor(sf::Color::Green);

    VertexRectangle rec = VertexRectangle(100, 250, 690, 500);

    sf::Clock clock;
    float time = 0.;
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
                    rec.rotate(0, time);
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    rec.rotate(1, time);
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    rec.move(0, time);
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    rec.move(1, time);
                }
            }
        }

        if (isColliding(rec.getArray(), circle))
        {
            rec.setColor(sf::Color::Yellow);
        }
        else
        {
            rec.setColor(sf::Color::Red);
        }
        //     rec.move(time);
        window.clear();
        window.draw(circle);
        window.draw(rec);
        window.display();
        time = std::min(clock.restart().asSeconds(), 0.01f);
    }


    return 0;
}