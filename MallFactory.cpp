#include "MallFactory.h"

MallFactory:: MallFactory()
{
    building = new Mall();
}

Building* MallFactory:: build()
{
    return building-> clone();

}
