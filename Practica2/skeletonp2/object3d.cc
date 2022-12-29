/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"
#include "glwidget.h"

using namespace _colors_ne;
using namespace _gl_widget_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

/*
void _object3D::draw_points(){
    glColor3f(1,0,1);
    glBegin(GL_POINTS);
    for(unsigned int i=0;i<Vertices.size();i++){
        glVertex3fv((GLfloat *) &Vertices[i]);
    }
}
*/

void _object3D::draw_line()
{
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    for(unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();

}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{

    glColor3f(1,0.5,0);
    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        glColor3f(i%2,0.5,0);
    }
    glEnd();
}


