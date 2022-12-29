/*! \file
 * Miguel Torres Alonso
 */

#include "union.h"

using namespace _colors_ne;

_union::_union()
{

}

void _union::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,0.4,-0.55);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1,ajustar_altura_respaldo,1);
        glScalef(0.1,1,0.1);
        soporte.draw_point();
    glPopMatrix();

    respaldo.draw_points(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _union::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,0.4,-0.55);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1,ajustar_altura_respaldo,1);
        glScalef(0.1,1,0.1);
        soporte.draw_line();
    glPopMatrix();

    respaldo.draw_line(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _union::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,0.4,-0.55);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1,ajustar_altura_respaldo,1);
        glScalef(0.1,1,0.1);
        soporte.draw_fill();
    glPopMatrix();

    respaldo.draw_fill(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _union::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,0.4,-0.55);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1,ajustar_altura_respaldo,1);
        glScalef(0.1,1,0.1);
        soporte.draw_chess();
    glPopMatrix();

    respaldo.draw_chess(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}
