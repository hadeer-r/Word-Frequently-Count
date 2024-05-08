#ifndef CHECKER_H
#define CHECKER_H
#include <string>
#include<stack>
#include "trie.h"
using namespace std;
class Checker: public trie
{

private:
    trie Trie;

public:
    Checker()=default;

    void addWord(const string& word);
    bool isCorrect(const string& word);
    string autoCorrect(const string& word);
    vector<string> autoComplete(const string& prefix) const;

<<<<<<< HEAD
    bool startsWith(const string& prefix) const;
    void dfs(trieNode* node, const string& prefix, vector<string>& suggestions) const;
=======
>>>>>>> 3fa6f30514190477f9d109a8e8f11431cff386ee

};

#endif // CHECKER_H
