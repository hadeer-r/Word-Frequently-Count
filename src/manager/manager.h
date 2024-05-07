#ifndef MANAGER_H
#define MANAGER_H
#include"Words.hpp"
#include "../manageText/upload_text.hpp"
#include <string>
#include <vector>
#include "../manageWords/Words.hpp"
#include "trie.h"
#include "checker.h"
#include <unordered_map>
#include<iostream>
using namespace std;
class Manager
{
public:
    Manager(const string& paragraph = "", const string& path = "");
    int search(const string word) const;
    vector<string> get_rank()const;
    void set_rank();

    vector<pair<string, int>> get_sorted() const;
    void set_sorted();

    bool startsWith(const string& prefix) const;
    void addWord(const string& word);
    bool isCorrect(const string& word);
    string autoCorrect(const string& word);
    vector<string> autoComplete(const string& prefix);

private:
    Words words;
    Checker manager_checker;
    vector<pair<string,int>> manager_words;
    vector<string> mananger_rank;
};
#endif // MANAGER_HPP

