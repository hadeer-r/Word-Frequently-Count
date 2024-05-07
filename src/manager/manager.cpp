#include "manager.h"

Manager ::Manager(const string &paragraph, const string &path)
    : words(paragraph, path),
      manager_checker()
{
    set_sorted();
    set_rank();
}

int Manager::search(const string word) const
{
    return words.search(word);
}

vector<string> Manager::get_rank() const
{
    return this->mananger_rank;
}
void Manager::set_rank()
{
    this->mananger_rank = words.rank();
}

vector<pair<string, int>> Manager::get_sorted() const
{
    return this->manager_words;
}
void Manager::set_sorted()
{
    this->manager_words = words.sorted();
}

bool Manager::startsWith(const string &prefix) const
{
    return false;
}
void Manager::addWord(const string &word)
{
    manager_checker.addWord(word);
}
bool Manager::isCorrect(const string &word)
{
    return manager_checker.isCorrect(word);
}

string Manager::autoCorrect(const string &word)
{
    return manager_checker.autoCorrect(word);
}

vector<string> Manager::autoComplete(const string &prefix)
{
    return manager_checker.autoComplete(prefix);
}
