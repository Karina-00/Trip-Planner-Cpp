#include "TripPlanner.h"


int UsersBase::login(std::string username, std::string password) {
	User* user;
	for (int i = 0; i < this->getListLength(); i++) {
		user = this->getElementByIndex(i);
		if (user->getUsername() == username && user->getPassword() == password) {
			std::cout << "\nHello " << username << "!" << std::endl;
			return i;
		}
	}
	std::cout << "Failed to log in. Try again." << std::endl;
	return -1;
}

int UsersBase::createAccount(std::string username, std::string password) {
	for (int i = 0; i < this->getListLength(); i++) {
		if (this->getElementByIndex(i)->getUsername() == username) {
			std::cout << "Username " << username << " already exists." << std::endl;
			return -1;
		}
	}
	User* newUser = new User(username, password);
	*this += newUser;
	std::cout << "\nWelcome " << username << "!" << std::endl;
	return this->getListLength()-1;
}