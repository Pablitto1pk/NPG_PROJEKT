
#ifndef UI_H
#define UI_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "memory.hpp" // moja klasa do obslugi listy słów i losowanka

class MyWindow : public QWidget {
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = nullptr);
    void startGame(int poziom); // metoda wejscia w etap2 (edytuje gui)

private:
    game Game; // obiekt klasy do obsługi gry

    //wybor trudnosci
    QLabel *label;
    QPushButton *button_easy;
    QPushButton *button_medium;
    QPushButton *button_hard;
    //etap drugi
    QLabel *wordLabel; // Tu bedzie losowane haslo
    QLineEdit *inputField; // pole do wpisywania hasła
};

#endif //UI_H
