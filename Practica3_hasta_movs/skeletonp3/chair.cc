/*! \file
 * Miguel Torres Alonso
 */

#include "chair.h"

using namespace _colors_ne;

_chair::_chair()
{

}

void _chair::draw_points()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_points();
    glPopMatrix();
}

void _chair::draw_line()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_line();
    glPopMatrix();

}

void _chair::draw_fill()
{
    glColor3fv((GLfloat *) &BLACK);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_fill();
    glPopMatrix();
}

void _chair::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,-1,0);
        silla.draw_chess();
    glPopMatrix();
}

