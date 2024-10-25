#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QDialog>

namespace Ui {
class mainPage;
}

class mainPage : public QDialog
{
    Q_OBJECT

public:
    explicit mainPage(QWidget *parent = nullptr);
    ~mainPage();

private:
    Ui::mainPage *ui;
};

#endif // MAINPAGE_H
