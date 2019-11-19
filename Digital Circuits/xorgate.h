/**
 * XORGATE_H
 * The output is true if one input is true
 * The output is false if both inputs are true
 * The output is false if both inputs are false
 */

#ifndef XORGATE_H
#define XORGATE_H

#include "gate.h"

class XORGate : public Gate {
public:
    // constructor
    explicit XORGate(string name);
    // convert input values to output
    void cycle() override;
};

#endif // XORGATE_H
