#include <stdio.h>

#include "NeuralNetwork.hpp"
#include "Neuron.hpp"

int main(int argc, const char** argv){

    // -t, training mode
    // requires a *.ndl (use for node layers)
    // and a *.tst, for training on

    // -q, query  mode
    // requires a *.ndl (the neural network)
    // and will output the answer based on the inputs

    // parse cmd line args, decide on mode, set vars

    NeuralNetwork noodle;

    Neuron* l1n1 = new Neuron();
    l1n1->AddInput(NULL, 0.5f);

    Neuron* l1n2 = new Neuron();
    l1n2->AddInput(NULL, 0.5f);

    Neuron* l2n1 = new Neuron();
    l2n1->AddInput(l1n1, 1.0f);
    l2n1->AddInput(l1n2, 1.0f);

    Neuron* l2n2 = new Neuron();
    l2n2->AddInput(l1n1, 5.0f);
    l2n2->AddInput(l1n2, 5.0f);

    Neuron* l3n1 = new Neuron();
    l3n1->AddInput(l2n1, 1.0f);
    l3n1->AddInput(l2n2, 0.2f);
    printf("l3n1: %f\n", l3n1->GetValue());

    return 0;
}
