#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>
#include <unordered_map>
#include "../manageText/upload_text.hpp"
using namespace std;

class trieNode
{
public:
    trieNode();
    unordered_map<char, trieNode *> children;
    bool EndOfWord;
};
class trie
{
protected:
    trieNode *root;

public:
    trie();
    void insert(const string &word);
    bool startsWith(const string &prefix) const;
    void dfs(trieNode *node, const string &prefix, string current_word, vector<string> &suggestions) const;
    void readWordsFromFileAndInsert(const string &path);
    trieNode *get_root() const { return root; }
    bool search(const string &word);
    void deleteSubtree(trieNode *node);
    ~trie();
};

#endif // TRIE_H
