#include "TripPlanner.h"


Cruise::Cruise(std::string f, std::string to, std::string t, std::string d, std::string id, float p) :
	Reservation(f, to, t, d, id, p) {};

Cruise::Cruise(Reservation* r) {
	this->setName(r->getName());
	this->setDate(r->getDate());
	this->setType(r->getType());
	this->setPrice(r->getPrice());
	this->setID(r->getID());
};

void Cruise::drawSymbol() {
	std::cout << "                    ||  ||  ||" << std::endl;
	std::cout << "              ______||__||__||_________" << std::endl;
	std::cout << "             /   ||||||||||||||||     |" << std::endl;
	std::cout << "      \\_____/_________________________|" << std::endl;
	std::cout << "        \\     ...................    /" << std::endl;
	std::cout << "         \\     ..................   /" << std::endl;
	std::cout << "          \\________________________/" << std::endl;
}
