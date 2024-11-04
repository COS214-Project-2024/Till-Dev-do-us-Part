#include <iostream>
#include <vector>
#include <string>

// Include necessary headers for transport modes and facilities
#include "TransportMode.h"
#include "BusMode.h"
#include "TrainMode.h"
#include "TaxiMode.h"
#include "CarMode.h"
#include "AirplaneMode.h"
#include "ModeFactory.h"
#include "BusModeFactory.h"
#include "BusStopFactory.h"
#include "RoadFactory.h"
#include "TrainModeFactory.h"
#include "TaxiModeFactory.h"
#include "TrainStationFactory.h"
#include "RailwayFactory.h"
#include "TaxiRankFactory.h"
#include "AirplaneModeFactory.h"
#include "AirportFactory.h"
#include "CarModeFactory.h"

#include "Department.h"
#include "TransportDept.h"

// Include observer and mediator headers
#include "CitizenObserver.h"
#include "ConcreteTransportationMediator.h"

// Include state pattern headers
#include "NormalState.h"
#include "CongestedState.h"
#include "EmptyState.h"

// Include iterator headers
#include "QueueIterator.h"
#include "StackIterator.h"

// Include facility headers
#include "Road.h"
#include "Railway.h"
#include "Airport.h"

int main() {
    // Factory Pattern - Create instances of each transport mode and facility
    std::cout << "=== Factory Pattern ===" << std::endl;
    // Making bus
    ModeFactory* mainmee = new BusModeFactory();
    StationFactory* stst= new BusStopFactory();
    FacilitiesFactory* facil= new RoadFactory();
    TransportDept* ment= new TransportDept(100000);

    //Making Train
    ModeFactory* stat= new TrainModeFactory();
    StationFactory* gau= new TrainStationFactory();
    FacilitiesFactory* rail= new RailwayFactory();

    // Making taxi
    ModeFactory* tax = new TaxiModeFactory();
    StationFactory* rank= new TaxiRankFactory();

    // Making airplane
    ModeFactory* plane= new AirplaneModeFactory();
    FacilitiesFactory* port= new AirportFactory();

    // Car
    ModeFactory* car = new CarModeFactory();
    
    // Mediator
    ConcreteTransportationMediator* medi= new ConcreteTransportationMediator();

    // Buses
    TransportMode* momo = mainmee->createMode();
    TransportMode* nene = mainmee->createMode();
    TransportMode* a = mainmee->createMode();
    TransportMode* b = mainmee->createMode();
    TransportMode* c = mainmee->createMode();
    TransportMode* d = mainmee->createMode();
    TransportMode* e = mainmee->createMode();
    TransportMode* f = mainmee->createMode();
    TransportMode* g = mainmee->createMode();
    TransportMode* h = mainmee->createMode();
    TransportMode* i = mainmee->createMode();

    // Trains
    TransportMode* t = stat->createMode();
    TransportMode* r = stat->createMode();

    // Taxis
    TransportMode* x = tax->createMode();
    TransportMode* m = tax->createMode();

    // Airplanes
    TransportMode* n = plane->createMode();
    TransportMode* q = plane->createMode();

    // Car
    TransportMode* w = car ->createMode();
    TransportMode* y = car ->createMode();



    // Bus Stop
    TransportStation* opop= stst->createStation();
    TransportStation* p= stst->createStation();

    // Train Station 
    TransportStation* rosebank= gau->createStation();
    TransportStation* hatfield= gau->createStation();


    // Taxi Rank
    TransportStation* springs= rank->createStation();
    TransportStation* brakpan= rank->createStation();

    // Facilities 
    // Roads
    TransportFacilities* roro= facil->createFacilities();
    TransportFacilities* adad= facil->createFacilities();

    // Railways
    TransportFacilities* ai= rail->createFacilities();
    TransportFacilities* ay= rail->createFacilities();

    // Airport
    TransportFacilities* rp= port->createFacilities();
    TransportFacilities* rt= port->createFacilities();
  
    // add to dept
    ment->addFacility(roro);
    ment->addFacility(adad);
    ment->addFacility(ai);
    ment->addFacility(ay);
    ment->addFacility(rp);
    ment->addFacility(rt);


    // set facil
    // Buses
    momo->SetFacilities(roro);
    nene->SetFacilities(roro);
    a->SetFacilities(roro);
    b->SetFacilities(roro);
    c->SetFacilities(roro);
    d->SetFacilities(roro);
    e->SetFacilities(roro);
    f->SetFacilities(roro);
    g->SetFacilities(roro);
    h->SetFacilities(roro);
    i->SetFacilities(roro);

    // Trains
    t->SetFacilities(ai);
    r->SetFacilities(ai);

    // Taxi
    x->SetFacilities(ai);
    m->SetFacilities(ai);

    // Planes
    n->SetFacilities(rp);
    q->SetFacilities(rt);

    // Cars
    w->SetFacilities(roro);
    y->SetFacilities(roro);

    // set dept
    // Buses
    momo->SetTransDept(ment);
    nene->SetTransDept(ment);
    a->SetTransDept(ment);
    b->SetTransDept(ment);
    c->SetTransDept(ment);
    d->SetTransDept(ment);
    e->SetTransDept(ment);
    f->SetTransDept(ment);
    g->SetTransDept(ment);
    h->SetTransDept(ment);
    i->SetTransDept(ment);

    // Trains
    t->SetTransDept(ment);
    r->SetTransDept(ment);

    // Taxis
    x->SetTransDept(ment);
    m->SetTransDept(ment);

    // Planes
    n->SetTransDept(ment);
    q->SetTransDept(ment);



    
    if (momo == nullptr) {
    std::cerr << "momo is nullptr!" << std::endl;
    } 
    else {
    std::cout << "Transport Mode Name: " << momo->getName() << std::endl;

    // Attempt to downcast to BusMode to call drive()
    if (TransportMode* bus = dynamic_cast<BusMode*>(momo)) {
        bus->SetMediator(medi);
        bus->SetFacilities(roro);
        bus->addStop(opop);
        bus->addStop(p);
        nene->SetMediator(medi);

        
        ((BusMode*)bus)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        std::cerr << "Error: momo is not a BusMode instance." << std::endl;
    }

    if (TransportMode* tray = dynamic_cast<TrainMode*>(t)) {
        tray->SetMediator(medi);
        tray->SetFacilities(ai);
        tray->addStop(rosebank);
        tray->addStop(hatfield);
        r->SetMediator(medi);

        
        ((TrainMode*)tray)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        std::cerr << "Error: momo is not a BusMode instance." << std::endl;
    }

     if (TransportMode* axi = dynamic_cast<TaxiMode*>(x)) {
        axi->SetMediator(medi);
        axi->SetFacilities(rp);
        axi->addStop(springs);
        axi->addStop(brakpan);
        m->SetMediator(medi);

        
        ((TrainMode*)axi)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        // std::cerr << "Error: taxi is not a BusMode instance." << std::endl;
    }

    if (TransportMode* play = dynamic_cast<AirplaneMode*>(n)) {
        play->SetMediator(medi);
        play->SetFacilities(rp);
        // play->addStop(springs);
        // play->addStop(brakpan);
        q->SetMediator(medi);

        
        ((TrainMode*)play)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        // std::cerr << "Error: plane is not a BusMode instance." << std::endl;
    }

    if (TransportMode* cr = dynamic_cast<CarMode*>(w)) {
        cr->SetMediator(medi);
        cr->SetFacilities(roro);
        // play->addStop(springs);
        // play->addStop(brakpan);
        y->SetMediator(medi);

        
        ((TrainMode*)cr)->drive(); // Call drive() if momo is indeed a BusMode
    } else {
        // std::cerr << "Error: car is not a BusMode instance." << std::endl;
    }
}

// Buses
delete momo;
delete nene;
delete a;
delete b;
delete c;
delete d;
delete e;
delete f;
delete g;
delete h;
delete i;

// Trains
delete t;
delete r;

// Taxi 
delete x;
delete m;

// Airplanes
delete n;
delete q;

// cars
delete w;
delete y;

// Stops
delete opop;
delete p;
delete rosebank;
delete hatfield;
delete springs;
delete brakpan;

//  Facilities already deleted 
// delete roro;
// delete adad;

// Rest
// Bus
delete medi;
delete ment;
delete facil;
delete stst;
delete mainmee;

// Train
delete rail;
delete gau;
delete stat;

// Taxi
delete rank;
delete tax;

// Airplane
delete port;
delete plane;

// Car
delete car;


    return 0;
}