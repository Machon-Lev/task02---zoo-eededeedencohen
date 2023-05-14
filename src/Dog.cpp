#include "Dog.h"
#include <random>

namespace {
	std::random_device random_device; 
	std::mt19937 engine{ random_device() };  
}

Dog::Dog(const std::string& name_, const Location& location_)
	: Mammal(name_, location_)
{
	this->num_of_legs = 4;
	this->isBites = random_device() % 2;
	this->isStepForward = true;
	this->sizeOfStep = 3;
	this->direction = this->getRandomDirection();
}

void Dog::printDetails() const
{
	cout << this->name << " is a dog at " << this->location << endl;

}

char Dog::getInitial() const
{
	return 'D';
}

void Dog::step()
{
	if(!this->isMoving)
		return;

	// save the last location:
	int lastLocationX = this->location.x;

	// step:
	this->location += this->direction * this->sizeOfStep;

	// check if need to change direction:
	if (this->isStepForward) 
	{
		if (((lastLocationX + this->sizeOfStep * this->direction.x) > 39) 
			|| ((lastLocationX + this->sizeOfStep * this->direction.x) < 0))
		{
			this->turnHorizontally();
		}
		this->isStepForward = false;
		this->sizeOfStep = -1;
	}
	else // is step backward
	{
		this->isStepForward = true;
		this->sizeOfStep = 3;
	}
}

void Dog::turnVertically()
{
	return;
}

void Dog::turnHorizontally()
{
	this->direction *= -1;
}

void Dog::move()
{
	if (this->isMoving)
	{
		cout << this->name << " is already moving" << endl;
		return;
	}

	this->isMoving = true;
	this->isStepForward = true;
	this->sizeOfStep = 3;
	cout << this->name << " is now moving" << endl;
	// if the x location is 0: the direction is right:
	if (this->location.x == 0)
	{
		this->direction = Location(1, 0);
		return;
	}
	// if the x location is 39: the direction is left
	if (this->location.x == 39)
	{
		this->direction = Location(-1, 0);
		return;
	}

	// random direction:
	this->direction = this->getRandomDirection();
}

Location Dog::getRandomDirection() const
{
	int direction = random_device() % 2;
	if (direction == 0)
		return Location(1, 0); // right 
	else
		return Location(-1, 0); // left
}

