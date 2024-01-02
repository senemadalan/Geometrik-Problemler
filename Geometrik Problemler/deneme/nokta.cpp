#include "nokta.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Parametresiz yapýcý
Nokta::Nokta() {
    setX(0.0);
    setY(0.0);
}

// Tek parametreli yapýcý
Nokta::Nokta(double value) {
    setX(value);
    setY(value);
}

// Ýki parametreli yapýcý
Nokta::Nokta(double xvalue, double yvalue) {
    setX(xvalue);
    setY(yvalue);
}

// Baþka bir noktayý alýp o noktanýn kopyasýný yeni nokta olarak üreten yapýcý
Nokta::Nokta(const Nokta& other) {
    setX(other.getX());
    setY(other.getY());
}

// Baþka bir nokta nesnesi ve ofset deðerleri ile yeni nokta üreten yapýcý
Nokta::Nokta(const Nokta& other, double ofset_x, double ofset_y) {
    setX(other.getX() + ofset_x);
    setY(other.getY() + ofset_y);
}

// x koordinatý için set metodu
void Nokta::setX(double xvalue) {
    x = xvalue;
}

// x koordinatý için get metodu
double Nokta::getX() const {
    return x;
}

// y koordinatý için set metodu
void Nokta::setY(double yvalue) {
    y = yvalue;
}

// y koordinatý için get metodu
double Nokta::getY() const {
    return y;
}

// Ayný anda iki koordinatý alan ve noktanýn x ve y koordinatlarýný deðiþtiren set metodu
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