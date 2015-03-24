/*  inputNode.h
 *
 *  A simple node with a constant value. Note that all functionality except for
 *  setting a value after initialization of the object exists in the abstract
 *  Node class. Also, the desctructor is defined separately, since we  may only
 *  assume for an InputNode that there will be no "dangling nodes" left over.
 *
 *  Vasco Portilheiro, 2015
 */

#ifndef __INPUT_NODE_H__
#define __INPUT_NODE_H__

#include "node.h"

class InputNode : public Node {
public:

    /* Constructor; may take no arguments, or the initial value. */
    InputNode();
    InputNode(bool value);

    /* Destructor. */
    virtual ~InputNode();

    /* Lets the user set a value for the input node. */
    // TODO: make this work with "stable" feature for percetrons
    //void set(bool value);

};

#endif
