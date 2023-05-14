#include "CloneFish.h"

CloneFish::CloneFish(const std::string& name_, const Location& location_) : Fish(name_, location_){}

void CloneFish::printDetails() const {
    cout << name << " is a clone fish at " << location << endl;
}

char CloneFish::getInitial() const {
    return 'C';
}

