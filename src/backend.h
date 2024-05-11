#ifndef BACKEND_H
#define BACKEND_H
#include "manager/manager.h"
#include <QObject>
#include <QtQml>
#include <QString>
#include <string>
#include <iostream>

class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
private:
    Manager manager;
public:
    explicit Backend(QObject *parent = nullptr);
    Q_INVOKABLE void getTextFromFile(QString path);
    Q_INVOKABLE void updateTextUser(QString path,QString paragraph);
    Q_INVOKABLE void sortFrequency(QString currentSort,QString paragraph);
    Q_INVOKABLE void rankWords(QString currentRank,QString paragraph);
    Q_INVOKABLE void autoCompletionWordds(QString paragraph);
    Q_INVOKABLE void searchWord(QString word);

signals:
    void getTextFromFileEmitted(QString text);
    void updateTextUserEmitted(QString path,QString paragraph);
    void sortFrequencyEmitted(QString currentSort,QString paragraph);
    void rankWordsEmitted(QString currentRank,QString paragraph);
    void autoCompletionWorddsEmitted(QString paragraph);
    void searchWordEmitted(int freq);

};

#endif // BACKEND_H

