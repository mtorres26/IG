#ifndef SPHERE_H
#define SPHERE_H


#include "object3d.h"
#include "revolution_object.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _sphere:public _revolution_object
{
public:
  _sphere(float radio = 0.5, float num_divisiones = 50.0, int num_perfiles = 50);

  void calcular_normales_vertices();
};

#endif // SPHERE_H
