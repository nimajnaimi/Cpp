// Name: Nima Naimi
// Date: March 11, 2018
// Assignment 8: Digital Circuits

/**
 * NOTGate
 * The output is false when the input is true
 * The output is true when the input is false
 */

#include "notgate.h"
#include "gate.h"

#include <iostream>

// constructor
// create 1 input that can take the output from another gate
NOTGate::NOTGate(string name) : Gate(name)
{
    inputs.resize(1);
    inputs[0] = nullptr;
    output = false;
}

// set output to be true when the value is false
void NOTGate::cycle() {
    output = !inputs[0]->output;
    cycled = true;
}
