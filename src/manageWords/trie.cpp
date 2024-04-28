#include "trie.h"
#include"trienode.h"
trie::trie() {
    root = new trieNode();
}

void trie::insert(const string& word) {
    trieNode* current = root;
    for (char c : word) {
        bool found = false;
        for (auto& child : current->children) {
            if (child.first == c) {
                current = child.second;
                found = true;
                break;
            }
        }
        if (!found) {
            trieNode* newNode = new trieNode();
            current->children.push_back(make_pair(c, newNode));
            current = newNode;
        }
    }
    current->EndOfWord = true;
}

bool trie::search(const string& word) {
    trieNode* current = root;
    for (char c : word) {
        bool found = false;
        for (auto& child : current->children) {
            if (child.first == c) {
                current = child.second;
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return current->EndOfWord;
}

bool trie::startsWith(const string& prefix) {
    trieNode* current = root;
    for (char c : prefix) {
        bool found = false;
        for (auto& child : current->children) {
            if (child.first == c) {
                current = child.second;
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}
