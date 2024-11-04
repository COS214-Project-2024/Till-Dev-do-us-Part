/**
 *@file Office.h
 *@brief Declaration of the Office class, a type of Commercial building. 
*/
#ifndef OFFICE_H
#define OFFICE_H

#include "Commercial.h"

/**
 * @class Office
 * @brief Represents an Office building derived from the Commercial class.
 */
class Office : public Commercial
{
    private:
        Citizen *occupant; /**< Pointer to the occupant of the Office */

    public:
        /**
         * @brief Constructs an Office object with default values.
         */
        Office();

        /**
         * @brief Destroys the Office object and removes any occupant.
         */
        ~Office();

        /**
         * @brief Demolishes the Office, removing the occupant.
         */
        virtual void demolish();

        /**
         * @brief Cleans the Office if resources are available.
         * @return true if cleaning was successful, false otherwise.
         */
        virtual bool clean();

        /**
         * @brief Adds an occupant to the Office if unoccupied.
         * @param c Pointer to the Citizen to be added as an occupant.
         * @return true if the occupant was successfully added, false if the Office already has an occupant.
         */
        virtual bool addOccupant(Citizen *c);

        /**
         * @brief Removes the specified occupant from the Office if present.
         * @param c Pointer to the Citizen to be removed.
         * @return true if the occupant was successfully removed, false otherwise.
         */
        virtual bool removeOccupant(Citizen *c);

        /**
         * @brief Creates a clone of the Office object.
         * @return A pointer to a new Building object that is a clone of the Office.
         */
        virtual Building *clone();

        /**
         * @brief Checks if the Office currently has an occupant.
         * @return true if the Office has an occupant, false otherwise.
         */
        virtual bool isOccupied();
};

#endif
