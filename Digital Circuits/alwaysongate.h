/**
 * AlwaysONgate
 * The output is always true
 * isReadyToCycle always returns true
 * used as the external connection
 */

 #ifndef ALWAYSONGATE_H
#define ALWAYSONGATE_H

#include <string>

#include "gate.h"

using namespace std;

class AlwaysONgate : public Gate {
public:
    // constructor. output always true
    explicit AlwaysONgate(string name) : Gate(name) { output = true; }
    // empty cycle function overriding base class
    void cycle() override { };
};

#endif // ALWAYSONGATE_H
