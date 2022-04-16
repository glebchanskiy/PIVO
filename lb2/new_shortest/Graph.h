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


class EdgeNode{
public:
    int key;
    int weight;
    EdgeNode *next;
    EdgeNode(int, int);
};



class Graph{
    bool directed;
public:
    EdgeNode *edges[MAXV + 1];
    Graph(bool);
    ~Graph();
    void insert_edge(int, int, int, bool);
    void print();
};

void dijkstra_shortest_path(Graph *g, int parent[], int distance[], int start);

void print_distances(int start, int distance[], int counter);

#endif //NEW_SHORTEST_GRAPH_H
