#pragma once
#include "nokta.h"
#include "dogruparcasi.h"
using namespace std;

// Nesne deðiþkeni olarak 3 tane Nokta nesnesi içeren Üçgen sýnýfý
class Ucgen {
private:
    Nokta nokta1;
    Nokta nokta2;
    Nokta nokta3;

public:
    Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3);

    void setNokta1(const Nokta& n1);
    Nokta getNokta1() const;

    void setNokta2(const Nokta& n2);
    Nokta getNokta2() const;

    void setNokta3(const Nokta& n3);
    Nokta getNokta3() const;

    std::string toString();
    double alan();
    double cevre();
    double* acilar();
};