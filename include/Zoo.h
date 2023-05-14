#pragma once
#include <vector>
#include "Animal.h"


class Zoo {
public:
    Zoo();
    ~Zoo();
    void run();
private:
    void stopAnimal(size_t index);
    void moveAnimal(size_t index); 
    void createAnimal(string type, string name); 
    void deleteAnimal(size_t index);
    bool isTypeOf (Animal* animal, string type); 
    void deleteAllAnimalsByType(string type);
    void stepAll();
    void deleteAll();
    void moveAll();
    void addAnimal(Animal* animal);
    void stopAll();
    void printAll() const;
    void printMap() const;
    Animal* getAnimal(size_t index) const;
    Location getDirection (size_t index) const;
    int getSize () const;
    string getName (size_t index) const;

    // UI functions 
    void printMainManu() const;
    void createAnimalUI();
    void stopAnimalUI();
    void moveAnimalUI();
    void deleteAnimalUI();
    void deleteAllAnimalsByTypeUI();
    void HelpUI() const;

    std::vector<Animal*> animals;
};
