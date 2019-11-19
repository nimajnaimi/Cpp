/**
 * Circuit
 * Has a set of gates that are added using addGate
 * cycle goes through all the gates and cycles them in the correct order
 */

#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <iostream>
#include <map>

#include "gate.h"

class Circuit {
public:
    // constructor
    Circuit();
    // destructor - delete all gates added
    virtual ~Circuit();
    // add a gate to the circuit
    void addGate(Gate * gate);
    // connect the output from gateNameOut to the
    // numbered input of gateNameIn
    void connect(string gateNameOut, unsigned int n, string gateNameIn);
    // go through all gates and cycle them
    void cycle() const;
private:
    // keep track of gates added
    map<string, Gate*> gates;
};

#endif // CIRCUIT_H
