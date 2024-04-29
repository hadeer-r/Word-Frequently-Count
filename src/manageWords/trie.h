#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>
#include <unordered_map>
#include "trienode.h"
using namespace std;
class trie {
private:
    trieNode* root;

public:
    trie();

    void insert(const string& word);

    bool search(const string& word);

    bool startsWith(const string& prefix);
};

#endif // TRIE_H
