#pragma once
#include "Animal.h"
#include "Zoo.h"

class Zoo;

class Mammal : public Animal {
	friend class Zoo;
protected:
    Mammal(const std::string& name_, const Location& location_);
    virtual ~Mammal() = default;

protected:
    int num_of_legs;
};
