#include "Graph.h"
#include "tester.h"


int main(){
    int test_number = 0;
    double duration;

    clock_t allTime;
    allTime = clock();


    while(test_number<21) {
        test_number++;

        Graph g(false);
        g.read(test_number);

        clock_t oneTestTime;
        oneTestTime = clock();

        g.dijkstra_shortest_path();
        g.print_distances(test_number);

        duration = (double)(clock() - oneTestTime) / (double) CLOCKS_PER_SEC;


        if (isEqual(test_number)) {
            if (test_number>9)
                cout << "Test " << test_number << " PASS" << "      [" << duration << "]" << endl;
            else
                cout << "Test " << test_number << " PASS" << "       [" << duration << "]" << endl;
        }
        else {
            if (test_number>9)
                cout << "Test " << test_number << " FAILED" << "      [" << duration << "]" << endl;
            else
                cout << "Test " << test_number << " FAILED" << "       [" << duration << "]" << endl;
        }
    }
    cout << "Время выполнения всех тестов " << (double)(clock() - allTime) / (double) CLOCKS_PER_SEC << " c";

    return 0;
}