#pragma once
#include "Mammal.h"
#include "Zoo.h"

class Zoo;

class Leon : public Mammal {
	friend class Zoo;
protected:
    Leon(const std::string& name_, const Location& location_);

    void printDetails() const override;
    char getInitial() const override;
    void step() override;
    void turnVertically() override;
    void turnHorizontally() override;
    Location getRandomDirection() const override;

private:
    bool hasMane;
    int sizeOfStep = 2;
};
