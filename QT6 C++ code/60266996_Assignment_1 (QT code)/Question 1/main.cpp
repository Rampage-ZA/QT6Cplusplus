#include "sentenceprocessor.h"
#include <QApplication>
#include <QInputDialog>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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




    return a.exec();
}

