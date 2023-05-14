#pragma once
#include <iostream>
#include <string>
#include "Location.h"
using std::string;
using std::cout;
using std::endl;

struct Location; 
class Zoo; 


class Animal {
    friend class Zoo;
protected:
    Animal(const string& name_, const Location& location_); // 1
    virtual ~Animal() = default; // 1.1
    virtual void printDetails() const = 0;  // 2
    virtual char getInitial() const = 0; // 3
    Location getLocation() const; // 4
    virtual void step() = 0; // 5
    virtual void stop();  // 6
    virtual void move(); // 7
    virtual void turnVertically() = 0; // 8
    virtual void turnHorizontally() = 0; // 9
    virtual Location getDirection() const; 
    virtual Location getRandomDirection() const = 0; 

protected:
    string name;
    Location location;
    Location direction;
    bool isMoving;
};


