/*! \file
 * Miguel Torres Alonso
 */

#include "backboard.h"
#include <QTimer>

using namespace _colors_ne;

_backboard::_backboard()
{

}

// Primer elemento del modelo jerarquico.
void _backboard::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0,-0.45);
        glTranslatef(0,ajustar_altura_respaldo,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1.2,0.9,0.2);
        respaldo.draw_point();
    glPopMatrix();
}

void _backboard::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0,-0.45);
        glTranslatef(0,ajustar_altura_respaldo,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1.2,0.9,0.2);
        respaldo.draw_line();
    glPopMatrix();
}

void _backboard::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLUE);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0,-0.45);
        glTranslatef(0,ajustar_altura_respaldo,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1.2,0.9,0.2);
        respaldo.draw_fill();
    glPopMatrix();
}

void _backboard::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0,-0.45);
        glTranslatef(0,ajustar_altura_respaldo,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1.2,0.9,0.2);
        respaldo.draw_chess();
    glPopMatrix();
}

void _backboard::draw_flat_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0,-0.45);
        glTranslatef(0,ajustar_altura_respaldo,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1.2,0.9,0.2);
        respaldo.draw_flat_shading();
    glPopMatrix();

}

void _backboard::draw_smooth_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0,-0.45);
        glTranslatef(0,ajustar_altura_respaldo,0);
        glRotatef(inclinar_asiento,1,0,0);
        glTranslatef(0,ajustar_altura_asiento,0);
        glRotatef(girar_asiento,0,1,0);
        glScalef(1.2,0.9,0.2);
        respaldo.draw_smooth_shading();
    glPopMatrix();

}
