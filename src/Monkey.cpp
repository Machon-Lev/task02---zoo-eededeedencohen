#include "Monkey.h"
#include <random>
#include <cstdlib>
#include <ctime>


namespace {
	std::random_device random_device;
	std::mt19937 engine{ random_device() };
}

Monkey::Monkey(const std::string& name_, const Location& location_)
	: Mammal(name_, location_) 
{
	this->num_of_legs = 2;
	this->hasGroup = random_device() % 2;
	this->goToSameDirectionCounter = 5; // counter 
	this->direction = this->getRandomDirection();
}

void Monkey::printDetails() const
{
	cout << this->name << " is a monkey at " << this->location << endl;
}

char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::step()
{
	if (!this->isMoving) 
		return;

	if (!goToSameDirectionCounter)
	{
		this->direction = this->getRandomDirection();
		this->goToSameDirectionCounter = 5;
	}
	// go randomaly 1 or 2 steps in the same direction and reduce the number of steps left
	int steps = random_device() % 2 + 1;
	Location lastLocation = this->location;
	this->location += this->direction * steps;

	// check if touched the border
	// if the direction is right or left
	if (this->direction.x != 0)
	{
		int fakeLocationX = lastLocation.x + this->direction.x * steps;
		// if the location is out of the border
		if (fakeLocationX > 39 || fakeLocationX < 0)
		{
			this->turnHorizontally();
		}
	}
	// if the direction is up or down
	else
	{
		int fakeLocationY = lastLocation.y + this->direction.y * steps;
		// if the location is out of the border
		if (fakeLocationY > 19 || fakeLocationY < 0)
		{
			this->turnVertically();
		}
	}
	this->goToSameDirectionCounter--;
}

void Monkey::move()
{
	if (this->isMoving)
	{
		cout << name << " is already moving" << endl;
		return;
	}
	this->isMoving = true;
	cout << name << " is now moving" << endl;
}

// vertically is up and down
void Monkey::turnVertically()
{
	this->direction*= -1;
}

// horizontally is right and left
void Monkey::turnHorizontally()
{
	this->direction*= -1;
}

Location Monkey::getRandomDirection() const
{
	int direction = random_device() % 4;
	switch (direction)
	{
		// right
	case 0:
		return Location(1, 0);
		// up
	case 1:
		return Location(0, -1);
		// down
	case 2:
		return Location(0, 1);
		// left
	case 3:
		return Location(-1, 0);
	}
	return Location(1, 0);
}


