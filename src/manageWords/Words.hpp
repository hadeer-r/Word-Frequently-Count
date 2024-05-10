#ifndef WORDS_HPP
#define WORDS_HPP
#include <unordered_map>
#include <vector>
#include "string"
#include "binary_search_tree.hpp"
#include "../manageText/upload_text.hpp"
using namespace std;

class Words {
private:
    unordered_map<string, int>wordFrequencies;
    BinarySTree treeWord;
    UploadText myFile;
public:
    Words(string paragraph, string path);

    int search(const string word) const;

    vector<string> rank();

    vector<pair<string,int>> sorted();

};

#endif // WORDS_H
