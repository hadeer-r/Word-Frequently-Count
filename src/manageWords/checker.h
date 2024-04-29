#ifndef CHECKER_H
#define CHECKER_H
#include <string>
#include "trie.h"
using namespace std;
class Checker
{

private:
    trie Trie;
public:
    Checker();

    void addWord(const string& word);

    bool isCorrect(const string& word);

    string autoCorrect(const string& word);

    bool autoComplete(const string& prefix);
};

#endif // CHECKER_H
