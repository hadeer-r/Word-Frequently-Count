#ifndef WORDS_HPP
#define WORDS_HPP
#include <unordered_map>
#include <vector>
#include"string"
#include"upload_text.hpp"
#include"binary_search_tree.hpp"
using namespace std;


class Words {
private:
    unordered_map<string, int>wordFrequencies;
    BinarySTree treeWord;
    UploadText myFile;
public:
    Words(string paragraph, string path);

    int search(const string word) const;

    vector<string> rank(vector<string> vecRank);

    vector<pair<string,int>> sorted(vector<pair<string, int>> wordSort);

};








#endif // WORDS_H