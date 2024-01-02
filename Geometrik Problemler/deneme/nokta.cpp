#include "nokta.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Parametresiz yap�c�
Nokta::Nokta() {
    setX(0.0);
    setY(0.0);
}

// Tek parametreli yap�c�
Nokta::Nokta(double value) {
    setX(value);
    setY(value);
}

// �ki parametreli yap�c�
Nokta::Nokta(double xvalue, double yvalue) {
    setX(xvalue);
    setY(yvalue);
}

// Ba�ka bir noktay� al�p o noktan�n kopyas�n� yeni nokta olarak �reten yap�c�
Nokta::Nokta(const Nokta& other) {
    setX(other.getX());
    setY(other.getY());
}

// Ba�ka bir nokta nesnesi ve ofset de�erleri ile yeni nokta �reten yap�c�
Nokta::Nokta(const Nokta& other, double ofset_x, double ofset_y) {
    setX(other.getX() + ofset_x);
    setY(other.getY() + ofset_y);
}

// x koordinat� i�in set metodu
void Nokta::setX(double xvalue) {
    x = xvalue;
}

// x koordinat� i�in get metodu
double Nokta::getX() const {
    return x;
}

// y koordinat� i�in set metodu
void Nokta::setY(double yvalue) {
    y = yvalue;
}

// y koordinat� i�in get metodu
double Nokta::getY() const {
    return y;
}

// Ayn� anda iki koordinat� alan ve noktan�n x ve y koordinatlar�n� de�i�tiren set metodu
void Nokta::set(double xvalue, double yvalue) {
    setX(xvalue);
    setY(yvalue);
}

// toString metodu
string Nokta::toString() {
    ostringstream oss;
    oss << fixed << setprecision(2) << "(" << x << ", " << y << ")";
    return oss.str();
}

// yazdir metodu
void Nokta::yazdir() {
    cout << toString() << endl;
}