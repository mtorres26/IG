/*! \file
 * Miguel Torres Alonso
 */

#include "seat.h"

using namespace _colors_ne;

_seat::_seat()
{

}

void _seat::draw_points()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0.9,0);
        glScalef(1,0.1,1);
        asiento.draw_point();
    glPopMatrix();

    soporte.draw_points();
}

void _seat::draw_line()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0.9,0);
        glScalef(1,0.1,1);
        asiento.draw_line();
    glPopMatrix();


    soporte.draw_line();
}

void _seat::draw_fill()
{
    glColor3fv((GLfloat *) &BLUE);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0.9,0);
        glScalef(1,0.1,1);
        asiento.draw_fill();
    glPopMatrix();

    soporte.draw_fill();
}

void _seat::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0.9,0);
        glScalef(1,0.1,1);
        asiento.draw_chess();
    glPopMatrix();

    soporte.draw_chess();
}


