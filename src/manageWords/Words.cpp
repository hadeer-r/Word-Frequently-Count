#include "Words.hpp"
#include <iostream>
#include<unordered_map>
using namespace std;

Words::Words(string paragraph = "", string path = "")
{
    if (paragraph != "") {
        myFile.read_paragraph(paragraph);
    }
    else if (path != "") {
        myFile.read_file(path);
    }
    wordFrequencies = myFile.get_wordsMap();
}

int Words::search(const string word)const {
    auto it = wordFrequencies.find(word);
    return it->second;
}

vector<string> Words::rank() {
    vector<string> words_rank = myFile.get_wordsRank();
    return words_rank;
}


vector<pair<string, int>> Words::sorted() {
    treeWord.fill_tree(wordFrequencies);
    vector<pair<string,int>> wordSort=treeWord.sorted();
    return wordSort;
}
