
#include "Graph.h"
#include "tester.h"

int counter = 0;


int main(){
    clock_t allTime;
    allTime = clock();

    double duration;
    while(counter<21) {
        counter++;

        auto *g = new Graph(false);

        int parent[MAXV + 1];
        int distance[MAXV + 1];
        int start = 1;

        string in_path = "../Tests/input/in." + to_string(counter);
        ifstream file(in_path);
        if (file.is_open()) {
            int temp;
            int x, y, m;

            file >> temp >> temp;

            while (!file.eof()) {
                file >> x >> y >> m;
                g->insert_edge(x, y, m, false);
            }
        }
        else {
            cout << "input test not founded." << endl;
        }
        file.close();

        clock_t oneTestTime;
        oneTestTime = clock();

        dijkstra_shortest_path(g, parent, distance, start);

        duration = (double)(clock() - oneTestTime) / (double) CLOCKS_PER_SEC;

        print_distances(start, distance, counter);

        delete g;


        string out_path = "../Tests/program_output/out." + to_string(counter);
        string test_out_path = "../Tests/output/" + to_string(counter) + ".a";

        if (isEqual(test_out_path, out_path)) {
            cout << "Тест " << counter << " пройден." << "  за: "<< duration << " c" << endl;
        }
        else {
            cout << "Тест " << counter << " провален." <<"  за: "<< duration << " c" << endl;
        }
    }
    cout << "Время выполнения всех тестов " << (double)(clock() - allTime) / (double) CLOCKS_PER_SEC << " c";

    return 0;
}