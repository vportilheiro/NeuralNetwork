/*  perceptron.h
 *
 *  A class that models a single perceptron node for an artificial neural
 *  network. A perceptron is a node that takes any number of n binary inputs,
 *  and then calculates their linear combination with some pre-defined
 *  corresponding n weights. This value is compared to a threshold, and the
 *  perceptron outputs either one or zero.
 *
 *  Vasco Portilheiro, 2015
 */

#ifndef __PERCEPTRON_H__
#define __PERCEPTRON_H__

#include <vector>
#include "node.h"

class Perceptron : public Node {
public:

    /* Constructor; takes a vector of pointers to the input nodes, as well
     * as a vector of the weights given to each input, respectively. Note that
     * if these vectors are of differing lengths, an error will be thrown.
     * The constructor also takes the perceptron's "bias." The bias can be
     * understood as the inverse (negative) of the threshold for the linear
     * combination above which a one will be the output. In other words,
     * a large bias means it is easy for the perceptron to fire a one. */
    Perceptron(const std::vector<Node*>& inputs,
               const std::vector<double>& weights, double bias);

    /* Destructor clears all memory associated with individual perceptron.*/
    virtual ~Perceptron();

    /* Evaluates the output for a current value of inputs. This function will
     * both return the result, and set the peceptron's value to it.*/
    virtual bool evaluate();

private:

    /* The input nodes for the perceptron. */
    std::vector<Node*> inputs;

    /* The weights given to each input. These are applied to the inputs in the
     * order they appear in the vector above. */
    std::vector<double> weights;

    /* Bias -- the negative of the threshold of the linear combination of
     * inputs to output a one. */
    double bias;

    /* Variable that represents wether the current value of the perceptron is
     * consistent with its inputs. If the perceptron is in fact "stable", then
     * calls to evaluate() will simply return the value, rather than
     * re-calculate it. */
    bool stable;
};

#endif
