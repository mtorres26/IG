/*! \file
 * Miguel Torres Alonso
 */

#include "base.h"

using namespace _colors_ne;

_base::_base()
{

}

void _base::draw_points()
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

    piston.draw_points();
}

void _base::draw_line()
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

    piston.draw_line();

}

void _base::draw_fill()
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

    piston.draw_fill();
}

void _base::draw_chess()
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

    piston.draw_chess();
}
