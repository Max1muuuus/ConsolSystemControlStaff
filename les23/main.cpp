#include <iostream>
#include "sqlite3/sqlite3.h"
#include "EnterProgram.h"

sqlite3* db = nullptr;
void initializeDatabase() {
    int exit = sqlite3_open("shop.db", &db);
    if (exit) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    const char* sqlGoods = R"(
        CREATE TABLE IF NOT EXISTS Goods(
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            Name TEXT,
            Description TEXT,
            Category TEXT,
            WarrantyPeriod TEXT,
            SerialNumber TEXT,
            Weight TEXT,
            Manufacturer TEXT,
            CountryOfOrigin TEXT,
            Price REAL,
            Discount REAL,
            TaxRate REAL,
            Rating REAL,
            StockQuantity REAL,
            SupplierContact REAL
        );
    )";

    const char* sqlGuests = R"(
        CREATE TABLE IF NOT EXISTS Guests(
            ID INTEGER PRIMARY KEY AUTOINCREMENT,
            Username TEXT,
            Password TEXT,
            Name TEXT,
            Email TEXT,
            Lastname TEXT,
            Address TEXT,
            PhoneNumber TEXT,
            Age INTEGER
        );
    )";

    char* messageError;
    exit = sqlite3_exec(db, sqlGoods, nullptr, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error creating Goods table: " << messageError << std::endl;
        sqlite3_free(messageError);
    }

    exit = sqlite3_exec(db, sqlGuests, nullptr, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error creating Guests table: " << messageError << std::endl;
        sqlite3_free(messageError);
    }

    std::cout << "Database initialized successfully!" << std::endl;
}

void mainMenu() {
    int choice;
    while (true) {
        std::cout << "\n==== MAIN MENU ====\n";
        std::cout << "1. Register Admin\n2. Login Admin\n";
        std::cout << "3. Register Guest\n4. Login Guest\n0. Exit\nChoice: ";
        std::cin >> choice;
        if (choice == 1) {
            std::string username, password, name, email, lastname, address, phone_number;
            int age, id;
            std::cout << "Enter username: " << std::endl;
            std::cin >> username;
            std::cout << "Enter password: " << std::endl;
            std::cin >> password;
            std::cout << "Enter name: " << std::endl;
            std::cin >> name;
            std::cout << "Enter email: " << std::endl;
            std::cin >> email;
            std::cout << "Enter lastname: " << std::endl;
            std::cin >> lastname;
            std::cout << "Enter address: " << std::endl;
            std::cin >> address;
            std::cout << "Enter phone_number: " << std::endl;
            std::cin >> phone_number;
            std::cout << "Enter age: " << std::endl;
            std::cin >> age;
            std::cout << "Enter id: " << std::endl;
            std::cin >> id;
            registerAdmin(username, password, name, email, lastname, address, phone_number, age, id);
        }
        else if (choice == 2) {
            std::string username, password;
            std::cout << "Enter username: " << std::endl;
            std::cin >> username;
            std::cout << "Enter password: " << std::endl;
            std::cin >> password;
            AdminClass admin(username, password);
            adminLogin(admin);
        }
        else if (choice == 3) {
            std::string username, password, name, email, lastname, address, phone_number;
            int age, id;
            std::cout << "Enter username: " << std::endl;
            std::cin >> username;
            std::cout << "Enter password: " << std::endl;
            std::cin >> password;
            std::cout << "Enter name: " << std::endl;
            std::cin >> name;
            std::cout << "Enter email: " << std::endl;
            std::cin >> email;
            std::cout << "Enter lastname: " << std::endl;
            std::cin >> lastname;
            std::cout << "Enter address: " << std::endl;
            std::cin >> address;
            std::cout << "Enter phone_number: " << std::endl;
            std::cin >> phone_number;
            std::cout << "Enter age: " << std::endl;
            std::cin >> age;
            std::cout << "Enter id: " << std::endl;
            std::cin >> id;
            registerGuest(username, password, name, email, lastname, address, phone_number, age, id);
        }
        else if (choice == 4) {
            std::string username, password;
            std::cout << "Enter username: " << std::endl;
            std::cin >> username;
            std::cout << "Enter password: " << std::endl;
            std::cin >> password;
            GuestClass guest(username, password);
            guestLogin(username, password, guest);
        }
        else if (choice == 0) break;
        else std::cout << "Invalid choice!\n";
    }
}

int main()
{
    initializeDatabase();
    mainMenu();
    sqlite3_close(db);
}

