#ifndef CONE_H
#define CONE_H

/*! \file
 * Miguel Torres Alonso
 *
 */

#include "object3d.h"
#include "revolution_object.h"
/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cone:public _revolution_object
{
public:
  _cone(float radio = 1, float altura = 1, int m = 100);
    void draw();
};

#endif // CONE_H
