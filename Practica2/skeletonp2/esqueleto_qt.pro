HEADERS += \
  colors.h \
  basic_object3d.h \
  cone.h \
  cylinder.h \
  file_ply_stl.h \
  revolution_object.h \
  tetrahedron.h \
  cube.h \
  object3d.h \
  axis.h \
  ply_object.h \
  sphere.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  object3d.cc \
  file_ply_stl.cc \
  revolution_object.cc \
  tetrahedron.cc \
  axis.cc \
  ply_object.cc \
  sphere.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
