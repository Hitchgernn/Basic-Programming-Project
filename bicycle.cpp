#include "bicycle.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Bicycle::Bicycle(const std::string& id, const std::string& model, bool available, double price)
    : id(id), model(model), isAvailable(available), price(price) {}

std::string Bicycle::getId() const {
    return id;
}

std::string Bicycle::getModel() const {
    return model;
}

double Bicycle::getPrice() const {
    return price;
}

bool Bicycle::getAvailability() const {
    return isAvailable;
}

void Bicycle::setAvailability(bool available) {
    this -> isAvailable = available;
}

void Bicycle::showAvailable() {
    std::ifstream file("data/bicycles.txt");
    std::string line;
    bool found = false;

    std::cout << "\n==== Available Bicycles ====\n";
    std::cout << "----------------------------\n";
    std::cout 
    << std::left << std::setw(10) << "ID"
    << std::setw(12) << "Model"
    << std::right << "Price";
    std::cout << "\n----------------------------";
    std::cout << std::endl; 
    while (std::getline(file, line)) {
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
            << std::left << std::setw(10) << id
            << std::setw(12) << model
            << std::right << price <<"\n";
        }
    }

    if (!found) {
        std::cout << "No bicycles available.\n";
    }
    file.close();
}

void Bicycle::addBicycle(const std::string& id, const std::string& model, double price) {
    std::ofstream file("data/bicycles.txt", std::ios::app);
    file << id << "," << model << ",1," << price << "\n";
    file.close();
    std::cout << "Bicycle added successfully.\n";
}

void Bicycle::removeBicycle(const std::string& id) {
    std::ifstream file("data/bicycles.txt");
    std::ofstream temp("data/temp.txt");
    std::string line;
    bool found = false;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string currentId;

        std::getline(iss, currentId, ',');
        if (currentId == id) {
            found = true;
            continue;
        }
        temp << line << "\n";
    }
}   
