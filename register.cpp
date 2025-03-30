#include "register.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Register::registerUser() {
    std::string firstname, lastname, phoneNumber, username, password;

    do {
        std::cout << "Enter First Name: ";
        std::cin >> firstname;
        std::cout << "Enter Last Name: ";
        std::cin >> lastname;
        std::cout << "Enter Phone Number: ";
        std::cin >> phoneNumber;
        std::cout << "Create Username: ";
        std::cin >> username;
        if (username == "admin") {
            std::cout << "you cannot use admin as your username\n";
            continue;
        } else if (username == "owner") {
            std::cout << "you cannot use owner as your username\n";
            continue;
        }
        std::cout << "Create Password: ";
        std::cin >> password;
    } while (username == "admin" || username == "owner");

    std::ifstream file("data/users.txt");
    std::string line;
    bool exists = false;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storedUsername;

        std::getline(iss, storedUsername, ',');
        if (storedUsername == username) {
            exists = true;
            break;
        }
    }

    file.close();

    if (exists) {
        std::cout << "Username already exists. Please try another.\n";
        return;
    }

    // Save new user to file
    std::ofstream outFile("data/users.txt", std::ios::app);
    outFile << username << "," << password << "," << firstname << "," << lastname << "," << phoneNumber << "\n";
    outFile.close();

    std::cout << "Registration successful!\n";
}

