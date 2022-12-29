#ifndef SEAT_H
#define SEAT_H

#include "union.h"
#include "cube.h"

class _seat:public _cube{
public:

    _seat();
    void draw_points();
    void draw_line();
    void draw_fill();
    void draw_chess();
    float rotacion_asiento;
private:
    _union soporte;
    _cube asiento;

};


#endif // SEAT_H
