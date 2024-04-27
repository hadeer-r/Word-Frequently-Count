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

vector<string> Words::rank(vector<string> vecRank) {
    vecRank = myFile.get_wordsRank();
    return vecRank;
}


vector<pair<string, int>> Words::sorted(vector<pair<string,int>> wordSort) {
    wordSort = treeWord.sorted();
    return wordSort;
}
