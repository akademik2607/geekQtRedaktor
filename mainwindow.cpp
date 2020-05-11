#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myparserspecsymbols.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::permutationOfSpecSymbols(QString str, const QString &begin, const QString &end){
    int indB;
    int indE;

    if(str.isEmpty()) return;
    MyParserSpecsymbols myParser;
    indB = myParser.searcher(str, begin, 0);
    indE = myParser.searcher(str, end, (indB + begin.length()));
    if(indB == -1 || indE == -1) return;
     QString makr = str.mid(indB + 2, indE - indB - 2);
     QString result = myParser.makrPermutation(str, makr, indB, indE);
     ui->plainTextEdit->setPlainText(result);
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString str = ui->plainTextEdit->toPlainText();
    permutationOfSpecSymbols(str, "#@", "@");
}
