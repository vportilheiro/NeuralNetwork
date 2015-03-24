/*  inputNode.cpp
 *
 *  This is the implementation of a simple input node. See inputNode.h for more
 *  information.
 *
 *  Vasco Portilheiro, 2015
 */

#include "inputNode.h"

/* Constructor calls Node constructor. */
InputNode::InputNode() : Node() {}
InputNode::InputNode(bool value) : Node(value) {}

/* Desctructor. */
InputNode::~InputNode() {}

/* Sets value of the node. */
/*void InputNode::set(bool value) {
    this->value = value;
}*/
