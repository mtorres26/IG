/*! \file
 * Miguel Torres Alonso
 */

#include "union.h"

using namespace _colors_ne;

_union::_union()
{

}

void _union::draw_points()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,1.4,-0.55);
        glScalef(0.1,1,0.1);
        soporte.draw_point();
    glPopMatrix();

    respaldo.draw_points();
}

void _union::draw_line()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,1.4,-0.55);
        glScalef(0.1,1,0.1);
        soporte.draw_line();
    glPopMatrix();

    respaldo.draw_line();
}

void _union::draw_fill()
{
    glColor3fv((GLfloat *) &BLACK);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,1.4,-0.55);
        glScalef(0.1,1,0.1);
        soporte.draw_fill();
    glPopMatrix();

    respaldo.draw_fill();
}

void _union::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,1.4,-0.55);
        glScalef(0.1,1,0.1);
        soporte.draw_chess();
    glPopMatrix();

    respaldo.draw_chess();
}
