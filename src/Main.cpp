#include <stdio.h>

#include "Neuron.hpp"

int main(){
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
