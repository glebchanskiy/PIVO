//
// Created by Глеб on 13.04.22.
//

#include "parser.h"

Parser::Parser(string &path) {
    fstream file(path);

    if (file.is_open()) {
        string buff;
        int set_counter = 0; // счетчик строк

        while (getline(file, buff)) {
            set_counter++;
            if (set_counter>10)
                return;

            char flag = 'n';    // флаг для записи в поле "name"
            string name;        // имя множества
            string set_in_line; // содержимое множества как строка

            for (char symbol: buff) {
                if (symbol == '=') {
                    flag = 'l'; // флаг для записи в поле "set_in_line"
                    continue;
                } else if (flag == 'n') {
                    name += symbol;
                } else if (flag == 'l') {
                    set_in_line += symbol;
                }
            }


            Set temp = pars(set_in_line);
            temp.setSetName(name);
            parsedSets.push_back(temp);

            isParsed = true;
        }
    }
    else
        isParsed = false;
}



Set Parser::pars(string &set_in_line) {
    ////Принимает на вход строку содержащую множество,"
    //// возвращает множество из строки в формате Set"

    // обрезаем '{' в начале и конце строки
    // {[множество]} --> [множество]
    string f_set_in_line(set_in_line.begin() + 1, set_in_line.end() - 1);

    Set *temp1 = new Set(); // для основного множества
    Set *temp2 = new Set(); // все множества второй вложенности
    Set *temp3 = new Set(); // множества третий вложенности

    stringstream ss(f_set_in_line);
    string item;
    char delim = ',';
    int nesting = 0; // счетчик вложенности

    // делим строку с множеством по "запятой" на элементы
    while (getline(ss, item, delim)) {

        // пустое множество
        if (item == "{}" and nesting == 0) {
            temp1->push_back(*(new Set()));
            continue;
        }
        // пустое множество внутри основного
        if (item == "{}" and nesting == 1) {
            temp2->push_back(*(new Set()));
            continue;
        }
        // пустое множество 3-ей вложенности
        if (item == "{}" and nesting == 2) {
            temp3->push_back(*(new Set()));
            continue;
        }

        if (item[0] == '{') {
            if (item[1] == '{') {
                nesting += 2;
                string temp_str(item.begin() + 2, item.end());
                temp3->push_back(temp_str);
                continue;
            }
            nesting++;
            string temp_str(item.begin() + 1, item.end());
            temp2->push_back(temp_str);
            continue;
        }

        if (item.back() == '}') {
            if (item[item.size() - 2] == '}') {
                string temp_str(item.begin(), item.end() - 2);
                temp3->push_back(temp_str);

                temp2->push_back(*(new Set(temp3)));
                temp3->clear();

                temp1->push_back(*(new Set(temp2)));
                temp2->clear();
                nesting -= 2;
                continue;
            }


            if (nesting == 1) {
                string temp_str(item.begin(), item.end() - 1);
                temp2->push_back(temp_str);
                temp1->push_back(*(new Set(temp2)));
                temp2->clear();
            } else if (nesting == 2) {
                string temp_str(item.begin(), item.end() - 1);
                temp3->push_back(temp_str);
                temp2->push_back(*(new Set(temp3)));
                temp3->clear();
            }

            nesting--;
            continue;
        }

        // в зависимости от вложенности добавляем элементы
        if (nesting == 0) {
            temp1->push_back(item);
        }
        if (nesting == 1) {
            temp2->push_back(item);
        }
        if (nesting == 2) {
            temp3->push_back(item);
        }
    }
    return *temp1;
}


bool Parser::isParsedSuccessfully() const {
    return isParsed;
}


