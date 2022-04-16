//
// Created by Глеб on 9.04.22.
//

#ifndef NEW_SHORTEST_TESTER_H
#define NEW_SHORTEST_TESTER_H

#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

bool isEqual(int test_number) {
    string out_path = "../Tests/program_output/out." + to_string(test_number);
    string test_out_path = "../Tests/output/" + to_string(test_number) + ".a";

    ifstream fin1(out_path, ios::binary);
    ifstream fin2(test_out_path, ios::binary);

    int counter = 0;
    string buff;

    if (fin2 && fin2) {
        char ch1, ch2;

        while (fin1.get(ch1) && fin2.get(ch2)) {
            counter++;
            if (ch1 != ch2) {
                getline(fin2, buff, ' ');
                cout << "[" << counter << "] " << "ожидалось -> " << ch2 << buff << endl;
                getline(fin1, buff, ' ');
                cout << "[" << counter << "] " << "получено -> " << ch1 << buff << endl;
                return false;
            }
        }
        return true;
    }
    else
        return false;
}

#endif //NEW_SHORTEST_TESTER_H
