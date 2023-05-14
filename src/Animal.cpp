#include "Animal.h"
#include "Location.h"

Animal::Animal(const string& name_, const Location& location_)
    : name(name_), location(location_), isMoving(true) {
}

Location Animal::getLocation() const {
    return location;
}

void Animal::stop() {
	if (!this->isMoving)
	{
		cout << name << " is already stopped" << endl;
		return;
	}
	this->isMoving = false;
	cout << name << " stopped" << endl;
}

void Animal::move() {
	if (this->isMoving)

	{
		cout << name << " is already moving" << endl;
		return;
	}
	this->isMoving = true;
	this->direction = this->getRandomDirection();
	cout << name << " is now moving" << endl;
}

Location Animal::getDirection() const {
	return direction;
}


