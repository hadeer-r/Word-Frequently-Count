#include "checker.h"
#include "trie.h"

Checker::Checker() : Trie() {}

void Checker::addWord(const string &word)
{
    Trie.insert(word);
}

<<<<<<< HEAD
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
=======
vector<string>Checker:: autocorrect(const string& word) const {
    vector<string> suggestions;
    string prefix = "";
    for (size_t i = 0; i < word.size(); ++i) {
        prefix += word[i];
        if (!Trie.startsWith(prefix)) {
            suggestions=autoComplete(prefix);
            break;
>>>>>>> f7eb5e1f9344b3c79e766f2874e2cd763af558a8
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
