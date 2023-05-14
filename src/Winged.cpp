#include "Winged.h"
#include <random>

namespace {
	std::random_device random_device;
	std::mt19937 engine{ random_device() };
}

Location Winged::getRandomDirection() const {
	int locationX = random_device() % 2; 
	if (locationX == 0) locationX = -1;

	int locationY = random_device() % 2; 
	if (locationY == 0) locationY = -1; 

	return Location(locationX, locationY);
}


Winged::Winged(const std::string& name_, const Location& location_) : Animal(name_, location_)
{
	this->flightSpeed = 1;
	this->isMoving = true;
	if (needDefaultDirection())
		this->direction = getDefaultDirection();
	else
		this->direction = getRandomDirection();
}


void Winged::step() {
	if (!this->isMoving)
		return;
	int stepCounter = 0;
	while (stepCounter < this->flightSpeed)
	{
		if (((this->location.x + this->direction.x) < 0)
			|| ((this->location.x + this->direction.x) > 39)
			|| ((this->location.y + this->direction.y ) < 0)
			|| ((this->location.y + this->direction.y ) > 19)) {
			this->direction *= -1;
		}
		this->location = this->location + this->direction;
		stepCounter++;
	}
	
}

void Winged::move() {
	if (this->isMoving)
	{
		cout << this->name << " is already moving" << endl;
		return;
	}
	if (needDefaultDirection())
		this->direction = this->getDefaultDirection();
	else
		this->direction = this->getRandomDirection();

	this->isMoving = true;
	cout << this->name << " is now moving" << endl;
}

// TO DO: implement this function
bool Winged::needDefaultDirection() const {
	return (this->location == Location(0,0) || this->location == Location(39, 0)
		|| this->location == Location(0, 19) || this->location == Location(39, 19));
}


Location Winged::getDefaultDirection() const {
	// case 1: left-top corner => right-down
	if (this->location == Location(0, 0))
		return Location(1, 1);
	// case 2: right-top corner => left-down
	else if (this->location == Location(39, 0))
		return Location(-1, 1);
	// case 3: left-bottom corner => right-up
	else if (this->location == Location(0, 19))
		return Location(1, -1);
	// case 4: right-bottom corner => left-up
	else if (this->location == Location(39, 19))
		return Location(-1, -1);
	else
		return Location(0, 0);
}

void Winged::turnVertically() {
	this->direction.y *= -1;
}

void Winged::turnHorizontally() {
	this->direction.x *= -1;
}



