/**
 * AlwaysONgate
 * The output is always flase
 * isReadyToCycle always returns true
 * used as the external connection
 */

#ifndef ALWAYSOFFGATE_H
#define ALWAYSOFFGATE_H

#include <string>
#include "gate.h"

using namespace std;

class AlwaysOFFgate : public Gate {
public:
    // constructor. output always false
    explicit AlwaysOFFgate(string name) : Gate(name) { output = false; }
    // empty cycle function overriding base class
    void cycle() override { }
};

#endif // ALWAYSOFFGATE_H
