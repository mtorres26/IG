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
    perfil.resize(4);

    perfil[0] = _vertex3f(0, -altura/2, 0); // Cierre tapa inferior
    perfil[1] = _vertex3f(radio, -altura/2, 0); // Vertice esquina inferior
    perfil[2] = _vertex3f(radio, altura/2, 0); // Vertice esquina superior
    perfil[3] = _vertex3f(0, altura/2, 0); // Cierre tapa superior

    // Si cambio orden de vertices del perfil, se crea mal

    revolucionar(perfil,num_perfiles);
}

