#include "GuestClass.h"
#include <iostream>
#include "AdminClass.h"

GuestClass::GuestClass() : UserClass() {
	this->age = 0;
	this->id = 0;
}
GuestClass::GuestClass(std::string username, std::string password) : UserClass() {
	this->username = username;
	this->password = password;
}
GuestClass::GuestClass(std::string username, std::string password, std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id) : UserClass(name, email, lastname, address, phone_number, age, id) {
	this->username = username;
	this->password = password;
}

void GuestClass::viewGoods (GoodsClass* goods) const {
	for (auto g : goods_list) {
		std::cout << "Name: " << g->getName() << std::endl;
		std::cout << "Description: " << g->getDescription() << std::endl;
		std::cout << "Category: " << g->getCategory() << std::endl;
		std::cout << "Warranty Period: " << g->getWarrantyPeriod() << std::endl;
		std::cout << "Serial Number: " << g->getSerialNumber() << std::endl;
		std::cout << "Weight: " << g->getWeight() << std::endl;
		std::cout << "Manufacturer: " << g->getManufacturer() << std::endl;
		std::cout << "Country of Origin: " << g->getCountryOfOrigin() << std::endl;
		std::cout << "Price: $" << g->getPrice() << std::endl;
		std::cout << "Discount: " << g->getDiscount() * 100 << "%" << std::endl;
		std::cout << "Tax Rate: " << g->getTaxRate() * 100 << "%" << std::endl;
		std::cout << "Rating: " << g->getRating() << "/5" << std::endl;
		std::cout << "Stock Quantity: " << g->getStockQuantity() << std::endl;
		std::cout << "Supplier Contact: $" << g->getSupplierContact() << std::endl;
		std::cout << "-----------------------------" << std::endl;
	}
}

std::string GuestClass::getUsername() const {
	return this->username;
}
std::string GuestClass::getPassword() const {
	return this->password;
}
void GuestClass::setUsername(std::string username) {
	this->username = username;
}
void GuestClass::setPassword(std::string password) {
	this->password = password;
}