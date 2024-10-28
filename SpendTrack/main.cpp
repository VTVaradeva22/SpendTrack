#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QPropertyAnimation>
#include <QStackedWidget>



class LoginPage : public QWidget{
public:
    LoginPage(QWidget *parent = nullptr) : QWidget(parent){
        QVBoxLayout *layout = new QVBoxLayout(this);



        QLabel *loginLabel = new QLabel("Create an Account",this);
        QFont titleFont("Times New Roman",24,QFont::Bold,true);
        loginLabel->setFont(titleFont);
        loginLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(loginLabel);

    }
};







class NavBar : public QWidget {
public:
    NavBar(QWidget *parent = nullptr) : QWidget(parent) {
        // Градиентен фон за навигационната лента, насочен вертикално
        this->setStyleSheet("background: qradialgradient(cx:0.5, cy:0.5, radius: 1.0, "
                            "fx:0.5, fy:0.5, stop:0 rgba(173, 255, 179, 255), stop:1 rgba(200, 255, 200, 0));");
        this->setFixedHeight(80);

        // Основен layout на навигационната лента
        QHBoxLayout *navLayout = new QHBoxLayout(this);
        navLayout->setContentsMargins(20, 0, 20, 0);

        // Заглавие на приложението
        QLabel *appName = new QLabel("SpendTrack", this);
        QFont titleFont("Times New Roman", 28, QFont::Bold, true);
        appName->setFont(titleFont);
        appName->setStyleSheet("color: black;");

        // Стил за бутоните на навигационната лента
        QString navButtonStyle = "QPushButton { background-color: transparent; color: black; padding: 10px; font-size: 18px; font-family: 'Times New Roman'; font-style: italic; border: none; }"
                                 "QPushButton:hover { color: #BDFF8B; font-weight: bold; }";

        // Създаване на бутони
        QPushButton *homeButton = new QPushButton("Home");
        QPushButton *incomeButton = new QPushButton("Income");
        QPushButton *expenseButton = new QPushButton("Expenses");
        QPushButton *budgetButton = new QPushButton("Budget");
        QPushButton *reportButton = new QPushButton("Reports");

        // Прилагане на стил към бутоните
        homeButton->setStyleSheet(navButtonStyle);
        incomeButton->setStyleSheet(navButtonStyle);
        expenseButton->setStyleSheet(navButtonStyle);
        budgetButton->setStyleSheet(navButtonStyle);
        reportButton->setStyleSheet(navButtonStyle);

        // Добавяне на елементи в навигационната лента
        navLayout->addWidget(appName);
        navLayout->addStretch();
        navLayout->addWidget(homeButton);
        navLayout->addWidget(incomeButton);
        navLayout->addWidget(expenseButton);
        navLayout->addWidget(budgetButton);
        navLayout->addWidget(reportButton);
    }
};

class MainPage : public QWidget {
    QStackedWidget *stackedWidget;


public:

    MainPage(QStackedWidget *stackedWidget, QWidget *parent = nullptr) : QWidget(parent), stackedWidget(stackedWidget) {
        // Настройки на фона за основната страница с плавен преливащ градиент
        this->setStyleSheet("background: qradialgradient(cx:0.5, cy:0.5, radius: 1.0, "
                            "fx:0.5, fy:0.5, stop:0 rgba(173, 255, 179, 255), stop:1 rgba(200, 255, 200, 0));");

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // Заглавие „Welcome to SpendTrack“
        QLabel *welcomeLabel = new QLabel("Welcome to SpendTrack", this);
        QFont contentFont("Times New Roman", 24, QFont::Bold, true);
        welcomeLabel->setFont(contentFont);
        welcomeLabel->setStyleSheet("color: black;");
        welcomeLabel->setAlignment(Qt::AlignCenter);

        // Бутон за логин или регистрация
        QPushButton *loginButton = new QPushButton("Log In / Sign Up", this);
        QFont buttonFont("Times New Roman", 18, QFont::Bold);
        loginButton->setFont(buttonFont);
        loginButton->setStyleSheet("background-color: #BDFF8B; color: black; padding: 10px 20px; border-radius: 5px;");
        loginButton->setCursor(Qt::PointingHandCursor);

        // Connect -> след натискане на бутоона да ни прехвърли към LoginPage

        connect(loginButton,&QPushButton::clicked,this,&MainPage::onLoginButtonClicked);

        // Добавяне на елементи
        mainLayout->addStretch();
        mainLayout->addWidget(welcomeLabel, 0, Qt::AlignCenter);
        mainLayout->addWidget(loginButton, 0, Qt::AlignCenter);
        mainLayout->addStretch();

        // Анимация за заглавието
        QPropertyAnimation *animation = new QPropertyAnimation(welcomeLabel, "opacity");
        animation->setDuration(2000);
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->start();
    }

private slots:
    void onLoginButtonClicked(){
        stackedWidget->setCurrentIndex(1);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Създаване на главния прозорец
    QWidget window;
    QVBoxLayout *windowLayout = new QVBoxLayout(&window);
    windowLayout->setContentsMargins(0, 0, 0, 0);

    // Добавяне на навигационната лента в горната част
    NavBar *navBar = new NavBar();
    windowLayout->addWidget(navBar);


private slots:
    void onLoginButtonClicked(){
        stackedWidget->setCurrentIndex(1);
    }
};


    // Основна страница
    MainPage *mainPage = new MainPage(stackedWidget);
    LoginPage *loginPage = new LoginPage();


    stackedWidget->addWidget(mainPage);
    stackedWidget->addWidget(loginPage);


    // Настройки на прозореца
    window.setWindowTitle("SpendTrack - Elegant Navigation Bar Example");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
