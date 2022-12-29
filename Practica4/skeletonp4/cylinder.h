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

  _cylinder(float radio = 0.5, float altura =1, int m=100);
  void create(float radio = 0.5, float altura =1);
  void draw(_mode_draw mode);

};

#endif // CYLINDER_H
