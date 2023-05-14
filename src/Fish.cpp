#include "Fish.h"
#include <random>

namespace {
	std::random_device random_device;
	std::mt19937 engine{ random_device() };
}

Fish::Fish(const std::string& name_, const Location& location_) : Animal(name_, location_)
{   
	this->direction = this->getRandomDirection();
}

void Fish::step() {
	if (!this->isMoving)
		return;
	
	Location lastLocation = this->location;
	this->location += (this->direction * this->speed);

	if ((lastLocation.x + (this->direction * this->speed).x > 39) 
		|| (lastLocation.x + (this->direction * this->speed).x < 0))
	{
		this->turnHorizontally();
	}

	if ((lastLocation.y + (this->direction * this->speed).y > 19)
		|| (lastLocation.y + (this->direction * this->speed).y < 0))
	{
		this->turnVertically();
	}
}

//=====================================
// from up to down, or from down to up
//=====================================
void Fish::turnVertically() {
	this->direction.y *= -1;
}

//===========================================
// from left to right, or from right to left
//===========================================

void Fish::turnHorizontally() {
	this->direction.x *= -1;
}


Location Fish::getDirection() const {
	return this->direction;
}

Location Fish::getRandomDirection() const {
	Location direction;
	do {
		int directionX = random_device() % 3 - 1; // -1, 0, 1
		int directionY = random_device() % 3 - 1; // -1, 0, 1
		direction = Location(directionX, directionY);
	} while (direction.x == 0 && direction.y == 0);

	return direction;
}


