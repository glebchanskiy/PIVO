#include "Set.h"
#include "parser.h"

#include <iostream>

using namespace std;


int main() {

    clock_t oneTestTime;
    oneTestTime = clock();

    Set a, b, a1, a2;

    a.pprint();

    string path = "../test.txt";
    Parser pars(path);

    if (pars.isParsedSuccessfully()) {

        for (auto i : pars.parsedSets) {
            i.pprint();
        }

        a = pars.parsedSets[0];
        b = pars.parsedSets[1];

        a1 = pars.parsedSets[2];
        a2 = pars.parsedSets[3];



        cout << endl << endl;

        Set s1;
        s1.difference(a,b);
        s1.pprint();

        Set s2;
        s2.difference(b,a);
        s2.pprint();

        Set result;
        result.unite(s1,s2);
        result.pprint();

        cout << endl;

        Set result2;
        result2.difference(a1,a2);
        result2.pprint();
    }


    cout << endl;

    Set j;
    j.setSetName("J");

    Set j_;
    string i="I";
    j_.push_back(i);
    j_.push_back(*(new Set()));

    string aa="A";
    j_.push_back(aa);
    j.push_back(j_);

    j.pprint();

    Set j2(j);
    j2.setSetName("J2");
    j2.pprint();


    Set temp;
    temp.difference(j2,j);
    temp.pprint();



    cout << endl <<"[" << (double)(clock() - oneTestTime) / (double) CLOCKS_PER_SEC << "]" << endl;


    return 0;
}
