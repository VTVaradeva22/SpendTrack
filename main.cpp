#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QPropertyAnimation>
#include <QStackedWidget>
#include <QFormLayout>
#include <QLineEdit>

class BudgetPage : public QWidget {
public:
    BudgetPage(QWidget* parent = nullptr) : QWidget(parent) {
        this->setStyleSheet("background: qradialgradient(cx:0.5, cy:0.5, radius: 1.0, "
                            "fx:0.5, fy:0.5, stop:0 rgba(173, 255, 179, 255), stop:1 rgba(200, 255, 200, 0));");

        QVBoxLayout* mainLayout = new QVBoxLayout(this);

        QLabel* titleLabel = new QLabel("Budget", this);
        titleLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 24px; font-weight: bold; color: black;");
        titleLabel->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(titleLabel);
    }
};
class ExpensesPage : public QWidget {
public:
    ExpensesPage(QWidget* parent = nullptr) : QWidget(parent) {
        this->setStyleSheet("background: qradialgradient(cx:0.5, cy:0.5, radius: 1.0, "
                            "fx:0.5, fy:0.5, stop:0 rgba(173, 255, 179, 255), stop:1 rgba(200, 255, 200, 0));");

        QVBoxLayout* mainLayout = new QVBoxLayout(this);

        QLabel* titleLabel = new QLabel("Expenses", this);
        titleLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 24px; font-weight: bold; color: black;");
        titleLabel->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(titleLabel);

        QFormLayout* formLayout = new QFormLayout;

        dateInput = new QLineEdit(this);
        categoryInput = new QLineEdit(this);
        amountInput = new QLineEdit(this);

        dateInput->setPlaceholderText("Enter date (e.g., 2023-11-01)");
        categoryInput->setPlaceholderText("Enter category (e.g., Food)");
        amountInput->setPlaceholderText("Enter amount (e.g., 200)");

        dateInput->setStyleSheet("font-family: 'Times New Roman'; font-size: 18px;");
        categoryInput->setStyleSheet("font-family: 'Times New Roman'; font-size: 18px;");
        amountInput->setStyleSheet("font-family: 'Times New Roman'; font-size: 18px;");

        formLayout->addRow("Date:", dateInput);
        formLayout->addRow("Category:", categoryInput);
        formLayout->addRow("Amount:", amountInput);

        mainLayout->addLayout(formLayout);

        QPushButton* addButton = new QPushButton("Add Expense", this);
        addButton->setStyleSheet("background-color: red; color: white; font-family: 'Times New Roman'; font-weight: bold;");
        mainLayout->addWidget(addButton);

        connect(addButton, &QPushButton::clicked, this, &ExpensesPage::addExpense);

        expensesLayout = new QVBoxLayout();
        mainLayout->addLayout(expensesLayout);

        totalLabel = new QLabel("Total Expenses: 0", this);
        totalLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 18px; font-weight: bold; color: black;");
        mainLayout->addWidget(totalLabel);

        chartLabel = new QLabel(this);
        mainLayout->addWidget(chartLabel);

        updateChart();
    }

private slots:
    void addExpense() {
        QString date = dateInput->text();
        QString category = categoryInput->text();
        QString amount = amountInput->text();

        bool ok;
        double amountValue = amount.toDouble(&ok);
        if (date.isEmpty() || category.isEmpty() || amount.isEmpty() || !ok || amountValue <= 0) {
            return;
        }

        QHBoxLayout* expenseLayout = new QHBoxLayout();
        expenseLayout->addWidget(new QLabel(date, this));
        expenseLayout->addWidget(new QLabel(category, this));
        expenseLayout->addWidget(new QLabel(amount, this));

        expensesLayout->addLayout(expenseLayout);

        dateInput->clear();
        categoryInput->clear();
        amountInput->clear();

        totalExpenses += amountValue;
        expenseData[category] += amountValue;

        totalLabel->setText("Total Expenses: " + QString::number(totalExpenses));
        updateChart();
    }

    void updateChart() {
        QString chartText = "Expenses Distribution:\n";
        for (auto it = expenseData.begin(); it != expenseData.end(); ++it) {
            chartText += QString("%1: %2%\n").arg(it.key()).arg((it.value() / totalExpenses) * 100, 0, 'f', 2);
        }
        chartLabel->setText(chartText);
    }

private:
    QVBoxLayout* expensesLayout;
    QLineEdit* dateInput;
    QLineEdit* categoryInput;
    QLineEdit* amountInput;
    QLabel* totalLabel;
    QLabel* chartLabel;
    double totalExpenses = 0;
    QMap<QString, double> expenseData;
};
class IncomesPage : public QWidget {
public:
    IncomesPage(QWidget* parent = nullptr) : QWidget(parent) {
        this->setStyleSheet("background: qradialgradient(cx:0.5, cy:0.5, radius: 1.0, "
                            "fx:0.5, fy:0.5, stop:0 rgba(173, 255, 179, 255), stop:1 rgba(200, 255, 200, 0));");

        QVBoxLayout* mainLayout = new QVBoxLayout(this);


        QLabel* titleLabel = new QLabel("Incomes", this);
        titleLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 24px; font-weight: bold; color: black;");
        titleLabel->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(titleLabel);

        QFormLayout* formLayout = new QFormLayout;

        dateInput = new QLineEdit(this);
        categoryInput = new QLineEdit(this);
        amountInput = new QLineEdit(this);

        dateInput->setPlaceholderText("Enter date (e.g., 2023-11-01)");
        categoryInput->setPlaceholderText("Enter category (e.g., Salary)");
        amountInput->setPlaceholderText("Enter amount (e.g., 1000)");

        dateInput->setStyleSheet("font-family: 'Times New Roman'; font-size: 18px;");
        categoryInput->setStyleSheet("font-family: 'Times New Roman'; font-size: 18px;");
        amountInput->setStyleSheet("font-family: 'Times New Roman'; font-size: 18px;");

        formLayout->addRow("Date:", dateInput);
        formLayout->addRow("Category:", categoryInput);
        formLayout->addRow("Amount:", amountInput);

        mainLayout->addLayout(formLayout);


        QPushButton* addButton = new QPushButton("Add Income", this);
        addButton->setStyleSheet("background-color: green; color: white; font-family: 'Times New Roman'; font-weight: bold;");
        mainLayout->addWidget(addButton);


        connect(addButton, &QPushButton::clicked, this, &IncomesPage::addIncome);

        incomesLayout = new QVBoxLayout();
        mainLayout->addLayout(incomesLayout);


        totalLabel = new QLabel("Total Income: 0", this);
        totalLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 18px; font-weight: bold; color: black;");
        mainLayout->addWidget(totalLabel);
    }

private slots:
    void addIncome() {
        QString date = dateInput->text();
        QString category = categoryInput->text();
        QString amount = amountInput->text();


        bool ok;
        double amountValue = amount.toDouble(&ok);
        if (date.isEmpty() || category.isEmpty() || amount.isEmpty() || !ok || amountValue <= 0) {
            return;
        }


        QHBoxLayout* incomeLayout = new QHBoxLayout();
        incomeLayout->addWidget(new QLabel(date, this));
        incomeLayout->addWidget(new QLabel(category, this));
        incomeLayout->addWidget(new QLabel(amount, this));


        incomesLayout->addLayout(incomeLayout);

        dateInput->clear();
        categoryInput->clear();
        amountInput->clear();


        totalIncome += amountValue;
        totalLabel->setText("Total Income: " + QString::number(totalIncome));
    }

private:
    QVBoxLayout* incomesLayout;
    QLineEdit* dateInput;
    QLineEdit* categoryInput;
    QLineEdit* amountInput;
    QLabel* totalLabel;
    double totalIncome = 0;
};

class LoginPage : public QWidget {
    QStackedWidget* stackedWidget;

public:
    LoginPage(QStackedWidget* stackedWidget, QWidget* parent = nullptr) : QWidget(parent), stackedWidget(stackedWidget) {

        this->setStyleSheet("background: qradialgradient(cx:0.5, cy:0.5, radius: 1.0, "
                            "fx:0.5, fy:0.5, stop:0 rgba(173, 255, 179, 255), stop:1 rgba(200, 255, 200, 0));");

        QVBoxLayout* layout = new QVBoxLayout(this);


        QLabel* loginLabel = new QLabel("Create an Account", this);
        QFont titleFont("Times New Roman", 24, QFont::Bold, true);
        loginLabel->setFont(titleFont);
        loginLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(loginLabel);


        QFormLayout* formLayout = new QFormLayout();


        QHBoxLayout* nameLayout = new QHBoxLayout();
        QLineEdit* firstNameInput = new QLineEdit(this);
        QLineEdit* lastNameInput = new QLineEdit(this);
        firstNameInput->setPlaceholderText("First name");
        lastNameInput->setPlaceholderText("Last name");
        nameLayout->addWidget(firstNameInput);
        nameLayout->addWidget(lastNameInput);
        formLayout->addRow(nameLayout);


        QLineEdit* emailInput = new QLineEdit(this);
        emailInput->setPlaceholderText("Email");
        formLayout->addRow(emailInput);


        QLineEdit* passwordInput = new QLineEdit(this);
        passwordInput->setPlaceholderText("Enter your password");
        passwordInput->setEchoMode(QLineEdit::Password);
        formLayout->addRow(passwordInput);


        layout->addLayout(formLayout);

        QPushButton* createAccountButton = new QPushButton("Create account");
        createAccountButton->setStyleSheet("background-color: green");
        layout->addWidget(createAccountButton, 0, Qt::AlignCenter);

        connect(createAccountButton, &QPushButton::clicked, this, &LoginPage::onCreateAccountClicked);

        layout->setAlignment(Qt::AlignCenter);
    }

private slots:
    void onCreateAccountClicked() {

        stackedWidget->setCurrentIndex(2);
    }
};
class NavBar : public QWidget {
    QStackedWidget* stackedWidget;

public:
    NavBar(QStackedWidget* stackedWidget, QWidget* parent = nullptr) : QWidget(parent), stackedWidget(stackedWidget) {
        this->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgba(173, 255, 179, 150), stop:1 rgba(200, 255, 200, 0));");
        this->setFixedHeight(80);

        QHBoxLayout* navLayout = new QHBoxLayout(this);
        navLayout->setContentsMargins(20, 0, 20, 0);

        QLabel* appName = new QLabel("SpendTrack", this);
        QFont titleFont("Times New Roman", 28, QFont::Bold, true);
        appName->setFont(titleFont);
        appName->setStyleSheet("color: black;");

        QString navButtonStyle = "QPushButton { background-color: transparent; color: black; padding: 10px; font-size: 18px; font-family: 'Times New Roman'; font-style: italic; border: none; }"
                                 "QPushButton:hover { color: #BDFF8B; font-weight: bold; }";

        QPushButton* homeButton = new QPushButton("Home");
        QPushButton* incomeButton = new QPushButton("Income");
        QPushButton* expenseButton = new QPushButton("Expenses");
        QPushButton* budgetButton = new QPushButton("Budget");

        homeButton->setStyleSheet(navButtonStyle);
        incomeButton->setStyleSheet(navButtonStyle);
        expenseButton->setStyleSheet(navButtonStyle);
        budgetButton->setStyleSheet(navButtonStyle);


        connect(homeButton, &QPushButton::clicked, this, &NavBar::onHomeButtonClicked);
        connect(incomeButton, &QPushButton::clicked, this, &NavBar::onIncomeButtonClicked);
        connect(expenseButton, &QPushButton::clicked, this, &NavBar::onExpenseButtonClicked);
        connect(budgetButton, &QPushButton::clicked, this, &NavBar::onBudgetButtonClicked);


        navLayout->addWidget(appName);
        navLayout->addStretch();
        navLayout->addWidget(homeButton);
        navLayout->addWidget(incomeButton);
        navLayout->addWidget(expenseButton);
        navLayout->addWidget(budgetButton);
    }

private slots:
    void onHomeButtonClicked() {
        stackedWidget->setCurrentIndex(0);
    }

    void onIncomeButtonClicked() {
        stackedWidget->setCurrentIndex(2);
    }

    void onExpenseButtonClicked() {
        stackedWidget->setCurrentIndex(3);
    }
    void onBudgetButtonClicked() {
        stackedWidget->setCurrentIndex(4);
    }

};
class MainPage : public QWidget {
    QStackedWidget* stackedWidget;

public:
    MainPage(QStackedWidget* stackedWidget, QWidget* parent = nullptr) : QWidget(parent), stackedWidget(stackedWidget) {
        this->setStyleSheet("background: qradialgradient(cx:0.5, cy:0.5, radius: 1.0, fx:0.5, fy:0.5, stop:0 rgba(173, 255, 179, 255), stop:1 rgba(200, 255, 200, 0));");

        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        QLabel* welcomeLabel = new QLabel("Welcome to SpendTrack", this);
        QFont contentFont("Times New Roman", 24, QFont::Bold, true);
        welcomeLabel->setFont(contentFont);
        welcomeLabel->setStyleSheet("color: black;");
        welcomeLabel->setAlignment(Qt::AlignCenter);

        QPushButton* loginButton = new QPushButton("Log In / Sign Up", this);
        QFont buttonFont("Times New Roman", 18, QFont::Bold);
        loginButton->setFont(buttonFont);
        loginButton->setStyleSheet("background-color: #BDFF8B; color: black; padding: 10px 20px; border-radius: 5px;");
        loginButton->setCursor(Qt::PointingHandCursor);

        connect(loginButton, &QPushButton::clicked, this, &MainPage::onLoginButtonClicked);

        mainLayout->addStretch();
        mainLayout->addWidget(welcomeLabel, 0, Qt::AlignCenter);
        mainLayout->addWidget(loginButton, 0, Qt::AlignCenter);
        mainLayout->addStretch();
    }

private slots:
    void onLoginButtonClicked() {
        stackedWidget->setCurrentIndex(1);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout* windowLayout = new QVBoxLayout(&window);
    windowLayout->setContentsMargins(0, 0, 0, 0);

    QStackedWidget* stackedWidget = new QStackedWidget;

    NavBar* navBar = new NavBar(stackedWidget);

    windowLayout->addWidget(navBar);
    windowLayout->addWidget(stackedWidget);

    MainPage* mainPage = new MainPage(stackedWidget);
    LoginPage* loginPage = new LoginPage(stackedWidget);
    IncomesPage* incomesPage = new IncomesPage();
    ExpensesPage* expensesPage = new ExpensesPage();
    BudgetPage* budgetPage = new BudgetPage();

    // Add pages to stacked widget
    stackedWidget->addWidget(mainPage);
    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(incomesPage);
    stackedWidget->addWidget(expensesPage);
    stackedWidget->addWidget(budgetPage);
    // Add to stacked widget

    window.setWindowTitle("SpendTrack - Elegant Navigation Bar Example");
    window.resize(1280, 720);
    window.show(); // Show the main window

    return app.exec(); // Start the application event loop
}
