#pragma once
#include "Animal.h"
#include "Zoo.h"

class Zoo;

class Fish : public Animal {
	friend class Zoo;
protected:
    Fish(const std::string& name_, const Location& location_);
    ~Fish() override = default;
    void step() override;
    void turnVertically() override;
    void turnHorizontally() override;
    Location getDirection() const;
    Location getRandomDirection() const override;

protected:
    int  speed = 1;
};

