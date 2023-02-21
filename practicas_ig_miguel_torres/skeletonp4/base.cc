/*! \file
 * Miguel Torres Alonso
 */

#include "base.h"

using namespace _colors_ne;

_base::_base()
{

}

// Quinto elemento, se transforma y se llama al elemento precedente que engloba a los anteriores
void _base::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,0.15);
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,-0.15);
        glRotatef(135,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,-0.15);
        glRotatef(45,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_point();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,0.15);
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_point();
    glPopMatrix();

    piston.draw_points(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _base::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,0.15);
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,-0.15);
        glRotatef(135,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,-0.15);
        glRotatef(45,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_line();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,0.15);
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_line();
    glPopMatrix();

    piston.draw_line(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);

}

void _base::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,0.15);
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,-0.15);
        glRotatef(135,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,-0.15);
        glRotatef(45,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_fill();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,0.15);
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_fill();
    glPopMatrix();

    piston.draw_fill(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _base::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,0.15);
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,-0.15);
        glRotatef(135,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,-0.15);
        glRotatef(45,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_chess();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,0.15);
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_chess();
    glPopMatrix();

    piston.draw_chess(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _base::draw_flat_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,0.15);
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,-0.15);
        glRotatef(135,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,-0.15);
        glRotatef(45,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_flat_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,0.15);
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_flat_shading();
    glPopMatrix();

    piston.draw_flat_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);


}

void _base::draw_smooth_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,0.15);
        glRotatef(45,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_smooth_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.15,0.22,-0.15);
        glRotatef(135,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_smooth_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,-0.15);
        glRotatef(45,0,1,0);
        glRotatef(45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_smooth_shading();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0.15,0.22,0.15);
        glRotatef(135,0,1,0);
        glRotatef(-45,0,0,1);
        glScalef(0.1,0.5,0.1);
        base.draw_smooth_shading();
    glPopMatrix();

    piston.draw_smooth_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}
