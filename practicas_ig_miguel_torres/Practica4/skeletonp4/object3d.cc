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


    glBegin(GL_TRIANGLES);
    for(unsigned int i=0;i<Triangles.size();i++)
    {
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
    glPolygonMode(GL_FRONT,GL_FILL);

    glBegin(GL_TRIANGLES);
    glColor3f(1,0.5,0); // Para que no se quede un triangulo del color del fill
    for(unsigned int i=0;i<Triangles.size();i++)
    {
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        glColor3f(i%2,0.5,0);
    }
    glEnd();
}

void _object3D::calcular_normales_triangulos()
{
    _vertex3f vec1, vec2, normal;
    Normales_Triangulos.resize(Triangles.size());
    for(unsigned int i=0; i<Triangles.size(); i++)
    {
        // Obtener dos vectores en el triángulo y calcular el producto vectorial
        vec1=Vertices[Triangles[i]._1]-Vertices[Triangles[i]._0];
        vec2=Vertices[Triangles[i]._2]-Vertices[Triangles[i]._0];
        normal=vec1.cross_product(vec2);
        // Modulo
        // float m = sqrt(normal.x*normal.x+normal.y*normal.y+normal.z*normal.z);
        // Normalización
        // Normales_Triangulos[i]= _vertex3f(normal.x/m, normal.y/m, normal.z/m);
        Normales_Triangulos[i].normalize(); // Funcion para normalizar
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
        Normales_Vertices[i].normalize(); //función de vector<_vertex3f> para normalizar
    }
}


void _object3D::draw_flat_shading()
{
    /*
        glEnable(GL_CULL_FACE);// Elimina de los calculos los triangulos que miren
                             // hacia el otro lado del observador
        glCullFace(GL_BACK);
        glFrontFace(GL_CW);  // Hace trampa y decide que las caras frontales son las
                             // que están en sentido horario en vez de antihorario
    */

        calcular_normales_triangulos();
        glEnable(GL_LIGHTING);
        glEnable(GL_NORMALIZE);
        glShadeModel(GL_FLAT);

    /*        glEnable (GL_LIGHT0);
            glLightfv (GL_LIGHT0, GL_POSITION, (GLfloat *) &luz_posicion);
            glLightfv (GL_LIGHT0, GL_AMBIENT, (GLfloat *) &luz_ambiente);
            glLightfv (GL_LIGHT0, GL_DIFFUSE, (GLfloat *) &luz_difusa);
            glLightfv (GL_LIGHT0, GL_SPECULAR, (GLfloat *) &luz_especular);
    */
    /*
            glEnable (GL_LIGHT1);
            glLightfv (GL_LIGHT1, GL_AMBIENT, (GLfloat *) &luz_ambiente);
            glLightfv (GL_LIGHT1, GL_DIFFUSE, (GLfloat *) &luz_difusa);
            glLightfv (GL_LIGHT1, GL_SPECULAR, (GLfloat *) &luz_especular);
            glLightfv (GL_LIGHT1, GL_POSITION, (GLfloat *) &luz_posicion);


            glEnable (GL_LIGHT2);
            glLightfv (GL_LIGHT2, GL_AMBIENT, (GLfloat *) &luz_ambiente);
            glLightfv (GL_LIGHT2, GL_DIFFUSE, (GLfloat *) &luz_difusa);
            glLightfv (GL_LIGHT2, GL_SPECULAR, (GLfloat *) &luz_especular);
            glLightfv (GL_LIGHT2, GL_POSITION, (GLfloat *) &luz_posicion);
    */

        glEnable(GL_COLOR_MATERIAL);
        //glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
        //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, (GLfloat *) &luz_ambiente);
        //glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, (GLfloat *) &material_difusa);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, (GLfloat *) &material_ambiente);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *) &material_especular);
        glMaterialfv(GL_FRONT, GL_EMISSION, (GLfloat *) &material_emision);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_brillo);

        glPolygonMode(GL_FRONT,GL_FILL);
        glBegin(GL_TRIANGLES);
            for (unsigned int i=0;i < Triangles.size();i++)
            {
                glNormal3fv((GLfloat *) &Normales_Triangulos[i]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
                glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
            }
        glEnd();

    glDisable(GL_NORMALIZE);
    glDisable(GL_LIGHTING);


}

void _object3D::draw_smooth_shading()
{
/*
    glEnable(GL_CULL_FACE);// Elimina de los calculos los triangulos que miren
                         // hacia el otro lado del observador
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);  // Hace trampa y decide que las caras frontales son las
                         // que están en sentido horario en vez de antihorario
*/

    calcular_normales_vertices();
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

/*        glEnable (GL_LIGHT0);
        glLightfv (GL_LIGHT0, GL_POSITION, (GLfloat *) &luz_posicion);
        glLightfv (GL_LIGHT0, GL_AMBIENT, (GLfloat *) &luz_ambiente);
        glLightfv (GL_LIGHT0, GL_DIFFUSE, (GLfloat *) &luz_difusa);
        glLightfv (GL_LIGHT0, GL_SPECULAR, (GLfloat *) &luz_especular);
*/
        glEnable (GL_LIGHT1);
        glLightfv (GL_LIGHT1, GL_AMBIENT, (GLfloat *) &luz_ambiente);
        glLightfv (GL_LIGHT1, GL_DIFFUSE, (GLfloat *) &luz_difusa);
        glLightfv (GL_LIGHT1, GL_SPECULAR, (GLfloat *) &luz_especular);
        glLightfv (GL_LIGHT1, GL_POSITION, (GLfloat *) &luz_posicion);

/*
        glEnable (GL_LIGHT2);
        glLightfv (GL_LIGHT2, GL_AMBIENT, (GLfloat *) &luz_ambiente);
        glLightfv (GL_LIGHT2, GL_DIFFUSE, (GLfloat *) &luz_difusa);
        glLightfv (GL_LIGHT2, GL_SPECULAR, (GLfloat *) &luz_especular);
        glLightfv (GL_LIGHT2, GL_POSITION, (GLfloat *) &luz_posicion);
*/

    glEnable(GL_COLOR_MATERIAL);
    //glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, (GLfloat *) &luz_ambiente);
    //glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, (GLfloat *) &material_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, (GLfloat *) &material_ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, (GLfloat *) &material_especular);
    glMaterialfv(GL_FRONT, GL_EMISSION, (GLfloat *) &material_emision);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_brillo);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
    glDisable(GL_LIGHTING);
}
