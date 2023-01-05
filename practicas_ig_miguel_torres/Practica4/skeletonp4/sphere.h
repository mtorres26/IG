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
  _sphere(float radio = 1,int n = 60, int m = 60);

  void calcular_normales_vertices();
};

#endif // SPHERE_H
