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

    void draw_flat_shading();
    void draw_smooth_shading();
private:
    _cylinder rueda_trasera_izq;
    _cylinder rueda_trasera_der;
    _cylinder rueda_delantera_izq;
    _cylinder rueda_delantera_der;

    _base base;
};

#endif // WHEEL_H
