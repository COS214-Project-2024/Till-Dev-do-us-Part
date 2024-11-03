#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <iostream>

class Citizen {
public:
    enum HealthStatus { Healthy, InTreatment, Critical, Deceased };

private:
    std::string name;
    HealthStatus status;
    int health;

public:
    // Constructor to initialize a citizen with a name and initial health status
    Citizen(std::string name, int initialHealth = 50) 
        : name(name), health(initialHealth), status(InTreatment) {}

    // Getter and Setter for health
    int getHealth(){
        return health;
    }

    void setHealth(int newHealth) {
        health = newHealth;
        // Update status based on health level
        if (health == 100) {
            status = Healthy;
        } else if (health <= 0) {
            status = Deceased;
        } else {
            status = InTreatment;
        }
    }

    // Getter for HealthStatus
    HealthStatus getStatus() const {
        return status;
    }

    // Method to update health decrementally to simulate deterioration
    void deteriorateHealth(int amount) {
        health -= amount;
        if (health <= 0) {
            status = Deceased;
            health = 0;
        }
    }

    // Getter for Citizen's name
    std::string getName() const {
        return name;
    }

    // Destructor
    ~Citizen()
    {
        
    }
};

#endif
