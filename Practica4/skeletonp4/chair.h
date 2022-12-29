#ifndef CHAIR_H
#define CHAIR_H

#include "wheel.h"

class _chair:public _object3D
{
public:
    _chair();

    void draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);

    void draw_flat_shading();
    void draw_smooth_shading();
private:
    _wheel silla;


};

#endif // CHAIR_H
