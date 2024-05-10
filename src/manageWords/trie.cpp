#include "trie.h"
#include <fstream>
#include <iostream>
using namespace std;
trieNode::trieNode()
{
    EndOfWord = false;
}
trie::trie()
{
    root = new trieNode();
    readWordsFromFileAndInsert("dictionary.txt");
}

void trie::insert(const string &word)
{
    trieNode *current = root;
    for (char c : word)
    {

        if (current->children.count(c) == 0)
        {

            current->children[c] = new trieNode();
        }

        current = current->children[c];
    }
    current->EndOfWord = true;
}
void trie::readWordsFromFileAndInsert(const string &path)
{
    ifstream my_file(path);
    if (!my_file.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string word;
    while (my_file >> word)
    {
        insert(word);
    }

    my_file.close();
}

bool trie::startsWith(const string &prefix) const
{
    trieNode *current = root;
    for (char c : prefix)
    {
        if (current->children.count(c) == 0)
        {
            return false;
        }
        current = current->children[c];
    }
    return true;
}

void trie::dfs(trieNode *node, const string &prefix, string current_word, vector<string> &suggestions) const
{
    if (node->EndOfWord)
    {
        suggestions.push_back(prefix + current_word);
    }

    for (auto &child : node->children)
    {

        dfs(child.second, prefix, current_word + child.first, suggestions);
    }
}
trie::~trie()
{
    // Call a helper function to recursively delete all nodes starting from the root
    deleteSubtree(root);
}

void trie::deleteSubtree(trieNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    // Recursively delete child nodes
    for (auto it = node->children.begin();it!=node->children.end();++it)
    {
        deleteSubtree(it->second);
    }

    // Delete the current node
    delete node;
}
