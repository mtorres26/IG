/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "revolution_object.h"
#include "ply_object.h"
#include "wheel.h"
#include "backboard.h"
#include "piston.h"
#include "seat.h"
#include "union.h"
#include "base.h"
#include "chair.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_CONE,OBJECT_CYLINDER,OBJECT_SPHERE,OBJECT_PLY,OBJECT_WHEEL,OBJECT_BASE,OBJECT_PISTON,OBJECT_SEAT,OBJECT_UNION,OBJECT_BACKBOARD,OBJECT_CHAIR} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();
  void funcion_animacion();

  void luces();
  void materiales();

public slots:


private slots:

protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _cone Cone;
  _cylinder Cylinder;
  _sphere Sphere;
  _revolution_object Revolution_Object;
  _ply_object Ply;
  _wheel Wheel;
  _base Base;
  _piston Piston;
  _seat Seat;
  _union Union;
  _backboard Backboard;
  _chair Chair;

  QTimer *Timer;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
  bool Draw_flat_shading;
  bool Draw_smooth_shading;

  bool animacion = false;

  float altura_respaldo = 1.0;
  float giro_asiento = 0.0;
  float inclinacion_asiento = 0.0;
  float altura_asiento = 1.0;


  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
  float giro_luz;



};

#endif
