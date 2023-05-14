#include <conio.h>   
#include "Zoo.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include "Animal.h"
#include "Location.h"
#include "Fish.h"
#include "Shark.h"
#include "CloneFish.h"
#include "Mammal.h"
#include "Monkey.h"
#include "Dog.h"
#include "Leon.h"
#include "Winged.h"
#include "Owl.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;

// ANSI escape code for red text color
const char* redColor = "\033[31m";

// ANSI escape code for green text color
const char* greenColor = "\033[32m";

// ANSI escape code for yellow text color
const char* yellowColor = "\033[33m";

// ANSI escape code for blue text color
const char* blueColor = "\033[34m";

// ANSI escape code for magenta text color
const char* magentaColor = "\033[35m";

// ANSI escape code for cyan text color
const char* cyanColor = "\033[36m";

// ANSI escape code for orange text color
const char* orangeColor = "\033[38;5;208m";

// ANSI escape code to reset text color
const char* resetColor = "\033[0m";

// Zoo:
Zoo::Zoo() {
	srand(time(NULL));
	// insert animls to the zoo
	createAnimal("Lion", "Simba");
	createAnimal("Lion", "Mufasa");
	createAnimal("Monkey", "Rafiki");
	createAnimal("Owl", "Hedwig");
	createAnimal("Dog", "Toto");
	createAnimal("Shark", "Jaws");
	createAnimal("CloneFish", "Nemo");
}

Zoo::~Zoo() {
    deleteAll();
}

// createAnimal:
void Zoo::createAnimal(string type, string name) {
    if (type == "Shark") {
		addAnimal(new Shark(name, Location(rand() % 40, rand() % 20)));
	} 
    else if (type == "CloneFish") {
		addAnimal(new CloneFish(name, Location(rand() % 40, rand() % 20)));
	} 
    else if (type == "Monkey") {
		addAnimal(new Monkey(name, Location(rand() % 40, rand() % 20)));
	}
    else if (type == "Dog") {
		addAnimal(new Dog(name, Location(rand() % 40, rand() % 20)));
	}
    else if (type == "Lion") {
		addAnimal(new Leon(name, Location(rand() % 40, rand() % 20)));
	}
    else if (type == "Owl") {
		addAnimal(new Owl(name, Location(rand() % 40, rand() % 20)));
	}
    else {
		cout << "Invalid type of animal" << endl;
	}
}

void Zoo::addAnimal(Animal* animal) {
    animals.push_back(animal);
}

void Zoo::stopAnimal(size_t index) {
    if (index < animals.size()) {
        animals[index]->stop();
    }
}

void Zoo::stopAll() {
    for (Animal* animal : animals) {
		animal->stop();
	}
}

void Zoo::moveAnimal(size_t index) {
    if (index < animals.size()) {
        animals[index]->move();
    }
}

void Zoo::moveAll() {
    for (Animal* animal : animals) {
		animal->move();
	}
}

void Zoo::deleteAnimal(size_t index) {
    if (index < animals.size()) {
        delete animals[index];
        animals.erase(animals.begin() + index);
    }
}

void Zoo::deleteAll() {
    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();
}

void Zoo::printAll() const {
	// orange color
	cout << orangeColor;
	for (size_t i = 0; i < animals.size(); i++) {
		cout << orangeColor << (i+1) << ". " << resetColor;
		animals[i]->printDetails();
	}
}

void Zoo::stepAll() {
    for (Animal* animal : animals) {
		animal->step();
	}
}

void Zoo::printMap() const{
 
    char map[20][40] = {0};
	char mapColor[20][40] = {0}; // 0 - white, 1 - red (for the !isMoving Animals), 2 - green (for the isMoving Animals)
    // fill the metrix:
    for (Animal* animal : animals) {
        map[animal->location.y][animal->location.x] = animal->getInitial();
		mapColor[animal->location.y][animal->location.x] = animal->isMoving ? 2 : 1;
	}
    // print the column numbers form 0 to 9
    cout << "   ";
    for (int t = 0; t < 10; t++) {
        cout<< " " << t << " ";
    }
    // print the column numbers from 10 to 39
    for (int x = 10; x < 40; x++) {
        cout << " " << x;
    }

    cout << endl << endl; // space between the numbers and the map

    // for that iterate on the row of the map
    for (int i = 0; i < 20; i++) {
        if (i < 10)
        {
            cout << "  " << i;
        }
        else
        {
            cout << " " << i;
        }
        // for that iterate on the column of the map
        for (int j = 0; j < 40; j++) {
            if (map[i][j] == 0) {
				cout << " - ";
            }
            else {
				//cout << " " << redColor <<map[i][j] << resetColor <<" ";
				if (mapColor[i][j] == 1) {
					cout << " " << redColor << map[i][j] << resetColor << " ";
				}
				else if (mapColor[i][j] == 2) {
					cout << " " << greenColor << map[i][j] << resetColor << " ";
				}
			}
		}
        cout << endl << endl;
	}
}

Animal* Zoo::getAnimal(size_t index) const {
    if (index < animals.size()) {
		return animals[index];
	}
	return nullptr;
}

Location Zoo::getDirection(size_t index) const {
    if (index < animals.size()) {
		return animals[index]->getDirection();
	}
	return Location(0, 0);
}

int Zoo::getSize() const {
	return animals.size();
}

string Zoo::getName(size_t index) const {
    if (index < animals.size())
    {
        return animals[index]->name;
    }
    else 
    return "";
}

void Zoo::run() {

    char option = '0';
	printMap();
	this->printMainManu();
    while (option != 7)
    {
        option = _getch();
		system("cls");
		printMap();

		switch (option) 
		{
		case '1': {
			this->stopAnimalUI();
			break;
		}
		case '2': {
			this->moveAnimalUI();
			break;
		}
		case '3': {
			createAnimalUI();
			break;
		}
		case '4': {
			this->deleteAnimalUI();
			break;
		}
		case '5': {
			this->deleteAllAnimalsByTypeUI();
			break;
		}
		case '6': {
			this->HelpUI();
			break;
		}
		case '7': {
			this->deleteAll();
			cout << "Goodbye!" << endl;
			return;
		}
		default: 
			break;
		

		} // end of switch case
		system("cls");
		printMap();
		printAll();
		option = '.';
		while(option == '.')
		{
			cout << endl;
			cout << greenColor << "Please enter an option: " << resetColor <<endl;
			cout << "- Dot ( . ): Making all the moving animals go." << endl;
			cout << "- Any other button: return to the main menu." << endl;
			option = getch();
			system("cls");

			switch (option)
			{
				case '.': 
				{
					stepAll();
					printMap();
					printAll();
					break;
				}
				default:
				{
					this->printMap();
					this->printMainManu();
					option = '0';
					break;
				}

			}
		}


    } // end of while loop

}


void Zoo::printMainManu() const {
	cout << greenColor << "Please enter an option: "<< resetColor << endl;
	cout << "1. Stop an animal" << endl;
	cout << "2. Move an animal" << endl;
	cout << "3. Create an animal" << endl;
	cout << "4. Delete an animal" << endl;
	cout << "5. Delete all animal by type" << endl;
	cout << "6. Help" << endl;
	cout << "7. Exit" << endl;
	cout << endl;
	cout << yellowColor << " - To go to the full zoo map -  click any other button" << resetColor << endl;
}

// Guide the user to create an animal
void Zoo::createAnimalUI()
{
	cout << greenColor << "Please enter the type name of the animal you want to create form the list below: " << resetColor << endl;
	cout << yellowColor << "Leon, Monkey, Dog, CloneFish, Shark, Owl, Mammal, Fish, Winged" << resetColor << endl;

	// Insert the type of the animal
	string type;
	cin >> type;
	while (type != "Leon" && type != "Monkey" && type != "Dog" && type != "CloneFish" && type != "Shark" && type != "Owl")
	{
		system("cls");
		this->printMap();
		cout << redColor << "Invalid type name!" << resetColor << endl;
		cout << greenColor << "Please enter the type name of the animal you want to create form the list below: " << resetColor << endl;
		cout << yellowColor << "Leon, Monkey, Dog, CloneFish, Shark, Owl, Mammal, Fish, Winged" << resetColor << endl;
		cin >> type;
	}
	system("cls");
	this->printMap();
	cout << greenColor << "Please enter the name of the animal: " << resetColor;
	string name;
	cin >> name;

	createAnimal(type, name);
	system("cls");
	this->printMap();
	cout << greenColor << "The " << type << " named " << name << " was created successfully!" << resetColor << endl;
	cout << yellowColor << "- Press Enter to continue..." << resetColor;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

void Zoo::stopAnimalUI()
{
	// case there is no Animals at the zoo - return:
	if (animals.size() == 0) 
	{
		cout << orangeColor << "There is no animals at the Zoo." << resetColor << endl << endl;
		cout << yellowColor << "- Press Enter to return the full Zoo Map..." << resetColor;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
		return;
	}

	cout << greenColor << "Please enter the number of the animal you want to stop form the list below:  " << resetColor << endl;
	this->printAll();
	cout << endl;
	cout << yellowColor << " - To return to the Zoo Map - enter 0" << resetColor << endl;
	size_t index;
	cin >> index;
	// validation with option to exit the function
	while (index > animals.size())
	{
		if (index == 0)
		{
			return;
		}
		system("cls");
		this->printMap();

		cout << redColor <<"Invalid number!"<< resetColor << endl;
		cout << greenColor << "Please enter a valid number from the list below to move the animal: " << resetColor << endl;
		this->printAll();
		cout << endl;
		cout << yellowColor << " - To return to the Zoo Map - enter 0" << resetColor << endl;
		cin >> index;
	}
	system("cls");
	this-> printMap();
	stopAnimal(index-1);
	cout << endl;

	if (index != 0)
	{
		cout << yellowColor << "- Press Enter to return the full Zoo Map..." << resetColor;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
	}
}

void Zoo::moveAnimalUI() 
{
	if (animals.size() == 0)
	{
		cout << orangeColor << "There is no animals at the Zoo." << resetColor << endl << endl;
		cout << yellowColor << "- Press Enter to return the full Zoo Map..." << resetColor;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
		return;
	}
	cout << greenColor << "Please enter the index of the animal you want to move from the list below: " << resetColor << endl;
	this->printAll();
	cout << endl;
	cout << yellowColor << " - To return to the Zoo Map - enter 0" << resetColor << endl;
	size_t index;
	cin >> index;
	// validation with option to exit the function
	while (index > animals.size())
	{
		if (index == 0)
		{
			return;
		}
		// clear the screen
		system("cls");
		cout << redColor << "Invalid index!" << resetColor << endl;
		cout << greenColor << "Please enter a valid index from the list below to move the animal: " << resetColor << endl;
		this->printAll();
		cout << yellowColor << " - To return to the Zoo Map - enter 0" << resetColor << endl;
		cin >> index;
	}
	// clear the screen
	system("cls");
	this->printMap();
	moveAnimal(index-1);
	cout << endl;
	cout << yellowColor << "- Press Enter to return the full Zoo Map..." << resetColor;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}



bool Zoo::isTypeOf(Animal* animal, string type) {
	if (type == "Leon" && dynamic_cast<Leon*>(animal) != nullptr)
		return true;
	if (type == "Monkey" && dynamic_cast<Monkey*>(animal) != nullptr)
		return true;
	if (type == "Dog" && dynamic_cast<Dog*>(animal) != nullptr)
		return true;
	if (type == "CloneFish" && dynamic_cast<CloneFish*>(animal) != nullptr)
		return true;
	if (type == "Shark" && dynamic_cast<Shark*>(animal) != nullptr)
		return true;
	if (type == "Owl" && dynamic_cast<Owl*>(animal) != nullptr)
		return true;
	if (type == "Mammal" && dynamic_cast<Mammal*>(animal) != nullptr)
		return true;
	if (type == "Fish" && dynamic_cast<Fish*>(animal) != nullptr)
		return true;
	if (type == "Winged" && dynamic_cast<Winged*>(animal) != nullptr)
		return true;
	return false;
}

void Zoo::deleteAllAnimalsByType(string type)
{	
	// iterate on the vector - for begem - for end:
	std::vector<Animal*>::iterator it = this->animals.begin();
	while (it != animals.end())
	{
		Animal* animal = *it;
		if (isTypeOf(animal, type))
		{
			it = animals.erase(it);
			delete animal;
		}
		else
		{
			it++;
		}
	}
}



void Zoo::deleteAnimalUI()
{
	if (animals.size() == 0)
	{
		cout << orangeColor << "There is no animals at the Zoo." << resetColor << endl << endl;
		cout << yellowColor << "- Press Enter to return the full Zoo Map..." << resetColor << endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
		return;
	}
	cout << greenColor << "Please enter the number of the animal ypu want to delete from the list below: " << resetColor << endl;
	this->printAll();
	cout << endl << endl;
	cout << yellowColor << "- To return to the Zoo Map - enter 0" << resetColor << endl;
	size_t index;
	cin >> index;
	// validation with option to exit the function
	while (index > animals.size())
	{
		if (index == 0)
		{
			return;
		}
		// clear the screen
		system("cls");
		this->printMap();
		cout << redColor << "Invalid index!" << resetColor << endl;
		cout << greenColor << "Please enter a valid number from the list below: " << resetColor << endl;
		this->printAll();
		cout << "To return to the Zoo Map, enter 0" << endl;
		cin >> index;
	}
	string deletedAnimalName = animals[index - 1]->name;
	deleteAnimal(index-1);
	// clear the screen
	system("cls");
	this->printMap();
	cout << endl;
	cout << greenColor << deletedAnimalName << " was deleted from the Zoo." << resetColor << endl << endl;
	cout << yellowColor << "- Press Enter to return the full Zoo Map..." << resetColor;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

void Zoo::deleteAllAnimalsByTypeUI()
{

	cout << greenColor << "Please enter the type of the animals you want to delete from the list below: " << resetColor << endl;
	cout << yellowColor << "Leon, Monkey, Dog, CloneFish, Shark, Owl, Mammal, Fish, Winged" << resetColor << endl;
	string type;
	cin >> type;
	// validation with option to exit the function
	while (type != "Leon" && type != "Monkey" && type != "Dog" && type != "CloneFish" && type != "Shark" && type != "Owl" && type != "Mammal" && type != "Fish" && type != "Winged")
	{
		system("cls");
		this->printMap();
		cout << redColor << "Invalid type name!" << resetColor << endl;
		cout << greenColor << "Please enter a valid type name from the list below: " << resetColor << endl;
		cout << yellowColor << "Leon, Monkey, Dog, CloneFish, Shark, Owl, Mammal, Fish, Winged" << resetColor << endl;
		cin >> type;
	}
	deleteAllAnimalsByType(type);
	system("cls");
	this->printMap();
	cout << greenColor << "All the " << type << "'s were deleted!" << resetColor << endl;
	cout << yellowColor << "- Press Enter to return the full Zoo Map..." << resetColor;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

void Zoo::HelpUI() const
{
	// clear the screen
	system("cls");
	this->printMap();
	cout << greenColor << "Choose one of the following options:" << resetColor << endl;
	cout << "1. How To Add An Animal To The Zoo" << endl;
	cout << "2. How To Stop An Animal In The Zoo" << endl;
	cout << "3. How To Move An Animal In The Zoo" << endl;
	cout << "4. How To Delete An Animal From The Zoo" << endl;
	cout << "5. How To Delete All Animals Of A Specific Type From The Zoo" << endl;
	cout << "6. Explanation of the zoo map" << endl;
	cout << "Any other key - Return to the Full Zoo map" << endl;

	// swith case for the user's choice
	int choice;
	cin >> choice;

	// clear the screen
	system("cls");
	this->printMap();
	
	switch (choice)
	{
		case 1:
		{
			// clear the screen
			cout << orangeColor << "Guide To Add An Animal To The Zoo:" << resetColor << endl << endl;
			cout << cyanColor << "Step 1: " << resetColor << "Choose the option 'Create an animal' from the Main Menu by press 3" << endl << endl;
			cout << cyanColor << "Step 2: " << resetColor << "Write the type of the animal you want to create from the list below:" << endl << endl;
			cout << greenColor << "Important Note:" << resetColor << "The type name must be written exactly as it appears in the Animal List." << endl;
			cout << "You can press 1 to see all the Animal List." << endl << endl;
			cout << cyanColor << "Step 3: " << resetColor << "Enter the name of the animal." << endl;
			cout << "After you enter the name, the animal will be added to the Zoo." << endl;
			cout << endl;
			cout << yellowColor << "- Press Enter to return the full zoo map..." << resetColor << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			break;
		}
		case 2:
		{
			cout << orangeColor << "Guide To Stop An Animal In The Zoo:" << resetColor << endl << endl;
			cout << cyanColor << "Step 1: " << resetColor << "Choose the option 'Stop an animal' from the Main Menu by press 1" << endl << endl;
			cout << cyanColor << "Step 2: " << resetColor << "Choose the animal you want to stop from the list below:" << endl << endl;
			cout << cyanColor << "Step 3: " << resetColor << "Enter the number of the animal you want to stop" << endl;
			cout <<"After you enter the number, the animal will stop." << endl << endl;
			cout << greenColor << "Important Note: " << resetColor << "Stopped animals are painted on the map in " << redColor << "Red" << resetColor << endl;
			cout << "When you try to stop an animal that is already stopped, you will get a message that the animal is already stopped." << endl;
			cout << endl;
			cout << yellowColor << "- Press Enter to return the full zoo map..." << resetColor << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			break;
		}
		case 3:
		{
			cout << orangeColor << "Guide To Move An Animal In The Zoo:" << resetColor << endl << endl;
			cout << cyanColor << "Step 1: " << resetColor << "Choose the option 'Move an animal' from the Main Menu by press 2" << endl << endl;
			cout << cyanColor << "Step 2: " << resetColor << "Choose the animal you want to move from the list below:" << endl << endl;
			cout << cyanColor << "Step 3: " << resetColor << "Enter the number of the animal you want to move" << endl;
			cout << "After you enter the number, the animal will move." << endl << endl;
			cout << greenColor << "Important Note:" << resetColor << "Moving animals are painted on the map in " << greenColor << "Green" << resetColor << endl;
			cout << "When you try to move an animal that is already moving, you will get an message  that the animal is already moving." << endl;
			cout << endl;
			cout << yellowColor << "- Press Enter to return the full zoo map..." << resetColor << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			break;
		}
		case 4:
		{
			cout << orangeColor << "Guide To Delete An Animal From The Zoo:" << resetColor << endl << endl;
			cout << cyanColor << "Step 1: " << resetColor << "Choose the option 'Delete an animal' from the Main Menu by press 4" << endl << endl;
			cout << cyanColor << "Step 2: " << resetColor << "Enter the number of the animal you want to delete from the list below:" << endl;
			cout << "After you enter the number, the animal will be deleted from the Zoo." << endl;
			cout << endl;
			cout << yellowColor << "- Press Enter to return the full zoo map..." << resetColor << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			break;
		}
		case 5:
		{
			cout << orangeColor << "Guide To Delete All Animals Of A Specific Type From The Zoo:" << resetColor << endl << endl;
			cout << cyanColor << "Step 1: " << resetColor << "Choose the option 'Delete all animals of a specific type' from the Main Menu by press 5" << endl << endl;
			cout << cyanColor << "Step 2: " << resetColor << "Enter the type name of the animal you want to delete from the list below:" << endl << endl;
			cout << greenColor << "Important Note: " << resetColor << "The type name must be written exactly as it appears in the Animal List." << endl;
			cout << "After you enter the type, all the animals of this type will be deleted from the Zoo." << endl;
			cout << endl;
			cout << yellowColor << "- Press Enter to return the full zoo map..." << resetColor << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			break;
		}
		case 6:
		{
			cout << orangeColor << "Explanation of the zoo map:" << resetColor << endl << endl;
			cout << "The zoo map will appear in each time at the top of the screen." << endl << endl;
			cout << "The Animal List will appear below the map when you go from" << endl << "the main menu to the full zoo map by press Any key except the menu options. " << endl;
			cout << "An animal on the map was represented by the first letter of its type" << endl;
			cout << "Example: Lion will appear on the map with the letter L " << endl << endl;
			cout << "The animals on the map are divided into two colors:" << endl;
			cout << greenColor << "Green" << resetColor << " - Moving animals" << endl;
			cout << redColor << "Red" << resetColor << " - Stopped animals" << endl << endl;
			cout << "When you in the full zoo map, you can press dot (.) to cause the moving animals to move one step" << endl;
			cout << endl;
			cout << yellowColor << "- Press Enter to return the full zoo map..." << resetColor << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
			break;

		}

	}
}



