#ifndef CONE_H
#define CONE_H

/*! \file
 * Miguel Torres Alonso
 *
 */

#include "revolution_object.h"
/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _cone:public _revolution_object
{
public:
  _cone(float radio = 1, float altura = 1, int m = 50);

};

#endif // CONE_H
