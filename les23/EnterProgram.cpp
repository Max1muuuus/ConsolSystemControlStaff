#include "EnterProgram.h"
#include <iostream>

AdminClass registerAdmin(std::string username, std::string password, std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id)
{
	AdminClass admin(username, password, name, email, lastname, address, phone_number, age, id);
	return admin;
}
GuestClass registerGuest(std::string username, std::string password, std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id)
{
	GuestClass guest(username, password, name, email, lastname, address, phone_number, age, id);
	return guest;
}

void adminLogin(AdminClass& admin) {
	if (admin.getUsername() == "admin" && admin.getPassword() == "admin") {
		std::cout << "Admin login successful!" << std::endl;
		adminMenu(admin);
	}
	else {
		std::cout << "Invalid admin credentials!" << std::endl;
	}
}

void guestLogin(std::string username, std::string password, GuestClass& guest) {
	if (guest.getUsername() == username && guest.getPassword() == password) {
		std::cout << "Guest login successful!" << std::endl;
		guestMenu(guest);
	}
	else {
		std::cout << "Invalid guest credentials!" << std::endl;
	}
}

void adminMenu(AdminClass& admin) {
	std::cout << "Welcome to the Admin Menu, " << admin.getName() << "!" << std::endl;
	int choice = -1;
	while (choice != 0) {
		std::cout << "1. Add Goods" << std::endl;
		std::cout << "2. Delete Goods" << std::endl;
		std::cout << "3. Change Price" << std::endl;
		std::cout << "4. View Goods" << std::endl;
		std::cout << "5. Add Guest" << std::endl;
		std::cout << "6. Delete Guest" << std::endl;
		std::cout << "7. View All Guests" << std::endl;
		std::cout << "8. View Guest" << std::endl;
		std::cout << "0. Logout" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		if (choice == 1) {
			std::string name, description, category, warranty_period, serial_number, weight, manufacturer, country_of_origin;
			double price, discount, tax_rate, rating, stock_quantity, supplier_contact;
			std::cout << "Enter goods name: ";
			std::cin >> name;
			std::cout << "Enter goods description: ";
			std::cin >> description;
			std::cout << "Enter goods category: ";
			std::cin >> category;
			std::cout << "Enter goods warranty period: ";
			std::cin >> warranty_period;
			std::cout << "Enter goods serial number: ";
			std::cin >> serial_number;
			std::cout << "Enter goods weight: ";
			std::cin >> weight;
			std::cout << "Enter goods manufacturer: ";
			std::cin >> manufacturer;
			std::cout << "Enter goods country of origin: ";
			std::cin >> country_of_origin;
			std::cout << "Enter goods price: ";
			std::cin >> price;
			std::cout << "Enter goods discount: ";
			std::cin >> discount;
			std::cout << "Enter goods tax rate: ";
			std::cin >> tax_rate;
			std::cout << "Enter goods rating: ";
			std::cin >> rating;
			std::cout << "Enter goods stock quantity: ";
			std::cin >> stock_quantity;
			std::cout << "Enter goods supplier contact: ";
			std::cin >> supplier_contact;
			GoodsClass goods(name, description, category, warranty_period, serial_number, weight, manufacturer, country_of_origin,
				price, discount, tax_rate, rating, stock_quantity, supplier_contact);
			admin.addGoods(goods);
		}
		else if (choice == 2) {
			std::string serial_number;
			std::cout << "Enter goods serial number to delete: ";
			std::cin >> serial_number;
			admin.deleteGoods(serial_number);
		}
		else if (choice == 3) {
			std::string serial_number;
			double new_price;
			std::cout << "Enter goods serial number to change price: ";
			std::cin >> serial_number;
			std::cout << "Enter new price: ";
			std::cin >> new_price;
			admin.changePrice(serial_number, new_price);
		}
		else if (choice == 4) {
			GoodsClass goods;
			admin.viewGoods(goods);
		}
		else if (choice == 5) {
			std::string username, password, name, email, lastname, address, phone_number;
			int age, id;
			std::cout << "Enter guest username: ";
			std::cin >> username;
			std::cout << "Enter guest password: ";
			std::cin >> password;
			std::cout << "Enter guest name: ";
			std::cin >> name;
			std::cout << "Enter guest email: ";
			std::cin >> email;
			std::cout << "Enter guest lastname: ";
			std::cin >> lastname;
			std::cout << "Enter guest address: ";
			std::cin >> address;
			std::cout << "Enter guest phone number: ";
			std::cin >> phone_number;
			std::cout << "Enter guest age: ";
			std::cin >> age;
			std::cout << "Enter guest id: ";
			std::cin >> id;
			GuestClass guest(username, password, name, email, lastname, address, phone_number, age, id);
			admin.addGuest(guest);
		}
		else if (choice == 6) {
			std::string username;
			std::cout << "Enter guest username to delete: ";
			std::cin >> username;
			admin.deleteGuest(username);
		}
		else if (choice == 7) {
			admin.viewAllGuests();
		}
		else if (choice == 8) {
			std::string username;
			std::cout << "Enter guest username to view: ";
			std::cin >> username;
			GuestClass guest(username, "", "", "", "", "", "", 0, 0);
			admin.viewGuest(guest);
		}
		else if (choice == 0) {
			std::cout << "Logging out..." << std::endl;
		}
		else {
			std::cout << "Invalid choice! Please try again." << std::endl;
		}
	}
}


void guestMenu(GuestClass& guest) {
	std::cout << "Welcome to the Guest Menu, " << guest.getName() << "!" << std::endl;
	int choice = -1;
	while (choice != 0) {
		std::cout << "1. View Goods" << std::endl;
		std::cout << "0. Logout" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		if (choice == 1) {
			GoodsClass goods;
			guest.viewGoods(goods);
		}
		else if (choice == 0) {
			std::cout << "Logging out..." << std::endl;
		}
		else {
			std::cout << "Invalid choice! Please try again." << std::endl;
		}
	}
}