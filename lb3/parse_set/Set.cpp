//
// Created by Глеб on 13.04.22.
//

#include "Set.h"

#include <utility>


Set::Set()=default;

Set::Set(int size) {
    this->main_container.reserve(size);
}

Set::Set(Set *s) {
    // конструктор копирования
    this->main_container = s->main_container;
    this->SetName = s->SetName;
    this->setIsDirected = s->setIsDirected;
}


Set::SetElement::SetElement(Set& data) {
    this->next = &data;
}

Set::SetElement::SetElement(std::string data) {
    this->str_part = data;
}


void Set::push_back(std::string &element) {
    this->main_container.emplace_back(Set::SetElement(element));
}

void Set::push_back(Set &element) {
    this->main_container.emplace_back(Set::SetElement(element));
}

void Set::push_back(Set::SetElement &element) {
    this->main_container.emplace_back(element);
}


void Set::print_dir() {
    std::cout << "<";

    for (auto i : main_container) {
        if (i.next != nullptr) {
            if (this->setIsDirected)
                i.next->print_dir();
            else
                i.next->print();
        }
        if (not i.str_part.empty()) {
            if (elementIsEqual(i, main_container.back()))
                std::cout << "" << i.str_part << "";
            else
                std::cout << "" << i.str_part << ", ";
        }
    }

    std::cout << ">, ";
}


void Set::print() {
    std::cout << "{";

    for (auto i : main_container) {
        if (i.next != nullptr) {
            if (i.next->setIsDirected)
                i.next->print_dir();
            else
                i.next->print();
        }
        if (not i.str_part.empty()) {
            if (elementIsEqual(i, main_container.back()))
                std::cout << "" << i.str_part << "";
            else
                std::cout << "" << i.str_part << ", ";
        }
    }

    std::cout << "}, ";
}

void Set::clear() {
    this->main_container.clear();
}

void Set::pprint() {
    std::cout << SetName << "=";
    print();
    std::cout << std::endl;
}

void Set::setSetName(std::string name) {
    this->SetName = name;
}

std::string Set::getSetName() {
    return this->SetName;
}


void Set::sort(Set &set) {
    SetElement temp;
    if (set.main_container.empty())
        return;
    for (int i = 0; i < set.main_container.size() - 1; i++) {
        for (int j = 0; j < set.main_container.size() - i - 1; j++) {
            if (set.main_container[j].str_part > set.main_container[j + 1].str_part) {

                temp = set.main_container[j];
                set.main_container[j] = set.main_container[j + 1];
                set.main_container[j + 1] = temp;
            }
        }
    }
}

bool elementIsEqual(Set::SetElement &,Set::SetElement &);

bool Set::setIsEqual(Set &first_set, Set &second_set) {
    sort(first_set);
    sort(second_set);
    if (first_set.main_container.size()!=second_set.main_container.size())
        return false;

    int size = first_set.main_container.size() < second_set.main_container.size()?
            (int)first_set.main_container.size():(int)second_set.main_container.size();

    bool flag = true;
    for (int i=0; i<size; i++) {
        if (!elementIsEqual(first_set.main_container[i],second_set.main_container[i])) {
            flag = false;
            break;
        }
    }
    return flag;
}

bool Set::elementIsEqual(Set::SetElement &first_set,Set::SetElement &second_set) {
    if (( first_set.str_part == second_set.str_part ) and
        (!first_set.str_part.empty() and
         !second_set.str_part.empty()) ) {
        return true;
    }
    else if ( first_set.next != nullptr and second_set.next != nullptr and (first_set.next->setIsDirected and second_set.next->setIsDirected)) {
        return setIsEqual(*first_set.next, *second_set.next);
    }
    else
        return false;
}

void Set::difference(Set &first_set, Set &second_set) {
    this->setSetName("(" + first_set.getSetName() + "\\" + second_set.getSetName() + ")");
    this->main_container.reserve(first_set.main_container.size() + second_set.main_container.size());

    for (auto i: first_set.main_container) {
        for (auto j: second_set.main_container) {
            if (!elementIsEqual(i,j)) {
                if (elementIsEqual(j,second_set.main_container[second_set.main_container.size()-1])) {
                    this->push_back(i);
                }
            } else {
                break;
            }
        }
    }
}

void Set::unite(Set &first_set, Set &second_set) {
    this->setSetName("(" + first_set.getSetName() + "⋃" + second_set.getSetName() + ")");
    this->main_container.reserve(first_set.main_container.size() + second_set.main_container.size());

    for (auto i: first_set.main_container) {
        this->push_back(i);
    }

    for (auto i: second_set.main_container)
        for (auto j: first_set.main_container)
            if (!elementIsEqual(i,j)) {
                if (elementIsEqual(j,first_set.main_container[first_set.main_container.size()-1]))
                    this->push_back(i);
            } else
                break;
}

void Set::cross(Set &first_set, Set &second_set) {
    this->setSetName("(" + first_set.getSetName() + "⋂" + second_set.getSetName() + ")");
    this->main_container.reserve(first_set.main_container.size() + second_set.main_container.size());

    for (auto i: second_set.main_container)
        for (auto j: first_set.main_container)
            if (elementIsEqual(i,j))
                this->push_back(j);
}


