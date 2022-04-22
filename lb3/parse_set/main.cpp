#include "Set.h"
#include "parser.h"

#include <iostream>

using namespace std;


int main() {

    clock_t oneTestTime;
    oneTestTime = clock();

    Set A, B, a, b, big1, big2, result;

    A.pprint();

    string path = "../test.txt";
    Parser pars(path);

    if (pars.isParsedSuccessfully()) {

        for (auto i : pars.parsedSets) {
            i.pprint();
        }

        A = pars.parsedSets[0];
        B = pars.parsedSets[1];

        a = pars.parsedSets[2];
        b = pars.parsedSets[3];

        big1 = pars.parsedSets[5];
        big2 = pars.parsedSets[6];


        cout << endl << endl;

        Set A_diff_B;
        A_diff_B.difference(A,B);
        A_diff_B.pprint();

        Set B_diff_A;
        B_diff_A.difference(B,A);
        B_diff_A.pprint();


        result.unite(A_diff_B,B_diff_A);
        result.pprint();

        result.cross(A,B);
        result.pprint();

        cout << endl;

        result.difference(a,b);
        result.pprint();

        result.difference(b,a);
        result.pprint();

        result.unite(a,b);
        result.pprint();

        result.cross(a,b);
        result.pprint();

        cout << endl;

        result.difference(big1,big2);
        result.pprint();
        result.difference(big2,big1);
        result.pprint();
        result.unite(big2,big1);
        result.pprint();
        result.cross(big2,big1);
        result.pprint();

    }


    cout << endl;

    Set j;
    j.setSetName("J");

    Set j_inner;

    string i="I";
    j_inner.push_back(i);

    j_inner.push_back(*(new Set()));

    string aa="A";
    j_inner.push_back(aa);

    j.push_back(j_inner);

    j.pprint();

    Set g(j);
    g.setSetName("G");
    g.pprint();


    Set temp;
    temp.difference(j,g);
    temp.pprint();

    temp.cross(j,g);
    temp.pprint();

    temp.unite(j,g);
    temp.pprint();



    cout << endl <<"[" << (double)(clock() - oneTestTime) / (double) CLOCKS_PER_SEC << "]" << endl;


    return 0;
}
