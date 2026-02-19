#include "GoodsClass.h"

GoodsClass::GoodsClass()
{
	name = "";
	description = "";
	category = "";
	warranty_period = "";
	serial_number = "";
	weight = "";
	manufacturer = "";
	country_of_origin = "";
	price = 0.0;
	discount = 0.0;
	tax_rate = 0.0;
	rating = 0.0;
	stock_quantity = 0.0;
	supplier_contact = 0.0;
}

GoodsClass::GoodsClass(std::string name, std::string description, std::string category, std::string warranty_period, std::string serial_number, std::string weight, std::string manufacturer, std::string country_of_origin,
	double price, double discount, double tax_rate, double rating, double stock_quantity, double supplier_contact)
{
	this->name = name;
	this->description = description;
	this->category = category;
	this->warranty_period = warranty_period;
	this->serial_number = serial_number;
	this->weight = weight;
	this->manufacturer = manufacturer;
	this->country_of_origin = country_of_origin;
	this->price = price;
	this->discount = discount;
	this->tax_rate = tax_rate;
	this->rating = rating;
	this->stock_quantity = stock_quantity;
	this->supplier_contact = supplier_contact;
}

std::string GoodsClass::getName() const
{
	return name;
}
std::string GoodsClass::getDescription() const
{
	return description;
}
std::string GoodsClass::getCategory() const
{
	return category;
}
std::string GoodsClass::getWarrantyPeriod() const
{
	return warranty_period;
}
std::string GoodsClass::getSerialNumber() const
{
	return serial_number;
}
std::string GoodsClass::getWeight() const
{
	return weight;
}
std::string GoodsClass::getManufacturer() const
{
	return manufacturer;
}
std::string GoodsClass::getCountryOfOrigin() const
{
	return country_of_origin;
}
double GoodsClass::getPrice() const
{
	return price;
}
double GoodsClass::getDiscount() const
{
	return discount;
}
double GoodsClass::getTaxRate() const
{
	return tax_rate;
}
double GoodsClass::getRating() const
{
	return rating;
}
double GoodsClass::getStockQuantity() const
{
	return stock_quantity;
}
double GoodsClass::getSupplierContact() const
{
	return supplier_contact;
}
void GoodsClass::setName(std::string name)
{
	this->name = name;
}
void GoodsClass::setDescription(std::string description)
{
	this->description = description;
}
void GoodsClass::setCategory(std::string category)
{
	this->category = category;
}
void GoodsClass::setWarrantyPeriod(std::string warranty_period)
{
	this->warranty_period = warranty_period;
}
void GoodsClass::setSerialNumber(std::string serial_number)
{
	this->serial_number = serial_number;
}
void GoodsClass::setWeight(std::string weight)
{
	this->weight = weight;
}
void GoodsClass::setManufacturer(std::string manufacturer)
{
	this->manufacturer = manufacturer;
}
void GoodsClass::setCountryOfOrigin(std::string country_of_origin)
{
	this->country_of_origin = country_of_origin;
}
void GoodsClass::setPrice(double price)
{
	this->price = price;
}
void GoodsClass::setDiscount(double discount)
{
	this->discount = discount;
}
void GoodsClass::setTaxRate(double tax_rate)
{
	this->tax_rate = tax_rate;
}
void GoodsClass::setRating(double rating)
{
	this->rating = rating;
}
void GoodsClass::setStockQuantity(double stock_quantity)
{
	this->stock_quantity = stock_quantity;
}
void GoodsClass::setSupplierContact(double supplier_contact)
{
	this->supplier_contact = supplier_contact;
}