// Additional Iterator implementations
class AirportIterator : public TransportIterator {
private:
    int current;
    std::vector<TransportStation*> airports;
public:
    AirportIterator(const std::vector<TransportStation*>& stations) 
        : current(0), airports(stations) {}
    
    TransportStation* next() override {
        if (hasNext()) {
            return airports[current++];
        }
        return nullptr;
    }
    
    bool hasNext() override {
        return current < airports.size();
    }
    
    void first() {
        current = 0;
    }
};