/*! \file
 * Miguel Torres Alonso
 *
 */

#include "wheel.h"

using namespace _colors_ne;

_wheel::_wheel()
{

}

// Sexto elemento del modelo jerarquico
void _wheel::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_point();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_point();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_point();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_point();
    glPopMatrix();

    base.draw_points(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _wheel::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_line();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_line();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_line();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_line();
    glPopMatrix();

    base.draw_line(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _wheel::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLACK);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_fill();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_fill();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_fill();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_fill();
    glPopMatrix();

    base.draw_fill(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _wheel::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_chess();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_chess();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_chess();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_chess();
    glPopMatrix();

    base.draw_chess(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _wheel::draw_flat_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_flat_shading();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_flat_shading();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_flat_shading();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_flat_shading();
    glPopMatrix();

    base.draw_flat_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);


}

void _wheel::draw_smooth_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(-0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_smooth_shading();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(-45,1,0,0);
        rueda.draw_smooth_shading();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(-90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_smooth_shading();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3,0,-0.3);
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,0,1);
        glRotatef(45,1,0,0);
        rueda.draw_smooth_shading();
    glPopMatrix();

    base.draw_smooth_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);

}

