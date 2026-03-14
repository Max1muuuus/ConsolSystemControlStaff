#include "ExportImport.h"
#include <fstream>
#include <vector>

void SerializeGoodsList(const std::vector<GoodsClass>& goods_list) {
    std::ofstream ofs("goods.txt");
    ofs << goods_list.size() << "\n";
    for (const auto& g : goods_list) {
        ofs << g.getName() << "\n";
        ofs << g.getDescription() << "\n";
        ofs << g.getCategory() << "\n";
        ofs << g.getWarrantyPeriod() << "\n";
        ofs << g.getSerialNumber() << "\n";
        ofs << g.getWeight() << "\n";
        ofs << g.getManufacturer() << "\n";
        ofs << g.getCountryOfOrigin() << "\n";
        ofs << g.getPrice() << "\n";
        ofs << g.getDiscount() << "\n";
        ofs << g.getTaxRate() << "\n";
        ofs << g.getRating() << "\n";
        ofs << g.getStockQuantity() << "\n";
        ofs << g.getSupplierContact() << "\n";
    }
}

void DeserializeGoodsList(std::vector<GoodsClass>& goods_list) {
    std::ifstream ifs("goods.txt");
    size_t size;
    ifs >> size;
    ifs.ignore();
    goods_list.clear();
    for (size_t i = 0; i < size; i++) {
        std::string name, desc, cat, wp, sn, wt, man, coo;
        double price, discount, tax, rating, stock, supplier;
        std::getline(ifs, name);
        std::getline(ifs, desc);
        std::getline(ifs, cat);
        std::getline(ifs, wp);
        std::getline(ifs, sn);
        std::getline(ifs, wt);
        std::getline(ifs, man);
        std::getline(ifs, coo);
        ifs >> price >> discount >> tax >> rating >> stock >> supplier;
        ifs.ignore();
        goods_list.emplace_back(name, desc, cat, wp, sn, wt, man, coo, price, discount, tax, rating, stock, supplier);
    }
}

void SerializeAdmin(const AdminClass& admin) {
    std::ofstream ofs("admin.txt");
    ofs << admin.getUsername() << "\n";
    ofs << admin.getPassword() << "\n";
    ofs << admin.getName() << "\n";
    ofs << admin.getEmail() << "\n";
    ofs << admin.getLastname() << "\n";
    ofs << admin.getAddress() << "\n";
    ofs << admin.getPhoneNumber() << "\n";
    ofs << admin.getAge() << "\n";
    ofs << admin.getId() << "\n";
}

AdminClass DeserializeAdmin() {
    std::ifstream ifs("admin.txt");
    std::string u, p, name, email, lname, addr, phone;
    int age, id;
    std::getline(ifs, u);
    std::getline(ifs, p);
    std::getline(ifs, name);
    std::getline(ifs, email);
    std::getline(ifs, lname);
    std::getline(ifs, addr);
    std::getline(ifs, phone);
    ifs >> age >> id;
    return AdminClass(u, p, name, email, lname, addr, phone, age, id);
}

void SerializeGuestList(const std::vector<GuestClass>& guest_list) {
    std::ofstream ofs("guests.txt");
    ofs << guest_list.size() << "\n";
    for (const auto& g : guest_list) {
        ofs << g.getUsername() << "\n";
        ofs << g.getPassword() << "\n";
        ofs << g.getName() << "\n";
        ofs << g.getEmail() << "\n";
        ofs << g.getLastname() << "\n";
        ofs << g.getAddress() << "\n";
        ofs << g.getPhoneNumber() << "\n";
        ofs << g.getAge() << "\n";
        ofs << g.getId() << "\n";
    }
}

void DeserializeGuestList(std::vector<GuestClass>& guest_list) {
    std::ifstream ifs("guests.txt");
    size_t size;
    ifs >> size;
    ifs.ignore();
    guest_list.clear();
    for (size_t i = 0; i < size; i++) {
        std::string u, p, name, email, lname, addr, phone;
        int age, id;
        std::getline(ifs, u);
        std::getline(ifs, p);
        std::getline(ifs, name);
        std::getline(ifs, email);
        std::getline(ifs, lname);
        std::getline(ifs, addr);
        std::getline(ifs, phone);
        ifs >> age >> id;
        ifs.ignore();
        guest_list.emplace_back(u, p, name, email, lname, addr, phone, age, id);
    }
}
