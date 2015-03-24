/* neuralNetwork.cpp
 *
 * This file implements a matrix-based neural network. For more information,
 * see neuralNetwork.h.
 *
 * Vasco Portilheiro, 2015
 */

#include "neuralNetwork.h"

#include <time.h>
#include <cmath>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

/* Constructor takes an initializer list of the size of each layer in the
 * network.
 * Example:     NeuralNetwork networkName({784, 30, 10});
 */
NeuralNetwork::NeuralNetwork(const std::vector<int>& layers) {
    
    /* Set number of layers to size of passed initializer list */
    numLayers = layers.size();

    /* This creates a generator of random numbers using a Gaussian distribution
     * of mean zero and variance 1. */
    boost::variate_generator<boost::mt19937, boost::normal_distribution<> >
        generator(boost::mt19937(time(0)), boost::normal_distribution<>());

    /* Initialize the biases to random vectors of the correct sizes. Note that
     * only starting at the second layer do neurons have biases. */
    for (int i = 0; i < (numLayers - 1); ++i) {
        int layerSize = layers[i + 1];
        VectorXd* bias = new VectorXd(layerSize);
        for (int j = 0; j < layerSize; ++j) {
            (*bias)[j] = generator();
        }
        biases.push_back(bias);
    }
    
    /* Initialize the list of random weight matrices, where W_jk is the weight
     * from the kth neuron in the input layer to the jth of the ouput layer. */
    for (int i = 0; i < (numLayers - 1); ++i) {
        int numRows = layers[i + 1];
        int numColumns = layers[i];
        MatrixXd* weight = new MatrixXd(numRows, numColumns);
        for (int j = 0; j < numRows; ++j) {
            for (int k = 0; k < numColumns; ++k) {
                (*weight)(j, k) = generator();
            }
        }
        weights.push_back(weight);
    }
}

/* Destructor deletes all memory allocated to biases and weights */
NeuralNetwork::~NeuralNetwork() {
    for (int i = 0; i < (numLayers - 1); ++i) {
        delete biases[i];
        delete weights[i];
    }
}

/* This function computes the result for a given input vector. It saves a copy
 * operation by taking a second vector by reference, which will store this
 * result. Whatever its contents, it is first overwritten to be a copy of the
 * input vector, and then fed forward through the network.
 * This function uses the Eigen library unaryExpr() function to apply the
 * sigmoid function to each neuron's output, by calling it on the vector of
 * outputs. This allows for the "feedforward" algorithm to simply compute the
 * matrix-vector products plus the bias vectors, and apply the vectorized
 * sigmoid function.*/
void NeuralNetwork::feedforward(const VectorXd& input, VectorXd& result) {
    result = input;
    for (int i = 0; i < (numLayers - 1); ++i) {
        result =
            ((*weights[i]) * result + (*biases[i])).unaryExpr(std::ptr_fun(sigmoid));
    }
}

/* Sigmoid function, used as activation function. */
double NeuralNetwork::sigmoid(double z) {
    return (1 / (1 + exp(z)));
}
