#include <math.h>
#include <stdio.h>

#include "Neuron.hpp"

Neuron::Neuron(){
    value = 0.0f;
    shouldRecompute = true;

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

        shouldRecompute = true;
    } else {
        shouldRecompute = false;
        value = weight;
    }
}

void Neuron::ModifyWeight(Neuron* input, double newWeight){
    // slow as fuck... Hopefully we won't use this, we'll use something else for backtracking
    // or, the backtracking program necessitates O(n), so either way, fuck it.
    if(input){
        for(int i = 0; i < used; ++i){
            if(inputs[i] == input){
                weights[i] = newWeight;
            }
        }

        shouldRecompute = true;
    } else {
        value = newWeight;
    }

}

double Neuron::GetValue(){
    if(shouldRecompute){
        double sum = 0.0f;

        for(int i = 0; i < used; ++i){
            if(inputs[i]){
                sum += inputs[i]->GetValue() * weights[i];
            }
        }

        value = sum;
        shouldRecompute = false;
    }

    return value;
}
