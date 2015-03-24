/*  node.cpp
 *
 *  Implements the node class. See node.h for more information.
 *
 *  Vasco Portilheiro, 2015
 */

#include "node.h"

/* No-argument constructor will set the node's value to a default of zero. */
Node::Node() {
    value = false;
}

/* Constructor which takes an initial value. */
Node::Node(bool value) {
    this->value = value;
}

/* Empty destructor. */
Node::~Node(){}

/* Returns the value of the node. */
bool Node::evaluate() {
    return value;
}
