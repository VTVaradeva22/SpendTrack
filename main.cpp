#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QPropertyAnimation>

class NavBar : public QWidget {
public:
    NavBar(QWidget* parent = nullptr) : QWidget(parent) {
        // Gradient background for the navigation bar, directed vertically
        this->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgba(173, 255, 179, 150), stop:1 rgba(200, 255, 200, 0));");

        // Set fixed height for the navigation bar
        this->setFixedHeight(80);

        // Main layout of the navigation bar
        QHBoxLayout* navLayout = new QHBoxLayout(this);
        navLayout->setContentsMargins(20, 0, 20, 0); // Set margins for the layout

        // Application title label
        QLabel* appName = new QLabel("SpendTrack", this);
        QFont titleFont("Times New Roman", 28, QFont::Bold, true);
        appName->setFont(titleFont);
        appName->setStyleSheet("color: black;");

        // Style for navigation buttons
        QString navButtonStyle = "QPushButton { background-color: transparent; color: black; padding: 10px; font-size: 18px; font-family: 'Times New Roman'; font-style: italic; border: none; }"
            "QPushButton:hover { color: #BDFF8B; font-weight: bold; }";

        // Create navigation buttons
        QPushButton* homeButton = new QPushButton("Home");
        QPushButton* incomeButton = new QPushButton("Income");
        QPushButton* expenseButton = new QPushButton("Expenses");
        QPushButton* budgetButton = new QPushButton("Budget");
        QPushButton* reportButton = new QPushButton("Reports");

        // Apply style to the buttons
        homeButton->setStyleSheet(navButtonStyle);
        incomeButton->setStyleSheet(navButtonStyle);
        expenseButton->setStyleSheet(navButtonStyle);
        budgetButton->setStyleSheet(navButtonStyle);
        reportButton->setStyleSheet(navButtonStyle);

        // Add elements to the navigation bar layout
        navLayout->addWidget(appName);
        navLayout->addStretch(); // Add stretchable space between the title and buttons
        navLayout->addWidget(homeButton);
        navLayout->addWidget(incomeButton);
        navLayout->addWidget(expenseButton);
        navLayout->addWidget(budgetButton);
        navLayout->addWidget(reportButton);
    }
};

class MainPage : public QWidget {
public:
    MainPage(QWidget* parent = nullptr) : QWidget(parent) {
        // Background settings for the main page with a smooth radial gradient
        this->setStyleSheet("background: qradialgradient(cx:0.5, cy:0.5, radius: 1.0, "
            "fx:0.5, fy:0.5, stop:0 rgba(173, 255, 179, 255), stop:1 rgba(200, 255, 200, 0));");

        QVBoxLayout* mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0); // No margins around the main layout

        // Title "Welcome to SpendTrack"
        QLabel* welcomeLabel = new QLabel("Welcome to SpendTrack", this);
        QFont contentFont("Times New Roman", 24, QFont::Bold, true);
        welcomeLabel->setFont(contentFont);
        welcomeLabel->setStyleSheet("color: black;");
        welcomeLabel->setAlignment(Qt::AlignCenter); // Center the title

        // Button for login or sign up
        QPushButton* loginButton = new QPushButton("Log In / Sign Up", this);
        QFont buttonFont("Times New Roman", 18, QFont::Bold);
        loginButton->setFont(buttonFont);
        loginButton->setStyleSheet("background-color: #BDFF8B; color: black; padding: 10px 20px; border-radius: 5px;");
        loginButton->setCursor(Qt::PointingHandCursor); // Change cursor to pointer on hover

        // Adding elements to the main layout
        mainLayout->addStretch(); // Add stretchable space above the label
        mainLayout->addWidget(welcomeLabel, 0, Qt::AlignCenter); // Center the welcome label
        mainLayout->addWidget(loginButton, 0, Qt::AlignCenter); // Center the login button
        mainLayout->addStretch(); // Add stretchable space below the button

        // Animation for the welcome label
        QPropertyAnimation* animation = new QPropertyAnimation(welcomeLabel, "opacity");
        animation->setDuration(2000); // Duration of the animation
        animation->setStartValue(0.0); // Start with opacity 0
        animation->setEndValue(1.0); // End with full opacity
        animation->start(); // Start the animation
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Creating the main window
    QWidget window;
    QVBoxLayout* windowLayout = new QVBoxLayout(&window);
    windowLayout->setContentsMargins(0, 0, 0, 0); // No margins for the main window layout

    // Adding the navigation bar at the top
    NavBar* navBar = new NavBar();
    windowLayout->addWidget(navBar);

    // Main page
    MainPage* mainPage = new MainPage();
    windowLayout->addWidget(mainPage);

    // Window settings
    window.setWindowTitle("SpendTrack - Elegant Navigation Bar Example");
    window.resize(1280, 720);
    window.show(); // Show the main window

    return app.exec(); // Start the application event loop
}
