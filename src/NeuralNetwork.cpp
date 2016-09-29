#include <stdio.h>

#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(){
    int iterations = 0;

    //#######################################
    // Level 1, inputs
    //#######################################

    Neuron* l1n1 = new Neuron;
    l1n1->AddInput(NULL, 0.0f);
    inputs[0] = l1n1;

    Neuron* l1n2 = new Neuron;
    l1n2->AddInput(NULL, 0.0f);
    inputs[1] = l1n2;

    //#######################################
    // Level 2
    //#######################################
    Neuron* l2n1 = new Neuron;
    l2n1->AddInput(l1n1, 0.0f);
    l2n1->AddInput(l1n2, 0.0f);

    output = l2n1;
}

void NeuralNetwork::Run(){
    // This is the place for shittt
    printf("L2N1 Value: %d\n", output->GetValue());
}
