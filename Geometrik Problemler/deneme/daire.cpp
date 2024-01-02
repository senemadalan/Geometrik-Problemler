#define _USE_MATH_DEFINES
#include "daire.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

// Merkez (Nokta nesnesi olarak) ve yar��ap� parametre olarak alan yap�c�.
Daire::Daire(const Nokta& merkez, double yaricapvalue) {
    merkezNokta = merkez;
    yaricap = yaricapvalue;
}

// Ba�ka bir Daire nesnesi al�p kopyas�n� yeni bir Daire nesnesi olarak olu�turan yap�c�.
Daire::Daire(const Daire& other) {
    merkezNokta = other.merkezNokta;
    yaricap = other.yaricap;
}

// Ba�ka bir Daire nesnesi ve x de�eri alarak, parametre al�nan Daire nesnesini yar��ap� x ile �arp�lm�� olarak kopyalayan yap�c�
Daire::Daire(const Daire& other, double x_carpani) {
    merkezNokta = other.merkezNokta;
    yaricap = other.yaricap * x_carpani;
}

// Alan hesaplama metodu
double Daire::alan() {
    return M_PI * pow(yaricap, 2);
}

// �evre hesaplama metodu
double Daire::cevre() {
    return 2 * M_PI * yaricap;
}

// Kesi�im kontrol metodu
int Daire::kesisim(const Daire& other) {
    // �ki daire aras�ndaki mesafenin hesaplanmas�
    double mesafe = sqrt(pow(merkezNokta.getX() - other.merkezNokta.getX(), 2) +
        pow(merkezNokta.getY() - other.merkezNokta.getY(), 2));

    // Daireler tamamen �rt���yorsa
    if (mesafe == 0 && yaricap == other.yaricap) {
        return 1;
    }

    // Daireler i� i�e ge�mi�se
    if (mesafe < abs(yaricap - other.yaricap)) {
        return 0;
    }

    // Daireler kesi�iyorsa
    if (mesafe < yaricap + other.yaricap && mesafe > abs(yaricap - other.yaricap)) {
        return 1;
    }

    // Hi� kesi�im yoksa
    return 2;
}

// toString metodu
string Daire::toString() {
    ostringstream oss;
    oss << "Merkez: " << merkezNokta.toString() << ", Yar��ap: " << fixed << setprecision(2) << yaricap;
    return oss.str();
}

// yazdir metodu
void Daire::yazdir() {
    cout << toString() << endl;
}