#include "TripPlanner.h"

Flight::Flight(Reservation* r) {
	this->setName(r->getName());
	this->setDate(r->getDate());
	this->setType(r->getType());
	this->setPrice(r->getPrice());
	this->setID(r->getID());
};

Flight::Flight(std::string f, std::string to, std::string t, std::string d, std::string id, float p) :
	Reservation(f, to, t, d, id, p) {};

void Flight::drawSymbol() {
	std::cout << "                           _             ____  " << std::endl;
	std::cout << "                          | \\           /   |" << std::endl;
	std::cout << "                    ______|__\\_________/    |" << std::endl;
	std::cout << "                 __//////    o  o  o  o  o  |  " << std::endl;
	std::cout << "                (___________    ____________|" << std::endl;
	std::cout << "                            \\  \\ " << std::endl;
	std::cout << "                             \\  \\ " << std::endl;
	std::cout << "                              \\__\\ " << std::endl;
}
