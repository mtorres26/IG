/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"
#include "object3d.h"
#include <QTimer>

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(400, 400);
  setFocusPolicy(Qt::StrongFocus);





/*
  QTimer *cronometro = new QTimer(this);
  connect(cronometro,SIGNAL(timeout()),this,SLOT(funcion_animacion()));
  cronometro->start(0);
*/
}



/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/


void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_7:Object=OBJECT_CHAIR;break;

  case Qt::Key_Q:if(altura_respaldo<1.05){altura_respaldo+=0.05;};break;
  case Qt::Key_W:if(altura_respaldo>0.90){altura_respaldo-=0.05;};break;
  case Qt::Key_S:if(giro_asiento<10){giro_asiento+=1;};break;
  case Qt::Key_D:if(giro_asiento>-10){giro_asiento-=1;};break;
  case Qt::Key_Z:if(inclinacion_asiento<5){inclinacion_asiento+=1;};break;
  case Qt::Key_X:if(inclinacion_asiento>-5){inclinacion_asiento-=1;};break;
  case Qt::Key_E:if(altura_asiento<1.05){altura_asiento+=0.05;};break;
  case Qt::Key_R:if(altura_asiento>0.95){altura_asiento-=0.05;};break;


  //case Qt::Key_A:;break;



/*
  case Qt::Key_T:
  case Qt::Key_Y:
  case Qt::Key_U:
  case Qt::Key_I:
*/

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;



  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:Observer_distance*=1.2;break;
  case Qt::Key_PageDown:Observer_distance/=1.2;break;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case OBJECT_PLY:Ply.draw_point();break;
    case OBJECT_CHAIR:Chair.draw_points(altura_respaldo,giro_asiento,inclinacion_asiento,altura_asiento);break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_PLY:Ply.draw_line();break;
    case OBJECT_CHAIR:Chair.draw_line(altura_respaldo,giro_asiento,inclinacion_asiento,altura_asiento);break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_CONE:Cone.draw_fill();break;
    case OBJECT_CYLINDER:Cylinder.draw_fill();break;
    case OBJECT_SPHERE:Sphere.draw_fill();break;
    case OBJECT_PLY:Ply.draw_fill();break;
    case OBJECT_CHAIR:Chair.draw_fill(altura_respaldo,giro_asiento,inclinacion_asiento,altura_asiento);break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess();break;
    case OBJECT_PLY:Ply.draw_chess();break;
    case OBJECT_CHAIR:Chair.draw_chess(altura_respaldo,giro_asiento,inclinacion_asiento,altura_asiento);break;
    default:break;
    }
  }


}


void _gl_widget::funcion_animacion()
{
/*
    altura_respaldo = 1.5;
    giro_asiento = 0.0;
    inclinacion_asiento = 0.0;
    altura_asiento = 1.0;
*/
/*
    altura_respaldo=1.7;

    altura_respaldo=1.3;

    altura_respaldo=1.5;
*/
  /*
    giro_asiento+=ANGLE_STEP;

    giro_asiento=-10;

    giro_asiento=0.0;

    inclinacion_asiento=5;

    inclinacion_asiento=-5;

    inclinacion_asiento=0.0;

    altura_asiento=1.1;

    altura_asiento=0.9;

    altura_asiento=1.0;
*/
    if(altura_respaldo<1.05){altura_respaldo+=0.05;};

    if(altura_respaldo>0.90){altura_respaldo-=0.05;};

    if(giro_asiento<10){giro_asiento+=1;};

    if(giro_asiento>-10){giro_asiento-=1;};
    if(inclinacion_asiento<5){inclinacion_asiento+=1;};
    if(inclinacion_asiento>-5){inclinacion_asiento-=1;};
    if(altura_asiento<1.05){altura_asiento+=0.05;};
    if(altura_asiento>0.95){altura_asiento-=0.05;};

    update();
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(0.15,0.15,0.15,0.15);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;
}
