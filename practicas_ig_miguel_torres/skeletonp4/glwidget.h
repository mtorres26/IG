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
#include "chess_board.h"


namespace _gl_widget_ne {

    const float X_MIN=-.1;
    const float X_MAX=.1;
    const float Y_MIN=-.1;
    const float Y_MAX=.1;
    const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
    const float BACK_PLANE_PERSPECTIVE=1000;
    const float DEFAULT_DISTANCE=2;
    const float ANGLE_STEP=1;

    typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_CONE,OBJECT_CYLINDER,OBJECT_SPHERE,OBJECT_PLY,OBJECT_WHEEL,OBJECT_BASE,OBJECT_PISTON,OBJECT_SEAT,OBJECT_UNION,OBJECT_BACKBOARD,OBJECT_CHAIR, OBJECT_CHESSBOARD} _object;
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

    void lights();
    void materials();
    void disable_lights();

    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

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

    _gl_widget_ne::_object Object;

    bool Draw_point;
    bool Draw_line;
    bool Draw_fill;
    bool Draw_chess;
    bool Draw_flat_shading;
    bool Draw_smooth_shading;

    bool Light0;
    bool Light1;

    // Declaración e inicializacion de luces
    // Parametros luz0 blanca
    GLfloat luz_posicion_blanca[4]={0.0, 0.0, 1.0, 0.0}; // w = 0, luz en infinito
    GLfloat luz_ambiente_blanca[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat luz_difusa_blanca[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat luz_especular_blanca[4]={1.0, 1.0, 1.0, 1.0};

    // Parametros luz1 blanca
    GLfloat luz_posicion_magenta[4]={0.0, 0.0, 1.0, 1.0}; /// w no es 0, luz no esta en infinito
    GLfloat luz_ambiente_magenta[4]={1.0, 0.0, 1.0, 1.0};
    GLfloat luz_difusa_magenta[4]={1.0, 0.0, 1.0, 1.0};
    GLfloat luz_especular_magenta[4]={1.0, 0.0, 1.0, 1.0};


    // Declaracion de materiales, inicializacion en constructor
    int material;
    _vertex4f ambiente[3];
    _vertex4f difusa[3];
    _vertex4f especular[3];
    GLfloat brillo[3];
    _vertex4f emision[3];

    float altura_respaldo = 1.0;
    float giro_asiento = 0.0;
    float inclinacion_asiento = 0.0;
    float altura_asiento = 1.0;
    bool speed_altura_respaldo;
    bool speed_giro_asiento;
    bool speed_inclinacion_asiento;
    bool speed_altura_asiento;
    float modificar_altura_respaldo;
    float modificar_giro_asiento;
    float modificar_inclinacion_asiento;
    float modificar_altura_asiento;

    float SensibilidadRueda;
    QPoint MouseCoordinates;


    float Observer_angle_x;
    float Observer_angle_y;
    float Observer_distance;

};

#endif
