#pragma once
#include "nokta.h"
using namespace std;

//Dairenin merkezi (Nokta nesnesi olarak) ve yar��ap�n� nesne de�i�kenleri olarak tutan Daire s�n�f�
class Daire {
private:
    Nokta merkezNokta;
    double yaricap;

public:
    Daire(const Nokta& merkez, double yaricapvalue);
    Daire(const Daire& other);
    Daire(const Daire& other, double x_carpani);

    double alan();
    double cevre();
    int kesisim(const Daire& other);

    string toString();
    void yazdir();
};