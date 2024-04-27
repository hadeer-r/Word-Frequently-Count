#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<pair<string, int>> vecPair;
typedef unordered_map<string, int> wordMap;

struct TreeNode
{
    int counter{};
    string word{""};
    TreeNode *right{};
    TreeNode *left{};

    TreeNode(int counter, string word) : counter(counter), word(word) {}
    ~TreeNode() {}
};

class BinarySTree
{

public:
    BinarySTree() = default;

    void insert(string word, int counter);

    TreeNode *search(const pair<int, string> &word) const;

    void deleteNode(string word);

    void fill_tree(const wordMap &words);

    vecPair sorted() const;

    ~BinarySTree();

private:
    TreeNode *root{};

    TreeNode *search(const pair<int, string> &word, TreeNode *root) const;

    vecPair sorted(TreeNode *root) const;

    void deleteNode(string word, TreeNode *root);

    void insert(string word, int counter, TreeNode *root);

    void destroyRecursive(TreeNode *root);
};

#endif
