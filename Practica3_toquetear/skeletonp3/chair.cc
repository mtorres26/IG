/*! \file
 * Miguel Torres Alonso
 */

#include "chair.h"

using namespace _colors_ne;

_chair::_chair()
{

}

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

