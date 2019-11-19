/**
 * ANDGate
 * The output is true when both inputs are true
 */

#ifndef ANDGATE_H
#define ANDGATE_H

#include "gate.h"

class ANDGate : public Gate {
public:
    // constructor
    explicit ANDGate(string name);
    // convert input values to output
    void cycle() override;
};

#endif // ANDGATE_H
