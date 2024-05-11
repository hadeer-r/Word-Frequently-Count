#include "Words.hpp"
#include <iostream>
#include<unordered_map>
using namespace std;

Words::Words(string paragraph)
{
    if (paragraph != "") {
        myFile.read_paragraph(paragraph);
    }

    wordFrequencies = myFile.get_wordsMap();
}

int Words::search(const string word)const {
    auto it = wordFrequencies.find(word);
    if(it==nullptr)
        return 0;
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

void Words::updateMap(string paragraph){
    myFile.read_paragraph(paragraph);
    wordFrequencies=myFile.get_wordsMap();
}


