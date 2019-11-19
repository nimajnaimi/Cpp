#include "alwaysoffgate.h"

AlwaysOFFgate::AlwaysOFFgate(string name) : Gate(name)
{
    output = false;
}

AlwaysOFFgate::~AlwaysOFFgate()
{
    //dtor
}

void AlwaysOFFgate::cycle() {

}

bool AlwaysOFFgate::isReadyToCycle() const {
    return true;
}
