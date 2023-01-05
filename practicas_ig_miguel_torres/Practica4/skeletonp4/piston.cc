/*! \file
 * Miguel Torres Alonso
 */

#include "piston.h"

using namespace _colors_ne;
_piston::_piston()
{

}

void _piston::draw_points(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(1,ajustar_altura_asiento,1);
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_point();
    glPopMatrix();

    asiento.draw_points(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _piston::draw_line(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(1,ajustar_altura_asiento,1);
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_line();
    glPopMatrix();

    asiento.draw_line(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _piston::draw_fill(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(1,ajustar_altura_asiento,1);
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_fill();
    glPopMatrix();

    asiento.draw_fill(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _piston::draw_chess(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(1,ajustar_altura_asiento,1);
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_chess();
    glPopMatrix();

    asiento.draw_chess(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);
}

void _piston::draw_flat_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(1,ajustar_altura_asiento,1);
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_flat_shading();
    glPopMatrix();

    asiento.draw_flat_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);


}

void _piston::draw_smooth_shading(float ajustar_altura_respaldo, float girar_asiento, float inclinar_asiento, float ajustar_altura_asiento)
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(1,ajustar_altura_asiento,1);
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_smooth_shading();
    glPopMatrix();

    asiento.draw_smooth_shading(ajustar_altura_respaldo,girar_asiento,inclinar_asiento,ajustar_altura_asiento);


}
