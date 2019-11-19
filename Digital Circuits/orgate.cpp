// Name: Nima Naimi
// Date: March 11, 2018
// Assignment 8: Digital Circuits

/**
 * ORGate
 * The output is true if either input is true
 */

#include "orgate.h"
#include "gate.h"

#include <iostream>

// constructor
// create 2 inputs that can take the output from other gates
ORGate::ORGate(string name) : Gate(name)
{
    inputs.resize(2);
    inputs[0] = nullptr;
    inputs[1] = nullptr;
    output = false;
}

// set output to be true when either value is true
void ORGate::cycle() {
    output = inputs[0]->output || inputs[1]->output;
    cycled = true;
}
