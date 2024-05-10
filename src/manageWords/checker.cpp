#include "checker.h"
#include "trie.h"

Checker::Checker() : Trie() {}

void Checker::addWord(const string &word)
{
    Trie.insert(word);
}

bool Checker:: isCorrect(const string& word) {
    return Trie.search(word);
}

string Checker::autoCorrect(const string& word) {
    string correctedWord = word;
    for (char& c : correctedWord) {
        if (isupper(c)) {
            c = tolower(c);
        }
    }

    if (isCorrect(correctedWord)) {
        return correctedWord;
    }

    for (int i = 0; i < correctedWord.length(); ++i) {
        char originalChar = correctedWord[i];
        for (char c = 'a'; c <= 'z'; ++c) {
            if (correctedWord[i] != c) {
                correctedWord[i] = c;
                if (isCorrect(correctedWord)) {
                    return correctedWord;
                }
            }
        }
        correctedWord[i] = originalChar;
    }

    return word;
}

vector<string> Checker::autoComplete(const string &prefix) const
{
    trieNode *current = Trie.get_root();
    vector<string> suggestions;

    for (char c : prefix)
    {
        if (!current->children.count(c))
        {
            return suggestions;
        }
        current = current->children[c];
    }

    Trie.dfs(current, prefix, "", suggestions);
    return suggestions;
};
