#pragma once
#include <string>
#include "GoodsClass.h"
#include "AdminClass.h"
#include "GuestClass.h"
#include "ExportImport.h"
#include "UserClass.h"
#include "ExportImport.h"

AdminClass registerAdmin(std::string username, std::string password, std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id);
GuestClass registerGuest(std::string username, std::string password, std::string name, std::string email, std::string lastname, std::string address, std::string phone_number, int age, int id);

void adminLogin(AdminClass& admin);
void guestLogin(std::string username, std::string password, GuestClass& guest);

void adminMenu(AdminClass& admin);
void guestMenu(GuestClass& guest);
