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

class Manager
{
public:
    Manager(const string& paragraph = "", const string& path = "");
    int search(const string word) const;
    vector<string> rank(vector<string> vecRank);
    vector<pair<string, int>> sorted(vector<pair<string, int>> wordSort) const;
    bool startsWith(const string& prefix) const;
    void addWord(const string& word);
    bool isCorrect(const string& word);
    string autoCorrect(const string& word);
    bool autoComplete(const string& prefix);

        // text
    void read_file(string path);
    void read_paragraph(string paragraph);
    unordered_map<string,int> get_wordsMap();
    vector<string> get_wordsRank();
    void from_line_to_words(string line);

private:
    Words words;
    Checker manager_rank;
    unordered_map<string,int> manager_words;
    vector<string> mananger_rank;
    UploadText uploadText;
};
#endif // MANAGER_HPP



// manager constructor
















