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

class BusMode : public TransportMode {
public:
    BusMode();
    void drive();
    void stopdrive();
        void SetTransDept(TransportDept* transDept);
    std::string getName() const override;
    void SendMessage(std::string state);
    std::string GetMessage();



};