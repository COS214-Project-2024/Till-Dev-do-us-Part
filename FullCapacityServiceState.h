#ifndef FullCapacitySERVICESTATE_H
#define FullCapacitySERVICESTATE_H

#include "ServiceState.h"
#include "ServiceUtility.h"

class FullCapacityServiceState : public ServiceState {
public:
    void handleService(ServiceUtility* utility) override;
    std::string getStateName() const override { return "FullCapacity"; }
};

#endif // FullCapacitySERVICESTATE_H
