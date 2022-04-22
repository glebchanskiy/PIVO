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
                }
                else if (flag == 'n') {
                    name += symbol;
                }
                else if (flag == 'l') {
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
    Set *temp4 = new Set(); // множества третий вложенности

    stringstream ss(f_set_in_line);
    string item;
    char delim = ',';
    int nesting = 0; // счетчик вложенности

    // делим строку с множеством по "запятой" на элементы
    while (getline(ss, item, delim)) {
        bool direct = false;
        // пустое множество
        if ((item == "{}" or item == "<>") and nesting == 0) {
            temp1->push_back(*(new Set()));
            continue;
        }
        // пустое множество внутри основного
        if ((item == "{}" or item == "<>") and nesting == 1) {
            temp2->push_back(*(new Set()));
            continue;
        }
        // пустое множество 3-ей вложенности
        if ((item == "{}" or item == "<>") and nesting == 2) {
            temp3->push_back(*(new Set()));
            continue;
        }
        // пустое множество 4-ей вложенности
        if ((item == "{}" or item == "<>") and nesting == 3) {
            temp4->push_back(*(new Set()));
            continue;
        }
        // исключительные случаи
        if ((item == "{{}}" or item == "<<>>") and nesting==0) {
            temp3->push_back(*(new Set()));
            temp2->push_back(*temp3);
            temp1->push_back(*temp2);
            continue;
        }
        if ((item == "{{{}}}" or item == "<<<>>>") and nesting==0) {
            temp4->push_back(*(new Set()));
            temp3->push_back(*temp4);
            temp2->push_back(*temp3);
            temp1->push_back(*temp2);
            continue;
        }


        if (item[0] == '{') {
            if (item[1] == '{') {
                if (item[2] == '{') {
                    nesting += 3;
                    string temp_str(item.begin() + 3, item.end());
                    item = temp_str;
                }
                nesting += 2;
                string temp_str(item.begin() + 2, item.end());
                item = temp_str;
            }
            nesting++;
            string temp_str(item.begin() + 1, item.end());
            item = temp_str;
        }

        if (item.back() == '}') {
            if (item[item.size() - 2] == '}') {
                if (item[item.size() - 3] == '}') {
                    string temp_str(item.begin(), item.end() - 3);
                    temp4->push_back(temp_str);

                    temp3->push_back(*(new Set(temp4)));
                    temp4->clear();

                    temp2->push_back(*(new Set(temp3)));
                    temp3->clear();

                    temp1->push_back(*(new Set(temp2)));
                    temp2->clear();

                    nesting -= 3;
                    continue;
                }
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
            } else if (nesting == 3) {
                string temp_str(item.begin(), item.end() - 1);
                temp4->push_back(temp_str);
                temp3->push_back(*(new Set(temp4)));
                temp4->clear();
            }

            nesting--;
            continue;
        }

        while (true) {
            if (item[0] == '<') {
                if (item[1] == '<') {
                    if (item[2] == '<') {
                        direct = true;
                        nesting += 3;
                        string temp_str(item.begin() + 3, item.end());
                        item = temp_str;
                        break;
                    }
                    direct = true;
                    nesting += 2;
                    string temp_str(item.begin() + 2, item.end());
                    item = temp_str;
                    break;
                }
                direct = true;
                nesting++;
                string temp_str(item.begin() + 1, item.end());
                item = temp_str;
                break;
            }
            break;
        }


        if (item.back() == '>') {
            if (item[item.size() - 2] == '>') {
                if (item[item.size() - 3] == '>') {
                    string temp_str(item.begin(), item.end() - 3);
                    temp4->setIsDirected= true;
                    temp4->push_back(temp_str);

                    temp3->push_back(*(new Set(temp4)));
                    temp4->clear();
                    temp4->setIsDirected=false;

                    temp2->push_back(*(new Set(temp3)));
                    temp3->clear();

                    temp1->push_back(*(new Set(temp2)));
                    temp2->clear();

                    nesting -= 3;
                    continue;
                }
                string temp_str(item.begin(), item.end() - 2);
                temp3->setIsDirected= true;
                temp3->push_back(temp_str);

                temp2->push_back(*(new Set(temp3)));
                temp3->clear();
                temp3->setIsDirected= false;

                temp1->push_back(*(new Set(temp2)));
                temp2->clear();
                nesting -= 2;
                continue;
            }

            if (nesting == 1) {
                string temp_str(item.begin(), item.end() - 1);
                temp2->push_back(temp_str);
                temp2->setIsDirected= true;

                temp1->push_back(*(new Set(temp2)));
                temp2->clear();
                temp2->setIsDirected=false;
            } else if (nesting == 2) {
                string temp_str(item.begin(), item.end() - 1);
                temp3->push_back(temp_str);
                temp3->setIsDirected= true;

                temp2->push_back(*(new Set(temp3)));
                temp3->clear();
                temp3->setIsDirected=false;
            } else if (nesting == 3) {
                string temp_str(item.begin(), item.end() - 1);
                temp4->push_back(temp_str);
                temp4->setIsDirected = true;

                temp3->push_back(*(new Set(temp4)));
                temp4->clear();
                temp4->setIsDirected=false;
            }

            nesting--;
            continue;
        }



        if (nesting == 0) {
            temp1->push_back(item);
        }
        else if (nesting == 1) {
            temp2->push_back(item);
        }
        else if (nesting == 2) {
            temp3->push_back(item);
        }
        else if (nesting == 3) {
            temp4->push_back(item);
        }

        // в зависимости от вложенности добавляем элементы

    }
    return *temp1;
}


bool Parser::isParsedSuccessfully() const {
    return isParsed;
}


