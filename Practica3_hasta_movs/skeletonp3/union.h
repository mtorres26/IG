#ifndef UNION_H
#define UNION_H

#include "cube.h"
#include "backboard.h"
class _union:public _cube{
public:
    _union();
    void draw_points();
    void draw_line();
    void draw_fill();
    void draw_chess();
private:
    _backboard respaldo;
    _cube soporte;
};

#endif // UNION_H
