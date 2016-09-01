#ifndef NEURON_H
#define NEURON_H

class Neuron {
public:
    Neuron();

    double GetValue();
    void AddInput(Neuron* input, double weight);
private:
    int used;
    int max;

    bool dirty;
    double value;
    double* weights;
    Neuron** inputs;

    bool IsDirty();
};

#endif
