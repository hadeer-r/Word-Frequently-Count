#include "trie.h"
#include"trienode.h"
#include"trie.h"
trie::trie() {
    root = new trieNode();
}

void trie::insert(const string& word) {
    trieNode* current = root;
    for (char c : word) {

        if (current->children.count(c) == 0) {

            current->children[c] = new trieNode();
        }

        current = current->children[c];
    }

    current->EndOfWord = true;
}
 void trie:: readWordsFromFileAndInsert(const string& path) {
       ifstream my_file(path);
    if (!my_file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string word;
    while (my_file >> word) {
        insert(word);
    }

   my_file.close();
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
bool trie:: startsWith(const string& prefix) const {
    trieNode* current = root;
    for (char c : prefix) {
        if (current->children.count(c) == 0) {
            return false;
        }
        current = current->children[c];
    }
    return true;
}


void trie:: dfs(trieNode* node, const string& prefix, vector<string>& suggestions) const {
    if (node->EndOfWord) {
        suggestions.push_back(prefix);
    }
    for (const auto& child : node->children) {
        dfs(child.second, prefix + child.first, suggestions);
    }
}
