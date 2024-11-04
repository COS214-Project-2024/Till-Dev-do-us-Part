// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest/doctest.h"
// #include "HealthDept.h"
// #include "Clinic.h"
// #include "Hospital1.h"
// #include "Hospital2.h"
// #include "Citizen.h"
// #include "Policy.h"
// #include "Memento.h"
// #include "Caretaker.h"
// #include "Government.h"
// #include "Department.h"

// // Testing Policy class
// TEST_CASE("Policy Class Tests") {
//     Policy policy("Healthcare Reform", "HR-001", "Improving healthcare services.");
//     CHECK(policy.getName() == "Healthcare Reform");
//     CHECK(policy.getDescription() == "Improving healthcare services.");

//     Policy emptyPolicy("", "", "");
//     CHECK(emptyPolicy.getName() == "");
//     CHECK(emptyPolicy.getDescription() == "");

//     CHECK_THROWS_AS(policy.getDescription().substr(1000, 5), std::out_of_range);
// }

// // Testing Memento class
// TEST_CASE("Memento Class Tests") {
//     Memento memento;
//     std::vector<Policy*> policies = {
//         new Policy("Policy 1", "P1", "Description 1"),
//         new Policy("Policy 2", "P2", "Description 2")
//     };

//     memento.setActivePolicies(policies);
//     auto activePolicies = memento.getActivePolicies();
//     CHECK(activePolicies.size() == 2);
//     CHECK(activePolicies[0]->getName() == "Policy 1");

//     memento.setActivePolicies({});
//     CHECK(memento.getActivePolicies().size() == 0);

//     //CHECK_THROWS_AS(memento.setActivePolicies({nullptr}), std::invalid_argument);

// //     for (auto p : policies) delete p;
// }

// // Testing Caretaker class
// TEST_CASE("Caretaker Class Tests") {
//     Caretaker caretaker;
//     Memento* memento = new Memento();

//     caretaker.saveMemento(memento);
//     CHECK(caretaker.getMemento() == memento);

//     caretaker.saveMemento(nullptr);
//     CHECK(caretaker.getMemento() == nullptr);

//     delete memento;
// }

// //Testing Government class
// TEST_CASE("Government Class Tests") {
//     Government* government = Government::getInstance();
//     CHECK(government != nullptr);

//     Department* dept = new HealthDept(50000);
//     government->addDepartment("Health", dept);
//     CHECK(government->getDepartment("Health") == dept);
//     government->removeDepartment("Health");
//     CHECK(government->getDepartment("Health") == nullptr);

//     CHECK_NOTHROW(government->removeDepartment("NonExistentDept"));

//     Policy* policy1 = new Policy("Healthcare Reform", "HR-001", "Improving healthcare services.");
//     government->enactPolicy(policy1);
//     CHECK(government->getPolicies().size() == 1);
//     government->revertPolicy("Healthcare Reform");
//     CHECK(government->getPolicies().size() == 0);

//     government->revertPolicy("NonExistentPolicy");
//     CHECK(government->getPolicies().size() == 0);

//     Memento* memento = government->createMemento();
//     CHECK(memento != nullptr);
//     CHECK(memento->getActivePolicies().size() == 0);

//     //CHECK_NOTHROW(government->setMemento(nullptr));

// //     delete memento;
//     delete dept;
//     delete policy1;
// }

// // Testing HealthDept class
// TEST_CASE("HealthDept Class Tests") {
//     HealthDept healthDept(1000);

//     Clinic* clinic = new Clinic();
//     healthDept.addFacility("Clinic", clinic);
//     CHECK(healthDept.getFacilities().size() == 1);

//     HealthDept lowBudgetDept(500000);
//     CHECK_NOTHROW(lowBudgetDept.addFacility("LowBudgetClinic", new Clinic()));
//     CHECK(lowBudgetDept.getFacilities().size() == 1);

//     healthDept.totalDeaths();

//     delete clinic;
// }

// // Testing HealthcareFacility class
// TEST_CASE("HealthcareFacility Class Tests") {
//     Clinic clinic;

//     Citizen* healthyCitizen = new Citizen("Healthy", 100);
//     clinic.dischargePatient(healthyCitizen);
//     CHECK(healthyCitizen->getHealth() == 100);

//     int value = clinic.generateRandomValue();
//     CHECK(value >= 1);
//     CHECK(value <= 3);

//     delete healthyCitizen;
// }

// // Testing Clinic class with admitPatient logic
// TEST_CASE("Clinic Class Tests") {
//     Clinic clinic;
//     Citizen* patient = new Citizen("Patient", 40);

//     clinic.admitPatient(patient);
//     CHECK((patient->getHealth() == 100 ||patient==nullptr));

//     Citizen* healthyCitizen = new Citizen("Healthy Citizen", 90);
//     clinic.admitPatient(healthyCitizen);
//     CHECK(healthyCitizen->getHealth() == 90);

//     delete patient;
//     delete healthyCitizen;
// }

// // Testing Hospital1 class
// TEST_CASE("Hospital1 Class Tests") {
//     Hospital1 hospital;
//     Citizen* patient = new Citizen("Hospital Patient", 25);

//     hospital.admitPatient(patient);
//     CHECK((patient==nullptr|| patient->getHealth() == 100 ));

//     Citizen* highHealthPatient = new Citizen("High Health", 40);
//     hospital.admitPatient(highHealthPatient);
//     CHECK(highHealthPatient->getHealth() == 40);

//     delete patient;
//     delete highHealthPatient;
// }

// // Testing Hospital2 class
// TEST_CASE("Hospital2 Class Tests") {
//     Hospital2 hospital;
//     Citizen* criticalPatient = new Citizen("Critical Patient", 10);

//     hospital.admitPatient(criticalPatient);
//     CHECK((criticalPatient==nullptr||criticalPatient->getHealth() == 100));

//     Citizen* lessCriticalPatient = new Citizen("Less Critical", 20);
//     hospital.admitPatient(lessCriticalPatient);
//     CHECK(lessCriticalPatient->getHealth() == 20);

//     delete criticalPatient;
//     delete lessCriticalPatient;
// }

// // Testing HealthcareFacility Chain of Responsibility
// TEST_CASE("HealthcareFacility Chain of Responsibility Tests") {
//     HealthcareFacility* clinic = new Clinic();
//     HealthcareFacility* hospital1 = new Hospital1();
//     HealthcareFacility* hospital2 = new Hospital2();

//     clinic->addSuccessor(hospital1);
//     hospital1->addSuccessor(hospital2);

//     Citizen* moderatePatient = new Citizen("Moderate Patient", 25);
//     clinic->admitPatient(moderatePatient);
//     CHECK((moderatePatient==nullptr|| moderatePatient->getHealth() == 100));

//     Citizen* criticalPatient = new Citizen("Critical Patient", 5);
//     clinic->admitPatient(criticalPatient);
//     CHECK((criticalPatient==nullptr||criticalPatient->getHealth() == 100 ));

//     Citizen* healthyCitizen = new Citizen("Healthy Citizen", 90);
//     clinic->admitPatient(healthyCitizen);
//     CHECK(healthyCitizen->getHealth() == 90);

//     delete clinic;
//     delete hospital1;
//     delete hospital2;
//     delete moderatePatient;
//     delete criticalPatient;
//     delete healthyCitizen;
// }
