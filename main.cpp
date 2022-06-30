// Copyright 2022 Riya Deokar riyaa@bu.edu
// Copyright 2022 Zakarey Sharif zsharif@bu.edu
// Copyright 2022 Ruhaan Bhagat rbhagat@bu.edu
// Copyright 2022 Camila Zhan Jin czhanjin@bu.edu

#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <string>
#include <unistd.h>
#include <vector>

using namespace sf;
using namespace std;

// Define the size of the game board. Create a rectangular board.
int sizeboard=16;
int w = 60;
int h = 40;
int width = sizeboard * w;
int height = sizeboard * h;

// Define the window in video mode giving static functions for our display.
RenderWindow window(VideoMode(width, height), "Snake.io");

// Initialize direction, size, movement of the snakes. 
int sdirec;
int srdirec;
int num = 6;

// Use a public class for each of the elements of the game (two snakes and target fruit)
class Snake {
    public:
    int x,y;}  s[100];

class Snake2 {
    public:
    int x,y;}  r[100];

class Fruit {
    public:
    int x,y;} f;

// Function 1: snake s (snake one) - function commands: Game over: once snake s hits the wall, moving direction, size increase of snake s after eating fruit.
void Player1(){

    // Text description of game over (size, font, color, message displayed...)
    sf::Text text;
    sf::Font gotham;
    gotham.loadFromFile("images/Gotham-Bold.otf");
    text.setFont(gotham);
    text.setPosition(window.getSize().x / 2.f - 140, window.getSize().y / 3.f);
    text.setString("Game Over : Player 1 Hit Wall");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);

    // Assign a number to each of the possible directions the snake can move (up, down, left, right).
    for (int i = num;i > 0; --i)
     {s[i].x = s[i-1].x; s[i].y = s[i-1].y;}

    if (sdirec == 0) {
        s[0].y += 1; 
    }     
    if (sdirec == 1) {
        s[0].x -= 1;   
    }     
    if (sdirec == 2) {
        s[0].x += 1; 
    }        
    if (sdirec == 3) {
        s[0].y -= 1;
    }   
    // randomize the position of the fruit 
    if ((s[0].x == f.x) && (s[0].y == f.y)) {
        num++; f.x = rand()%w; f.y = rand()%h;
    }
    // quit the game if the snake(s) move beyond the board. 
    if (s[0].x > w) {
        window.draw(text);
        window.display();
        sleep(10);
        exit(0);
    }
    if (s[0].x < 0) {
        window.draw(text);
        window.display();
        sleep(10);
        exit(0);
    }
    if (s[0].y > h) {
        window.draw(text);
        window.display();
        sleep(10);
        exit(0);
    }
    if (s[0].y < 0) {
        window.draw(text);
        window.display();
        sleep(10);
        exit(0);
    }
    // increase the size of the snake when a fruit is eaten. 
    for (int i = 1;i < num;i++)
     if (s[0].x == s[i].x && s[0].y == s[i].y) 
     num = i;     
}
// Function 2: snake r (snake two) - function commands: Game over: once snake s hits the wall, moving direction, size increase of snake r after eating fruit.
 void Player2() {

    // Text description of game over (size, font, color, message displayed...)
    sf::Text text;
    sf::Font gotham;
    gotham.loadFromFile("images/Gotham-Bold.otf");
    text.setFont(gotham);
    text.setPosition(window.getSize().x / 2.f - 140, window.getSize().y / 3.f);
    text.setString("Game Over : Player 2 Hit Wall");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);

    // Assign a number to each of the possible directions the snake can move (up, down, left, right).
    for (int i = num;i>0;--i) {
        r[i].x=r[i-1].x; r[i].y=r[i-1].y;
    }
         
    if (srdirec==0) r[0].y+=1;      
    if (srdirec==1) r[0].x-=1;        
    if (srdirec==2) r[0].x+=1;         
    if (srdirec==3) r[0].y-=1;   
    
    // randomize the position of the fruit 
    if ((r[0].x==f.x) && (r[0].y==f.y)){
        num++; f.x=rand()%w; f.y=rand()%h;
    }

    // quit the game if the snake(s) move beyond the board. 
    if (r[0].x > w) {
        window.draw(text);
        window.display();
        sleep(10);
        exit(0);
    }
    if (r[0].x < 0) {
        window.draw(text);
        window.display();
        sleep(10);
        exit(0);
    }
    if (r[0].y > h) {
        window.draw(text);
        window.display();
        sleep(10);
        exit(0);
    }
    if (r[0].y < 0) {
        window.draw(text);
        window.display();
        sleep(10);
        exit(0);
    }
    
    // increase the size of the snake when a fruit is eaten. 
    for (int i = 1; i < num; i++){
        if (r[0].x == r[i].x && r[0].y == r[i].y)  
        num = i;
    }
 }

int main() { 
    // Set music for the game. 
    // Music choice: FCB Barca anthem (best soccer team in the world (subjective)). 
    sf::Music music;
    if (!music.openFromFile("music.ogg"))
     return -1; // error
    music.play();

    // Score counts the size of the snakes (initial size == 6).
    char var; 
    int score1 = -6; 
    int score2 = -6; 

    // Let user choose single or two players.  
    std::cout << "multiplayer? enter Y or N" << "\n";
    std::cin >> var; 

    
    srand(time(0));


    // Displaying screen window. 
    // Upload images of the game to the directory, assign texture and sprite.  
    sf::Text screen;
    if(var=='N'){
        screen.setPosition(window.getSize().x / 2.f - 120, 3.f);
    }
    if(var=='Y'){
        screen.setPosition(window.getSize().x / 2.f - 222, 3.f);
    }
    screen.setCharacterSize(30);
    screen.setFillColor(sf::Color::Black);
    sf::Font gotham;
    if(!gotham.loadFromFile("images/Gotham-Bold.otf")); 
    screen.setFont(gotham);

    sf::Text screen2; 
    screen2.setPosition(window.getSize().x / 2.f - 140, window.getSize().y / 3.f);
    screen2.setCharacterSize(30);
    screen2.setFillColor(sf::Color::Red);
    screen2.setFont(gotham);

    Texture t1,t2,t3,t4;
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/gold.png");
    t3.loadFromFile("images/pink.png");
    t4.loadFromFile("images/app.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);
    Sprite sprite4(t4);

    Clock clock;
    float timer = 0, delay = 0.1;

    f.x=10;
    f.y=10; 

    // Assign direction command to the computer keyboard. 
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time; 

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)      
                window.close();
        }
        // Single player. 
        if(var == 'N'){
            if (Keyboard::isKeyPressed(Keyboard::Left)) sdirec=1;   
            if (Keyboard::isKeyPressed(Keyboard::Right)) sdirec=2;    
            if (Keyboard::isKeyPressed(Keyboard::Up)) sdirec=3;
            if (Keyboard::isKeyPressed(Keyboard::Down)) sdirec=0; 
            if (Keyboard::isKeyPressed(Keyboard::P)) {
                //system pauses when P is pressed. 
                sleep(1);
                    while(1) {
                        window.clear(sf::Color::White);
                        //print message
                        std::stringstream message;
                        message << "Game paused \n press 'p' to continue";
                        screen2.setString(message.str()); 
                        window.draw(screen2);
                        window.display();
                        if (Keyboard::isKeyPressed(Keyboard::P)){
                            //system("pause");
                            break;
                        }    
                    } 
                sleep(1);
            }         
        }   
        // Multiple (2) player.
        else if(var == 'Y'){
            if (Keyboard::isKeyPressed(Keyboard::Left)) sdirec=1; // left 
            if (Keyboard::isKeyPressed(Keyboard::Right)) sdirec=2; // right    
            if (Keyboard::isKeyPressed(Keyboard::Up)) sdirec=3; // up
            if (Keyboard::isKeyPressed(Keyboard::Down)) sdirec=0; // down  
            
            if (Keyboard::isKeyPressed(Keyboard::A)) srdirec=1; // left 
            if (Keyboard::isKeyPressed(Keyboard::D)) srdirec=2; // right     
            if (Keyboard::isKeyPressed(Keyboard::W)) srdirec=3; // up
            if (Keyboard::isKeyPressed(Keyboard::S)) srdirec=0; // down 
            if (Keyboard::isKeyPressed(Keyboard::P)){
             
            // system pauses when P is pressed. 
                sleep(1);
                    while(1) {
                        window.clear(sf::Color::White);
                        //print message
                        std::stringstream message;
                        message << "Game paused \n press 'p' to continue";
                        screen2.setString(message.str()); 
                        window.draw(screen2);
                        window.display();
                        if (Keyboard::isKeyPressed(Keyboard::P)){
                            //system("pause");
                            break;
                        }    
                    } 
                sleep(1);
            }
        }; 
        
        if (timer > delay) {
            if(var == 'N')
            {
                timer=0; 
                Player1(); 
            }
            if(var == 'Y'){
                timer=0; 
                Player1(); 
                Player2();
            }
        }

   ////// draw  ///////
    window.clear();
    // Set position of the snakes. 
    for (int i=0; i<w; i++) 
      for (int j=0; j<h; j++){
          sprite1.setPosition(i*sizeboard, j*sizeboard);  
          window.draw(sprite1); 
      }
      for (int i=0;i<num;i++){
          sprite2.setPosition(s[i].x*sizeboard, s[i].y*sizeboard);  
          window.draw(sprite2); 
          // Display a score board for the snakes based on how many apples are eaten by each snake. 
          if(var=='N'){
              if(sprite2.getPosition()==sprite4.getPosition()){
                score1++; 
              }
          }
              if(var == 'Y'){
                  sprite3.setPosition(r[i].x*sizeboard, r[i].y*sizeboard);  
                  window.draw(sprite3);
                  //SCORE
                  if(sprite2.getPosition()==sprite4.getPosition()){
                      score1++; 
                      }
                      if(sprite3.getPosition()==sprite4.getPosition()){
                          score2++; 
                      }
              }
      }
      // Print out the real time score. 
      sprite4.setPosition(f.x*sizeboard, f.y*sizeboard);  window.draw(sprite4);    
      //window.display();
                    
            //window.clear(sf::Color::White);
			//Print message
			stringstream message;
            if(var=='N'){
                message << "    SCORE: " << score1;
            }
            if(var=='Y'){
                message << "    SCORE1: " << score1 << "    SCORE2: " << score2;
            }
			screen.setString(message.str());
			//draw all
			window.draw(screen);
			window.display();
			//continue the loop, do not go in game;
			continue;
    }
    return 0;
}
