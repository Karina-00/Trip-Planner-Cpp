#include "TripPlanner.h"

Reservation* ReservationsBase::getTripById(std::string tripId) {
	for (int i = 0; i < this->getListLength(); i++) {
		if (this->getElementByIndex(i)->getID() == tripId) {
			return this->getElementByIndex(i);
		}
	}
	return nullptr;
}

void ReservationsBase::printAllTrips() {
	std::cout << "\nAll the available offers:\n" << std::endl;
	std::cout << "==============================================";
	std::cout << "==============================================" << std::endl;
	for (int i = 0; i < this->getListLength(); i++) {
		Reservation* trip = this->getElementByIndex(i);
		std::cout << i + 1 << ". " << trip->getName() << std::endl;
		std::cout << "\tThe date: " << trip->getDate() << std::endl;
		std::cout << "\tPrice: " << trip->getPrice() << " $" << std::endl;
		std::cout << "\tType: " << trip->getType() << std::endl;
		trip->drawSymbol();
		std::cout << "\n==============================================";
		std::cout << "==============================================" << std::endl;
	}
}
