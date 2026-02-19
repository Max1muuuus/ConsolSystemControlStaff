#pragma once
#include <string>

class GoodsClass {
private:
	std::string name, description, category, warranty_period, serial_number, weight, manufacturer, country_of_origin;
	double price, discount, tax_rate, rating, stock_quantity, supplier_contact;
public:
	GoodsClass();
	GoodsClass(std::string name, std::string description, std::string category, std::string warranty_period, std::string serial_number, std::string weight, std::string manufacturer, std::string country_of_origin,
		double price, double discount, double tax_rate, double rating, double stock_quantity, double supplier_contact);
	std::string getName() const;
	std::string getDescription() const;
	std::string getCategory() const;
	std::string getWarrantyPeriod() const;
	std::string getSerialNumber() const;
	std::string getWeight() const;
	std::string getManufacturer() const;
	std::string getCountryOfOrigin() const;
	double getPrice() const;
	double getDiscount() const;
	double getTaxRate() const;
	double getRating() const;
	double getStockQuantity() const;
	double getSupplierContact() const;
	void setName(std::string name);
	void setDescription(std::string description);
	void setCategory(std::string category);
	void setWarrantyPeriod(std::string warranty_period);
	void setSerialNumber(std::string serial_number);
	void setWeight(std::string weight);
	void setManufacturer(std::string manufacturer);
	void setCountryOfOrigin(std::string country_of_origin);
	void setPrice(double price);
	void setDiscount(double discount);
	void setTaxRate(double tax_rate);
	void setRating(double rating);
	void setStockQuantity(double stock_quantity);
	void setSupplierContact(double supplier_contact);
};