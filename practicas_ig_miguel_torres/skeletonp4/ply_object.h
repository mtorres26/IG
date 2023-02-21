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
    // Se le pasa al constructor la ruta del archivo PLY que queremos cargar
  _ply_object(const string &fichero_ply= "/home/mtorres/PracIG/ply_models/big_porsche.ply");
};


#endif // PLY_OBJECT_H
