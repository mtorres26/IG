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
#include <QImageReader>


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

      // Teclas de movimiento de los grados de libertad
  case Qt::Key_Q:if(altura_respaldo<1.08){altura_respaldo+=modificar_altura_respaldo;};break;
  case Qt::Key_W:if(altura_respaldo>0.93){altura_respaldo-=modificar_altura_respaldo;};break;
  case Qt::Key_S:if(giro_asiento<10){giro_asiento+=modificar_giro_asiento;};break;
  case Qt::Key_D:if(giro_asiento>-10){giro_asiento-=modificar_giro_asiento;};break;
  case Qt::Key_Z:if(inclinacion_asiento<3){inclinacion_asiento+=modificar_inclinacion_asiento;};break;
  case Qt::Key_X:if(inclinacion_asiento>-3){inclinacion_asiento-=modificar_inclinacion_asiento;};break;
  case Qt::Key_E:if(altura_asiento<1.00){altura_asiento+=modificar_altura_asiento;};break;
  case Qt::Key_R:if(altura_asiento>0.95){altura_asiento-=modificar_altura_asiento;};break;

  // Para controlar la velocidad de cada grado de libertad, asigno a una tecla un bool que active o no
  // la velocidad. Si está activo, aumentará la variable float que modifica el grado de libertad y
  // si está desactivado, decrementará
  case Qt::Key_C:
      speed_altura_respaldo=!speed_altura_respaldo;
      if(speed_altura_respaldo)
      {
          modificar_altura_respaldo = 0.03;
      }
      else
      {
          modificar_altura_respaldo = 0.01;
      }
      break;
  case Qt::Key_V:
      speed_giro_asiento=!speed_giro_asiento;
      if(speed_giro_asiento)
      {
          modificar_giro_asiento = 4;
      }
      else
      {
          modificar_giro_asiento = 1;
      }
      break;
  case Qt::Key_B:
      speed_inclinacion_asiento=!speed_inclinacion_asiento;
      if(speed_inclinacion_asiento)
      {
          modificar_inclinacion_asiento = 2;
      }
      else
      {
          modificar_inclinacion_asiento = 1;
      }
      break;
  case Qt::Key_N:
      speed_altura_asiento=!speed_altura_asiento;
      if(speed_altura_asiento)
      {
          modificar_altura_asiento = 0.05;
      }
      else
      {
          modificar_altura_asiento = 0.01;
      }

      break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;

      // Activar o desactivar luces
  case Qt::Key_J:Light0=!Light0;break;
  case Qt::Key_K:Light1=!Light1;break;
  case Qt::Key_M:material = ((material + 1) % 3);break;

  case Qt::Key_F1:;break;
  case Qt::Key_F2:Draw_chess=!Draw_chess;break;
  case Qt::Key_F3:Draw_flat_shading=!Draw_flat_shading;break;
  case Qt::Key_F4:Draw_smooth_shading=!Draw_smooth_shading;break;
  case Qt::Key_F5:;break;
  case Qt::Key_F6:;break;
  case Qt::Key_F7:;break;

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

void _gl_widget::mousePressEvent(QMouseEvent *event)
{
    // Se llama a esta funcion cuando se hace click con el boton izq, se guarda el QPoint
    // de pos() en MouseCoordinates, y al arrastrar el raton por la pantalla, se llama a mouseMoveEvent
    if(event->buttons() == Qt::LeftButton){
        MouseCoordinates = event->pos();
    }

    update();
}

void _gl_widget::mouseMoveEvent(QMouseEvent *event)
{
    // El angulo que gira alrededor del eje x += coord 'Y' de donde he movido menos la coord 'Y' de donde
    // hice click en mousePressEvent. A partir de la primera vez que se ejecuta, se guarda en MouseCoordinates
    // el ultimo punto donde se arrastró el raton, para que al volver hacer click y arrastrar no tenga
    // en cuenta la ultima vez que se clicko, sino la ultima coordenada donde se arrastro
    Observer_angle_x += (event->pos().y() - MouseCoordinates.y());
    // Lo mismo pero con el otro eje
    Observer_angle_y += (event->pos().x() - MouseCoordinates.x());

    // Se actualizan las coordenadas del mouse
    MouseCoordinates = event->pos();

    update();
}

void _gl_widget::wheelEvent(QWheelEvent *event)
{
    // Se castea a float la coordenada 'Y' del angulo que ha girado la rueda del mouse
    // angleDelta devuelve un valor positivo si la rueda ha sido rotada para alante, lo que zoomea nuestra camara,
    // al contrario para alejar la camara

    Observer_distance -= ((float)(event->angleDelta().y())) * SensibilidadRueda;
    update();
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

  if (Draw_flat_shading){
    lights();
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_flat_shading();break;
    case OBJECT_CUBE:Cube.draw_flat_shading();break;
    case OBJECT_CONE:Cone.draw_flat_shading();break;
    case OBJECT_CYLINDER:Cylinder.draw_flat_shading();break;
    case OBJECT_SPHERE:Sphere.draw_flat_shading();break;
    case OBJECT_PLY:Ply.draw_flat_shading();break;
    case OBJECT_CHAIR:Chair.draw_flat_shading(altura_respaldo,giro_asiento,inclinacion_asiento,altura_asiento);break;
    default:break;
    }
  }

  if (Draw_smooth_shading){
    lights();
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_smooth_shading();break;
    case OBJECT_CUBE:Cube.draw_smooth_shading();break;
    case OBJECT_CONE:Cone.draw_smooth_shading();break;
    case OBJECT_CYLINDER:Cylinder.draw_smooth_shading();break;
    case OBJECT_SPHERE:Sphere.draw_smooth_shading();break;
    case OBJECT_PLY:Ply.draw_smooth_shading();break;
    case OBJECT_CHAIR:Chair.draw_smooth_shading(altura_respaldo,giro_asiento,inclinacion_asiento,altura_asiento);break;
    default:break;
    }
  }
}


void _gl_widget::lights()
{
    glEnable(GL_LIGHTING); // Activar iluminacion

    if(Light0){glEnable(GL_LIGHT0);} // Activar o desactivar luz0 y luz1
    else{glDisable(GL_LIGHT0);}

    if(Light1){glEnable(GL_LIGHT1);}
    else{glDisable(GL_LIGHT1);}

    // Modificar parametros de las luces
    glLightfv (GL_LIGHT0, GL_POSITION, (GLfloat *) &luz_posicion_blanca); // Luz0 en infinito
    glLightfv (GL_LIGHT0, GL_AMBIENT, (GLfloat *) &luz_ambiente_blanca);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, (GLfloat *) &luz_difusa_blanca);
    glLightfv (GL_LIGHT0, GL_SPECULAR, (GLfloat *) &luz_especular_blanca);

    glLightfv (GL_LIGHT1, GL_POSITION, (GLfloat *) &luz_posicion_magenta); // Luz1 no en infinito
    glLightfv (GL_LIGHT1, GL_AMBIENT, (GLfloat *) &luz_ambiente_magenta);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, (GLfloat *) &luz_difusa_magenta);
    glLightfv (GL_LIGHT1, GL_SPECULAR, (GLfloat *) &luz_especular_magenta);

    // La luz se desactiva con otra funcion
}

void _gl_widget::disable_lights() // Funcion que se llama en paintGL y en modos de draw que no haya luces
{
    glDisable(GL_LIGHTING);
}

void _gl_widget::materials()
{
    glEnable(GL_RESCALE_NORMAL);
    // Cada parametro es un vector de tamaño 3 donde cada posicion del vector es un material

    glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &difusa[material]);
    glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &ambiente[material]);
    glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &especular[material]);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo[material]);
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
  disable_lights();
  materials();
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

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=false;
  Draw_fill=false;
  Draw_chess=true;
  Draw_flat_shading=false;
  Draw_smooth_shading=false;

  Object = OBJECT_TETRAHEDRON;

  speed_altura_respaldo = false;
  speed_giro_asiento = false;
  speed_inclinacion_asiento = false;
  speed_altura_asiento = false;
  modificar_altura_respaldo = 0.01;
  modificar_giro_asiento = 1;
  modificar_inclinacion_asiento = 1;
  modificar_altura_asiento = 0.01;

  SensibilidadRueda = 0.001;

  Light0 = true;
  Light1 = true;

  // Formula de la luz no puede superar a 1 en cada componente de RGB, es decir,
  // se coge componente R/G/B de una luz y se comprueba la formula con la componente R/G/B de amb,dif,esp por separado
  // Ir = Il · Ka + Il · Kd · cos(α) + Il · Ke · cos^n (β)
  // Cuando cosenos valen 1, queda Ir = Il · Ka + Il · Kd + Il · Ke

  material = 0;
  // Inicializacion de materiales
  // Material 0 = blanco
  ambiente[0] = _vertex4f(0.2, 0.2, 0.2, 1);
  difusa[0] = _vertex4f(0.5, 0.5, 0.5, 1);
  especular[0] = _vertex4f(0.3, 0.3, 0.3, 1);

  // Material 1 = azul
  ambiente[1] = _vertex4f(0.0, 0.0, 0.2, 1);
  difusa[1] = _vertex4f(0.2, 0.2, 0.5, 1);
  especular[1] = _vertex4f(0.1, 0.1, 0.3, 1);

  // Material 2 = verde
  // Se ve muy oscuro porque el material no refleja luz verde al ser la luz magenta, es decir,
  // luz magenta = (1, 0, 1) y nuestro material es en su mayoria (0, 1, 0), entonces segun la formula
  // de arriba hay muy poca Ir (intensidad reflejada)
  ambiente[2] = _vertex4f(0.0, 0.2, 0.0, 1);
  difusa[2] = _vertex4f(0.2, 0.5, 0.2, 1);
  especular[2] = _vertex4f(0.1, 0.3, 0.1, 1);

  // Maximo brillo = 128
  brillo[0] = 64;
  brillo[1] = 64;
  brillo[2] = 64;

}
