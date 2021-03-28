#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Ball : public Drawable
{
public:
	Ball(float t_X, float t_Y);
	~Ball() = default;
	Ball() = delete;

	void update();

	float left();
	float right();
	float top();
	float bottom();

	void reflect();
	void moveUp();
	void moveDown();

	void setPosition(float t_X, float t_Y);
	void setVelocity();

	Vector2f getPosition();
private:
	CircleShape shape;	
	const float ballRadius{ 10.0f };
	const float ballVelocity{ 7.5f };
	void draw(RenderTarget& target, RenderStates state) const override; 
	Vector2f velocity{ ballVelocity, ballVelocity };
};

