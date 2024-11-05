#include "Townhouse.h"
#include "Citizen.h"

/**
 * @brief Constructs a Townhouse with predefined attributes.
 * @author Katlego
 */
Townhouse::Townhouse() : Residential("Townhouse")
{
    value = 7000;
    area = 200;
    capacity = 3;
}

/**
 * @brief Destructor for the Townhouse class, calls demolish() and prints a message.
 */
Townhouse::~Townhouse()
{
    demolish();
    cout << "Townhouse demolished!" << endl;
}

/**
 * @brief Demolishes the townhouse by clearing all occupants.
 */
void Townhouse::demolish()
{
    cout << "Removing everyone from the Townhouse" << endl;
    occupants.clear();
}

/**
 * @brief Uses the shower if water and electricity are sufficient.
 * Reduces cleanliness and changes state if necessary.
 * @return true if the shower was used successfully, false otherwise.
 */
bool Townhouse::useShower()
{
    // Checks if water and electricity can be used
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(100) && useElectricity(50))
        {
            cout << "Townhouse used shower.";
            if (cleanliness - 15 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "Townhouse is now in Dilapidated state:\n";
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
        // Outputs insufficient water or electricity message
        cout << "Not enough water or electricity to use shower:" << endl;
        cout << "Required water to shower: 100" << endl;
        cout << "Required electricity to shower: 50" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return requestElectricity(50) && requestWater(100);
    }
    cout << "Townhouse is in " << this->state->getName() << " and cannot use shower" << endl;
    return false;
}

/**
 * @brief Uses the toilet if water and electricity are sufficient.
 * Reduces cleanliness and changes state if necessary.
 * @return true if the toilet was used successfully, false otherwise.
 */
bool Townhouse::useToilet()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(13) && useElectricity(3))
        {
            if (cleanliness - 10 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "Townhouse is now in Dilapidated state:\n";
                cout << "Cleanliness: " << cleanliness << "\n";
                cout << "Electricity: " << electricityUnits << "\n";
                cout << "Water: " << waterUnits << "\n";
            }
            else
            {
                cleanliness -= 10;
            }
            cout << "Townhouse used toilet.";
            return true;
        }
        cout << "Not enough water to use toilet:" << endl;
        cout << "Required electricity for toilet: 3" << endl;
        cout << "Required water for toilet: 13" << endl;
        cout << "Current water: " << waterUnits << endl;
        return requestElectricity(3) && requestWater(13);
    }
    cout << "Townhouse is in " << this->state->getName() << " and cannot use Toilet" << endl;
    return false;
}

/**
 * @brief Uses the stove if electricity is sufficient.
 * Reduces cleanliness and changes state if necessary.
 * @return true if the stove was used successfully, false otherwise.
 */
bool Townhouse::useStove()
{
    if (this->state->canUseElectricity())
    {
        if (useElectricity(58))
        {
            if (cleanliness - 15 <= 0)
            {
                cleanliness = 0;
                delete this->state;
                this->state = new DilapidatedState();
                cout << "Townhouse is now in Dilapidated state:\n";
                cout << "Cleanliness: " << cleanliness << "\n";
                cout << "Electricity: " << electricityUnits << "\n";
                cout << "Water: " << waterUnits << "\n";
            }
            else
            {
                cleanliness -= 15;
            }
            cout << "Used stove.";
            return true;
        }
        cout << "Not enough electricity to use stove:" << endl;
        cout << "Required electricity for stove: 58" << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return requestElectricity(58);
    }
    cout << "Townhouse is in " << this->state->getName() << " and cannot use stove" << endl;
    return false;
}

/**
 * @brief Cleans the townhouse if water and electricity are sufficient.
 * Increases cleanliness and changes state if necessary.
 * @return true if the townhouse was cleaned successfully, false otherwise.
 */
bool Townhouse::clean()
{
    if (this->state->canUseWater() && this->state->canUseElectricity())
    {
        if (useWater(300) && useElectricity(70))
        {
            if (cleanliness + 30 >= 100)
            {
                cleanliness = 100;
            }
            else
            {
                if (cleanliness <= 0 && cleanliness + 30 >= 0 && waterUnits > 0 && electricityUnits >0)
                {
                    delete state;
                    state = new CompleteState();
                    cout << "Townhouse is now in Operational state:\n";
                }
                cleanliness += 30;
            }
            cout << "Townhouse cleaned.";
            return true;
        }
        cout << "Not enough water or electricity to clean the Townhouse:" << endl;
        cout << "Required water to clean: 300" << endl;
        cout << "Required electricity to clean: 70" << endl;
        cout << "Current water: " << waterUnits << endl;
        cout << "Current electricity: " << electricityUnits << endl;
        return requestElectricity(50) && requestWater(100);
    }
    cout << "Townhouse is in " << this->state->getName() << " and cannot be cleaned" << endl;
    return false;
}

/**
 * @brief Adds a citizen to the townhouse as an occupant if there is capacity.
 * @param c Pointer to the Citizen to be added.
 * @return true if the occupant was added successfully, false if at capacity.
 */
bool Townhouse::addOccupant(Citizen *c)
{
    if (c != nullptr && occupants.size() < capacity)
    {
        occupants.push_back(c);
        cout << "Occupant added to Townhouse" << endl;
        return true;
    }
    return false;
}

/**
 * @brief Removes a specific occupant from the townhouse.
 * @param c Pointer to the Citizen to be removed.
 * @return true if the occupant was removed successfully, false otherwise.
 */
bool Townhouse::removeOccupant(Citizen *c)
{
    vector<Citizen *>::iterator it = find(occupants.begin(), occupants.end(), c);
    if (it != occupants.end())
    {
        occupants.erase(it);
        cout << "Occupant removed from the Townhouse" << endl;
        return true;
    }
    cout << "Occupant not in the Townhouse" << endl;
    return false;
}

/**
 * @brief Creates a clone of the current townhouse.
 * @return A pointer to a new cloned Townhouse object.
 */
Building *Townhouse::clone()
{
    Townhouse *newHouse = new Townhouse();
    newHouse->cleanliness = this->cleanliness;
    newHouse->electricityUnits = this->electricityUnits;
    newHouse->waterUnits = this->waterUnits;
    newHouse->value = this->value;
    newHouse->area = this->area;
    newHouse->capacity = this->capacity;

    return newHouse;
}

/**
 * @brief Checks if the townhouse is currently occupied.
 * @return true if there are occupants, false otherwise.
 */
bool Townhouse::isOccupied()
{
    return !occupants.empty();
}

/**
 * @brief Displays the current state of the townhouse, including cleanliness,
 * water units, electricity units, value, area, and number of occupants.
 */
void Townhouse::display()
{
    std::cout << "-----------------Townhouse-------------------" << std::endl;
    std::cout << "   - Cleanliness                   : " << cleanliness << std::endl;
    std::cout << "   - Electricity Units             : " << electricityUnits << std::endl;
    std::cout << "   - Water Units                   : " << waterUnits << std::endl;
    std::cout << "   - Value                         : " << value << std::endl;
    std::cout << "   - Area                          : " << area << std::endl;
    std::cout << "   - Number of Occupants           : " << occupants.size() << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}
