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
  _sphere(float radio = 1,int n = 100, int m = 60);
};

#endif // SPHERE_H
