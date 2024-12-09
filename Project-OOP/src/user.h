#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string firstname;
    std::string lastname;
    std::string phone;
public:
    User() = default;

    virtual ~User() {}

    void setUsername(const std::string& uname);

    void setFirstname(const std::string& fname);

    void setLastname(const std::string& lname);
    
    void setPhone(const std::string& p);
    
    std::string getUsername() const;
    
    std::string getFirstname() const;

    std::string getLastname() const;

    std::string getPhone() const;


    virtual void showMenu() = 0;
};

#endif
