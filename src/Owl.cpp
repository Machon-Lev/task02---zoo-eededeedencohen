#include "Owl.h"

const vector<Location> Owl::topLeftCorner = { Location(0,0), Location(1,0), Location(2,0),
	Location(0,1), Location(1,1), Location(2,1), Location(0,2), Location(1,2), Location(2,2) };

const vector<Location> Owl::topRightCorner = { Location(37,0), Location(38,0), Location(39,0),
	Location(37,1), Location(38,1), Location(39,1), Location(37,2), Location(38,2), Location(39,2) };

const vector<Location> Owl::bottomLeftCorner = { Location(0,17), Location(1,17), Location(2,17),
	 Location(0,18), Location(1,18), Location(2,18), Location(0,19), Location(1,19), Location(2,19) };

const vector<Location> Owl::bottomRightCorner = { Location(37,17), Location(38,17), Location(39,17),
	 Location(37,18), Location(38,18), Location(39,18), Location(37,19), Location(38,19), Location(39,19) };

bool Owl::needDefaultDirection() const {
	// if the owl is in one of the corners, it needs a default direction
	if (std::find(topLeftCorner.begin(), topLeftCorner.end(), this->location) != topLeftCorner.end())
		return true;
	if (std::find(topRightCorner.begin(), topRightCorner.end(), this->location) != topRightCorner.end())
		return true;
	if (std::find(bottomLeftCorner.begin(), bottomLeftCorner.end(), this->location) != bottomLeftCorner.end())
		return true;
	if (std::find(bottomRightCorner.begin(), bottomRightCorner.end(), this->location) != bottomRightCorner.end())
		return true;
	return false;
}

Location Owl::getDefaultDirection() const {
	// case the owl in the top left corner
	if (std::find(topLeftCorner.begin(), topLeftCorner.end(), this->location) != topLeftCorner.end())
		return Location(1, 1);
	// case the owl in the top right corner
	if (std::find(topRightCorner.begin(), topRightCorner.end(), this->location) != topRightCorner.end())
		return Location(-1, 1);
	// case the owl in the bottom left corner
	if (std::find(bottomLeftCorner.begin(), bottomLeftCorner.end(), this->location) != bottomLeftCorner.end())
		return Location(1, -1);
	// case the owl in the bottom right corner
	if (std::find(bottomRightCorner.begin(), bottomRightCorner.end(), this->location) != bottomRightCorner.end())
		return Location(-1, -1);
	return this->getRandomDirection();
}

Owl::Owl(const std::string& name_, const Location& location_) : Winged(name_, location_){
	this->flightSpeed = 3;
}

void Owl::printDetails() const {
	cout << name << " is an owl at " << location << endl;
}

char Owl::getInitial() const {
	return 'O';
}




