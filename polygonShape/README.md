Para crear polígonos personalizados es muy similar a OpenGL u otras librerías que tienen que ver con visualización de figuras.

## Explicación del código
### Librerías
En este caso se usara box2d por lo que se deben implementar las librerías necesarias.
```c++
#include <iostream>
#include <Box2d/Box2d.h>
```

### Polígonos
La estructura para crear cada figura es la misma, primero vamos a crear una variable tipo ***b2PolygonShape*** a la cual le asignaremos el nombre de nuestra figura
``` c++
b2PolygonShape triangle;
```

Para trazar la figura usaremos la función ***Set(points, count)*** la cual recibe como parámetro la posición de los vértices que formaran nuestra figura y como segundo parámetro el numero de vértices que componen nuestra figura. Para definir los vértices de nuestra figura vamos a crear una variable de tipo b2Vec2 que funcionara como un array de puntos y su longitud será igual al numero de vértices de la figura.
``` c++
b2Vec2 vertexTriangle[3];
```

Después vamos a insertar dentro del array de vértices las coordenadas que definen cada uno de los vértices de la siguiente forma
``` c++
vertexTriangle[0].Set(0.0f,1.0f);
vertexTriangle[1].Set(0.0f,0.0f);
vertexTriangle[2].Set(1.0f,0.0f);
```

por ultimo vamos a hacer uso de la función ***Set(points, count)*** mencionada anteriormente, mandando como primer parámetro nuestro arreglo de vértices y como segundo parámetro nuestro numero de vértices.
``` c++
triangle.Set(vertexTriangle, 3);
```
y de esta forma ya creamos una figura personalizada en Box2D

Ahora para crear un cuadrado vamos a hacer prácticamente lo mismo con la diferencia de que vamos a modificar la longitud del arreglo de vértices y el count en la función ***Set(points, count)*** 
```c++
//Cuadrado
b2PolygonShape cube;
b2Vec2 vertexCube[4];
vertexCube[0].Set(2.0f,0.0f);
vertexCube[1].Set(3.0f,0.0f);
vertexCube[2].Set(3.0f,1.0f);
vertexCube[3].Set(2.0f,1.0f);
cube.Set(vertexCube, 4);
```

Lo mismo con el pentágono
```c++
//Pentagono
b2PolygonShape pentagono;
b2Vec2 vertexPentagono[5];
vertexPentagono[0].Set(4.0f,0.0f);
vertexPentagono[1].Set(5.0f,0.0f);
vertexPentagono[2].Set(5.2f,0.6f);
vertexPentagono[3].Set(4.5f,1.1f);
vertexPentagono[4].Set(3.8f,0.6f);
pentagono.Set(vertexPentagono, 5);
```

Hexágono
```c++
b2PolygonShape hexagono;
b2Vec2 vertexHexagono[6];
vertexHexagono[0].Set(6.0f,0.0f);
vertexHexagono[1].Set(7.0f,0.0f);
vertexHexagono[2].Set(7.4f,0.5f);
vertexHexagono[3].Set(7.0f,1.0f);
vertexHexagono[4].Set(6.0f,1.0f);
vertexHexagono[5].Set(5.6f,0.5f);
hexagono.Set(vertexHexagono, 6);
```

Octágono
```c++
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
```

Y de esta forma podemos crear una infinidad de posibles polígonos para nuestra simulación.