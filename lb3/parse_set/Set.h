//
// Created by Глеб on 13.04.22.
//

#ifndef PARSE_SET_SET_H
#define PARSE_SET_SET_H

#include <vector>
#include <iostream>
#include <string>


class Set {
public:
    class SetElement {
    public:
        std::string str_part;
        Set * next = nullptr;

        explicit SetElement(Set&);
        explicit SetElement(std::string);
        SetElement()=default;
    };
    bool setIsDirected=false;


    Set();
    explicit Set(int size);
    explicit Set(Set *s);


    void setSetName(std::string name);
    std::string getSetName();


    void push_back(std::string &element);
    void push_back(Set& element);
    void push_back(Set::SetElement &element);

    void unite(Set &first_set, Set &second_set);
    void cross(Set &first_set, Set &second_set);
    void difference(Set &first_set, Set &second_set);

    void clear();
    void pprint();

private:
    void sort(Set &set);
    bool setIsEqual(Set &first_set, Set &second_set);
    bool elementIsEqual(Set::SetElement &first_set,Set::SetElement &second_set);

    void print();
    void print_dir();
    std::string SetName="UNKNOWN";
    std::vector<Set::SetElement> main_container;
};


#endif //PARSE_SET_SET_H
