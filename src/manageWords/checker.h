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

<<<<<<< HEAD
    void addWord(const string &word);
    vector<string> autoCorrect(const string &word);
    vector<string> autoComplete(const string &prefix) const;
=======
    void addWord(const string& word);
   vector<string> autocorrect(const string& word) const;
    vector<string> autoComplete(const string& prefix) const;

>>>>>>> f7eb5e1f9344b3c79e766f2874e2cd763af558a8
};

#endif // CHECKER_H
