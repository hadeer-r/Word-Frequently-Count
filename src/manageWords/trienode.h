#ifndef TRIENODE_H
#define TRIENODE_H
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class trieNode
{
public:
    trieNode();
    vector<pair<char, trieNode*>> children;
    bool EndOfWord;
};

#endif // TRIENODE_H
