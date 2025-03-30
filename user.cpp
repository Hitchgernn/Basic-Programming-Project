#include <iostream>
#include <string>
#include "user.h"

void User::setUsername(const std::string& uname) { 
    this->username = uname; 
}
void User::setFirstname(const std::string& fname) { 
    this->firstname = fname; 
}
void User::setLastname(const std::string& lname) { 
    this->lastname = lname; 
}
void User::setPhone(const std::string& p) { 
    this->phone = p;
}
std::string User::getUsername() const {
    return username;
}
std::string User::getFirstname() const { 
    return firstname; 
}
std::string User::getLastname() const { 
    return lastname; 
}
std::string User::getPhone() const { 
    return phone; 
}