#include "checker.h"
#include "trie.h"

Checker::Checker() : Trie() {}

void Checker::addWord(const string &word)
{
    Trie.insert(word);
}

bool Checker::isCorrect(const string &word)
{
    return Trie.search(word);
}

string Checker::autoCorrect(const string &word)
{
    string correctedWord = word;
    bool foundCorrection = false;
    for (int i = 0; i < word.length(); ++i)
    {


        for (char c = 'a',u='A'; c <= 'z'; ++c,++u)
        {
            
            if (word[i] != c&&word[i])
            {
                correctedWord[i] = c;
                if (isCorrect(correctedWord))
                {
                    return correctedWord;
                }
            }
        }
        correctedWord[i] = word[i];
    }
    return correctedWord;
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
