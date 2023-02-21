#ifndef REVOLUTION_OBJECT_H
#define REVOLUTION_OBJECT_H

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

class _revolution_object:public _object3D
{
public:
  _revolution_object();

  void revolucionar(vector<_vertex3f> perfil, int num);
};



#endif // REVOLUTION_OBJECT_H
