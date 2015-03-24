/*  node.h
 *
 *  Abstarct definition of a node to be used in a neural network. Nodes may
 *  include percetrons, as will as be used directly for input. The only
 *  requirement for a node is having an associated "value" which may be
 *  retriecved by other nodes as input.
 *
 *  Vasco Portilheiro, 2015
 */

#ifndef __NODE_H__
#define __NODE_H__

class Node {
public:

    /* Constructor, which may take no arguments. Alternitavely, an initial
     * value may be set. (Otherwise, the value is assumed to be zero.) */
    Node();
    Node(bool value);

    /* Abstract destructor. */
    virtual ~Node() = 0;

    /* Returns the value of the node. */
    virtual bool evaluate();

protected:

    /* Value of node. */
    bool value;

};

#endif
