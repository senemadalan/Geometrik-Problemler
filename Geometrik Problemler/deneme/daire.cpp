#define _USE_MATH_DEFINES
#include "daire.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

// Merkez (Nokta nesnesi olarak) ve yarýçapý parametre olarak alan yapýcý.
Daire::Daire(const Nokta& merkez, double yaricapvalue) {
    merkezNokta = merkez;
    yaricap = yaricapvalue;
}

// Baþka bir Daire nesnesi alýp kopyasýný yeni bir Daire nesnesi olarak oluþturan yapýcý.
Daire::Daire(const Daire& other) {
    merkezNokta = other.merkezNokta;
    yaricap = other.yaricap;
}

// Baþka bir Daire nesnesi ve x deðeri alarak, parametre alýnan Daire nesnesini yarýçapý x ile çarpýlmýþ olarak kopyalayan yapýcý
Daire::Daire(const Daire& other, double x_carpani) {
    merkezNokta = other.merkezNokta;
    yaricap = other.yaricap * x_carpani;
}

// Alan hesaplama metodu
double Daire::alan() {
    return M_PI * pow(yaricap, 2);
}

// Çevre hesaplama metodu
double Daire::cevre() {
    return 2 * M_PI * yaricap;
}

// Kesiþim kontrol metodu
int Daire::kesisim(const Daire& other) {
    // Ýki daire arasýndaki mesafenin hesaplanmasý
    double mesafe = sqrt(pow(merkezNokta.getX() - other.merkezNokta.getX(), 2) +
        pow(merkezNokta.getY() - other.merkezNokta.getY(), 2));

    // Daireler tamamen örtüþüyorsa
    if (mesafe == 0 && yaricap == other.yaricap) {
        return 1;
    }

    // Daireler iç içe geçmiþse
    if (mesafe < abs(yaricap - other.yaricap)) {
        return 0;
    }

    // Daireler kesiþiyorsa
    if (mesafe < yaricap + other.yaricap && mesafe > abs(yaricap - other.yaricap)) {
        return 1;
    }

    // Hiç kesiþim yoksa
    return 2;
}

// toString metodu
string Daire::toString() {
    ostringstream oss;
    oss << "Merkez: " << merkezNokta.toString() << ", Yarýçap: " << fixed << setprecision(2) << yaricap;
    return oss.str();
}

// yazdir metodu
void Daire::yazdir() {
    cout << toString() << endl;
}