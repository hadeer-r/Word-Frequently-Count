#include "manager.h"
#include <iostream>
using namespace std;

Manager ::Manager(const string &paragraph, const string &path) : words(paragraph, path) {}

int Manager::search(const string word) const {
    return words.search(word)}

vector<string> Manager::rank(vector<string> vecRank)
{
  return words.rank(vecRank);
}

vector<pair<string, int>> Manager::sorted() const
{
  return words.sorted();
}

bool Manager::startsWith(const string &prefix) const
{
  return false;
}
void Manager::addWord(const string &word)
{
  checker.addWord(word);
}
bool Manager::isCorrect(const string &word)
{
  return checker.isCorrect(word);
}
string Manager::autoCorrect(const string &word)
{
  return checker.autoCorrect(word);
}
bool Manager::autoComplete(const string &prefix)
{
  return checker.autoComplete(prefix);
}
void Manager ::read_file(string path)
{
  UploadTex.read_file(path)
}
void Manager::read_paragraph(string paragraph)
{
  UploadText::read_paragraph(paragraph)
}
void Manager::from_line_to_words(string line)
{
  UploadText::from_line_to_words(line)
}
