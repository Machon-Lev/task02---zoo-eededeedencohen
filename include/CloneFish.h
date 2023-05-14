#pragma once
#include "Fish.h"
#include "Zoo.h"

class Zoo;

class CloneFish : public Fish {
	friend class Zoo;
protected:
    CloneFish(const std::string& name_, const Location& location_);
    ~CloneFish() override = default;

    void printDetails() const override;
    char getInitial() const override;
};
