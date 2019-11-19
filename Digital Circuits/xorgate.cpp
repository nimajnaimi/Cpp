// Name: Nima Naimi
// Date: March 11, 2018
// Assignment 8: Digital Circuits

/**
 * XORGATE_H
 * The output is true if one input is true
 * The output is false if both inputs are true
 * The output is false if both inputs are false
 */

#include "xorgate.h"
#include "gate.h"

#include <iostream>

// constructor
// create 2 inputs that can take the output from other gates
XORGate::XORGate(string name) : Gate(name)
{
    inputs.resize(2);
    inputs[0] = nullptr;
    inputs[1] = nullptr;
    output = false;
}

// set output to be true when either value is true
void XORGate::cycle() {
    output = (inputs[0]->output && !inputs[1]->output) || (!inputs[0]->output && inputs[1]->output);
    cycled = true;
}
