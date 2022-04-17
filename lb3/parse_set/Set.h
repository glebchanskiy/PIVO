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
        int int_part = '0';
        char char_part = ' ';
        std::string str_part;
        Set * next = nullptr;
        explicit SetElement(int);
        explicit SetElement(char);
        explicit SetElement(Set&);
        explicit SetElement(std::string);
        SetElement()=default;
    };



    Set();
    explicit Set(int size);
    explicit Set(Set *s);


    void setSetName(std::string name);
    std::string getSetName();


    void push_back(int element);
    void push_back(char element);
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
    std::string SetName="UNKNOWN";
    std::vector<Set::SetElement> main_container;
};


#endif //PARSE_SET_SET_H
