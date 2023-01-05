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


void _revolution_object::revolucionar(vector<_vertex3f> perfil, int num_perfiles, _figura figura){

    _vertex3f vert_aux;
    _vertex3i cara_aux;
    int i,j;

    int num_vertices_perfil;

    float radio,altura;

    if(figura == SPHERE)
    {
        radio = sqrt((perfil[2].x*perfil[2].x) + (perfil[2].y*perfil[2].y));
    }

    else if(figura == CONE || figura == CYLINDER)
    {
        radio = abs(perfil[0].x);
        altura = abs(perfil[1].y);
    }

    num_vertices_perfil = perfil.size();

    if(figura == CONE)
    {
        num_vertices_perfil = 1;
    }

    Vertices.resize(num_vertices_perfil*num_perfiles + 2);

    for(i = 0;i < num_perfiles;i++)
    {
        for(j = 0;j < num_vertices_perfil; j++)
        {
            vert_aux.x=perfil[j].x*cos(2.0*M_PI*i/(1.0*num_perfiles)) + perfil[j].z*sin(2.0*M_PI*i/(1.0*num_perfiles));
            vert_aux.z= -perfil[j].x*sin(2.0*M_PI*i/(1.0*num_perfiles)) + perfil[j].z*cos(2.0*M_PI*i/(1.0*num_perfiles));
            vert_aux.y=perfil[j].y;
            Vertices[j+i*num_vertices_perfil]=vert_aux;
        }
    }

    Triangles.resize(2*(num_vertices_perfil - 1) * num_perfiles + 2*num_perfiles);

    int t = 0;

    if (figura == CYLINDER || figura == SPHERE)
    {
        for(i = 0;i < (num_perfiles - 1); i++)
        {
            for(j = 0; j < (num_vertices_perfil - 1); j++)
            {
                Triangles[t]._0 = j + i * num_vertices_perfil;
                Triangles[t]._1 = j + num_vertices_perfil + 1 + i * num_vertices_perfil;
                Triangles[t]._2 = num_vertices_perfil + j + i * num_vertices_perfil;
                t++;
                Triangles[t]._0 = j + i*num_vertices_perfil;
                Triangles[t]._1 = j + 1 + i*num_vertices_perfil;
                Triangles[t]._2 = j + num_vertices_perfil + 1 + i*num_vertices_perfil;
                t++;

            }

        }

        int vertices_ult_perfil = i * num_vertices_perfil;

        for(i = 0;i < (num_vertices_perfil - 1); i++)
        {
            Triangles[t]._0=i + vertices_ult_perfil;
            Triangles[t]._1=i+1;
            Triangles[t]._2=i;
            t++;
            Triangles[t]._0=i + vertices_ult_perfil;
            Triangles[t]._1=i+1 + vertices_ult_perfil;
            Triangles[t]._2=i+1;
            t++;
        }
    }


    if(fabs(perfil[0].x) > 0.0)
    {
        vert_aux.x = 0.0;


        if(figura == CONE)
        {
            vert_aux.y = 0.0;
        }
        else if(figura == CYLINDER)
        {
            vert_aux.y = perfil[0].y;

        }
        else if(figura == SPHERE)
        {
            vert_aux.y = -radio;
        }

        vert_aux.z  = 0.0;

        Vertices[num_perfiles * num_vertices_perfil] = vert_aux;

        for(i = 0; i < num_perfiles; i++)
        {
            Triangles[t]._0=num_perfiles*num_vertices_perfil;
            Triangles[t]._1=i*num_vertices_perfil;
            Triangles[t]._2=((i+1) % num_perfiles)*num_vertices_perfil;
            t++;
        }

    }

    if(fabs(perfil[num_vertices_perfil - 1].x) > 0.0)
    {
        vert_aux.x= 0.0;


        if(figura == CONE)
        {
            vert_aux.y = altura;
        }
        else if(figura == CYLINDER)
        {
            vert_aux.y = perfil[num_vertices_perfil -1].y;
        }
        else if(figura == SPHERE)
        {
            vert_aux.y = radio;

        }

        vert_aux.z = 0.0;

        Vertices[num_perfiles*num_vertices_perfil + 1] = vert_aux;

        if(figura == CYLINDER || figura == SPHERE)
        {
            for(i = 0; i < num_perfiles - 1; i++)
            {
                Triangles[t]._0=num_perfiles*num_vertices_perfil+1;
                Triangles[t]._1=i*num_vertices_perfil+(num_vertices_perfil-1);
                Triangles[t]._2=(i+1)*num_vertices_perfil+(num_vertices_perfil-1);
                t++;

            }

            Triangles[t]._0=num_perfiles*num_vertices_perfil+1;
            Triangles[t]._1=i*num_vertices_perfil+(num_vertices_perfil-1);
            Triangles[t]._2=(num_vertices_perfil-1);
            t++;
        }

        else if(figura == CONE)
        {
            for(i = 0; i < num_perfiles; i++)
            {
                Triangles[t]._0=num_perfiles*num_vertices_perfil+1;
                Triangles[t]._1=i*num_vertices_perfil;
                Triangles[t]._2=num_vertices_perfil*((i+1) % num_perfiles);
                t++;
            }
        }
    }

}


