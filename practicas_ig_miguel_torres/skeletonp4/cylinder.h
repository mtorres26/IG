#ifndef CYLINDER_H
#define CYLINDER_H


#include "revolution_object.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cylinder:public _revolution_object
{
public:

  _cylinder(float radio = 0.5, float altura =1, int num_perfiles=50);

};

#endif // CYLINDER_H
