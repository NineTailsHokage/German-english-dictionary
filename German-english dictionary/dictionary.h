#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <algorithm>

class Dictionary {
private:
    std::vector<std::pair<std::string, std::string>> words;

public:
    Dictionary();
    void addWord(const std::string& german, const std::string& english);
    void deleteWord(const std::string& german);
    std::string lookupWord(const std::string& german);
    void listWords();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

#endif