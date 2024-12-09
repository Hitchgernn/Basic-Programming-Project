#include "database.h"
#include "bicycle.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

bool Database::addUser(const std::string& firstname, const std::string& lastname, const std::string& phone,
                       const std::string& username, const std::string& password) {
    std::ifstream file("data/users.txt");
    std::string line, existingUsername;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::getline(iss, existingUsername, ',');
        if (existingUsername == username) {
            return false;
        }
    }
    file.close();

    std::ofstream outFile("data/users.txt", std::ios::app);
    outFile << username << "," << password << "," << firstname << "," << lastname << "," << phone << "\n";
    outFile.close();
    return true;
}

bool Database::verifyUser(const std::string& username, const std::string& password) {
    std::ifstream file("data/users.txt");
    std::string line, storedUsername, storedPassword;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::getline(iss, storedUsername, ',');
        std::getline(iss, storedPassword, ',');
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    return false;
}

void Database::rentBicycle(const std::string& username) {
    std::ifstream bicycleFile("data/bicycles.txt");
    std::ofstream tempFile("data/temp.txt", std::ios::trunc);
    std::ofstream rentalFile("data/rentals.txt", std::ios::app);
    if (!bicycleFile.is_open()) {
        std::cout << "Failed to open bicycles file.\n";
        return;
    }

    std::string line, selectedId, selectedModel;
    int selectedTime;
    bool found = false;
    Bicycle* selectedBicycle = nullptr;

    std::cout << "\nAvailable Bicycles for Rent:\n";
    // while (std::getline(bicycleFile, line)) {
    //     std::istringstream iss(line);
    //     std::string id, model, available;
    //     double price;


    //     std::getline(iss, id, ',');
    //     std::getline(iss, model, ',');
    //     std::getline(iss, available, ',');
    //     iss >> price;

    //     if (available == "1") {
    //         std::cout << "ID: " << id << ", Model: " << model << ", Price: " << price <<"\n";
    //     }
    // }
    std::cout << "------------------------------\n";
    std::cout 
    << std::left << std::setw(12) << "ID"
    << std::setw(12) << "Model"
    << std::right << "Price";
    std::cout << "\n------------------------------";
    std::cout << std::endl; 
    while (std::getline(bicycleFile, line)) {
        std::istringstream iss(line);
        std::string id, model, available;
        double price;
        std::getline(iss, id, ',');
        std::getline(iss, model, ',');
        std::getline(iss, available, ',');
        iss >> price;

        if (available == "1") {
            found = true;
            std::cout
            << std::left << std::setw(12) << id
            << std::setw(12) << model
            << std::right << price <<"\n";
        }
    }

    

    bicycleFile.clear();
    bicycleFile.seekg(0);

    std::cout << "Enter the ID of the bicycle to rent: ";
    std::cin >> selectedId;
    do {
        std::cout << "Enter duration in hour (max 7 hour): ";
        std::cin >> selectedTime;
        if (selectedTime > 7) {
            std::cout << "Maximum rent is 7 hour \n";
        } else if (selectedTime < 1) {
            std::cout << "Minimum rent is 1 hour \n";
        }
    } while (selectedTime < 1 || selectedTime > 7);

    while (std::getline(bicycleFile, line)) {
        std::istringstream iss(line);
        std::string id, model, available;
        double price;

        std::getline(iss, id, ',');
        std::getline(iss, model, ',');
        std::getline(iss, available, ',');
        iss >> price;

        if (id == selectedId && available == "1") {
            found = true;
            selectedModel = model;
            selectedBicycle = new Bicycle(id, model, true, price);
            tempFile << id << "," << model <<",0," << price <<"\n";
        } else {
            tempFile << line << "\n";
        }
    }

    bicycleFile.close();
    tempFile.close();
    double price = selectedBicycle->getPrice();
    double totalCost = selectedTime*price;
    std::cout << "Total cost for rental: Rp." << totalCost << "\n";

    int paymentOption;
    std::cout << "Select Payment Method:\n";
    std::cout << "1. Cash\n";
    std::cout << "2. QRIS\n";
    std::cout << "Enter your choice: ";
    std::cin >> paymentOption;

    if (paymentOption == 1) {
        std::cout << "You selected Cash.\n";
    } else if (paymentOption == 2) {
        std::cout << "You selected QRIS.\n";
    } else {
        std::cout << "Invalid payment option. Transaction cancelled.\n";
        return;
    }

    std::cout << "Payment successful! Rental Successful!\n";

    std::remove("data/bicycles.txt");
    std::rename("data/temp.txt", "data/bicycles.txt");

    if (found) {
        rentalFile << username << "," << selectedId << "," << selectedTime << "," << __DATE__ << "\n";
        std::cout << "Bicycle rented successfully!\n";
    } else {
        std::cout << "Bicycle with ID " << selectedId << " is not available.\n";
    }

    rentalFile.close();
}

void Database::returnBicycle(const std::string& username) {
    std::ifstream rentalFile("data/rentals.txt");
    std::ofstream tempRentalFile("data/temp_rentals.txt", std::ios::trunc);
    std::ifstream bicycleFile("data/bicycles.txt");
    std::ofstream tempBicycleFile("data/temp_bicycles.txt", std::ios::trunc);

    if (!rentalFile.is_open() || !bicycleFile.is_open()) {
        std::cout << "Failed to open files.\n";
        return;
    }

    std::string line, selectedId;
    bool found = false;

    std::cout << "Your Rentals:\n";
    while (std::getline(rentalFile, line)) {
        std::istringstream iss(line);
        std::string renter, id, model, date;
        double price;

        std::getline(iss, renter, ',');
        std::getline(iss, id, ',');
        std::getline(iss, model, ',');
        std::getline(iss, date, ',');
        iss >> price;

        if (renter == username) {
            std::cout << "ID: " << id << ", Model: " << model << ", Date: " << __DATE__ << "\n";
        }
    }

    rentalFile.clear();
    rentalFile.seekg(0);

    std::cout << "Enter the ID of the bicycle to return: ";
    std::cin >> selectedId;

    while (std::getline(rentalFile, line)) {
        std::istringstream iss(line);
        std::string renter, id, model, date;
        double price;

        std::getline(iss, renter, ',');
        std::getline(iss, id, ',');
        std::getline(iss, model, ',');
        std::getline(iss, date, ',');
        iss >> price;

        if (renter == username && id == selectedId) {
            found = true;
        } else {
            tempRentalFile << line << "\n";
        }
    }

    while (std::getline(bicycleFile, line)) {
        std::istringstream iss(line);
        std::string id, model, available;
        double price;

        std::getline(iss, id, ',');
        std::getline(iss, model, ',');
        std::getline(iss, available, ',');
        iss >> price;

        if (id == selectedId) {
            tempBicycleFile << id << "," << model << ",1," << price << "\n";
        } else {
            tempBicycleFile << line << "\n";
        }
    }

    rentalFile.close();
    tempRentalFile.close();
    bicycleFile.close();
    tempBicycleFile.close();

    std::remove("data/rentals.txt");
    std::rename("data/temp_rentals.txt", "data/rentals.txt");

    std::remove("data/bicycles.txt");
    std::rename("data/temp_bicycles.txt", "data/bicycles.txt");

    if (found) {
        std::cout << "Bicycle returned successfully!\n";
    } else {
        std::cout << "No record found for the bicycle with ID " << selectedId << " rented by you.\n";
    }
}
