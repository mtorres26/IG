#ifndef BASE_H
#define BASE_H

#include "cube.h"
#include "piston.h"

class _base:public _cube{
public:
    _base();

    void draw_points();
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _cube base_delantera_der;
    _cube base_delantera_izq;
    _cube base_trasera_der;
    _cube base_trasera_izq;

    _piston piston;
};

#endif // BASE_H
