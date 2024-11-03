// #include <iostream>
// #include "Government.h"
// #include "HealthDept.h"
// #include "Clinic.h"
// #include "Hospital1.h"
// #include "Policy.h"
// #include "Memento.h"
// #include "Caretaker.h"
// #include "Citizen.h"
// #include "Hospital2.h"

// // Test Citizen stub class

// int main() {
//     // Create Singleton Government instance
//     Government* government = Government::getInstance();
//     government->addDepartment("Health", new HealthDept(50000.0f));  // Add Health Department with budget

//     // Access Health Department and add healthcare facilities
//     HealthDept* healthDept = dynamic_cast<HealthDept*>(government->getDepartment("Health"));
//     if (healthDept == nullptr) {
//         std::cerr << "Failed to retrieve HealthDept.\n";
//         return 1;
//     }

//     // Initialize healthcare facilities
//     Clinic* clinic1 = new Clinic();
//     Hospital1* hospital1 = new Hospital1();
//     Hospital2* hospital2 = new Hospital2();
//     healthDept->addFacility("Clinic", clinic1);
//     healthDept->addFacility("General Hospital", hospital1);
//     healthDept->addFacility("Intensive Care Hospital", hospital1);


//     // Set clinic1 successor to hospital1, simulating Chain of Responsibility
//     clinic1->addSuccessor(hospital1);
//     hospital1->addSuccessor(hospital2);

//     // Test admitting patients
//     Citizen* patient1 = new Citizen("John Doe");
//     Citizen* patient2 = new Citizen("Jane Smith");
//     Citizen* patient3 = new Citizen("Alice Brown");
//     patient1->setHealth(43);
//     patient2->setHealth(20);
//     patient3->setHealth(9);

//     std::cout << "\n--- Admitting Patient 1 to Clinic ---\n";
//     healthDept->admitPatient(patient1);  // Admit John Doe to the clinic

//     std::cout << "\n--- Admitting Patient 2 to Clinic ---\n";
//     healthDept->admitPatient(patient2);  // Admit Jane Smith to the clinic

//     std::cout << "\n--- Admitting Patient 3 to Clinic (Chain of Responsibility Test) ---\n";
//     healthDept->admitPatient(patient3);  // If Clinic is full, should transfer to Hospital1

//     // Simulate policy management in Government
//     Policy* healthcarePolicy = new Policy("Universal Healthcare", " UH01 ", " Provide accessible healthcare to all citizens. ");
//     Policy* crime = new Policy(" Crime Policy "," CP01"," Anyone who commits crime will be hanged in public. ");
//     std::cout << "\n--- Enacting Healthcare Policy ---\n";
//     government->enactPolicy(healthcarePolicy);
//     government->enactPolicy(crime);

//     std::cout << "\n--- Current Policies ---\n";
//     for (const auto& policy : government->getPolicies()) {
//         std::cout << "Policy: " << policy->getName() << " - " << policy->getDescription() << "\n";
//     }

//     // Save state of policies with Memento
//     Caretaker caretaker;
//     caretaker.saveMemento(government->createMemento());
//     std::cout << "\n--- Memento Saved ---\n";

//     // Revert a policy and check remaining policies
//     std::cout << "\n--- Reverting Universal Healthcare Policy ---\n";
//     government->revertPolicy("Universal Healthcare");

//     std::cout << "\n--- Policies after Reversion ---\n";
//     for (const auto& policy : government->getPolicies()) {
//         std::cout << "Policy: " << policy->getName() << " - " << policy->getDescription() << "\n";
//     }

//     // Restore previous policies using Memento
//     std::cout << "\n--- Restoring Policies from Memento ---\n";
//     government->setMemento(caretaker.getMemento());
    

//     std::cout << "\n--- Policies after Restoration ---\n";

//     for (auto& policy : government->getPolicies()) {
//         std::cout << "Policy: " << policy->getName() << " - " << policy->getDescription() << "\n";
//     }

//     // Check death toll tracking
//     std::cout << "\n--- Total Death Toll in Health Dept ---\n";
//     healthDept->totalDeaths();

//     // Cleanup
//     delete patient1;
//     delete patient2;
//     delete patient3;
//     delete healthcarePolicy;
//     delete clinic1;
//     delete hospital1;

//     std::cout << "\n--- End of Tests ---\n";
//     return 0;
// }
