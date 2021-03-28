#include "Ball.h"

Ball::Ball(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(Color::White);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Ball::update()
{
	shape.move(this->velocity);
	//sprawdzenie gora-dol
	if (this->top() < 0)
		velocity.y = ballVelocity;
	else if (this->bottom() > 600)
		velocity.y = -ballVelocity;
	
	//sprawdzenie prawo-lewo
	if (this->left() < 0)
		velocity.x = ballVelocity;
	else if (this->right() > 800)
		velocity.x = -ballVelocity;
}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

Vector2f Ball::getPosition()
{
	return shape.getPosition();
}

void Ball::reflect()
{
	if (this->velocity.x > 0)
		velocity.x = -ballVelocity;
	else if (this->velocity.x < 0)
		velocity.x = ballVelocity;
}

void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}

void Ball::moveUp()
{
	this->velocity.y = -ballVelocity;
}

void Ball::setPosition(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
}

void Ball::setVelocity()
{
	this->velocity.y = 0;
	this->velocity.x = ballVelocity;
}