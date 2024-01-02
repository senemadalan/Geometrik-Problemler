#pragma once
#include <string>
using namespace std;

class Nokta {
private:
    double x;
    double y;

public:
    Nokta();
    Nokta(double value);
    Nokta(double xvalue, double yvalue);
    Nokta(const Nokta& other);
    Nokta(const Nokta& other, double ofset_x, double ofset_y);

    void setX(double xvalue);
    double getX() const;

    void setY(double yvalue);
    double getY() const;

    void set(double xvalue, double yvalue);

    std::string toString();
    void yazdir();
};
