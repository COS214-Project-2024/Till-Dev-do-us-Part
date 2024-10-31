#ifndef SERVICESTATE_H
#define SERVICESTATE_H



class ServiceUtility;

class ServiceState 
{
public:
    virtual ~ServiceState() = default;

    // Service-specific behavior for this state
    virtual void handleService(ServiceUtility *utility) = 0;
    virtual std::string getStateName() const = 0;

};

#endif