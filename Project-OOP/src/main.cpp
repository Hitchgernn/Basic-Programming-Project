#include <iostream>
#include "register.h"
#include "login.h"

void showMainMenu() {
    std::cout << "\n========== Main Menu ==========\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        showMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                Register::registerUser();
                break;
            case 2:
                Login::login();
                break;
            case 0:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
