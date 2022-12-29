#ifndef SEAT_H
#define SEAT_H

#include "union.h"
#include "cube.h"

class _seat:public _cube{
public:

    _seat();
    void draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    void draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento);
    float rotacion_asiento;
private:
    _union soporte;
    _cube asiento;

};


#endif // SEAT_H
