#ifndef SENTENCEPROCESSOR_H
#define SENTENCEPROCESSOR_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class SentenceProcessor; }
QT_END_NAMESPACE

class SentenceProcessor : public QMainWindow
{
    Q_OBJECT

public:
    SentenceProcessor(QWidget *parent = nullptr);
    ~SentenceProcessor();

    int getWordNumber(QString string);
    void getVowelNumber(QString string);
    void isReversible(QString string);
    void wordsReversed(QString string);
    void formatSentence(QString string);
//    QString string = "hello world";


private slots:
    void on_pushButton_clicked();

private:
    Ui::SentenceProcessor *ui;

};
#endif // SENTENCEPROCESSOR_H
