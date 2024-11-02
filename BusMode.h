// BusMode.h

#pragma once
#include "TransportMode.h"
#include "Road.h"
#include "ModeFactory.h"
#include "CitizenObserver.h"
#include "QueueIterator.h"
#include "StackIterator.h"
#include <vector>
#include <string>
#include <list>
#include <memory>


class TransportFacilities;
class TransportationMediator;

class BusMode : public TransportMode {
public:
    BusMode();
    void drive();
    void stopdrive();
    std::string getName() const override;
    void SendMessage(const std::string& state);
    std::string GetMessage();



};