#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "Neuron.hpp"

class NeuralNetwork {
public:
    NeuralNetwork();

    void Run();
private:
    int iterations;
    Neuron* inputs[2];
    Neuron* output;
};

#endif
