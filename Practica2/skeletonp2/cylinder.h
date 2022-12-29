#ifndef CYLINDER_H
#define CYLINDER_H





#include "object3d.h"
#include "revolution_object.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cylinder:public _revolution_object
{
public:
  _cylinder(float radio = 1, float altura = 1, int m = 100);

};

#endif // CYLINDER_H
