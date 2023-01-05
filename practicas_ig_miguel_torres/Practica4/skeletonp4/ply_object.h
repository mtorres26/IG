#ifndef PLY_OBJECT_H
#define PLY_OBJECT_H



/*! \file
 * Miguel Torres Alonso
 *
 */

#include "object3d.h"
#include "file_ply_stl.h"

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _ply_object:public _file_ply
{
public:
  _ply_object(string archivo= "/home/mtorres/PracIG/ply_models/big_porsche.ply");
  int cargar(const string &archivo);
};


#endif // PLY_OBJECT_H
