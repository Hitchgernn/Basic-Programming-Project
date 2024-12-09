#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"

class Customer : public User {
public:

    Customer(const std::string& uname) {
        setUsername(uname);
    }

    void showMenu() override;

};

#endif
