## Explicación física
Para crear un mundo se tiene que crear la fuerza gravitatoria que en este caso es la de la tierra ($9.81\frac{m}{s^2}$). 
En este mundo un cuadrado de $1m$ se posiciona a una altura de $20m$ del mundo tomando como referencia su centro y justo abajo del cuadrado se posiciona una plataforma de $50m*1m$ a una altura de $-10m$ del mundo tomando como referencia su centro, por lo tanto la altura del cuadrado con respecto a la base es $(20m-0.5m)+(10m-0.5m)$ dando un resultado de $29m$ de distancia entre el cuadrado y la base.
El cuadrado cuenta con una densidad de $10\frac{kg}{m^3}$ y una fricción de $0.3$.
Cuando se corre el programa en base a los parámetros del mundo mencionados anteriormente, el cuadrado caerá verticalmente hacia la base debido a la fuerza de gravedad, alterando factores como la densidad del cuadrado o la aceleración de la gravedad podremos alterar su velocidad 


## Explicación programación
El código implementa la librería Box2D, se define un mundo con su propia fuerza gravitatoria definida en forma de vector2
```b2Vec2 gravity(0.0f,-9.81f);``` 
Se asigna la gravedad a un mundo
```b2World world(gravity);``` 
Se define un objeto static y su posición en el mundo
```b2BodyDef groundBodyDef;   groundBodyDef.position.Set(0.0f,-10.0f);```
Se asigna el objeto al mundo
```b2Body* groundBody = world.CreateBody(&groundBodyDef);```
Se define una variable que contendrá la forma del cuerpo
```b2PolygonShape groundBox;```
```groundBox.SetAsBox(50.0f,1.0f);```
Se le complementa un atributo físico que es la densidad
```groundBody ->CreateFixture(&groundBox, 0.0);```
Se definen las características de otro cuerpo
```b2BodyDef bodyDef;```
```bodyDef.type = b2_dynamicBody;```
```bodyDef.position.Set(0.0f, 20.0f);```
Se crea el objeto en el mundo
```b2Body* body = world.CreateBody(&bodyDef);```
Se vuelve a definir la forma del objeto, se definen y asignan las características físicas al objeto (forma, fricción y densidad)

Se instancia el número de actualizaciones que habrá en 1 segundo
```float timeStep = 1.0f/60.0f;```
Se definen sus iteraciones por velocidad y posición
```int32 velocityIterations = 6;```
```int32 positionIteration = 2;```
Se crea un ciclo for que realizará las actualizaciones de la simulación, el ciclo se realiza 300 veces por lo que durará 5 segundos, dentro del ciclo se ejecuta el comando de actualizar el mundo y se muestran su posicion vectorial y ángulo en cada actualización 
```for(int32 i = 0; i < 300; ++i) 
     { 
         world.Step(timeStep, velocityIterations, positionIteration); 
         b2Vec2 position = body->GetPosition(); 
         float angle = body->GetAngle(); 
         printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle); 
     }
```




