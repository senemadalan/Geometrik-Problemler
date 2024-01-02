#define _USE_MATH_DEFINES
#include "dogruparcasi.h"
#include <iostream>
#include <cmath>

// Ýki uç noktayý Nokta nesnesi olarak alan yapýcý
DogruParcasi::DogruParcasi(const Nokta& baslangicNokta, const Nokta& bitisNokta) {
    basNokta = baslangicNokta;
    sonNokta = bitisNokta;
}

// Baþka DogruParcasi nesnesi alýp kopyasýný yeni DogruParcasi nesnesi olarak oluþturan yapýcý
DogruParcasi::DogruParcasi(const DogruParcasi& other) {
    basNokta = other.basNokta;
    sonNokta = other.sonNokta;
}

// Bir Nokta nesnesi, uzunluk ve eðim alarak doðru parçasýnýn uç noktalarýný hesaplayan yapýcý   
DogruParcasi::DogruParcasi(const Nokta& midNokta, double uzunluk, double aciDerece) {
    // Derecenin radyan cinsine dönüþtürülmesi
    double aciRadyan = aciDerece * M_PI / 180.0;

    // Açýyý kullanarak eðim deðerinin hesaplanmasý
    double egim = tan(aciRadyan);

    // Yatay ve dikey bileþenlerin hesaplanmasý
    double yatayBilesen = uzunluk * cos(aciRadyan) / 2.0;
    double dikeyBilesen = uzunluk * sin(aciRadyan) / 2.0;

    // Baþlangýç noktasýný ve bitiþ noktasýnýn ayarlanmasý
    basNokta = Nokta(midNokta.getX() - yatayBilesen, midNokta.getY() - dikeyBilesen); 
    sonNokta = Nokta(midNokta.getX() + yatayBilesen, midNokta.getY() + dikeyBilesen); 
}

// Baþlangýç noktasý için set metodu
void DogruParcasi::setbasNokta(const Nokta& baslangicNokta) {
    basNokta = baslangicNokta;
}

// Baþlangýç noktasý için get metodu
Nokta DogruParcasi::getbasNokta() const {
    return basNokta;
}

// Bitiþ noktasý için set metodu
void DogruParcasi::setsonNokta(const Nokta& bitisNokta) {
    sonNokta = bitisNokta;
}

// Bitiþ noktasý için get metodu
Nokta DogruParcasi::getsonNokta() const {
    return sonNokta;
}

// Baþlangýç ve bitiþ noktalarýnýn tutulmasý için yazýlan setP1 metodu
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

// KesiþimNoktasý hesaplama metodu
Nokta DogruParcasi::DikKesisimNoktasiBul(const Nokta& verilenNokta) const {
    // Doðru parçasýnýn uzunluk vektörünün hesaplanmasý
    double dogruParcaX = sonNokta.getX() - basNokta.getX();
    double dogruParcaY = sonNokta.getY() - basNokta.getY();

    // Doðru parçasýnýn birim vektörünün hesaplanmasý
    double dogruParcaUzunluk = sqrt(dogruParcaX * dogruParcaX + dogruParcaY * dogruParcaY);
    double birimDogruParcaX = dogruParcaX / dogruParcaUzunluk;
    double birimDogruParcaY = dogruParcaY / dogruParcaUzunluk;

    // Verilen noktanýn doðru parçasýna dik olan vektörünün hesaplanmasý
    double dikVectorX = verilenNokta.getX() - basNokta.getX();
    double dikVectorY = verilenNokta.getY() - basNokta.getY();

    // Verilen noktanýn doðru parçasýna dik olan uzaklýðýnýn hesaplanmasý
    double uzaklik = dikVectorX * birimDogruParcaX + dikVectorY * birimDogruParcaY;

    // Doðru parçasýnýn üzerindeki kesiþim noktasýnýn hesaplanmasý
    double kesisimNoktasiX = basNokta.getX() + uzaklik * birimDogruParcaX;
    double kesisimNoktasiY = basNokta.getY() + uzaklik * birimDogruParcaY;


    // Yeni Nokta nesnesini oluþtur ve döndür
    return Nokta(kesisimNoktasiX, kesisimNoktasiY);
}

// Orta noktayý hesaplayan metot
Nokta DogruParcasi::ortaNokta() {
    return Nokta((basNokta.getX() + sonNokta.getX()) / 2, (basNokta.getY() + sonNokta.getY()) / 2);
}

// Nokta sýnýfýndaki toString metodu kullanýlarak yapýlan toString yöntemi
string DogruParcasi::toString() {
    return basNokta.toString() + " - " + sonNokta.toString();
}

// Ekrana yazdýrma metodu
void DogruParcasi::yazdir() {
    cout << toString() << endl;
}
