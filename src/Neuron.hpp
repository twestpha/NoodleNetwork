#ifndef NEURON_H
#define NEURON_H

class Neuron {
public:
    Neuron();

    double GetValue();
    void AddInput(Neuron* input, double weight);
    void ModifyWeight(Neuron* input, double newWeight);
private:
    int used;
    int max;

    bool shouldRecompute;
    double value;
    double* weights;
    Neuron** inputs;
};

#endif
