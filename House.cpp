#include "House.h"
#include "Adult.h"

/**
 * @brief Constructor for the House class.
 * Initializes the value, area, and capacity for the house.
 * @author Katlego
 */
House::House() : Residential("House")
{
    value = 1000;
    area = 500;
    capacity = 5;
}

/**
 * @brief Destructor for the House class.
 * Demolishes the house and outputs a message.
 */
House::~House()
{
    demolish();
    cout << "House demolished!" << endl;
}

/**
 * @brief Demolishes the house by clearing all occupants.
 * Outputs a message indicating the house has been cleared.
 */
void House::demolish()
{
    cout << "Removing everyone from the House" << endl;
    occupants.clear();
}

/**
 * @brief Attempts to use the shower in the house.
 * Checks if sufficient water and electricity are available,
 * adjusts cleanliness, and potentially changes the house's state.
 * @return true if the shower was used successfully, false otherwise.
 */
bool House::useShower()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(80) && useElectricity(40))
        {
            cout << "House used shower.\n";
            if (cleanliness - 10 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "House is now in Dilapidated state\n";
            }
            else
            {
                cleanliness -= 10;
            }
            return true;
        }
        cout << "Not enough water or electricity to use shower:" << endl;
        cout << "Required water to shower: 80" << endl;
        cout << "Required electricity to shower: 40" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl
             << endl;

        if (requestElectricity(40) && requestWater(80))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "House is in " << this->state->getName() << " and cannot use shower" << endl;
    return false;
}

/**
 * @brief Attempts to use the toilet in the house.
 * Checks if sufficient water and electricity are available,
 * adjusts cleanliness, and potentially changes the house's state.
 * @return true if the toilet was used successfully, false otherwise.
 */
bool House::useToilet()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(16) && useElectricity(5))
        {
            cout << "House used toilet.";
            if (cleanliness - 14 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "House is now in Dilapidated state:\n";
                cout << "Cleanliness: " << cleanliness << "\n";
                cout << "Electricity: " << electricityUnits << "\n";
                cout << "Water: " << waterUnits << "\n";
            }
            else
            {
                cleanliness -= 14;
            }
            return true;
        }
        cout << "Not enough water to use toilet:" << endl;
        cout << "Required electricity for toilet: 5" << endl;
        cout << "Required water for toilet: 16" << endl;
        cout << "Current water: " << waterUnits << endl;

        if (requestElectricity(5) && requestWater(16))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "House is in " << this->state->getName() << " and cannot use Toilet" << endl;
    return false;
}

/**
 * @brief Attempts to use the stove in the house.
 * Checks if sufficient electricity is available,
 * adjusts cleanliness, and potentially changes the house's state.
 * @return true if the stove was used successfully, false otherwise.
 */
bool House::useStove()
{
    if (this->state->canUseElectricity())
    {
        if (useElectricity(40))
        {
            cout << "House used stove.";
            if (cleanliness - 15 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "House is now in Dilapidated state:\n";
                cout << "Cleanliness: " << cleanliness << "\n";
                cout << "Electricity: " << electricityUnits << "\n";
                cout << "Water: " << waterUnits << "\n";
            }
            else
            {
                cleanliness -= 15;
            }
            return true;
        }
        cout << "Not enough electricity to use stove:" << endl;
        cout << "Required electricity for stove: 40" << endl;
        cout << "Current electricity: " << electricityUnits << endl;

        if (requestElectricity(40))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "House is in " << this->state->getName() << " and use stove" << endl;
    return false;
}

/**
 * @brief Attempts to clean the house.
 * Checks if sufficient water and electricity are available,
 * adjusts cleanliness, and potentially changes the house's state.
 * @return true if the house was cleaned successfully, false otherwise.
 */
bool House::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(200) && useElectricity(40))
        {
            cout << "House cleaned." << endl;
            if (cleanliness + 30 >= 100)
            {
                cleanliness = 100;
            }
            else
            {
                if (cleanliness <= 0 && cleanliness + 30 >= 0 && waterUnits > 0 && electricityUnits > 0)
                {
                    delete state;
                    state = new CompleteState();
                    cout << "House now in Operational state\n";
                }
                cleanliness += 30;
            }
            return true;
        }

        cout << "Not enough water or electricity to clean the House:" << endl;
        cout << "Required water to clean: 200" << endl;
        cout << "Required electricity to clean: 40" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        if (requestElectricity(40) && requestWater(200))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    cout << "House is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

/**
 * @brief Adds an occupant to the house if capacity is not exceeded.
 * @param c Pointer to the Citizen to be added.
 * @return true if occupant was added successfully, false otherwise.
 */
bool House::addOccupant(Citizen *c)
{
    if (c != nullptr)
    {
        if (occupants.size() < capacity)
        {
            occupants.push_back(c);
            // cout << "Occupant added to House" << endl;
            return true;
        }
        else{
            // cout << "Occupant could not be added to House, House at capacity" << endl;
            return false;
        }
    }

    cout << "Citizen does not exist" << endl;
    return false;
}

/**
 * @brief Removes an occupant from the house.
 * @param c Pointer to the Citizen to be removed.
 * @return true if occupant was removed successfully, false if not found.
 */
bool House::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator first = occupants.begin();
    vector<Citizen *>::iterator last = occupants.end();

    vector<Citizen *>::iterator it = find(first, last, c);
    if (it != last)
    {
        occupants.erase(it);
        cout << "Occupant removed from the House" << endl;
        return true;
    }

    cout << "Occupant not in the House" << endl;
    return false;
}

/**
 * @brief Clones the current house, returning a pointer to the new instance.
 * @return A pointer to a newly cloned House object.
 */
Building *House::clone()
{
    House *newHouse = new House();
    newHouse->cleanliness = this->cleanliness;
    newHouse->electricityUnits = this->electricityUnits;
    newHouse->waterUnits = this->waterUnits;
    newHouse->value = this->value;
    newHouse->area = this->area;
    newHouse->capacity = this->capacity;

    return newHouse;
}

/**
 * @brief Checks if the house is currently occupied.
 * @return true if there are occupants, false otherwise.
 */
bool House::isOccupied()
{
    return occupants.size() > 0;
}

/**
 * @brief Displays the current state of the house, including cleanliness,
 * water units, electricity units, value, area, and number of occupants.
 */
void House::display()
{

    std::cout << "-----------------House-------------------" << std::endl;
    std::cout << "   - Cleanliness                   : " << cleanliness << std::endl;
    std::cout << "   - Electricity Units             : " << electricityUnits << std::endl;
    std::cout << "   - Water Units                   : " << waterUnits << std::endl;
    std::cout << "   - Value Units                   : " << value << std::endl;
    std::cout << "   - Area                          : " << area << std::endl;
    std::cout << "   - Number of Occupants           : " << occupants.size() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}
