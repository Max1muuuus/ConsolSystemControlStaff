#pragma once
#include <string>
#include "GoodsClass.h"
#include <vector>
#include "UserClass.h"
#include "GuestClass.h"

extern std::vector<GoodsClass*> goods_list;
extern std::vector<GuestClass*> guest_list;

class AdminClass : public UserClass {
private:
	std::string username, password;
	GoodsClass* goods;
	GuestClass* guests;
public:
	AdminClass();
	AdminClass(std::string username, std::string password);
	AdminClass(std::string username, std::string password, std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id);

	void addGoods(GoodsClass* goods);
	void deleteGoods(std::string serial_number);
	void changePrice(std::string serial_number, double new_price);
	void viewGoods(GoodsClass& goods);

	void addGuest(GuestClass* guest);
	void deleteGuest(std::string username);
	void viewAllGuests();
	void viewGuest(GuestClass* guest);

	std::string getUsername() const;
	std::string getPassword() const;
	void setUsername(std::string username);
	void setPassword(std::string password);
};