#include "upload_text.hpp"
#include <fstream>
#include <string>
#include <sstream>

//___________________Methods___________________//

void UploadText::read_file(string path)
{
    ifstream my_file(path);
    if (my_file.fail())
    {
        return;
    }

    string line{""};

    while (getline(my_file, line))
    {
        from_line_to_words(line);
    }
    my_file.close();
}

void UploadText::read_paragraph(string paragraph)
{
    istringstream iss{paragraph};
    string line;
    while (getline(iss, line))
    {
        from_line_to_words(line);
    }
}

void UploadText::from_line_to_words(string line)
{
    istringstream iss{line};

    string word;

    while (getline(iss, word, ' '))
    {
        if (is_pun(word[word.size() - 1]) || is_pun(word[0]))
            word = delete_pun(word);

        if (word == "")
            continue;

        if (this->words.count(word))
        {
            words[word]++;
        }
        else
        {
            words[word] = 1;
            rank.push_back(word);
        }
    }
}

wordMap UploadText::get_wordsMap()
{
    return words;
}

vecRank UploadText::get_wordsRank()
{
    return rank;
}


void UploadText::write_inFile(string path,string paragraph){
    ofstream my_file(path);
    if(my_file.fail())
    cout<<"can't open file\n";
    my_file<<paragraph<<"\n";
    my_file.close();
}

//_________________utilities_________________//

string UploadText::delete_pun(string word)
{
    string result{""};
    bool is_start = false,
         is_end = false;
    int sz = (int)word.size();
    for (int i = 0; i < sz; ++i)
    {
        if (isalpha(word[i]))
            is_start = true;
        if (is_start)

            result += word[i];
        if (i <= sz - 2 && isalpha(word[i]) && !isalpha(word[i + 1]))
        {
            break;
        }
    }
    return result;
}

bool UploadText::is_pun(char ch)
{
    return !isalpha(ch);
}
