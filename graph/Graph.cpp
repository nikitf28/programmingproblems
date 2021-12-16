//
// Created by nikita on 11.11.2021.
//

#include "Graph.h"

void Graph::removeNode(Node *node) {
    nodes.erase(node);
    for (set<Node>::iterator it = nodes.begin(); it != nodes.end(); it++){
        (*it)->removeNeighbour(node);
    }
}

void Graph::addEdge(Node *begin, Node *end) {
    if (nodes.find(begin) == nodes.end()){
        return;
    }
    if (nodes.find(end) == nodes.end()){
        return;
    }
    begin->addNeighbour(end);
    end->addNeighbour(begin);
}
