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

void _object3D::draw_line()
{
    glPolygonMode(GL_FRONT,GL_LINE);

    glBegin(GL_LINES);
    for(unsigned int i=0;i<Triangles.size();i++)
    {
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
    glPolygonMode(GL_FRONT,GL_FILL);
    //glEnable(GL_CULL_FACE); // Para que no se dibuje el interior del objeto

    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<Triangles.size();i++)
    {
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    //glDisable(GL_CULL_FACE);

}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT,GL_FILL);
    //glEnable(GL_CULL_FACE); // Para que no se dibuje el interior del objeto

    glBegin(GL_TRIANGLES);
    glColor3f(1,0.5,0); // Para que no se quede un triangulo del color del fill
    for(unsigned int i=0;i<Triangles.size();i++)
    {
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        glColor3f(i%2,0.5,0); // Se va cambiando de color en cada iteracion
    }
    glEnd();
    //glDisable(GL_CULL_FACE);

}

void _object3D::calcular_normales_triangulos()
{
    _vertex3f vec1, vec2, normal;
    Normales_Triangulos.resize(Triangles.size());
    for(unsigned int i=0; i<Triangles.size(); i++)
    {
        Normales_Triangulos[i]= _vertex3f(0.0, 0.0, 0.0);
        // Obtener dos vectores en el triángulo y calcular el producto vectorial
        // cuya normal tiene que apuntar hacia fuera del objeto
        vec1=Vertices[Triangles[i]._1]-Vertices[Triangles[i]._0];
        vec2=Vertices[Triangles[i]._2]-Vertices[Triangles[i]._0];
        normal=vec1.cross_product(vec2); // Producto vectorial de vec1 con vec2
        // Metemos la normal calculada en el vector y llamamos a la funcion normalize()
        Normales_Triangulos[i] = normal;
        Normales_Triangulos[i].normalize();
    }
}


void _object3D::calcular_normales_vertices()
{
    //Para hacer la normal a un vértice, necesitamos las normales a las caras
    calcular_normales_triangulos();
    Normales_Vertices.resize(Vertices.size());

    //Poner todas las normales a 0
    for(unsigned int i = 0; i < Vertices.size(); i++)
    {
        Normales_Vertices[i] = _vertex3f(0.0,0.0,0.0);
    }

    for(unsigned int i = 0; i < Triangles.size(); i++)
    {
        //Procedimiento: sumarle a los 3 vértices que pertenecen a una cara,
        //el valor de la normal a esa cara. Luego normalizamos
        Normales_Vertices[Triangles[i]._0] += Normales_Triangulos[i];
        Normales_Vertices[Triangles[i]._1] += Normales_Triangulos[i];
        Normales_Vertices[Triangles[i]._2] += Normales_Triangulos[i];
    }

    for(unsigned int i = 0; i < Vertices.size(); i++)
    {
        //Normalizar la normal a cada vertice
        Normales_Vertices[i].normalize(); //función para normalizar
    }
}


void _object3D::draw_flat_shading()
{
    calcular_normales_triangulos();

    glEnable(GL_CULL_FACE);// Elimina de los calculos los triangulos que miren
                         // hacia el otro lado del observador

    glEnable(GL_NORMALIZE); // Si no se llama a glNormalize, hay cambios bruscos en la iluminacion
                            // y parece que esta buggeado
    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_TRIANGLES);
        for (unsigned int i=0;i < Triangles.size();i++)
        {
            glNormal3fv((GLfloat *) &Normales_Triangulos[i]); // Normal del triangulo i
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]); // Vertices del triangulo i
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    glEnd();

    glDisable(GL_NORMALIZE);
    glDisable(GL_CULL_FACE);

}

void _object3D::draw_smooth_shading()
{
    calcular_normales_vertices();

    glEnable(GL_CULL_FACE);// Elimina de los calculos los triangulos que miren
                         // hacia el otro lado del observador
    glEnable(GL_NORMALIZE); // Si no se llama a glNormalize, hay cambios bruscos en la iluminacion
                            // y parece que esta buggeado
    glShadeModel(GL_SMOOTH);

    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);
        for(unsigned int i = 0; i < Triangles.size(); i++)
        {
            glNormal3fv((GLfloat*) &Normales_Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat*) &Vertices[Triangles[i]._0]);
            glNormal3fv((GLfloat*) &Normales_Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat*) &Vertices[Triangles[i]._1]);
            glNormal3fv((GLfloat*) &Normales_Vertices[Triangles[i]._2]);
            glVertex3fv((GLfloat*) &Vertices[Triangles[i]._2]);
        }
    glEnd();

    glDisable(GL_NORMALIZE);
    glDisable(GL_CULL_FACE);
}

