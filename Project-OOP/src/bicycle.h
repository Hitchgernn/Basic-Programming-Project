#ifndef BICYCLE_H
#define BICYCLE_H

#include <string>
#include <vector>

class Bicycle {
private:
    std::string id;
    std::string model;
    double price;
    bool isAvailable;

public:

    Bicycle(const std::string& id, const std::string& model, bool available, double price);

    std::string getId() const;

    std::string getModel() const;

    double getPrice() const;

    bool getAvailability() const;

    void setAvailability(bool available);

    static void showAvailable();

    static void addBicycle(const std::string& id, const std::string& model, double price);
    
    static void removeBicycle(const std::string& id);
};

#endif
