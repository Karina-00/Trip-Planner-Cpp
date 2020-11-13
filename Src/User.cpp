#include "TripPlanner.h"


User::User(std::string a, std::string b) : username(a), password(b) {};

User::~User() {
	for (int i = 0; i < myReservations.size(); i++)
		delete myReservations[i];
}

std::string User::getUsername() {
	return username;
}

std::string User::getPassword() {
	return password;
}

std::string User::getMyTripIdByIndex(int index) {
	return myReservations[index]->getID();
}

int User::getReservationCounter() {
	return myReservations.size();
}

bool User::hasReservation(std::string reservationNumber) {
	for (int i = 0; i < myReservations.size(); i++) {
		if (myReservations[i]->getID() == reservationNumber)
			return true;
	}
	return false;
}

void User::operator+=(Reservation* newReservation) {
	myReservations.push_back(newReservation);
}

void User::operator-=(std::string reservationNumber) {
	for (int i = 0; i < myReservations.size(); i++) {
		if (myReservations[i]->getID() == reservationNumber) {
			myReservations[i] = myReservations[myReservations.size() - 1];
			myReservations.pop_back();
			std::cout << "\nReservation successfully removed." << std::endl;
			return;
		}
	}
	std::cout << "\nFailed to find a reservation with such trip ID: " << reservationNumber << ". Make sure it's a proper number." << std::endl;
}

void User::displayMyTrips() {
	std::cout << "\nMy reservations:\n" << std::endl;
	std::cout << "==============================================";
	std::cout << "==============================================" << std::endl;
	for (int i = 0; i < myReservations.size(); i++) {
		Reservation* reservation = myReservations[i];
		std::cout << "Trip ID number: " << reservation->getID() << std::endl;
		std::cout << "\t" << reservation->getName() << std::endl;
		std::cout << "\tThe date: " << reservation->getDate() << std::endl;
		std::cout << "\tPrice: " << reservation->getPrice() << " $" << std::endl;
		std::cout << "\tType: " << reservation->getType() << std::endl;
		reservation->drawSymbol();
		std::cout << "\n==============================================";
		std::cout << "==============================================" << std::endl;
	}
	if (!myReservations.size()) {
		std::cout << "You don't have any reservations yet :c" << std::endl;
	}
}