#pragma once

class UsersBase : public Base <User> {
public:
	int login(std::string username, std::string password);
	int createAccount(std::string username, std::string password);
};