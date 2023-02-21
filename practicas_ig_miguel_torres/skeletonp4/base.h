#ifndef BASE_H
#define BASE_H

#include "cube.h"
#include "piston.h"

class _base:public _cube{
public:
    _base();

    void draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);

    void draw_flat_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_smooth_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
private:

    _cube base;

    _piston piston;
};

#endif // BASE_H
