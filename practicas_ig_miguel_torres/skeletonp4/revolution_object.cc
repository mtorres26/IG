/*! \file
 * Miguel Torres Alonso
 */


#include "object3d.h"
#include "glwidget.h"

using namespace _colors_ne;
using namespace _gl_widget_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/


_revolution_object::_revolution_object(){

}


void _revolution_object::revolucionar(vector<_vertex3f> perfil, int num_perfiles)
{

    int num_vertices_perfil = perfil.size();
    int vertices_revolucion[num_vertices_perfil][num_perfiles]; // Matriz con los vertices que se revolucionan
                                                                // para evitar triangulos degenerados y puntos repetidos
    float angulo = 2 * M_PI / num_perfiles; // Se divide 360º entre el num de perfiles
    int index_vertice = 0;
    int columna_perfiles = 0;

    int vertice_tapa_inferior;
    int vertice_tapa_superior;

    Vertices.resize(num_perfiles * num_vertices_perfil);
    Triangles.resize(num_perfiles * num_vertices_perfil * 2); // Como mucho ese tamaño

    for(int i = 0; i < num_perfiles; ++i)
    { // Para cada perfil
        float alfa = angulo * i; // Alpha es el angulo (respecto del eje 'Y') de un perfil y en cada iteracion es el siguiente perfil
        int fila_vertices = 0;

        for(int j = 0; j < num_vertices_perfil; ++j)
        {  // Para cada vertice de un perfil
            float radio = perfil[j].x;  // Coordenada x de cada vertice
            float x = radio * cos(alfa) ; // Formula de la guia de practicas
            float z = -radio * sin(alfa); // Formula de la guia de practicas

            // Si es el primer perfil, se crean las tapas superior e inferior
            if(i == 0)
            {
                if(x == 0) // Si la coordenada x de la revolucion es 0
                {
                    if(j == 0) // Si es el primer vertice del perfil, osea el que cierra las tapas inferiores
                    {
                        vertice_tapa_inferior = index_vertice;
                        // Vertice[0] = (0, -radio, z)
                        Vertices[index_vertice] = _vertex3f(x, perfil[j].y, z);
                        ++index_vertice;
                    }

                    if(j == num_vertices_perfil - 1) // Si es el ultimo vertice del perfil, osea tapa superior
                    {
                        vertice_tapa_superior = index_vertice;
                        // Vertices[num_vertices_perfil - 1] = (0, radio, z)
                        Vertices[index_vertice] = _vertex3f(x, perfil[j].y, z);
                        ++index_vertice;
                    }
                }
            }

            // Para todos los perfiles
            if(x != 0) // Si la coordenada x de la revolucion es distinta de 0, es decir,
                        // no es ni tapa  superior ni inferior
            {
                // Se guarda en una matriz que tiene por columnas los indices de los vertices
                // que se van revolucionando
                vertices_revolucion[fila_vertices][columna_perfiles] = index_vertice;
                Vertices[index_vertice] = _vertex3f(x, perfil[j].y, z);
                ++index_vertice;
            }

            ++fila_vertices;

        }

        ++columna_perfiles;
    }

    // Creacion de triangulos en sentido antihorario con los vertices obtenidos anteriormente

    int index_triangulo = 0;

    int fin = num_vertices_perfil - 2; // Acaba en el penultimo vertice, porque el ultimo es la tapa

    for (int i = 1; i < fin; i++)  // i empieza en 1 porque la matriz tiene tapa inferior en fila 0
    {   // Bucle que recorre las filas de la matriz
        int i_aux = (i + 1) % num_vertices_perfil; // i_aux es la siguiente fila de la matriz sin salirse
                                                    // del perfil

        for(int j = 0; j < num_perfiles; ++j)
        {   // Bucle que recorre las columnas de la matriz, hay 'num_perfiles' columnas
            int j_aux = (j + 1) % num_perfiles; // j_aux es la siguiente columna de la matriz sin salirse
                                                // del numero de perfiles
            int Vert1 = vertices_revolucion[i][j];  // Vertice distinto de 0 de un perfil
            int Vert2 = vertices_revolucion[i][j_aux]; // Se une con mismo vertice de siguiente perfil
            int Vert3 = vertices_revolucion[i_aux][j]; // Y se une con siguiente vertice del perfil
                                                // mencionado al principio
            int Vert4 = vertices_revolucion[i_aux][j_aux]; // Vertice que queda por definir del siguiente triangulo
                                                            // y que se une con dos de los anteriores

            Triangles[index_triangulo] = _vertex3ui(Vert1, Vert2, Vert3);
            ++index_triangulo;

            Triangles[index_triangulo] = _vertex3ui(Vert2, Vert4, Vert3);
            ++index_triangulo;
        }
    }

    for(int i = 0; i < num_perfiles; ++i) // Bucle para cerrar la tapa inferior
    {
        int i_aux = (i + 1) % num_perfiles;

        int VertInf1 = vertices_revolucion[1][i_aux]; // Vertice 1 es el mas cercano al vertice de cierre,
                                                        // se unen con este ultimo los de todos los perfiles
                                                        // en sentido antihorario
        int VertInf2 = vertices_revolucion[1][i];
        Triangles[index_triangulo] = _vertex3ui(vertice_tapa_inferior, VertInf1, VertInf2);
        ++index_triangulo;
    }

    for(int i = 0; i < num_perfiles; ++i) // el vertice anterior al de cierre de un perfil se une
                                          // con el mismo pero del siguiente perfil y con el de cierre
                                            // logrando el sentido antihorario
    {
        int i_aux = (i + 1) % num_perfiles;

        int VertSup1 = vertices_revolucion[num_vertices_perfil - 2][i];
        int VertSup2 = vertices_revolucion[num_vertices_perfil - 2][i_aux];
        Triangles[index_triangulo] = _vertex3ui(VertSup1, VertSup2, vertice_tapa_superior);
        ++index_triangulo;
    }
}


