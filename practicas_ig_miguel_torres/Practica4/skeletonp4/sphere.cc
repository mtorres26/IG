/*! \file
 * Miguel Torres Alonso
 *
 */


#include "sphere.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_sphere::_sphere(float radio,int n, int num_perfiles)
{
    vector<_vertex3f> perfil;
    _vertex3f vertice_aux;


    for(int i = 1; i < n; i++)
    {

        vertice_aux.x = radio*cos(M_PI*i/n-M_PI/2.0);
        vertice_aux.y = radio*sin(M_PI*i/n-M_PI/2.0);
        vertice_aux.z = 0.0;
        perfil.push_back(vertice_aux);

    }

    revolucionar(perfil,num_perfiles,SPHERE);
}


void _sphere::calcular_normales_vertices()
{
    Normales_Vertices.resize(Vertices.size());

    for(unsigned int i = 0; i < Vertices.size(); i++) //Poner todas las normales a 0
    {
        Normales_Vertices[i] = _vertex3f(0.0,0.0,0.0);
        // Normal = Vertice - Centro, y Centro = 0.
        Normales_Vertices[i]._0 = Vertices[i]._0;
        Normales_Vertices[i]._1 = Vertices[i]._1;
        Normales_Vertices[i]._2 = Vertices[i]._2;
        Normales_Vertices[i].normalize(); //función de vector<_vertex3f> para normalizar
    }
}
