/*! \file
 * Miguel Torres Alonso
 *
 */


#include "sphere.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_sphere::_sphere(float radio,float num_divisiones, int num_perfiles)
{
    vector<_vertex3f> perfil; // Los puntos del perfil no pueden tener otra direccion que no sea la ya escrita
    perfil.resize(num_divisiones); // Numero de vertices que tendra el perfil de la esfera

    float angulo = -M_PI/2; // Empezamos creando el perfil desde el (0,-1,0) pero en radianes
                            // Si se empieza desde Pi/2 hacia -Pi/2, se crea mal

    float suma = M_PI / (num_divisiones-1); // Se van sumando al angulo estos radianes para ir haciendo
                                            // la circunferencia, el -1 es para que al ir sumando
                                            // en el bucle for, de exactamente Pi/2 al final

    perfil[0] = _vertex3f(0,-radio,0); // Vertice que cierra tapa inferior
    angulo += suma; // Sumo una fraccion de una division del perfil

    for(int i=1; i < num_divisiones-1; i++) // El -1 es porque el ultimo vertice del perfil es el cierre
    {                                   // y porque sino 'angulo' sobrepasaria Pi/2
        // Formulas de la guia de practicas
        float x = radio * cos(angulo);
        float y = radio * sin(angulo);

        perfil[i] = _vertex3f(x,y,0);
        angulo += suma; // Se van sumando divisiones del perfil para ir cerrandolo
    }

    perfil[num_divisiones-1] = _vertex3f(0,radio,0); // Vertice que cierra tapa superior

    revolucionar(perfil,num_perfiles);
}


void _sphere::calcular_normales_vertices()
{
    Normales_Vertices.resize(Vertices.size());

    for(unsigned int i = 0; i < Vertices.size(); i++) //Poner todas las normales a 0
    {
        Normales_Vertices[i] = _vertex3f(0.0,0.0,0.0);
        // Segun guia de prado, Normal = Vertice - Centro, y Centro = 0.
        Normales_Vertices[i]._0 = Vertices[i]._0;
        Normales_Vertices[i]._1 = Vertices[i]._1;
        Normales_Vertices[i]._2 = Vertices[i]._2;
        Normales_Vertices[i].normalize(); //función de vector<_vertex3f> para normalizar
    }
}

