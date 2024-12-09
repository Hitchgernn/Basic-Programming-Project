#include "admin.h"
#include "bicycle.h"
#include "database.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Admin::Admin() {
    username = "admin";
}

void Admin::showMenu() {
    int choice;
    do {
        std::cout << "\n========= Admin Menu =========\n";
        std::cout << "1. Add Bicycle\n";
        std::cout << "2. Remove Bicycle\n";
        std::cout << "3. Show All Rentals\n";
        std::cout << "0. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBicycle();
                break;
            case 2:
                removeBicycle();
                break;
            case 3:
                showAllRentals();
                break;
            case 0:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Admin::addBicycle() {
    std::string id, model;
    double price;
    std::cout << "Enter Bicycle ID: ";
    std::cin >> id;
    std::cout << "Enter Bicycle Model: ";
    std::cin >> model;
    std::cout << "Enter Bicycle Price: ";
    std::cin >> price;

    Bicycle::addBicycle(id, model, price);
}

void Admin::removeBicycle() {
    std::string id;
    std::cout << "Enter Bicycle ID to remove: ";
    std::cin >> id;

    Bicycle::removeBicycle(id);
}

void Admin::showAllRentals() {
    std::ifstream file("data/rentals.txt");
    std::string line;
    bool found = false;

    std::cout << "\n================= All Rentals =================\n";
    std::cout << "-----------------------------------------------\n";
    std::cout 
    << std::left << std::setw(12) << "Username"
    << std::setw(15) << "Bicycle ID"
    << std::setw(9) << "Time"
    << std::setw(8) << "Date";
    std::cout << "\n-----------------------------------------------";
    std::cout << std::endl; 
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, username, date, hour;
        std::getline(iss, username, ',');
        std::getline(iss, id, ',');
        std::getline(iss, hour, ',');
        std::getline(iss, date, ',');

        std::cout 
        << std::left << std::setw(12) << username
        << std::setw(15) << id
        << std::setw(9) << hour
        << std::setw(8) << date << "\n";
    }
    file.close();
}
