/**
 * Base Class Gate
 * Defines a virtual digital gate that can have any number of inputs and a single output
 * The function cycle needs to be overriden by appropiate derived class
 * All variables and functions declared public for convenience
 * Need to convert it to use getters/setters in the future
 */

#include <string>
#include <iostream>


#include "gate.h"

using namespace std;

// write name, inputs and outputs to out for easy inspection
ostream& operator<<(ostream& out, const Gate& gate) {
    out << "<" << gate.name << "> ";
    for (Gate * g: gate.inputs) {
        out << (g->output ? '1' : '0') << " ";
    }
    out << "==> " << (gate.output ? '1' : '0');
    return out;
}

// constructor with name
Gate::Gate(string name) : name {name}, inputs {} { }

// destructor
Gate::~Gate() { }

// true if all gates at the inputs are cycled
bool Gate::isReadyToCycle() const {
    for (auto i: inputs)
        if (i == nullptr || !i->isReadyToCycle())
            return false;
    return true;
}

// set the input with given number to given gate
void Gate::setInputBit(unsigned int n, Gate * g) {
    if (n >= inputs.size()) {
        cout << "Error setting input " << n << " for " << name << endl;
        return;
    }
    inputs[n] = g;
}


