#include "UserClass.h"

UserClass::UserClass() {
	this->name = "";
	this->email = "";
	this->lastname = "";
	this->address = "";
	this->phone_number = "";
	this->age = 0;
	this->id = 0;
}
UserClass::UserClass(std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id) {
	this->name = name;
	this->email = email;
	this->lastname = lastname;
	this->address = address;
	this->phone_number = phone_number;
	this->age = age;
	this->id = id;
}
std::string UserClass::getName() const {
	return this->name;
}
std::string UserClass::getEmail() const {
	return this->email;
}
std::string UserClass::getLastname() const {
	return this->lastname;
}
std::string UserClass::getAddress() const {
	return this->address;
}
std::string UserClass::getPhoneNumber() const {
	return this->phone_number;
}
void UserClass::setName(std::string name) {
	this->name = name;
}
void UserClass::setEmail(std::string email) {
	this->email = email;
}
void UserClass::setLastname(std::string lastname) {
	this->lastname = lastname;
}
void UserClass::setAddress(std::string address) {
	this->address = address;
}
void UserClass::setPhoneNumber(std::string phone_number) {
	this->phone_number = phone_number;
}
int UserClass::getAge() const {
	return this->age;
}
int UserClass::getId() const {
	return this->id;
}
void UserClass::setAge(int age) {
	this->age = age;
}
void UserClass::setId(int id) {
	this->id = id;
}
