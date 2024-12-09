#include <iostream>
#include "user.h"
#include "customer.h"
#include "bicycle.h"
#include "database.h"

void Customer::showMenu() {
    int choice;
    do {
        std::cout << "\n======== Customer Menu ========\n";
        std::cout << "1. Show Available Bicycles\n";
        std::cout << "2. Rent a Bicycle\n";
        std::cout << "3. Return a Bicycle\n";
        std::cout << "0. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                Bicycle::showAvailable();
                break;
            case 2:
                Database::rentBicycle(getUsername());
                break;
            case 3:
                Database::returnBicycle(getUsername());
                break;
            case 0:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}
