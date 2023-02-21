/*! \file
 * Miguel Torres Alonso
 *
 */


#include "cone.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cone::_cone(float radio, float altura, int num_perfiles)
{
    vector<_vertex3f> perfil;
    perfil.resize(3);

    // Coordenadas de cada vértice que forma el perfil
    perfil[0] = _vertex3f(0, -altura/2, 0); // cierre de tapa inferior
    perfil[1] = _vertex3f(radio,-altura/2, 0); // radio del cono
    perfil[2] = _vertex3f(0, altura/2, 0); // vertice superior

    revolucionar(perfil,num_perfiles);

    // Al cambiar el orden de los vertices del perfil (el 0 por el 2 por ejemplo), se crea mal
}

