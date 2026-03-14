#include "AdminClass.h"
#include <iostream>
#include "sqlite3/sqlite3.h"

extern sqlite3* db;
std::vector<GoodsClass*> goods_list;
std::vector<GuestClass*> guest_list;

AdminClass::AdminClass() : UserClass() {
	username = "";
	password = "";
}
AdminClass::AdminClass(std::string username, std::string password) : UserClass() {
	this->username = username;
	this->password = password;
}
AdminClass::AdminClass(std::string username, std::string password, std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id)
	: UserClass(name, email, lastname, address, phone_number, age, id) {
	this->username = username;
	this->password = password;
}
void AdminClass::addGoods(GoodsClass* goods) {
	goods_list.push_back(goods);
	std::string sql = "INSERT INTO Goods(Name, SerialNumber, Price) VALUES('" +
		goods->getName() + "', '" +
		goods->getSerialNumber() + "', " +
		std::to_string(goods->getPrice()) + ");";
	sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}
void AdminClass::deleteGoods(std::string serial_number) {
	for (auto it = goods_list.begin(); it != goods_list.end(); it++) {
		if ((*it)->getSerialNumber() == serial_number) {
			goods_list.erase(it);
			break;
		}
	}
	std::string sql = "DELETE FROM Goods WHERE SerialNumber='" + serial_number + "';";
    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}
void AdminClass::changePrice(std::string serial_number, double new_price) {
	for (auto& goods : goods_list) {
		if (goods->getSerialNumber() == serial_number) {
			goods->setPrice(new_price);
			break;
		}
	}
	std::string sql = "UPDATE Goods SET Price=" + std::to_string(new_price) + " WHERE SerialNumber='" + serial_number + "';";
	sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}
void AdminClass::viewGoods(GoodsClass& goods) {
	std::cout << "Name: " << goods.getName() << std::endl;
	std::cout << "Description: " << goods.getDescription() << std::endl;
	std::cout << "Category: " << goods.getCategory() << std::endl;
	std::cout << "Warranty Period: " << goods.getWarrantyPeriod() << std::endl;
	std::cout << "Serial Number: " << goods.getSerialNumber() << std::endl;
	std::cout << "Weight: " << goods.getWeight() << std::endl;
	std::cout << "Manufacturer: " << goods.getManufacturer() << std::endl;
	std::cout << "Country of Origin: " << goods.getCountryOfOrigin() << std::endl;
	std::cout << "Price: $" << goods.getPrice() << std::endl;
	std::cout << "Discount: " << goods.getDiscount() * 100 << "%" << std::endl;
	std::cout << "Tax Rate: " << goods.getTaxRate() * 100 << "%" << std::endl;
	std::cout << "Rating: " << goods.getRating() << "/5" << std::endl;
	std::cout << "Stock Quantity: " << goods.getStockQuantity() << std::endl;
	std::cout << "Supplier Contact: $" << goods.getSupplierContact() << std::endl;
}
void AdminClass::addGuest(GuestClass* guest) {
	guest_list.push_back(guest);
	std::string sql = "INSERT INTO Guests(Username, Password, Name, Email, Lastname, Address, PhoneNumber, Age) VALUES('" +
		guest->getUsername() + "', '" +
		guest->getPassword() + "', '" +
		guest->getName() + "', '" +
		guest->getEmail() + "', '" +
		guest->getLastname() + "', '" +
		guest->getAddress() + "', '" +
		guest->getPhoneNumber() + "', " +
		std::to_string(guest->getAge()) + ");";
	sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}
void AdminClass::deleteGuest(std::string username) {
	for (auto it = guest_list.begin(); it != guest_list.end(); it++) {
		if ((*it)->getUsername() == username) {
			guest_list.erase(it);
			break;
		}
	}
	std::string sql = "DELETE FROM Guests WHERE Username='" + username + "';";
	sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}
void AdminClass::viewAllGuests() {
	for (const auto& guest : guest_list) {
		std::cout << "Username: " << guest->getUsername() << std::endl;
		std::cout << "Name: " << guest->getName() << std::endl;
		std::cout << "Email: " << guest->getEmail() << std::endl;
		std::cout << "Lastname: " << guest->getLastname() << std::endl;
		std::cout << "Address: " << guest->getAddress() << std::endl;
		std::cout << "Phone Number: " << guest->getPhoneNumber() << std::endl;
		std::cout << "Age: " << guest->getAge() << std::endl;
		std::cout << "ID: " << guest->getId() << std::endl;
		std::cout << "-----------------------------" << std::endl;
	}
}
void AdminClass::viewGuest(GuestClass* guest) {
	std::cout << "Username: " << guest->getUsername() << std::endl;
	std::cout << "Name: " << guest->getName() << std::endl;
	std::cout << "Email: " << guest->getEmail() << std::endl;
	std::cout << "Lastname: " << guest->getLastname() << std::endl;
	std::cout << "Address: " << guest->getAddress() << std::endl;
	std::cout << "Phone Number: " << guest->getPhoneNumber() << std::endl;
	std::cout << "Age: " << guest->getAge() << std::endl;
	std::cout << "ID: " << guest->getId() << std::endl;
}
std::string AdminClass::getUsername() const {
	return username;
}
std::string AdminClass::getPassword() const {
	return password;
}
void AdminClass::setUsername(std::string username) {
	this->username = username;
}
void AdminClass::setPassword(std::string password) {
	this->password = password;
}