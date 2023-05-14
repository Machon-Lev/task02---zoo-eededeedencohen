#pragma once
#include "Fish.h"
#include "Zoo.h"

class Zoo;

class Shark : public Fish {
	friend class Zoo;
protected:
    Shark(const std::string& name_, const Location& location_);
    ~Shark() override = default;

    void printDetails() const override;
    char getInitial() const override;
};
