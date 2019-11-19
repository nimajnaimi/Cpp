/**
 * NOTGate
 * The output is false when the input is true
 * The output is true when the input is false
 */

#ifndef NOTGATE_H
#define NOTGATE_H

#include "gate.h"

class NOTGate : public Gate {
public:
    // constructor
    explicit NOTGate(string name);
    // convert input values to output
    void cycle() override;
};

#endif // NOTGATE_H
