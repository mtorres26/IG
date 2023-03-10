/*! \file
 * Miguel Torres Alonso
 */

#include "chair.h"

using namespace _colors_ne;

_chair::_chair()
{

}

// Ultimo elemento del modelo jerarquico. Esta compuesto por todos los objetos y se comporta como un bloque.
// Tiene 3 grados de libertad, uno en el piston, uno en el asiento con dos tiipos de movimientos y uno en la union del asiento con el respaldo

void _chair::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_points(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
    glPopMatrix();
}

void _chair::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_line(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
    glPopMatrix();

}

void _chair::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLACK);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_fill(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
    glPopMatrix();
}

void _chair::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_chess(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
    glPopMatrix();
}

void _chair::draw_flat_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_flat_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
    glPopMatrix();
}

void _chair::draw_smooth_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_smooth_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
    glPopMatrix();
}
