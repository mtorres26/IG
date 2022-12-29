#ifndef PISTON_H
#define PISTON_H

#include "seat.h"
#include "cylinder.h"
class _piston:public _object3D{
public:
    _piston();

    void draw_points();
    void draw_line();
    void draw_fill();
    void draw_chess();

    float rotacion_asiento;

private:
    _cylinder piston;
    _seat asiento;

};

#endif // PISTON_H
