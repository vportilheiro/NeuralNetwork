/*  perceptron.cpp
 *
 *  This is the implementation of a perceptron node in a neural network.
 *  For more information, see perceptron.h.
 *
 *  Vasco Portilheiro, 2015
 */

#include "perceptron.h"

/* Constructor takes vector of inputs, respective weights given to those
 * inputs, and bias of outputing a one. */
Perceptron::Perceptron(const std::vector<Node*>& inputs,
                       const std::vector<double>& weights, double bias) {
    if (inputs.size() != weights.size())
        throw "Sizes of inputs vector and weights vector do not match!";

    this->inputs = inputs;
    this->weights = weights;
    this->bias = bias;
    this->stable = false;
}

/* Destructor. */
Perceptron::~Perceptron(){}

bool Perceptron::evaluate() {
    if (!stable) {
        double linearCombination = 0;
        for (int i = 0; i < inputs.size(); ++i) {
            linearCombination += weights[i] * inputs[i]->evaluate();
        }
        value = linearCombination + bias;
        stable = true;
    }
    return value;
}
