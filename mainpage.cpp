#include "mainpage.h"
#include "ui_mainpage.h"

mainPage::mainPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainPage)
{
    ui->setupUi(this);
}

mainPage::~mainPage()
{
    delete ui;
}
