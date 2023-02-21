#ifndef WHEEL_H
#define WHEEL_H

#include "cylinder.h"
#include "base.h"

class _wheel:public _cylinder
{

public:
    _wheel();
    void draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);

    void draw_flat_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_smooth_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
private:
    _cylinder rueda;

    _base base;
};

#endif // WHEEL_H
