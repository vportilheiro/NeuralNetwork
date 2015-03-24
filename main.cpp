#include <iostream>

#include "inputNode.h"
#include "perceptron.h"
#include "neuralNetwork.h"

int main() {
/*  Example of manual network:
 
    InputNode* i = new InputNode();
    InputNode* j = new InputNode(true);
    Perceptron* p = new Perceptron({i, j}, {-2, -2}, 3);

    bool result = p->evaluate();
    std::cout << result << std::endl;
    */

    std::cout << "Creating neural network...";
    NeuralNetwork net({784, 30, 10});
    std::cout << "done!" << std::endl;

    return 0;
}
