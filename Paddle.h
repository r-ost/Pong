#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Paddle : public Drawable
{
public:
	Paddle() = delete;
	Paddle(float t_X, float t_Y, Keyboard::Key key_up, Keyboard::Key key_down);
	~Paddle() = default;

	void update();

	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();
	void setKeys(Keyboard::Key key_up, Keyboard::Key key_down);
	void setPosition(float t_X, float t_Y);

private:
	RectangleShape shape;
	void draw(RenderTarget& target, RenderStates state) const override ;
	const float paddleHeight{ 80.0f };
	const float paddleWidth{ 10.0f };
	const float paddleVelocity{ 6.0f };
	Keyboard::Key key_up, key_down;
	Vector2f velocity{ 0, paddleVelocity };
};

