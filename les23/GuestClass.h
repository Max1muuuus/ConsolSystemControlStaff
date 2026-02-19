#pragma once
#include <string>
#include "GoodsClass.h"
#include "UserClass.h"

class GuestClass : public UserClass {
private:
	std::string username, password;
	GoodsClass* goods;
public:
	GuestClass();
	GuestClass(std::string username, std::string password, std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id);

	void viewGoods(GoodsClass& goods) const;

	std::string getUsername() const;
	std::string getPassword() const;
	void setUsername(std::string username);
	void setPassword(std::string password);
};
