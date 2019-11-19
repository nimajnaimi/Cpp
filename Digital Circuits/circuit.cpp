/**
 * Circuit
 * Has a set of gates that are added using addGate
 * cycle goes through all the gates and cycles them in the correct order
 */

#include <iostream>
#include <map>
#include <queue>
#include "circuit.h"

using namespace std;

// constructor
Circuit::Circuit() { }

// destructor - delete all gates added
Circuit::~Circuit() {
    for (auto item: gates)
        delete item.second;
}

// add a gate to the circuit
void Circuit::addGate(Gate * gate) {
    if (gates[gate->name] != nullptr) {
        cout << "Gate with name " << gate->name << " already in this circuit" << endl;
        return;
    }
    gates[gate->name] = gate;
}

// connect the output from gateNameOut to the
// numbered input of gateNameIn
void Circuit::connect(string gateNameOut, unsigned int n, string gateNameIn) {
    Gate * gate = gates[gateNameIn];
    if (!gate) {
        cout << "Could not find gate: " << gateNameIn << endl;
        return;
    }
    if (n >= gate->inputs.size()) {
        cout << gateNameIn << " does not have input " << n << endl;
        return;
    }
    Gate * out = gates[gateNameOut];
    if (!out) {
        cout << "Could not find gate: " << gateNameOut << endl;
        return;
    }
    gate->setInputBit(n, out);
}

// go through all gates and cycle them
// a gate can only be cycled if the gates at the inputs have been cycled
void Circuit::cycle() const {
    queue<Gate*> gateQueue;
    Gate * gate;
    cout << "Gates in circuit are: ";
    for (auto item: gates) {
        gate = item.second;
        cout << gate->name << " ";
        // add gate to queue
        gateQueue.push(gate);
        // set cycled to false, we have not cycled it yet
        // AlwaysONGate/AlwaysOFFGate override isReadyToCycle
        // and will ignore thsi variable
        gate->cycled = false;
    }
    cout << endl;
    while (! gateQueue.empty()) {
        gate = gateQueue.front();
        gateQueue.pop();
        if (gate->isReadyToCycle()) {
            // cout << "Cycling " << *gate << endl;
            gate->cycle();
        } else {
            // cout << "Skipping " << gate->name << endl;
            gateQueue.push(gate);
        }
    }
    cout << "Circuit cycle complete" << endl;
    for (auto item: gates) {
        gate = item.second;
        cout << *gate << endl;
    }
}
