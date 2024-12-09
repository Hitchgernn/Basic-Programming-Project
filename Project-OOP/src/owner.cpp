#include "owner.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Owner::Owner() {
    username = "owner";
}

void Owner::showMenu() {
    int choice;
    do {
        std::cout << "\n========= Owner Menu =========\n";
        std::cout << "1. Show Rental Report\n";
        std::cout << "0. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showRentalReport();
                break;
            case 0:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Owner::showRentalReport() {
    std::ifstream file("data/rentals.txt");
    std::string line;
    int totalRentals = 0;

    // if (!file.is_open()) {
    //     std::cout << "No rental data found.\n";
    //     return;
    // }
    std::cout << "\n================ Rental Report ================\n";
    std::cout << "-----------------------------------------------\n";
    std::cout 
    << std::left << std::setw(12) << "Username"
    << std::setw(15) << "Bicycle ID"
    << std::setw(9) << "Time"
    << std::setw(8) << "Date";
    std::cout << "\n-----------------------------------------------";
    std::cout << std::endl; 
    while (std::getline(file, line)) {
        totalRentals++;
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

    std::cout << "Total Rentals: " << totalRentals << "\n";
    file.close();
}
