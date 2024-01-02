#pragma once
#include "nokta.h"
using namespace std;

//Dairenin merkezi (Nokta nesnesi olarak) ve yarýçapýný nesne deðiþkenleri olarak tutan Daire sýnýfý
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