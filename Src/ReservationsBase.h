#pragma once


class ReservationsBase : public Base <Reservation> {
public:
	Reservation* getTripById(std::string tripId);
	void printAllTrips();
};
