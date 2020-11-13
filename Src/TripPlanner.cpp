#include "TripPlanner.h"


std::string USERS_FILE = "Text files/users.txt";
std::string TRIPS_FILE = "Text files/trips.txt";


void generateSpecialLinkedTrip(ReservationsBase* tripsBase) {
	LinkedTrip* specialTrip = new LinkedTrip();
	srand((unsigned int)time(NULL));

	int range = tripsBase->getListLength();
	int linkedTripSize = rand() % 2 + 2;
	std::set<int> randomIntegers;

	for (int i = 0; i < linkedTripSize; i++) {
		while(randomIntegers.size() == i)
			randomIntegers.insert(rand() % range);
	}

	for (std::set<int>::iterator i = randomIntegers.begin(); i != randomIntegers.end(); i++)
		*specialTrip += tripsBase->getElementByIndex(*i);

	if (specialTrip->getType() == "Flight")
		*tripsBase += new Flight(specialTrip);
	else if (specialTrip->getType() == "Cruise")
		*tripsBase += new Cruise(specialTrip);
	else
		*tripsBase += new MixedTrip(specialTrip);
}

int inputValidInteger() {
	int n;
	while (!(std::cin >> n)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Try again:\n>> ";
	}
	return n;
}

void readTripsFile(ReservationsBase* tripsBase){
	std::fstream trips;
	trips.open(TRIPS_FILE, std::ios::in);

	while (trips.good()) {
		std::string from, to, type, date, id, p;

		getline(trips, from, ',');
		getline(trips, to, ',');
		getline(trips, type, ',');
		getline(trips, date, ',');
		getline(trips, id, ',');
		getline(trips, p, '\n');
		float price = std::stof(p);

		if(type == "Flight")
			*tripsBase += new Flight(from, to, type, date, id, price);
		else if(type == "Cruise")
			*tripsBase += new Cruise(from, to, type, date, id, price);
		else
			*tripsBase += new MixedTrip(from, to, type, date, id, price);
	}
	trips.close();
}

void readUsersFile(UsersBase* usersBase, ReservationsBase* tripsBase) {
	std::fstream users;
	users.open(USERS_FILE, std::ios::in);

	while(users.good()) {
		std::string username, password, tripId;

		getline(users, username, ',');
		getline(users, password, ',');
		User* newUser = new User(username, password);
		
		while(getline(users, tripId, ',')) {
			if (tripId != "") {
				Reservation* trip = tripsBase->getTripById(tripId);
				if(trip) *newUser += trip;
			}
			else {
				getline(users, tripId, '\n');
				break;
			}
		}
		*usersBase += newUser;
	}
	users.close();
}

std::string inputPassword() {
	int i = 0;
	char ch;
	std::string password;
	while(true) {
		ch = _getch();
		if (ch != 8 && ch != 13) {
			std::cout << "*";
			password += ch;
			i++;
		}
		else if (ch == 8) {
			if (i > 0) {
				std::cout << "\b \b";
				i--;
				password.pop_back();
			}
		}
		else break;
	}
	return password;
}

User* login(UsersBase * usersBase) {
	int n, index;
	std::string username, password;

	while (true) {
		std::cout << "Choose an option (1/2):\n1)Log in\n2)Create an account\n>> ";
		n = inputValidInteger();
		std::cout << std::endl;

		std::cout << "Enter your username: ";
		std::cin >> username;

		std::cout << "Enter your password: ";
		password = inputPassword();
		std::cout << std::endl;

		switch (n) {
		case 1:
			index = usersBase->login(username, password);
			break;
		case 2:
			index = usersBase->createAccount(username, password);
			break;
		default:
			continue;
		}
		if (index >= 0) break;
	}
	return usersBase->getElementByIndex(index);
}

void seeMyReservations(User* user) {
	user->displayMyTrips();
}

void cancelTrip(User* user) {
	std::cout << "\nChoose the reservation you want to cancel:" << std::endl;
	seeMyReservations(user);
	std::cout << "\nEnter the reservation ID number of the trip you want to cancel:\n>> ";
	std::string tripId;
	std::cin >> tripId;
	*user -= tripId;
}

void bookTrip(ReservationsBase* tripsBase, User* user) {
	std::string tripId;
	tripsBase->printAllTrips();
	std::cout << "\nChoose the reservation number from the list:\n>> ";
	int index = inputValidInteger() - 1;

	Reservation* newTrip = tripsBase->getElementByIndex(index);
	if (newTrip) {
		if (user->hasReservation(newTrip->getID()))
			std::cout << "\nYou've already bought that trip.\n" << std::endl;
		else {
			*user += newTrip;
			std::cout << "\nReservation successfully bought.\n" << std::endl;
		}
	}
	else
		std::cout << "\nFailed to find a reservation with such a number on our list. Make sure it's a proper number.\n" << std::endl;
}

void updateFile(UsersBase* usersBase) {
	int usersCount = usersBase->getListLength();
	User* currentUser;

	std::ofstream users;
	users.open(USERS_FILE, std::ios::out | std::ios::trunc);

	for (int i = 0; i < usersCount; i++) {
		currentUser = usersBase->getElementByIndex(i);

		users << currentUser->getUsername() << ',' << currentUser->getPassword() << ',';
		for (int j = 0; j < currentUser->getReservationCounter(); j++)
			users << currentUser->getMyTripIdByIndex(j) << ',';
		users << ',';
		if (i != usersCount - 1) users << std::endl;
	}
	users.close();
}

void initialOperations(ReservationsBase* tripsBase, UsersBase* usersBase) {
	readTripsFile(tripsBase);
	readUsersFile(usersBase, tripsBase);
	generateSpecialLinkedTrip(tripsBase);

	std::cout << "Welcome to our travel agency. We are more than happy to see you here! " <<
		"Whether you want to travel with your family or friends, near or far, " <<
		"you will find something that meets your expectations.\n\n" <<
		"With each application launch, we generate one SPECIAL OFFER! " <<
		"It's a package of several tickets that costs 50% (!) less than all those tickets separately. " <<
		"Find it and take advantage of the promotion :)\n\nFirstly, you need to log in:\n" << std::endl;
}

int main()
{
	ReservationsBase* tripsBase = new ReservationsBase();
	UsersBase* usersBase = new UsersBase();
	initialOperations(tripsBase, usersBase);

	User* user = login(usersBase);
	std::cout << "\nWhat do you want to do?" << std::endl;
	int n;

	while (true) {
		std::cout << "\nChoose an option:\n" << std::endl;
		std::cout << "1) Book a trip.\n2) Cancel the trip.\n3) See all my reservations.\n4) Log out\n5) Exit.\n>> ";
		n = inputValidInteger();

		switch (n) {
		case 1:
			bookTrip(tripsBase, user);
			updateFile(usersBase);
			break;
		case 2:
			cancelTrip(user);
			updateFile(usersBase);
			break;
		case 3:
			seeMyReservations(user);
			break;
		case 4:
			user = login(usersBase);
			break;
		case 5:
			break;
		default:
			continue;
		}
		if (n == 5) break;
	}
	return 0;
}
