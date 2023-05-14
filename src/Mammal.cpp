#include "Mammal.h"

Mammal::Mammal(const std::string& name_, const Location& location_)
    : Animal(name_, location_) {
    this->num_of_legs = 4;
}
