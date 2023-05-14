#pragma once
#include "Winged.h"
#include "Zoo.h"
#include <vector>
using std::vector;

class Zoo;

class Owl : public Winged {
	 friend class Zoo;
protected:
	Owl(const std::string& name_, const Location& location_);
	~Owl() override = default;
	void printDetails() const override;
	char getInitial() const override;
	bool needDefaultDirection() const override;
	Location getDefaultDirection() const override;

private:
	const static vector<Location> topLeftCorner;
	const static vector<Location> topRightCorner;
	const static vector<Location> bottomLeftCorner;
	const static vector<Location> bottomRightCorner;

};
