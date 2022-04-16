//
// Created by Глеб on 13.04.22.
//

#ifndef PARSE_SET_PARSER_H
#define PARSE_SET_PARSER_H


#include <istream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include "Set.h"

using namespace std;

class Parser {
private:
    bool isParsed = false;

    Set parsedSet_1; // хранит множество из первой строки файла
    Set parsedSet_2; // из второй

    Set pars(string& line);

public:
    explicit Parser(string& path);
    bool isParsedSuccessfully() const;
    Set getFirstParsedSet();
    Set getSecondParsedSet();
};


#endif //PARSE_SET_PARSER_H
