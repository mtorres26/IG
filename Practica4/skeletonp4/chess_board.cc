#include "chess_board.h"

_chess_board::_chess_board(float size)
{
    Vertices.resize(4);

    Vertices[0] = _vertex3f(size/2,size/2,0);
    Vertices[1] = _vertex3f(-size/2,size/2,0);
    Vertices[2] = _vertex3f(-size/2,-size/2,0);
    Vertices[3] = _vertex3f(size/2,-size/2,0);

    Triangles.resize(2);

    Triangles[0] = _vertex3ui(0,1,3);
    Triangles[1] = _vertex3ui(1,2,3);

    TextureVertices.resize(4);

    TextureVertices[0] = _vertex2f(1, 1);
    TextureVertices[1] = _vertex2f(0, 1);
    TextureVertices[2] = _vertex2f(0, 0);
    TextureVertices[3] = _vertex2f(1, 0);

}
