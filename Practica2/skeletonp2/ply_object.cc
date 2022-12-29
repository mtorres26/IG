#include "object3d.h"
#include "file_ply_stl.h"
#include "ply_object.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>



_ply_object::_ply_object(string archivo)
{
    cargar(archivo);
}

int _ply_object::cargar(const string &fichero_ply){

    vector<float> Coordinates;
    vector<unsigned int> Positions;

    open(fichero_ply);
    read(Coordinates,Positions);
    close();

    Vertices.resize(Coordinates.size()/3);

    for(unsigned int i = 0; i < Coordinates.size(); i+=3)
    {
        Vertices[i/3] = _vertex3f(Coordinates[i], Coordinates[i+1], Coordinates[i+2]);
    }

    Triangles.resize(Positions.size()/3);

    for(unsigned int i = 0; i < Positions.size(); i+=3)
    {
        Triangles[i/3] = _vertex3ui(Positions[i], Positions[i+1], Positions[i+2]);
    }

    return (0);
}
