#include "TripPlanner.h"


void LinkedTrip::updateAttributes() {
	float pricesSum = 0.0;
	Reservation* trip;
	std::string type, date, tripId, name;
	float price;

	for (int i = 0; i < this->getListLength(); i++) {
		trip = this->getElementByIndex(i);
		name = this->getName();
		type = this->getType();
		date = this->getDate();
		tripId = this->getID();
		price = this->getPrice();

		if (i != 0) {
			name += "\n\t";
			date += "\n\t          ";
			if (trip->getType() != type)
				this->setType("Mixed");
		}
		else {
			name = "";
			date = "";
			this->setType(trip->getType());
			this->setID("0000");
		}
		this->setName(name + trip->getName());
		this->setDate(date + trip->getDate());
		pricesSum += trip->getPrice();
	}
	if (this->getListLength() > 1) {
		price = pricesSum * 0.5;

		std::stringstream formatedNewPrice, formatedPreviousPricesSum;
		formatedNewPrice << std::fixed << std::setprecision(2) << price;
		formatedPreviousPricesSum << std::fixed << std::setprecision(2) << pricesSum;
		std::string heading = "SPECIAL OFFER! 50 % OFF! \n\t" + formatedNewPrice.str() + " $ instead of " +
								formatedPreviousPricesSum.str() + " $\n\t";
		this->setPrice(price);
		this->setName(heading + this->getName());
	}
	else
		this->setPrice(pricesSum);
}

void LinkedTrip::operator+=(Reservation* newTrip) {
	Base:: operator+=(newTrip);
	this->updateAttributes();
}
