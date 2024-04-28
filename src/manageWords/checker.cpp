#include "checker.h"
Checker::Checker() {}

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

bool Checker::autoComplete(const string& prefix) {
    return Trie.startsWith(prefix);
}
