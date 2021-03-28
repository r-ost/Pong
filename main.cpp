#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include <windows.h>
#include <string>
using namespace std;
using namespace sf;

//mechanizm wykrywania kolizji
template <class T1, class T2> bool isIntersecting(T1& a, T2& b)
{
	return a.right() >= b.left() && a.left() <= b.right()
		&& a.bottom() >= b.top() && a.top() <= b.bottom();
}

bool collisionTest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball) || ball.left() < 100.f + 2.5f || ball.right() > 700 - 2.5f) return false;

	ball.reflect();

	if (ball.getPosition().y < paddle.getPosition().y)
		ball.moveUp();
	else if (ball.getPosition().y > paddle.getPosition().y)
		ball.moveDown();
}

int main()
{
	RenderWindow window{ VideoMode {800, 600}, "Pong" };
	
	Ball ball(400, 300);
	Paddle paddle_1(700, 300, Keyboard::Key::Up, Keyboard::Key::Down);
	Paddle paddle_2(100, 300, Keyboard::Key::Q, Keyboard::Key::A);
	bool new_game = true;
	int player_1=0, player_2=0;
	Font font;
	font.loadFromFile("arial.ttf");
	Text p1, p2, end_text;
	p1.setFont(font); p2.setFont(font); end_text.setFont(font);	
	string string_p1 = "", string_p2 = "", end_string;

	window.setFramerateLimit(60);
	Event event;
	while (true)
	{
		if (new_game)
		{
			ball.setPosition(400, 300);
			paddle_1.setPosition(700, 300);
			paddle_2.setPosition(100, 300);
			ball.setVelocity();
		}
			
		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}

		ball.update();
		paddle_1.update();
		paddle_2.update();

		new_game = false;
		if (ball.getPosition().x + 10.0f > 800)
		{
			player_1++;
			new_game = true;
		}
		else if (ball.getPosition().x - 10.0f < 0) 
		{
			player_2++;
			new_game = true;
		}

		collisionTest(paddle_1, ball);
		collisionTest(paddle_2, ball);

		if (new_game) Sleep(1000);
		
		if (player_1 == 7 || player_2 == 7)
		{
			if (player_1 == 7) end_string = "Wygral gracz pierwszy!";
			else if (player_2 == 7) end_string = "Wygral gracz drugi!";
			RenderWindow end_window{ VideoMode {300, 200}, "Pong", Style::Close };
			end_window.clear(Color::White);
			while (end_window.isOpen())
			{
				// check all the window's events that were triggered since the last iteration of the loop
				sf::Event end_event;
				while (end_window.pollEvent(end_event))
				{
					// "close requested" event: we close the window
					if (end_event.type == sf::Event::Closed)
						end_window.close();
				}
				end_text.setString(end_string);  end_text.setCharacterSize(24); end_text.setFillColor(Color::Black);  end_text.setPosition(30, 80);
				end_window.draw(end_text);
				end_window.display();
			}
			break;
		}
		string_p1 = to_string(player_1);
		string_p2 = to_string(player_2);
		
		p1.setString(string_p1);  p1.setCharacterSize(24);  p1.setFillColor(Color::White);  p1.setPosition(30, 50);
		p2.setString(string_p2);  p2.setCharacterSize(24);  p2.setFillColor(Color::White);  p2.setPosition(770, 50);


		window.draw(paddle_1);
		window.draw(paddle_2);
		window.draw(ball);
		window.draw(p1);
		window.draw(p2);

		window.display();

		
	}
	return 0;
}