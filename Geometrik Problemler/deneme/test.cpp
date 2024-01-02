#include <iostream>
#include "nokta.h"
#include "dogruparcasi.h"
#include "daire.h"
#include "ucgen.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Turkish");
    //Nokta
    cout << endl << "NOKTA SINIFI ���N TEST �IKTILARI:" << endl;
    Nokta n1;
    Nokta n2(5);
    Nokta n3(3, 4);
    Nokta n4(n3);
    Nokta n5(n3, 1, -1);

    cout << "Olu�turulan 5 noktan�n x ve y de�erleri:" << endl;
    n1.yazdir();
    n2.yazdir();
    n3.yazdir();
    n4.yazdir();
    n5.yazdir();

    cout << "1. ve 2. noktalar�n g�ncel x ve y de�erleri:" << endl;
    n1.setX(10);
    n1.yazdir();
    n2.set(25, 30);
    n2.yazdir();

    //Dogru Parcasi
    cout << endl << "DOGRUPARCASI SINIFI ���N TEST SONU�LARI:" << endl;
    Nokta n11;
    Nokta n21(3, 4);
    DogruParcasi dp(n11, n21);
    DogruParcasi dp2(dp);
    DogruParcasi dp3(n21, 10, 45);

    cout << "Olu�turulan 3 do�ru par�as�n�n ba�lang�� ve biti� noktalar�:" << endl;
    dp.yazdir();
    dp2.yazdir();
    dp3.yazdir();

    cout << "2. do�ru par�as�n�n ba�lang�� ve biti� noktalar�:" << endl;
    dp2.setP1(Nokta());
    dp2.yazdir();

    cout << "1. do�ru par�as� i�in uzunluk de�eri: " << dp.uzunluk() << endl;
    cout << "1. do�ru par�as� i�in orta nokta: " << dp.ortaNokta().toString() << endl;

    //Daire
    cout << endl << "DAIRE SINIFI ���N TEST SONU�LARI:" << endl;
    Nokta merkez1(0, 0);
    Daire d1(merkez1, 5);
    Daire d2(d1);
    Daire d3(d2, 3);

    cout << "Daire 1: ";
    d1.yazdir();
    cout << "Alan: " << d1.alan() << ", �evre: " << d1.cevre() << endl;

    cout << "Daire 2: ";
    d2.yazdir();
    cout << "Alan: " << d2.alan() << ", �evre: " << d2.cevre() << endl;

    cout << "Daire 3: ";
    d3.yazdir();
    cout << "Alan: " << d3.alan() << ", �evre: " << d3.cevre() << endl;

    cout << "Daire 1 ve Daire 2 Kesi�im Durumu: " << d1.kesisim(d2) << endl;
    cout << "Daire 1 ve Daire 3 Kesi�im Durumu: " << d1.kesisim(d3) << endl;

    //Ucgen
    cout << endl << "UCGEN SINIFI ���N TEST SONU�LARI:" << endl;
    Ucgen ucgen(Nokta(0, 0), Nokta(4, 0), Nokta(0, 3));

    cout << ucgen.toString() << endl;
    cout << "Alan: " << ucgen.alan() << endl;
    cout << "�evre: " << ucgen.cevre() << endl;

    double* acilar = ucgen.acilar();
    cout << "A��lar: " << acilar[0] << ", " << acilar[1] << ", " << acilar[2] << endl;

    return 0;
}