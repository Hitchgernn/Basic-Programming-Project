#ifndef DATABASE_H
#define DATABASE_H

#include <string>

class Database {
public:
    static bool addUser(const std::string& firstname, const std::string& lastname, const std::string& phone,
                        const std::string& username, const std::string& password);

    static bool verifyUser(const std::string& username, const std::string& password);

    static void rentBicycle(const std::string& username);
    
    static void returnBicycle(const std::string& username);
};

#endif
