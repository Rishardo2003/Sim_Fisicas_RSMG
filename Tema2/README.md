## Explicación Física
Tomando como mundo a Júpiter con las mismas características del mundo, esta vez se va a crear una bala de dimensiones $0.2m * 0.05m$, su densidad es de $0.01\frac{kg}{m^3}$, fricción de $0.3$ y se desplazará en un ángulo de $45°$ a una velocidad de $400\frac{m}{s}$, esto generará una curva parabólica en su trayectoria y al estar a un ángulo de $45°$ su alcance será máximo 

## Explicación programación 
Tomando en cuenta que ya sabemos cómo funciona todo lo antes visto, empezaremos a explicar el código nuevo.
Al trabajar con un objeto que se mueve a cierta velocidad formando una línea parabólica, debemos definir los datos que nos serán útiles, la velocidad y el ángulo de tiro
```float angle = 45.0f; // Angle in degrees```
```float speed = 400.0f; // Speed in m/s```
Para mover el objeto necesitamos enviar como parametro un vector2 por lo que necesitamos descomponer en sus componentes, usamos la trigonometría para sacar sus componentes, fórmula del seno para el cateto opuesto (componente en y) y fórmula del coseno para el cateto adyacente (componente en x), y nos quedaría una fórmula similar a las siguientes 
```float vx = speed * std::cos(angle * M_PI / 180.0f);```
```float vy = speed * std::sin(angle * M_PI / 180.0f);```
Luego se usa implementa la función que hará que nuestra bala se mueva dándole como parámetro las componentes que calculamos en forma de vector2
```body->SetLinearVelocity(b2Vec2(vx, vy));```
Al momento de realizar la simulación nuestra bala saldrá disparada a un ángulo de $45°$ a una velocidad de $400\frac{m}{s}$ 