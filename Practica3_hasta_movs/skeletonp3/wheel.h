#ifndef WHEEL_H
#define WHEEL_H

#include "cylinder.h"
#include "base.h"

class _wheel:public _cylinder
{

public:
    _wheel();
    void draw_points();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    _cylinder rueda_trasera_izq;
    _cylinder rueda_trasera_der;
    _cylinder rueda_delantera_izq;
    _cylinder rueda_delantera_der;

    _base base;
};

#endif // WHEEL_H
