#include "Set.h"
#include "parser.h"

#include <iostream>

using namespace std;


int main() {

    clock_t oneTestTime;
    oneTestTime = clock();

    Set a, b;

    a.pprint();

    string path = "../test.txt";
    Parser pars(path);

    if (pars.isParsedSuccessfully()) {
        a = pars.getFirstParsedSet();
        b = pars.getSecondParsedSet();

        a.pprint();
        b.pprint();

        cout << endl << endl;

        Set s1;
        s1.unite(a,b);
        s1.pprint();

        Set s2;
        s2.difference(b,a);
        s2.pprint();

        Set result;
        result.unite(s1,s2);
        result.pprint();
    }




    cout << endl <<"[" << (double)(clock() - oneTestTime) / (double) CLOCKS_PER_SEC << "]" << endl;

//// при сравнении " {{}, A, I, } " c " {{}, A, I, } " возвращает false;
    return 0;
}



//    Set s(10);
//    cout << s.main_container.capacity() << endl;
//
//    s.push_back(1);
//    s.push_back(2);
//    s.push_back(3);
//
//    Set t;
//    t.push_back(2);
//    t.push_back(3);
//
//    Set it;
//    it.push_back('a');
//    string stroka = "lol_kek";
//    it.push_back(stroka);
//    it.push_back('c');
//    it.push_back(it);
//
//    t.push_back(4);
//
//    s.push_back(t);
//
//    s.push_back('a');
//    s.push_back('b');
//
//    s.print(); cout<<endl;
