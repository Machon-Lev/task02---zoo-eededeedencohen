#include "Shark.h"

Shark::Shark(const std::string& name_, const Location& location_) : Fish(name_, location_) {
    speed = 5;
}

void Shark::printDetails() const {
    cout << name << " is a shark at " << location << endl;
}

char Shark::getInitial() const {
    return 'S';
}
