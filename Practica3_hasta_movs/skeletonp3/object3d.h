/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS,MODE_DRAW_REVOLUTION} _mode_draw;
typedef enum {CYLINDER,SPHERE,CONE} _figura;

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3ui> Quads;

  void draw_points();
  void draw_line();
  void draw_fill();
  void draw_chess() ;
  void draw(_mode_draw mode);
  void draw();


};

#endif // OBJECT3D_H
