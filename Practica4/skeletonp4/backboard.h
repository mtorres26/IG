#ifndef BACKBOARD_H
#define BACKBOARD_H

#include "sphere.h"
class _backboard:public _sphere{
public:
    _backboard();

    void draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);

    void draw_flat_shading();
    void draw_smooth_shading();
private:
    _sphere respaldo;
};

#endif // BACKBOARD_H
