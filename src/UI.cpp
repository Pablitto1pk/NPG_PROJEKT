

#include "UI.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>


MyWindow::MyWindow(QWidget *parent)
    : QWidget(parent)
{
    // Wielkosc i wyglad okna
    setFixedSize(800, 500);
    setStyleSheet("background-color: #007BFF;");
    //

    // Wygląd tabeli
    label = new QLabel("Wybierz poziom trudności aby rozpocząć");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("color: white; font-size: 32px; font-weight: bold;");
    //

    button_easy = new QPushButton("ŁATWY"); //tworzy guziki
    button_medium = new QPushButton("ŚREDNI");
    button_hard = new QPushButton("TRUDNY");

    // Ustawia wygląd przycisków (3 na raz)
    QList<QPushButton*> buttons = { button_easy, button_medium, button_hard };
    for (auto btn : buttons) {
        btn->setFixedHeight(40);
        btn->setStyleSheet("background-color: #0056b3; color: white; font-size: 16px;");
    }
    //

    // BOX Z GUZIKAMI (poziomo rozciagniete)
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(button_easy);
    buttonLayout->addSpacing(10);
    buttonLayout->addWidget(button_medium);
    buttonLayout->addSpacing(10);
    buttonLayout->addWidget(button_hard);
    buttonLayout->addStretch();
    //

    // Elementy do etapu drugiego gry
    wordLabel = new QLabel("Hasło wczytywane z klasy");
    wordLabel->setStyleSheet("font-size: 20px; color: white;");
    wordLabel->setAlignment(Qt::AlignCenter);

    inputField = new QLineEdit();
    inputField->setPlaceholderText("Wpisz odpowiedź...");
    inputField->setStyleSheet("font-size: 16px;");
    inputField->setFixedHeight(40);

    wordLabel->hide(); // wstepne ukrycie etapu drugiego
    inputField->hide();
    //

    // Głowny layout strony tytul i podlayout z guzikami
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addWidget(label, 0, Qt::AlignCenter);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    //etap2
    mainLayout->addSpacing(30);
    mainLayout->addWidget(wordLabel);
    mainLayout->addWidget(inputField);
    //

    connect(button_easy, &QPushButton::clicked, this, [this]() {
    startGame(0);
    });
    connect(button_medium, &QPushButton::clicked, this, [this]() {
        startGame(1);
    });
    connect(button_hard, &QPushButton::clicked, this, [this]() {
        startGame(2);
    });

    setLayout(mainLayout); // ustawia layout
    setWindowTitle("Gra memory"); // tytul okna z grą
}

void MyWindow::startGame(const int poziom) // int bo moja klasa obsluguje 0,1,2
{
    Game.set_level(poziom);// ustawia poziom trudnosci gry na podany

    // Ukryj przyciski i tytuł
    label->hide();
    button_easy->hide();
    button_medium->hide();
    button_hard->hide();

    std::string haslo = Game.get_pass(); // uzyskujemy haslo
    QString qhaslo = QString::fromStdString(haslo); // transformacja typu hasla
    wordLabel->setText("Zapamiętaj hasło: " + qhaslo);

    // Pokaż elementy etapu 2
    wordLabel->show();
    inputField->show();
}