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

  vector<_vertex3f> Normales_Triangulos;
  vector<_vertex3f> Normales_Vertices;

  GLfloat luz_posicion[4]={0.0, 0.0, 1.0, 0.0};
  GLfloat luz_ambiente[4]={0.0, 0.0, 0.0, 1.0};
  GLfloat luz_difusa[4]={1.0, 1.0, 1.0, 1.0};
  GLfloat luz_especular[4]={6.0, 6.0, 6.0, 1.0};

  GLfloat material_ambiente[4] = {0.2, 0.2, 0.2, 1.0};
  GLfloat material_difusa[4] = {0.8, 0.8, 0.8, 1.0};
  GLfloat material_especular[4]={6.0, 6.0, 6.0, 1.0};
  GLfloat material_brillo = 10;
  GLfloat material_emision[4]={0.0, 0.0, 0.0, 1.0};

  void draw_points();
  void draw_line();
  void draw_fill();
  void draw_chess();

  void draw_flat_shading();
  void draw_smooth_shading();

  void calcular_normales_triangulos();
  void calcular_normales_vertices();

};

#endif // OBJECT3D_H
