#ifndef MANAGER_HPP
#define MANAGER_HPP
#pragma once
#include <string>
#include <vector>
#include <utility>
#include "../manageWords/Words.hpp"
#include "trie.h"
#include "Checker.h"
#include <unordered_map>
#include <iostream>
using namespace std;

class Manager
{
public:
  Manager(const string &paragraph = "", const string &path = "");
  int search(const string word) const;
  vector<string> rank(vector<string> vecRank);
  vector<pair<string, int>> sorted() const;
  bool startsWith(const string &prefix) const;
  void addWord(const string &word);
  bool isCorrect(const string &word);
  string autoCorrect(const string &word);
  bool autoComplete(const string &prefix);
  // text
  void read_file(string path);
  void read_paragraph(string paragraph);
  wordMap get_wordsMap();
  vecRank get_wordsRank();
  void from_line_to_words(string line);

private:
  Words words;
  Checker checker;
  wordMap words;
  vecRank rank;
};
#endif // MANAGER_HPP