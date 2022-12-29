/*! \file
 * Miguel Torres Alonso
 */

#include "seat.h"

using namespace _colors_ne;

_seat::_seat()
{

}

void _seat::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,ajustar_altura_asiento,0);
        glTranslatef(0,-0.1,0);
        glRotatef(inclinar_asiento,1,0,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1,0.1,1);
        asiento.draw_point();
    glPopMatrix();

    soporte.draw_points(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _seat::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,ajustar_altura_asiento,0);
        glTranslatef(0,-0.1,0);
        glRotatef(inclinar_asiento,1,0,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1,0.1,1);
        asiento.draw_line();
    glPopMatrix();

    soporte.draw_line(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _seat::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLUE);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,ajustar_altura_asiento,0);
        glTranslatef(0,-0.1,0);
        glRotatef(inclinar_asiento,1,0,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1,0.1,1);
        asiento.draw_fill();
    glPopMatrix();

    soporte.draw_fill(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _seat::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,ajustar_altura_asiento,0);
        glTranslatef(0,-0.1,0);
        glRotatef(inclinar_asiento,1,0,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1,0.1,1);
        asiento.draw_chess();
    glPopMatrix();

    soporte.draw_chess(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}


