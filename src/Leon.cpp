#include "Leon.h"
#include <random>

namespace {
	std::random_device random_device;
	std::mt19937 engine{ random_device() };
}



Leon::Leon(const std::string& name_, const Location& location_)
	: Mammal(name_, location_)
{
	this->num_of_legs = 4;
	this->hasMane = random_device() % 2;
	this->direction = this->getRandomDirection();
}

void Leon::printDetails() const
{
	cout << this->name << " is a leon at " << this->location << endl;

}

char Leon::getInitial() const
{
	return 'L';
}

void Leon::step()
{
	if (!this->isMoving)
		return;

	int lastLocationX = this->location.x;
	// go 2 steps in the same direction
	this->location += this->direction * this->sizeOfStep;
	// check if need to change direction:
	// case 1: current direction is right (1,0):
	if ((lastLocationX + this->sizeOfStep*this->direction.x) > 39)
	{
		cout << "Leon " << this->name << " changed direction" << endl;
		this->turnHorizontally();
	}
	// case 2: current direction is left (-1,0):
	else if ((lastLocationX + this->sizeOfStep * this->direction.x) < 0)
	{
		cout << "Leon " << this->name << " changed direction" << endl;
		this->turnHorizontally();
	}
}

void Leon::turnVertically()
{
	return;
}

void Leon::turnHorizontally()
{
	this->direction *= -1;
}

Location Leon::getRandomDirection() const
{
	int direction = random_device() % 2;
	if (direction == 0)
		return Location(1, 0); // right
	else
		return Location(-1, 0); // left
}
