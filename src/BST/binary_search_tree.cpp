#include "binary_search_tree.hpp"
#include <iostream>

//__________________methods__________________//

// insertion
void BinarySTree::insert(string word, int counter)
{
    if (!this->root)
    { // if my tree doesn't have any node, so create first node
        root = new TreeNode(counter, word);
        return;
    }
    insert(word, counter, this->root);
}
void BinarySTree::insert(string word, int counter, TreeNode *root)
{
    if (!root)
        return;
    if (counter >= root->counter)
    { // add in right of the node
        if (!root->right)
            root->right = new TreeNode(counter, word);
        else
            insert(word, counter, root->right);
    }
    // add in the left of node (counter of new word < current counter)
    else
    {
        if (!root->left)
            root->left = new TreeNode(counter, word);
        else
            insert(word, counter, root->left);
    }
}

// search in tree : return an object of tree node
TreeNode *BinarySTree::search(const pair<int, string> &word) const
{
    return search(word, this->root);
}
TreeNode *BinarySTree::search(const pair<int, string> &word, TreeNode *root) const
{
    if (!root)
        return nullptr;
    if (word.first == root->counter && word.second == root->word)
        return root;
    if (word.first >= root->counter)
        return search(word, root->right);
    return search(word, root->left);
}

// fill tree sorted from unordered map of words and their frequencies
void BinarySTree::fill_tree(const wordMap &words)
{
    for (auto it = words.begin(); it != words.end(); ++it)
    {
        insert(it->first, it->second);
    }
}

// deletion
void BinarySTree::deleteNode(string word, TreeNode *root)
{
}
void BinarySTree::deleteNode(string word)
{
}

/* (sorted method)
 * return a vector of pair<string,int> by traversal from right to left
 *  from highest frequency to lowest
 *
 */
vecPair BinarySTree::sorted() const
{
    return sorted(this->root);
}
vecPair BinarySTree::sorted(TreeNode *root) const
{
    static vecPair result;
    if (!root)
        return result;
    sorted(root->right);
    result.push_back({root->word, root->counter});
    sorted(root->left);
    return result;
}

//__________________Destructor__________________//
BinarySTree::~BinarySTree()
{
    destroyRecursive(root);
}
void BinarySTree::destroyRecursive(TreeNode *root)
{
    if (!root)
        return;
    destroyRecursive(root->right);
    destroyRecursive(root->left);
    delete root;
}
