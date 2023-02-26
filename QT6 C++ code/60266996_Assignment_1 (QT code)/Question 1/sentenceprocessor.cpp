#include "sentenceprocessor.h"
#include "ui_sentenceprocessor.h"
#include <QMessageBox>
#include <algorithm>
#include <string>
#include <QInputDialog>
#include <QDir>

SentenceProcessor::SentenceProcessor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SentenceProcessor)
{
    ui->setupUi(this);
}
void test(){};

int SentenceProcessor::getWordNumber(QString string){
int count; //qDebug() <<

count = string.count(QLatin1Char(' '))+1;
return count;

};

void SentenceProcessor::getVowelNumber(QString string)
{
    int vowels;

    vowels = string.count(QLatin1Char('a'))+string.count(QLatin1Char('e'))+string.count(QLatin1Char('i'))+string.count(QLatin1Char('o'))+string.count(QLatin1Char('u')) ;

    QMessageBox msgBox;
    msgBox.setText("Number of vowels: "+QVariant(vowels).toString());
    msgBox.exec();

};

void SentenceProcessor::isReversible(QString string)
{
    QStringList stringCopy = string.split(' ');
    QStringList revString = string.split(' ');
//        QVector<QString> vect(5);

    std::reverse(revString.begin(), revString.end());

    if (stringCopy == revString)
    {
        QMessageBox msgBox;
        msgBox.setText("Is reversible");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Is not reversible");
        msgBox.exec();
    }

};

void SentenceProcessor::wordsReversed(QString string)
{
    QStringList revString = string.split(' ');
    std::reverse(revString.begin(), revString.end());

    QMessageBox msgBox;
    msgBox.setText("Reversed: "+QVariant(revString.join(' ')).toString());
    msgBox.exec();
};

void SentenceProcessor::formatSentence(QString string)
{

    string.replace(0, 1, string[0].toUpper());
    int count;
    count = string.count(QLatin1Char('.'));

    if (count == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Formatted: "+string+".");
        msgBox.exec();;
    }

    else
    {
    QMessageBox msgBox;
    msgBox.setText("Formatted: "+string);
    msgBox.exec();
    }

};


SentenceProcessor::~SentenceProcessor()
{
    delete ui;
}



void SentenceProcessor::on_pushButton_clicked()
{

    bool ok;
    SentenceProcessor w;

QString text = QInputDialog::getText(0, ("QInputDialog::getText()"),
                                     ("Sentence:"), QLineEdit::Normal,
                                     QDir::home().dirName(), &ok);


int num = w.getWordNumber(text);
if (num<2)
{
    QMessageBox msgBox;
    msgBox.setText("Too few words entered. Please re-enter.");
    msgBox.exec();
}

else
{
    QMessageBox msgBox;
    msgBox.setText("Number of words: "+QVariant(num).toString());
    msgBox.exec();

    w.getVowelNumber(text);
    w.isReversible(text);
    w.wordsReversed(text);
    w.formatSentence(text);
}
 w.show();

}

