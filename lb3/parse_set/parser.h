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

    Set pars(string& line);

public:
    explicit Parser(string& path);
    bool isParsedSuccessfully() const;
    vector<Set> parsedSets;
};


#endif //PARSE_SET_PARSER_H
