#pragma once
#include <string>

class UserClass {
protected:
	std::string name, email, lastname, address, phone_number;
	int age, id;
public:
	UserClass();
	UserClass(std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id);
	std::string getName() const;
	std::string getEmail() const;
	std::string getLastname() const;
	std::string getAddress() const;
	std::string getPhoneNumber() const;
	void setName(std::string name);
	void setEmail(std::string email);
	void setLastname(std::string lastname);
	void setAddress(std::string address);
	void setPhoneNumber(std::string phone_number);
	int getAge() const;
	int getId() const;
	void setAge(int age);
	void setId(int id);
};