#include "manager.h"
#include <sstream>
#include <unordered_map>
Manager ::Manager(const string& paragraph)
    : words(paragraph),
      manager_checker()
{
    set_sorted(paragraph);
    set_rank(paragraph);
}

int Manager::search(const string word)
{
    return words.search(word);
}

string Manager::get_rank(string paragraph)
{
    set_rank(paragraph);
    string ranking="";
    for(int i=0;i<(int)mananger_rank.size();++i){
        ranking+=makeLine(mananger_rank[i],i+1,false);
    }
    return ranking;
}
void Manager::set_rank(string paragraph)
{
    Words temp(paragraph);
    words=temp;
    this->mananger_rank = words.rank();
}

string Manager::get_sorted(string paragraph)
{
    UploadText mytext;
    mytext.read_paragraph(paragraph);
    unordered_map<string,int> myFreq=mytext.get_wordsMap();
    string sorted_freq="";
    for(const auto & par:myFreq){
        sorted_freq+=makeLine(par.first,par.second,true);
    }
    return sorted_freq;
}

void Manager::set_sorted(string paragraph)
{
    if(paragraph!="")
    words.updateMap(paragraph);
    this->manager_words = words.sorted();
}

void Manager::addWord(const string &word)
{
    manager_checker.addWord(word);
}

string Manager::autoWComplete(const string &prefix,int idx)
{
    vector<string> wordsComplete= manager_checker.autoComplete(prefix);
    cout<<wordsComplete[idx];
    return wordsComplete[idx];
}

void Manager::updateTextInFile(string path, string paragraph)
{
    file_manager.write_inFile(path,paragraph);
}

string Manager::makeLine(string word, int freq, bool right)
{
    ostringstream oss;

    if(right)
    {
        oss<<word;
        oss<<" : ";
        oss<<freq;
        oss<<"\n";
    }
    else {
        oss<<freq;
        oss<<" : ";
        oss<<word;
        oss<<"\n";
    }
    return oss.str();
}
