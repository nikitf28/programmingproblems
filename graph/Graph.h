//
// Created by nikita on 11.11.2021.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <string>
#include <set>

using namespace std;

typedef set<Node*>::const_iterator node_iterator;

class Node{
    string name;
    set<Node*> neighbours;
    void addNeighbour(Node* neighbour);
    void removeNeighbour(Node* neighbour);
public:
    Node(const string& aname) : name(aname){}
    const string& getName() const{
        return name;
    }
    node_iterator nb_begin() const{
        return neighbours.begin();
    }
    node_iterator nb_end() const{
        return neighbours.end();
    }
    friend class Graph;
};

class Graph {
    set<Node*> nodes;
public:
    void addNode(Node* node);
    void removeNode(Node* node);
    void addEdge(Node* begin, Node* end);
    void removeEdge(Node* begin, Node* end);
    node_iterator begin() const {
        return nodes.begin();
    }
    node_iterator end() const {
        return nodes.end();
    }
};




#endif //GRAPH_GRAPH_H
