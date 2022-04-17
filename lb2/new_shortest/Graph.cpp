//
// Created by Глеб on 9.04.22.
//

#include <fstream>
#include "Graph.h"

Graph::~Graph()= default;
Graph::Graph(bool directed){
    this->directed = directed;
    for(int i = 1; i < (MAXV + 1); i ++){
        this->edges[i] = nullptr;
    }
}


Graph::EdgeNode::EdgeNode(int key, int weight){
    this->key = key;
    this->weight = weight;
    this->next = nullptr;
}


void Graph::insert_edge(int x, int y, int weight, bool directed){
    if(x > 0 && x < (MAXV + 1) && y > 0 && y < (MAXV + 1)){
        auto *edge = new EdgeNode(y, weight);
        edge->next = this->edges[x];
        this->edges[x] = edge;
        if(!directed){
            insert_edge(y, x, weight, true);
        }
    }
}


void init_vars(bool visited[], int distance[]){
    for(int i = 1; i < (MAXV + 1); i ++){
        visited[i] = false;
        distance[i] = std::numeric_limits<int>::max();
    }
}


void Graph::dijkstra_shortest_path(){

    bool visited[MAXV + 1];
    EdgeNode *current;
    int v_curr;
    int v_neighbor;
    int weight;
    int smallest_dist;

    init_vars(visited, distance);

    distance[1] = 0;
    v_curr = 1;


    while(!visited[v_curr]){

        visited[v_curr] = true;
        current = this->edges[v_curr];

        while(current != nullptr){

            v_neighbor = current->key;
            weight = current->weight;

            if((distance[v_curr] + weight) < distance[v_neighbor]){
                distance[v_neighbor] = distance[v_curr] + weight;
            }
            current = current->next;
        }

        smallest_dist = std::numeric_limits<int>::max();
        for(int i = 1; i < (MAXV + 1); i++){
            if(!visited[i] && (distance[i] < smallest_dist)){
                v_curr = i;
                smallest_dist = distance[i];
            }
        }
    }
}


void Graph::print_distances(int test_number){
    ofstream file;
    string out_path = "../Tests/program_output/out." + to_string(test_number);
    file.open(out_path);
    for(int i = 1; i < (MAXV + 1); i ++){
        if(distance[i] != std::numeric_limits<int>::max()){
            file << distance[i] << " ";
        }
    }
    file.close();
}


void Graph::read(int test_number) {
    string in_path = "../Tests/input/in." + to_string(test_number);
    ifstream file(in_path);
    if (file.is_open()) {
        int x, y, weight;

        file >> weight >> weight;

        while (!file.eof()) {
            file >> x >> y >> weight;
            this->insert_edge(x, y, weight, false);
        }
    }
    else {
        cout << "input test not founded." << endl;
    }
    file.close();
}
