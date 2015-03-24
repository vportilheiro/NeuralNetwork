/*  neuralNetwork.h
 *
 *  This class provides an efficient implementation of a multilayered neural
 *  network. The neural network is composed of layers of neurons, where each
 *  neuron in a layer to connected to each neuron of the next layer. The
 *  neurons are given an activation function. By default, they are sigmoid
 *  neurons, which output the function,
 *
 *                      1
 *      sigma(z) = -------------
 *                  1 + (e ^ z)
 *
 *  where z is the "" of the neuron, or the linear combination of
 *  inputs multiplied by their respective weights, plus the neuron's bias.
 *  Rather than focusing on representing these neurons in themselves, however,
 *  this program focuses on calculating the output of a network given an input,
 *  and on training the network.
 *  This is done by representing the network as two corresponding lists, each
 *  entry being associated to a layer in the network. 
 *  One of the lists one of the vectors b, containing the biases for each layer.
 *  The second is of matrices W, where the n-th matrix represents the weights
 *  from the layer n to layer n+1. Thus W_jk is the weight from the neuron j
 *  in the first layer to weight to k in the second layer. Thus, the vector of
 *  activations in the second layer, a', can be written in terms of the
 *  activations of the neurons in the first layer as,
 *
 *      a' = sigma(w*a + b)
 *
 * Note that with this notation, the vectorized function sigma is used, where
 * it is applied to each component of the argument vector.
 *
 * The network is trained using stochastic gradient descent.
 *
 * Credit goes to Michael Nielsen, and his website:
 * neuralnetworksanddeeplearning.com
 * for a very well written an followable introduction to the subject.
 *
 * This class uses the Eigen library to handle most of its math. The library is
 * available at:
 * eigen.tuxfamily.org
 *
 * Vasco Portilheiro, 2015
 */

#ifndef __NEURAL_NET_H__
#define __NEURAL_NET_H__

#include <eigen3/Eigen/Dense>
#include <vector>

using Eigen::VectorXd;
using Eigen::MatrixXd;

class NeuralNetwork {

public:

    /* Constructor, takes the number of neurons in each layer, with any number
     * of layers being allowable. These are passed in as a constant reference
     * to a vector of integers. */
    NeuralNetwork(const std::vector<int>& layers);

    /* Destructor */
    ~NeuralNetwork();

    /* Generates the output to the network for the given input vector */
    void feedforward(const VectorXd& input, VectorXd& output);

private:

    /* Number of layers in network */
    int numLayers;

    /* List of the bias vectors for each layer, starting at the second
     * (first non-input) layer. These are set to random values using a
     * Gaussian distrubution with mean 0 and variance 1. */
    std::vector<VectorXd*> biases;

    /* List of the weight matrices connecting each layer of neurons. Since this
     * list can be seen as being of matrices "between" the neurons, it has the
     * same length as the list of biases (one less than number of layers). */
    std::vector<MatrixXd*> weights;

    /* Sigmoid activation function. Takes the sum z of the weighted inputs plus
     * the bias for any given neuron. */
    static double sigmoid(double z);

};

#endif
