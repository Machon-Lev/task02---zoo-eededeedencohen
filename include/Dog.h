#pragma once
#include "Mammal.h"
#include "Zoo.h"

class Zoo;


class Dog : public Mammal {
	friend class Zoo;
protected:
    Dog(const std::string& name_, const Location& location_);

    void printDetails() const override;
    char getInitial() const override;
    void step() override;
    void turnVertically() override;
    void turnHorizontally() override;
    void move() override;
    Location getRandomDirection() const override;

private:
    bool isBites;
    bool isStepForward;
    int sizeOfStep;
};
