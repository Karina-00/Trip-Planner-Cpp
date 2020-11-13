#pragma once


class User {
	std::string username, password;
	std::vector<Reservation*> myReservations;

public:
	User(std::string a, std::string b);
	~User();

	std::string getUsername();
	std::string getPassword();
	std::string getMyTripIdByIndex(int index);
	int getReservationCounter();
	bool hasReservation(std::string reservationNumber);
	void operator+=(Reservation* newReservation);
	void operator-=(std::string reservationNumber);
	void displayMyTrips();
};
