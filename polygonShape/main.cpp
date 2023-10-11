#include <iostream>
#include <Box2d/Box2d.h>

int main() {
    //Triangulo Rectangulo
    b2PolygonShape triangle;
    b2Vec2 vertexTriangle[3];
    vertexTriangle[0].Set(0.0f,1.0f);
    vertexTriangle[1].Set(0.0f,0.0f);
    vertexTriangle[2].Set(1.0f,0.0f);
    triangle.Set(vertexTriangle, 3);

    //Cuadrado
    b2PolygonShape cube;
    b2Vec2 vertexCube[4];
    vertexCube[0].Set(2.0f,0.0f);
    vertexCube[1].Set(3.0f,0.0f);
    vertexCube[2].Set(3.0f,1.0f);
    vertexCube[3].Set(2.0f,1.0f);
    cube.Set(vertexCube, 4);

    //Pentagono
    b2PolygonShape pentagono;
    b2Vec2 vertexPentagono[5];
    vertexPentagono[0].Set(4.0f,0.0f);
    vertexPentagono[1].Set(5.0f,0.0f);
    vertexPentagono[2].Set(5.2f,0.6f);
    vertexPentagono[3].Set(4.5f,1.1f);
    vertexPentagono[4].Set(3.8f,0.6f);
    pentagono.Set(vertexPentagono, 5);

    //Hexagono
    b2PolygonShape hexagono;
    b2Vec2 vertexHexagono[6];
    vertexHexagono[0].Set(6.0f,0.0f);
    vertexHexagono[1].Set(7.0f,0.0f);
    vertexHexagono[2].Set(7.4f,0.5f);
    vertexHexagono[3].Set(7.0f,1.0f);
    vertexHexagono[4].Set(6.0f,1.0f);
    vertexHexagono[5].Set(5.6f,0.5f);
    hexagono.Set(vertexHexagono, 6);

    //Octagono
    b2PolygonShape octagono;
    b2Vec2 vertexOctagono[8];
    vertexOctagono[0].Set(8.3f,0.0f);
    vertexOctagono[1].Set(8.7f,0.0f);
    vertexOctagono[2].Set(9.0f,0.3f);
    vertexOctagono[3].Set(9.0f,0.7f);
    vertexOctagono[4].Set(8.7f,1.0f);
    vertexOctagono[5].Set(8.3f,1.0f);
    vertexOctagono[6].Set(8.0f,0.7f);
    vertexOctagono[7].Set(8.0f,0.3f);
    octagono.Set(vertexOctagono, 8);

    return 0;
}
