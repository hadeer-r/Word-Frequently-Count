#ifndef UPLOAD_TEXT_HPP
#define UPLOAD_TEXT_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef unordered_map<string, int> wordMap;
typedef vector<string> vecRank;

class UploadText
{

private:
    int count;
    wordMap words;
    vecRank rank;

public:
    UploadText() = default;

    //_________________methods_________________//
    void read_file(string path);
    void read_paragraph(string paragraph);
    wordMap get_wordsMap();
    vecRank get_wordsRank();

    void from_line_to_words(string line);

    /*
     * write in file : updating text in file.txt
     * Or, make new file for user to save his paragraph
     */
    void write_inFile(string path);

    //_________________utilities_________________//
    string delete_pun(string word);
    bool is_valid_path(string path);
    bool is_pun(char ch);
};

#endif