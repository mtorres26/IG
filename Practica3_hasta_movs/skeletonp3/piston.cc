/*! \file
 * Miguel Torres Alonso
 */

#include "piston.h"

using namespace _colors_ne;
_piston::_piston()
{

}

void _piston::draw_points()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_point();
    glPopMatrix();


    asiento.draw_points();
}

void _piston::draw_line()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_line();
    glPopMatrix();

    glPushMatrix();
        glRotatef(rotacion_asiento,0,1,0);
        asiento.draw_line();
    glPopMatrix();
}

void _piston::draw_fill()
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_fill();
    glPopMatrix();

    asiento.draw_fill();
}

void _piston::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.16,0.5,0.16);
        glTranslatef(0,1.25,0);
        piston.draw_chess();
    glPopMatrix();

    asiento.draw_chess();
}
