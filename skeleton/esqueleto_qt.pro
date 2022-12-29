HEADERS += \
  colors.h \
  basic_object3d.h \
  file_ply_stl.h \
  cube.h \
  object3d.h \
  axis.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  cube.cc \
  object3d.cc \
  file_ply_stl.cc \
  axis.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
