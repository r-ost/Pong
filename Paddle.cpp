#include "Paddle.h"

Paddle::Paddle(float t_X, float t_Y, Keyboard::Key key_up, Keyboard::Key key_down)
{
	shape.setFillColor(Color::White);
	shape.setOrigin( this->paddleWidth / 2.f, this->paddleHeight / 2.f );
	shape.setPosition(t_X, t_Y);
	shape.setSize({ this->paddleWidth, this->paddleHeight });
	setKeys(key_up, key_down);
}

void Paddle::update()
{
	this->shape.move(this->velocity);

	if (Keyboard::isKeyPressed(key_up) && this->top() > 0)
		velocity.y = -paddleVelocity;
	else if (Keyboard::isKeyPressed(key_down) && this->bottom() < 600)
		velocity.y = paddleVelocity;
	else
		velocity.y = 0;
}

void Paddle::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);	
}

float Paddle::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}

float Paddle::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}

float Paddle::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Paddle::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Paddle::getPosition()
{
	return shape.getPosition();
}

void Paddle::setKeys(Keyboard::Key up, Keyboard::Key down)
{
	key_up = up;
	key_down = down;
}

void Paddle::setPosition(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
}