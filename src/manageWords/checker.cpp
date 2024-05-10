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
        string Correction = word;
        int minEdits = word.length();
        for (int i = 0; i < word.length(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (word[i] != c) {
                    string correctedWord = word;
                    correctedWord[i] = c;
                    int edits = 1;

                    if (isCorrect(correctedWord)) {
                        return correctedWord;
                    } else {

                        correctedWord[i] = toupper(c);
                        if (isCorrect(correctedWord) && edits < minEdits) {
                            Correction = correctedWord;
                            minEdits = edits;
                        }
                    }
                }
            }
            string correctedWord = word.substr(0, i) + word.substr(i + 1);
            int edits = 1;
            if (isCorrect(correctedWord) && edits < minEdits) {
            Correction = correctedWord;
                minEdits = edits;
            }
        }

        return Correction;
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
