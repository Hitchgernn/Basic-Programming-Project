#ifndef OWNER_H
#define OWNER_H

#include "user.h"

class Owner : public User {
public:
    Owner();
    void showMenu() override;
    void showRentalReport();
};

#endif
