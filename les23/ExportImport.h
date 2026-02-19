#pragma once
#include <string>
#include "GoodsClass.h"
#include "AdminClass.h"
#include "GuestClass.h"

void SerializeGoods(const GoodsClass& goods, const std::string& filename);
GoodsClass DeserializeGoods(const std::string& filename);

void SerializeAdmin(const AdminClass& admin, const std::string& filename);
AdminClass DeserializeAdmin(const std::string& filename);

void SerializeGuest(const GuestClass& guest, const std::string& filename);
GuestClass DeserializeGuest(const std::string& filename);
