#ifndef BACKBOARD_H
#define BACKBOARD_H

#include "sphere.h"
class _backboard:public _sphere{
public:
    _backboard();

    void draw_points();
    void draw_line();
    void draw_fill();
    void draw_chess();

    float rotacion_asiento;
private:
    _sphere respaldo;
};

#endif // BACKBOARD_H
