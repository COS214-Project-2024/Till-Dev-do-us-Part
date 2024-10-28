#include "TaxiRankIterator.h"
#include "TrainStation.h"
#include <list>


// TaxiRankIterator implementation
class TaxiRankIterator : public TransportIterator {
private:
    int current;
    std::list<TransportStation*> taxiRanks;
public:
    TaxiRankIterator(const std::list<TransportStation*>& ranks) 
        : current(0), taxiRanks(ranks) {}
    
    TransportStation* next() override {
        if (hasNext()) {
            auto it = std::next(taxiRanks.begin(), current);
            current++;
            return *it;
        }
        return nullptr;
    }
    
    bool hasNext() override {
        return current < taxiRanks.size();
    }
    
    void first() {
        current = 0;
    }
};