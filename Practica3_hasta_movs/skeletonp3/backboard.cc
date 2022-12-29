/*! \file
 * Miguel Torres Alonso
 */

#include "backboard.h"

using namespace _colors_ne;

_backboard::_backboard()
{

}

void _backboard::draw_points()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,2,-0.45);
        glScalef(0.6,0.5,0.1);
        glRotatef(25,0,1,0);
        respaldo.draw_point();
    glPopMatrix();
}

void _backboard::draw_line()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,2,-0.45);
        glScalef(0.6,0.5,0.1);
        glRotatef(25,0,1,0);
        respaldo.draw_line();
    glPopMatrix();
}

void _backboard::draw_fill()
{
    glColor3fv((GLfloat *) &BLUE);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,2,-0.45);
        glScalef(0.6,0.5,0.1);
        glRotatef(25,0,1,0);
        respaldo.draw_fill();
    glPopMatrix();
}

void _backboard::draw_chess()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,2,-0.45);
        glScalef(0.6,0.5,0.1);
        glRotatef(25,0,1,0);
        respaldo.draw_chess();
    glPopMatrix();
}
