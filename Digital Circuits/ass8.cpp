// Name: Nima Naimi
// Date: March 11, 2018
// Assignment 8: Digital Circuits
// Description: Tests all inputs for a series of gates
// ............ and tests the implementation of a half-adder

#include <iostream>

#include "alwaysongate.h"
#include "alwaysoffgate.h"
#include "andgate.h"
#include "orgate.h"
#include "notgate.h"
#include "xorgate.h"
#include "circuit.h"

using namespace std;

// 4 possible inputs: 0,0  0,1  1,0  and 1,1
// only 1,1 should give an output of 1
void testANDGate() {
    Circuit c;
    c.addGate(new AlwaysOFFgate("OFF"));
    c.addGate(new AlwaysONgate("ON"));
    c.addGate(new ANDGate("AndGate"));
    cout << endl << "TestAND: 0, 0" << endl;
    c.connect("OFF", 0, "AndGate");
    c.connect("OFF", 1, "AndGate");
    c.cycle();

    cout << endl << "TestAND: 0, 1" << endl;
    c.connect("ON", 1, "AndGate");
    c.cycle();

    cout << endl << "TestAND: 1, 0" << endl;
    c.connect("ON", 0, "AndGate");
    c.connect("OFF", 1, "AndGate");
    c.cycle();

    cout << endl << "TestAND: 1, 1" << endl;
    c.connect("ON", 0, "AndGate");
    c.connect("ON", 1, "AndGate");
    c.cycle();
}

// Tests all variations of inputs for an OR gate
// 0, 1 and 1, 0  and 1, 1 should be the only inputs to give the output 1
void testORGate() {
    Circuit c;
    c.addGate(new AlwaysOFFgate("OFF"));
    c.addGate(new AlwaysONgate("ON"));
    c.addGate(new ORGate("ORGate"));
    cout << endl << "TestOR: 0, 0" << endl;
    c.connect("OFF", 0, "ORGate");
    c.connect("OFF", 1, "ORGate");
    c.cycle();

    cout << endl << "TestOR: 0, 1" << endl;
    c.connect("ON", 1, "ORGate");
    c.cycle();

    cout << endl << "ORGate: 1, 0" << endl;
    c.connect("ON", 0, "ORGate");
    c.connect("OFF", 1, "ORGate");
    c.cycle();

    cout << endl << "TestOR: 1, 1" << endl;
    c.connect("ON", 0, "ORGate");
    c.connect("ON", 1, "ORGate");
    c.cycle();
}

// Tests all variations of inputs for a NOT gate
// 0 should be the only input to give the output 1
void testNOTGate() {
    Circuit c;
    c.addGate(new AlwaysOFFgate("OFF"));
    c.addGate(new AlwaysONgate("ON"));
    c.addGate(new NOTGate("NOTGate"));
    cout << endl << "TestNOT: 0" << endl;
    c.connect("OFF", 0, "NOTGate");
    c.cycle();

    cout << endl << "TestNOT: 1" << endl;
    c.connect("ON", 0, "NOTGate");
    c.cycle();
}

// Tests all variations of inputs for an XOR gate
// only 0, 1 and 1, 0 should give the output 1
void testXORGate() {
    Circuit c;
    c.addGate(new AlwaysOFFgate("OFF"));
    c.addGate(new AlwaysONgate("ON"));
    c.addGate(new XORGate("XORGate"));
    cout << endl << "TestXOR: 0, 0" << endl;
    c.connect("OFF", 0, "XORGate");
    c.connect("OFF", 1, "XORGate");
    c.cycle();

    cout << endl << "TestXOR: 0, 1" << endl;
    c.connect("ON", 1, "XORGate");
    c.cycle();

    cout << endl << "XORGate1: 1, 0" << endl;
    c.connect("ON", 0, "XORGate");
    c.connect("OFF", 1, "XORGate");
    c.cycle();

    cout << endl << "TestXOR: 1, 1" << endl;
    c.connect("ON", 0, "XORGate");
    c.connect("ON", 1, "XORGate");
    c.cycle();
}

// Implements a half-adder and tests the output using the necessary gates
// Should never give the output 1, 1
// Should output 0, 1 for the inputs 1, 0 or 0, 1
// Should output 0, 0 if both inputs are 0
void testHAdder() {
    Circuit c;
    c.addGate(new AlwaysOFFgate("OFF"));
    c.addGate(new AlwaysONgate("ON"));
    c.addGate(new XORGate("XORGate"));
    c.addGate(new ANDGate("ANDGate"));
    cout << endl << "TestHAdder: 0, 0" << endl;
    c.connect("OFF", 0, "XORGate");
    c.connect("OFF", 1, "XORGate");
    c.connect("OFF", 0, "ANDGate");
    c.connect("OFF", 1, "ANDGate");
    c.cycle();

    cout << endl << "TestHAdder: 0, 1" << endl;
    c.connect("OFF", 0, "XORGate");
    c.connect("ON", 1, "XORGate");
    c.connect("OFF", 0, "ANDGate");
    c.connect("ON", 1, "ANDGate");
    c.cycle();

    cout << endl << "TestHAdder: 1, 0" << endl;
    c.connect("ON", 0, "XORGate");
    c.connect("OFF", 1, "XORGate");
    c.connect("ON", 0, "ANDGate");
    c.connect("OFF", 1, "ANDGate");
    c.cycle();

    cout << endl << "TestHAdder: 1, 1" << endl;
    c.connect("ON", 0, "XORGate");
    c.connect("ON", 1, "XORGate");
    c.connect("ON", 0, "ANDGate");
    c.connect("ON", 1, "ANDGate");
    c.cycle();
}

int main()
{
    testANDGate();
    testORGate();
    testNOTGate();
    testXORGate();
    testHAdder();
    return 0;
}
