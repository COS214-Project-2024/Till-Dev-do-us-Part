class SewageSystem : public Utility
{
private:
    int capacity;

public:
    SewageSystem(int cap) : capacity(cap) {};
    ~SewageSystem();
};

SewageSystem::~SewageSystem()
{
}
