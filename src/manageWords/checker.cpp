#include "checker.h"
#include"trie.h"

void Checker::addWord(const string& word) {
    Trie.insert(word);
}

bool Checker::isCorrect(const string& word) {
    return Trie.search(word);
}

string Checker::autoCorrect(const string& word) {
    string correctedWord = word;
    for (int i = 0; i < word.length(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (word[i] != c) {
                correctedWord[i] = c;
                if (isCorrect(correctedWord)) {
                    return correctedWord;
                }
            }
        }
        correctedWord[i] = word[i];
    }
    return word;
}
vector<string> Checker::autoComplete(const string& prefix) const {
<<<<<<< HEAD
    // // trieNode* current = this->root;
    // vector<string> suggestions;
    // if (!startsWith(prefix)) {
    //     return suggestions;
    // }

    // // dfs(current, prefix, suggestions);
    // // return suggestions;
}
=======
    trieNode*current = root;
    vector<string> suggestions;
    if (!startsWith(prefix)) {
        return suggestions;
    }

    dfs(current, prefix, suggestions);
    return suggestions;
};
>>>>>>> 3fa6f30514190477f9d109a8e8f11431cff386ee
