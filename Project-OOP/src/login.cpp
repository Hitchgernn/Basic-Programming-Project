#include "login.h"
#include "database.h"
#include "customer.h"
#include "admin.h"
#include "owner.h"
#include <string>

void Login::login() {
    std::string username, password;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;

    if (username == "admin" && password == "admin") {
        Admin admin;
        admin.showMenu();
    } else if (username == "owner" && password == "owner") {
        Owner owner;
        owner.showMenu();
    } else if (Database::verifyUser(username, password)) {
        Customer customer(username);
        customer.showMenu();
    } else {
        std::cout << "Account not registered or incorrect credentials.\n";
    }
}
