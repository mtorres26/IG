/*! \file
 * Miguel Torres Alonso
 *
 */

#include "wheel.h"

using namespace _colors_ne;

_wheel::_wheel()
{

}


void _wheel::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-3,0,3);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda_delantera_der.draw_point();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(3,0,3);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda_delantera_izq.draw_point();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-3,0,-3);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda_trasera_der.draw_point();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(3,0,-3);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda_trasera_izq.draw_point();
    glPopMatrix();

    base.draw_points(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _wheel::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-3,0,3);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda_delantera_der.draw_line();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(3,0,3);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda_delantera_izq.draw_line();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-3,0,-3);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda_trasera_der.draw_line();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(3,0,-3);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda_trasera_izq.draw_line();
    glPopMatrix();

    base.draw_line(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _wheel::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLACK);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-3,0,3);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda_delantera_der.draw_fill();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(3,0,3);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda_delantera_izq.draw_fill();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-3,0,-3);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda_trasera_der.draw_fill();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(3,0,-3);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda_trasera_izq.draw_fill();
    glPopMatrix();

    base.draw_fill(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _wheel::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-3,0,3);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda_delantera_der.draw_chess();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(3,0,3);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda_delantera_izq.draw_chess();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(-3,0,-3);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda_trasera_der.draw_chess();
    glPopMatrix();

    glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(3,0,-3);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda_trasera_izq.draw_chess();
    glPopMatrix();

    base.draw_chess(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}
