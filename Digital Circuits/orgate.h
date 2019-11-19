/**
 * ORGate
 * The output is true if either input is true
 */

#ifndef ORGATE_H
#define ORGATE_H

#include "gate.h"

class ORGate : public Gate {
public:
    // constructor
    explicit ORGate(string name);
    // convert input values to output
    void cycle() override;
};

#endif // ORGATE_H
