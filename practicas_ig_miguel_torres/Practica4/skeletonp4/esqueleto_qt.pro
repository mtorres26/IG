HEADERS += \
  backboard.h \
  base.h \
  chair.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cylinder.h \
  file_ply_stl.h \
  piston.h \
  revolution_object.h \
  seat.h \
  tetrahedron.h \
  cube.h \
  object3d.h \
  axis.h \
  ply_object.h \
  sphere.h \
  glwidget.h \
  union.h \
  wheel.h \
  window.h

SOURCES += \
  auxiliar_code.cpp \
  backboard.cc \
  base.cc \
  basic_object3d.cc \
  chair.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  object3d.cc \
  file_ply_stl.cc \
  piston.cc \
  revolution_object.cc \
  seat.cc \
  tetrahedron.cc \
  axis.cc \
  ply_object.cc \
  sphere.cc \
  main.cc \
  glwidget.cc \
  union.cc \
  wheel.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
