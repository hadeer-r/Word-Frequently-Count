#ifndef CHECKER_H
#define CHECKER_H
#include <string>
#include<stack>
#include "trie.h"
using namespace std;
class Checker
{

private:
    trie Trie;
    trieNode*root;
public:
    Checker()=default;

    void addWord(const string& word);
    bool isCorrect(const string& word);
    string autoCorrect(const string& word);
    vector<string> autoComplete(const string& prefix) const;

    bool startsWith(const string& prefix) const;
    void dfs(trieNode* node, const string& prefix, vector<string>& suggestions) const;

};

#endif // CHECKER_H
