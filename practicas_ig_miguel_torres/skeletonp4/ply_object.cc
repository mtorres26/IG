/*! \file
 * Miguel Torres Alonso
 */


#include "object3d.h"
#include "file_ply_stl.h"
#include "ply_object.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>


_ply_object::_ply_object(const string &fichero_ply)
{
    vector<float> Coordinates; // Coordenadas de los vertices
    vector<unsigned int> Positions; // Caras formadas por los vertices de Positions

    open(fichero_ply);
    read(Coordinates,Positions); // Funcion proporcionada en Prado que lee vertices y triangulos del PLY
                                // y los guarda en dos vectores
    close();

    Vertices.resize(Coordinates.size()/3);

    for(unsigned int i = 0; i < Coordinates.size(); i+=3)
    { // Asigna a cada vertice sus 3 coordenadas
        Vertices[i/3] = _vertex3f(Coordinates[i], Coordinates[i+1], Coordinates[i+2]);
    }

    Triangles.resize(Positions.size()/3);

    for(unsigned int i = 0; i < Positions.size(); i+=3)
    { // Asigna a cada triangulo sus 3 vertices
        Triangles[i/3] = _vertex3ui(Positions[i], Positions[i+1], Positions[i+2]);
    }
}

