#include <math.h>
#include <stdio.h>

#include "Neuron.hpp"

Neuron::Neuron(){
    value = 0.0f;
    dirty = true;

    used = 0;
    max = 1;

    weights = new double[max];
    inputs = new Neuron*[max];
}

void Neuron::AddInput(Neuron* input, double weight){
    if(this == input){
        printf("Neuron cannot be its own input.\n");
        return;
    }

    if(input){
        if(used + 1 > max){
            double* weights_ = new double[max * 2];
            Neuron** inputs_ = new Neuron*[max * 2];
            max *= 2;

            for(int i = 0; i < used; ++i){
                weights_[i] = weights[i];
                inputs_[i] = inputs[i];
            }

            delete[] weights;
            delete[] inputs;

            weights = weights_;
            inputs = inputs_;
        }

        weights[used] = weight;
        inputs[used] = input;

        used++;

        dirty = true;
    } else {
        dirty = false;
        value = weight;
    }
}


double Neuron::GetValue(){
    if(dirty){
        double sum = 0.0f;

        for(int i = 0; i < used; ++i){
            if(inputs[i]){
                sum += inputs[i]->GetValue() * weights[i];
            }
        }

        value = sum;
        dirty = false;
    }

    return value;
}

bool Neuron::IsDirty(){
    return dirty;
}
