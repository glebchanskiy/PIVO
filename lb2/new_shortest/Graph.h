//
// Created by Глеб on 9.04.22.
//

#ifndef NEW_SHORTEST_GRAPH_H
#define NEW_SHORTEST_GRAPH_H
#define MAXV 30000

#include <iostream>
#include <iostream>
#include <limits>
#include <fstream>


using namespace std;

class Graph{
    bool directed;

public:
    class EdgeNode{
    public:
        int key;
        int weight;
        EdgeNode *next;
        EdgeNode(int, int);
    };

    EdgeNode *edges[MAXV + 1];
    int distance[MAXV + 1];
    Graph(bool);
    ~Graph();
    void read(int test_number);
    void insert_edge(int, int, int, bool);
    void dijkstra_shortest_path();
    void print_distances(int test_number);
};



#endif //NEW_SHORTEST_GRAPH_H
