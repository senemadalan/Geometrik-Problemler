#define _USE_MATH_DEFINES
#include "dogruparcasi.h"
#include <iostream>
#include <cmath>

// �ki u� noktay� Nokta nesnesi olarak alan yap�c�
DogruParcasi::DogruParcasi(const Nokta& baslangicNokta, const Nokta& bitisNokta) {
    basNokta = baslangicNokta;
    sonNokta = bitisNokta;
}

// Ba�ka DogruParcasi nesnesi al�p kopyas�n� yeni DogruParcasi nesnesi olarak olu�turan yap�c�
DogruParcasi::DogruParcasi(const DogruParcasi& other) {
    basNokta = other.basNokta;
    sonNokta = other.sonNokta;
}

// Bir Nokta nesnesi, uzunluk ve e�im alarak do�ru par�as�n�n u� noktalar�n� hesaplayan yap�c�   
DogruParcasi::DogruParcasi(const Nokta& midNokta, double uzunluk, double aciDerece) {
    // Derecenin radyan cinsine d�n��t�r�lmesi
    double aciRadyan = aciDerece * M_PI / 180.0;

    // A��y� kullanarak e�im de�erinin hesaplanmas�
    double egim = tan(aciRadyan);

    // Yatay ve dikey bile�enlerin hesaplanmas�
    double yatayBilesen = uzunluk * cos(aciRadyan) / 2.0;
    double dikeyBilesen = uzunluk * sin(aciRadyan) / 2.0;

    // Ba�lang�� noktas�n� ve biti� noktas�n�n ayarlanmas�
    basNokta = Nokta(midNokta.getX() - yatayBilesen, midNokta.getY() - dikeyBilesen); 
    sonNokta = Nokta(midNokta.getX() + yatayBilesen, midNokta.getY() + dikeyBilesen); 
}

// Ba�lang�� noktas� i�in set metodu
void DogruParcasi::setbasNokta(const Nokta& baslangicNokta) {
    basNokta = baslangicNokta;
}

// Ba�lang�� noktas� i�in get metodu
Nokta DogruParcasi::getbasNokta() const {
    return basNokta;
}

// Biti� noktas� i�in set metodu
void DogruParcasi::setsonNokta(const Nokta& bitisNokta) {
    sonNokta = bitisNokta;
}

// Biti� noktas� i�in get metodu
Nokta DogruParcasi::getsonNokta() const {
    return sonNokta;
}

// Ba�lang�� ve biti� noktalar�n�n tutulmas� i�in yaz�lan setP1 metodu
void DogruParcasi::setP1(const Nokta& baslangicVeBitisNokta) {
    basNokta = baslangicVeBitisNokta;
    sonNokta.setX(basNokta.getX());
    sonNokta.setY(basNokta.getY());
}

// Uzunluk hesaplama metodu
double DogruParcasi::uzunluk() {
    double deltaX = sonNokta.getX() - basNokta.getX();
    double deltaY = sonNokta.getY() - basNokta.getY();
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

// Kesi�imNoktas� hesaplama metodu
Nokta DogruParcasi::DikKesisimNoktasiBul(const Nokta& verilenNokta) const {
    // Do�ru par�as�n�n uzunluk vekt�r�n�n hesaplanmas�
    double dogruParcaX = sonNokta.getX() - basNokta.getX();
    double dogruParcaY = sonNokta.getY() - basNokta.getY();

    // Do�ru par�as�n�n birim vekt�r�n�n hesaplanmas�
    double dogruParcaUzunluk = sqrt(dogruParcaX * dogruParcaX + dogruParcaY * dogruParcaY);
    double birimDogruParcaX = dogruParcaX / dogruParcaUzunluk;
    double birimDogruParcaY = dogruParcaY / dogruParcaUzunluk;

    // Verilen noktan�n do�ru par�as�na dik olan vekt�r�n�n hesaplanmas�
    double dikVectorX = verilenNokta.getX() - basNokta.getX();
    double dikVectorY = verilenNokta.getY() - basNokta.getY();

    // Verilen noktan�n do�ru par�as�na dik olan uzakl���n�n hesaplanmas�
    double uzaklik = dikVectorX * birimDogruParcaX + dikVectorY * birimDogruParcaY;

    // Do�ru par�as�n�n �zerindeki kesi�im noktas�n�n hesaplanmas�
    double kesisimNoktasiX = basNokta.getX() + uzaklik * birimDogruParcaX;
    double kesisimNoktasiY = basNokta.getY() + uzaklik * birimDogruParcaY;


    // Yeni Nokta nesnesini olu�tur ve d�nd�r
    return Nokta(kesisimNoktasiX, kesisimNoktasiY);
}

// Orta noktay� hesaplayan metot
Nokta DogruParcasi::ortaNokta() {
    return Nokta((basNokta.getX() + sonNokta.getX()) / 2, (basNokta.getY() + sonNokta.getY()) / 2);
}

// Nokta s�n�f�ndaki toString metodu kullan�larak yap�lan toString y�ntemi
string DogruParcasi::toString() {
    return basNokta.toString() + " - " + sonNokta.toString();
}

// Ekrana yazd�rma metodu
void DogruParcasi::yazdir() {
    cout << toString() << endl;
}
