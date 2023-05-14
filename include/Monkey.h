#pragma once
#include "Mammal.h"
#include "Zoo.h"

class Zoo;

class Monkey : public Mammal {
	friend class Zoo;
protected:
    Monkey(const std::string& name_, const Location& location_);

    void printDetails() const override;
    char getInitial() const override;
    void step() override;
    void turnVertically() override;
    void turnHorizontally() override;
    void move() override;
    Location getRandomDirection() const override;

private:
    bool hasGroup;
    int  goToSameDirectionCounter;
    static const int MAX_GO_TO_SAME_DIRECTION = 5;
};
