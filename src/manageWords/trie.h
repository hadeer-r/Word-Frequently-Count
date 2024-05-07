#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>
#include <unordered_map>
#include "trienode.h"
#include "../manageText/upload_text.hpp"
using namespace std;
class trie {
private:
    trieNode* root;

public:
    trie();
    trie( string path);

    void insert(const string& word);

    bool search(const string& word);

    bool startsWith(const string& prefix);
    void readWordsFromFileAndInsert(const string& path);
};

#endif // TRIE_H
