/*! \file
 * Miguel Torres Alonso
 */

#include "base.h"

using namespace _colors_ne;

_base::_base()
{

}

void _base::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        base_delantera_der.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_delantera_izq.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_der.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_izq.draw_point();
    glPopMatrix();

    piston.draw_points(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _base::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        base_delantera_der.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_delantera_izq.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_der.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_izq.draw_line();
    glPopMatrix();

    piston.draw_line(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);

}

void _base::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        base_delantera_der.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_delantera_izq.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_der.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_izq.draw_fill();
    glPopMatrix();

    piston.draw_fill(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _base::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        base_delantera_der.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_delantera_izq.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_der.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_izq.draw_chess();
    glPopMatrix();

    piston.draw_chess(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _base::draw_flat_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        base_delantera_der.draw_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_delantera_izq.draw_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_der.draw_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_izq.draw_flat_shading();
    glPopMatrix();

    piston.draw_flat_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);


}

void _base::draw_smooth_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        base_delantera_der.draw_smooth_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_delantera_izq.draw_smooth_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_der.draw_smooth_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(-135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        glTranslatef(-3,0,0);
        glTranslatef(0,0,0);
        base_trasera_izq.draw_smooth_shading();
    glPopMatrix();

    piston.draw_smooth_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);


}
