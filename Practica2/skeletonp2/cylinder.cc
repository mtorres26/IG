/*! \file
 * Miguel Torres Alonso
 *
 */


#include "cylinder.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cylinder::_cylinder(float radio, float altura, int num_perfiles)
{

    vector<_vertex3f> perfil;
    _vertex3f vertice_aux;

    vertice_aux.x= radio;
    vertice_aux.y = -altura/2.0;
    vertice_aux.z = 0.0;
    perfil.push_back(vertice_aux);

    vertice_aux.x= radio;
    vertice_aux.y = altura/2.0;
    vertice_aux.z = 0.0;
    perfil.push_back(vertice_aux);

    vertice_aux.x= 0.0;
    vertice_aux.y = altura/2.0;
    vertice_aux.z = 0.0;
    perfil.push_back(vertice_aux);

    vertice_aux.x = 0.0;
    vertice_aux.y = -altura/2.0;
    vertice_aux.z = 0.0;
    perfil.push_back(vertice_aux);

    revolucionar(perfil,num_perfiles,1);

}
