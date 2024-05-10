#include "checker.h"
#include "trie.h"

Checker::Checker() : Trie() {}

void Checker::addWord(const string &word)
{
    Trie.insert(word);
}

vector<string>Checker:: autocorrect(const string& word) const {
    vector<string> suggestions;
    string prefix = "";
    for (size_t i = 0; i < word.size(); ++i) {
        prefix += word[i];
        if (!Trie.startsWith(prefix)) {
            suggestions=autoComplete(prefix);
            break;
        }
    }
    return suggestions;
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
