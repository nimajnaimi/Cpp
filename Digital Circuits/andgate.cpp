/**
 * ANDGate
 * The output is true when both inputs are true
 */

#include "andgate.h"
#include "gate.h"

#include <iostream>

// constructor
// create 2 inputs that can take the output from other gates
ANDGate::ANDGate(string name) : Gate(name)
{
    inputs.resize(2);
    inputs[0] = nullptr;
    inputs[1] = nullptr;
    output = false;
}

// set output to be true when both values are true
void ANDGate::cycle() {
    output = inputs[0]->output && inputs[1]->output;
    cycled = true;
}
