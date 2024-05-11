#include "backend.h"
#include <QFile>
#include <QTextStream>
#include <vector>
#include <string>
#include "sstream"
using namespace std;
Backend::Backend(QObject *parent)
    : QObject{parent}
{}

void Backend::getTextFromFile(QString path)
{
    QString text="";
    if(path!="")
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Error opening file: " << file.errorString();
            return;
        }

        qDebug()<<path;
        QTextStream stream(&file);
        text = stream.readAll();

        string paragraph=text.toStdString();
        Manager temp_m(paragraph);
        manager=temp_m;
    }

    emit getTextFromFileEmitted(text);
}

void Backend::updateTextUser(QString path, QString paragraph)
{
    string st_path=path.toStdString();
    string st_paragaraph=paragraph.toStdString();
    if(path=="")
    {manager.updateTextInFile("../../file.txt",st_paragaraph);
        qDebug() <<"Iam in new file";
    }
    else
        manager.updateTextInFile(st_path,st_paragaraph);
    emit updateTextUserEmitted(path,paragraph);

}

void Backend::sortFrequency(QString currentSort,QString paragraph)
{

    string st_paragraph=paragraph.toStdString();
    string st_sort= manager.get_sorted(st_paragraph);
    QString sort=QString::fromStdString(st_sort);
    currentSort=sort;
    emit sortFrequencyEmitted(currentSort,paragraph);
}

void Backend::rankWords(QString currentRank,QString paragraph)
{
    string st_paragraph=paragraph.toStdString();
    string st_rank= manager.get_rank(st_paragraph);
    QString rank=QString::fromStdString(st_rank);
    currentRank=rank;
    emit rankWordsEmitted(currentRank,paragraph);
}

void Backend::autoCompletionWordds(QString paragraph)
{
    if (!paragraph.isEmpty())
    {
        istringstream iss(paragraph.toStdString());
        vector<string> words;
        string word;

        // Read all words in the paragraph
        while (iss >> word) {
            words.push_back(word);
        }

        // Replace the last word with auto-completed word
        if (!words.empty()) {
            string new_word = manager.autoWComplete(words.back(), 0);
            words.back() = new_word;
        }

        // Join words back into paragraph
        ostringstream oss;
        for (size_t i = 0; i < words.size(); ++i) {
            oss << words[i];
            if (i < words.size() - 1) {
                oss << " ";
            }
        }

        paragraph = QString::fromStdString(oss.str());
    }

    emit autoCompletionWorddsEmitted(paragraph);
}

void Backend::searchWord(QString word)
{
    int freq=manager.search(word.toStdString());
    emit searchWordEmitted(freq);
}

