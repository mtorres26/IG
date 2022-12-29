#ifndef CHAIR_H
#define CHAIR_H

#include "wheel.h"

class _chair:public _object3D
{
public:
    _chair();

    void draw_points();
    void draw_line();
    void draw_fill();
    void draw_chess();
    float rotacion_asiento;
private:
    _wheel silla;


};

#endif // CHAIR_H
