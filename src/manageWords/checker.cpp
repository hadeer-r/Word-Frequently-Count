#include "checker.h"
#include "trie.h"

Checker::Checker() : Trie() {}

void Checker::addWord(const string &word)
{
    Trie.insert(word);
}

vector<string> Checker::autoCorrect(const string &word)
{
    vector<string> suggestions;
    if (Trie.search(word))
        return suggestions;
    string prefix = "";
    for (size_t i = 0; i < word.size(); ++i)
    {
        if (i == 0)
            prefix += word[i];
        else
        {
            cout << prefix << "\n";
            if (Trie.startsWith(prefix) && !Trie.startsWith(prefix + word[i]))
            {
                suggestions = autoComplete(prefix);
                break;
            }

            else
            {
                prefix += word[i];
            }
            if (i == (int)word.size() - 1 && Trie.startsWith(prefix))
            {
                suggestions = autoComplete(prefix);
            }
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
}
