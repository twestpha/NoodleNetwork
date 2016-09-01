#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

enum Mode {
    TrainingMode, QueryMode
};

class NeuralNetwork {
public:
    NeuralNetwork();

    void SetMode(Mode mode);

    void LoadFromFile(const char* filename);
private:
    Mode mode;
    // stuff...
};

#endif
