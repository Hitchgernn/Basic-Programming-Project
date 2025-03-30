#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin : public User {
public:
    Admin();
    void showMenu() override;
    void addBicycle();
    void removeBicycle();
    void showAllRentals();
};

#endif
