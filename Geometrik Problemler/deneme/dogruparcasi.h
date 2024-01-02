#pragma once
#include "nokta.h"
using namespace std;

//Nesne de�i�kenleri olarak bir do�ru par�as�n�n iki noktas�n� (Nokta nesnesi olarak) i�eren DogruParcasi s�n�f� 
class DogruParcasi {
private:
    Nokta basNokta;
    Nokta sonNokta;

public:
    DogruParcasi(const Nokta& baslangicNokta, const Nokta& bitisNokta);
    DogruParcasi(const DogruParcasi& other);
    DogruParcasi(const Nokta& midNokta, double uzunluk, double aciDerece);

    void setbasNokta(const Nokta& baslangicNokta);
    Nokta getbasNokta() const;

    void setsonNokta(const Nokta& bitisNokta);
    Nokta getsonNokta() const;

    void setP1(const Nokta& baslangicVeBitisNokta);

    double uzunluk();
    Nokta DikKesisimNoktasiBul(const Nokta& verilenNokta) const;
    Nokta ortaNokta();
    string toString();
    void yazdir();
};