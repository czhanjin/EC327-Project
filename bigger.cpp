// Copyright 2021 J Carruthers jbc@bu.edu
// This program makes a window, and
// sets in motion a red circle. Clicking
// on the circle makes it bigger.
//
// SFML: https://www.sfml-dev.org
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using std::cin;
using std::cout;
int main()
{   int s;
    int x,y;
    x=y=0;
    sf::Music music;
    if (!music.openFromFile("music.ogg"))
     return -1; // error
    music.play();
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(10);
    shape.setFillColor(sf::Color::Red);
    window.setFramerateLimit(20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed){
              auto location = shape.getPosition();

              double dx =location.x-event.mouseButton.x;
              double dy =location.y-event.mouseButton.y;
              double dist2 = dx*dx +dy*dy;
              cout << dx << " " << dy << "\n";
              float cr = shape.getRadius();
              if (dist2 < cr*cr) {
                shape.setRadius(cr*2);
              }
            }
        }

        window.clear();
        x += 5;
        y += 10;
        shape.setPosition(x % 200,y %200);
        window.draw(shape);
        window.display();
    }

    return 0;
}