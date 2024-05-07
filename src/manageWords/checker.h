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
<<<<<<< HEAD
=======
    bool startsWith(const string& prefix) const;
    void dfs(trieNode* node, const string& prefix, vector<string>& suggestions) const;

>>>>>>> ded845c798b63b91145a0f0c3e9b61c5950aeb40
};

#endif // CHECKER_H
