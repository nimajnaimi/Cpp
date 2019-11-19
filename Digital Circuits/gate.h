/**
 * Base Class Gate
 * Defines a virtual digital gate that can have any number of inputs and a single output
 * The function cycle needs to be overriden by appropiate derived class
 * All variables and functions declared public for convenience
 * Need to convert it to use getters/setters in the future
 */

#ifndef GATE_H
#define GATE_H

#include <string>
#include <vector>

using namespace std;

class Gate {
    // write name, inputs and outputs to out for easy inspection
    friend ostream& operator<<(ostream& out, const Gate& gate);
public:
    // constructor with name
    explicit Gate(string name);
    // destructor
    virtual ~Gate();
    // convert inputs to outputs, derived class must override
    virtual void cycle() = 0;
    // true if all gates at the inputs are cycled
    virtual bool isReadyToCycle() const;
    // set the input with given number to given gate
    void setInputBit(unsigned int n, Gate * gate);
    // current status. After cycle becomes true
    bool cycled {false};
    // current output
    bool output {false};
    // name of this gate
    string name {""};
    // all the gates at the inputs
    vector<Gate*> inputs;
};

#endif // GATE_H
