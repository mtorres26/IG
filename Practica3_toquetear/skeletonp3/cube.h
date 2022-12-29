#ifndef CUBE_H
#define CUBE_H

/*! \file
 * Miguel Torres Alonso
 *
 */

#include "object3d.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cube:public _object3D
{
public:
  _cube(float Size=1.0);
  void draw();

};

#endif // CUBE_H
