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
