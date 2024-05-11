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
    Manager(const string& paragraph="");
    int search(const string word);
    string get_rank(string paragraph);
    void set_rank(string paragraph);

    string get_sorted(string paragraph) ;
    void set_sorted(string paragraph);

    void addWord(const string& word);
    string autoCorrect(const string& word);
    string autoWComplete(const string& prefix,int idx);
    void updateTextInFile(string path,string paragraph);
    string makeLine(string word,int freq,bool right);

private:
    Words words;
    Checker manager_checker;
    vector<pair<string,int>> manager_words;
    vector<string> mananger_rank;
    UploadText file_manager;
};
#endif // MANAGER_HPP

