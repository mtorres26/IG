/*
// CÓDIGO PROPORCIONADO POR EL PROFESORADO

// Code to define the Qtimer for the animation
Timer = new QTimer(this);
Timer->setInterval(0);
connect(Timer, SIGNAL(timeout()), this, SLOT(tick()));

// Code for reading an image
QString File_name("image.jpg");
QImage Image;
QImageReader Reader(File_name);
Reader.setAutoTransform(true);
Image = Reader.read();
if (Image.isNull()) {
  QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                           tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
  exit(-1);
}
Image=Image.mirrored();
Image=Image.convertToFormat(QImage::Format_RGB888);

// Code to control the application of the texture
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

// Code to pass the image to OpenGL to form a texture 2D
glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());

*/
