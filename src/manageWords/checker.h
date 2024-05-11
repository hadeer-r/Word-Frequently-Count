#ifndef CHECKER_H
#define CHECKER_H
#include <string>
#include <stack>
#include "trie.h"
using namespace std;
class Checker
{

private:
    trie Trie;

public:
    Checker();

    void addWord(const string &word);
    vector<string> autoCorrect(const string &word);
    vector<string> autoComplete(const string &prefix) const;
};

#endif // CHECKER_H
