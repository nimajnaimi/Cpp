#include <iostream>

#include "alwaysongate.h"

AlwaysONgate::AlwaysONgate(string name) : Gate(name)
{
    output = true;
}

void AlwaysONgate::cycle() {

}

bool AlwaysONgate::isReadyToCycle() const {
    return true;
}
