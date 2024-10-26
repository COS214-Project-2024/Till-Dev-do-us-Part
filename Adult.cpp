#include "Adult.h"

//// i would like to remove this fuction so that all resource-related responsibilities for work are now managed by
//// in order to handle consumption based on a building level.
//// cause lets say a household hold runs out resources which adult must request for more ?
//// and for an adult to request for more they must also have a pointer to the resource department 
void Adult::goToWork() {
    const int electricityConsumption = 5; // Example: 5 units of electricity per adult

    // Request resources from the resource department
    if (resourceDepartment->requestElectricity(electricityConsumption)) {
        std::cout << "Adult is working. Consumed " << electricityConsumption << " units of electricity." << std::endl;
    } else {
        std::cout << "Not enough electricity available for work!" << std::endl;
    }

    
}
