#pragma once
#include "Animal.h"
#include "Zoo.h"

class Zoo;

class Winged : public Animal {
    	friend class Zoo;
protected:
    Winged(const std::string& name_, const Location& location_);
    ~Winged() override = default;
    void step() override;
    void move() override;
    virtual bool needDefaultDirection() const;
    virtual Location getDefaultDirection() const;
    Location getRandomDirection() const override;
    void turnVertically() override;
    void turnHorizontally() override;

protected:
    int flightSpeed;
};

