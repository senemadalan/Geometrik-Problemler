#define _USE_MATH_DEFINES
#include "ucgen.h"
#include <cmath>

// Üç tane Nokta nesnesi alan yapýcý
Ucgen::Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3) {
    nokta1 = n1;
    nokta2 = n2;
    nokta3 = n3;
}

// nokta1 için set metodu
void Ucgen::setNokta1(const Nokta& n1) {
    nokta1 = n1;
}

// nokta1 için get metodu
Nokta Ucgen::getNokta1() const {
    return nokta1;
}

// nokta2 için set metodu
void Ucgen::setNokta2(const Nokta& n2) {
    nokta2 = n2;
}

// nokta2 için get metodu
Nokta Ucgen::getNokta2() const {
    return nokta2;
}

// nokta3 için set metodu
void Ucgen::setNokta3(const Nokta& n3) {
    nokta3 = n3;
}

// nokta3 için get metodu
Nokta Ucgen::getNokta3() const {
    return nokta3;
}

// toString metodu
string Ucgen::toString() {
    return "Üçgen; " + nokta1.toString() + ", " + nokta2.toString() + ", " + nokta3.toString();
}

// Alan hesaplama metodu
double Ucgen::alan() {
    DogruParcasi kenar1(nokta1, nokta2);
    DogruParcasi kenar2(nokta2, nokta3);
    DogruParcasi kenar3(nokta3, nokta1);

    // Heron's formülü kullanýlarak üçgen alanýnýn hesaplanmasý
    double u = (kenar1.uzunluk() + kenar2.uzunluk() + kenar3.uzunluk()) / 2;
    return sqrt(u * (u - kenar1.uzunluk()) * (u - kenar2.uzunluk()) * (u - kenar3.uzunluk()));
}

// Üç doðru parçasý oluþturularak DogruParcasi sýnýfýndaki uzunluk metodu ile çevre hesaplama iþlemi
double Ucgen::cevre() {
    DogruParcasi kenar1(nokta1, nokta2);
    DogruParcasi kenar2(nokta2, nokta3);
    DogruParcasi kenar3(nokta3, nokta1);

    return kenar1.uzunluk() + kenar2.uzunluk() + kenar3.uzunluk();
}

// Üçgenin iç açýlarýný hesaplayan acilar metodu
double* Ucgen::acilar() {
    static double aciDizisi[3];

    DogruParcasi kenar1(nokta1, nokta2);
    DogruParcasi kenar2(nokta2, nokta3);
    DogruParcasi kenar3(nokta3, nokta1);

    // Kosinüs teoremi kullanýlarak üçgenin iç açýlarýný indexleme iþlemi ile hesaplama
    aciDizisi[0] = acos((kenar1.uzunluk() * kenar1.uzunluk() + kenar3.uzunluk() * kenar3.uzunluk() -
        kenar2.uzunluk() * kenar2.uzunluk()) /
        (2 * kenar1.uzunluk() * kenar3.uzunluk()));
    aciDizisi[1] = acos((kenar1.uzunluk() * kenar1.uzunluk() + kenar2.uzunluk() * kenar2.uzunluk() -
        kenar3.uzunluk() * kenar3.uzunluk()) /
        (2 * kenar1.uzunluk() * kenar2.uzunluk()));
    aciDizisi[2] = acos((kenar2.uzunluk() * kenar2.uzunluk() + kenar3.uzunluk() * kenar3.uzunluk() -
        kenar1.uzunluk() * kenar1.uzunluk()) /
        (2 * kenar2.uzunluk() * kenar3.uzunluk()));

    // Radyan cinsinden açýlarý dereceye çevirme
    for (int i = 0; i < 3; ++i) {
        aciDizisi[i] = aciDizisi[i] * 180 / M_PI;
    }

    return aciDizisi;   // C++ dizilerin doðrudan return edilmesine izin vermediðinden pointer ile return etme iþleminin gerçekleþtirilmesi
}