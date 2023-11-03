#### ***Nombre: Monrreal González Ricardo Salvador***
## Explicación
Los Joints son articulaciones que involucran por lo menos 2 cuerpos, los cuales permiten que ambos cuerpos se comporten de cierta manera dependiendo del joint, los joints que se verán en el siguiente código son:
- Distancia: Se hace referencia a 2 cuerpos, donde la única regla que se cumple es que ambos mantienen una distancia fija, pueden girar ambos manteniendo su distancia y puede rotar cada objeto independientemente del otro.
- Soldadura: A diferencia de la distancia, este objeto une 2 objeto, uno es completamente dependiente del otro y será como una replica de su movimiento en el mundo.
- Rotación: Se utiliza para simular una rotación de 1 objeto con otro objeto por lo general estático, se le puede aplicar una fuerza de motor para que gire.
- Rueda: Como su nombre lo dice, es un joint para ruedas, es similar al de rotación pero con el extra de poder moverse en dirección a su eje, haciendo su función de rueda.
- Prismática: Permite el movimiento de un objeto en un solo eje, por ejemplo, una barra que solo se mueve de arriba a abajo.
- Engrane: Trabaja con 2 objetos, rota un objeto y otro objeto con respecto al valor ratio, solo funciona con joints de revolución y prismáticos.

## Explicación del código
Primero se agregan las librerías necesarias y se inicializa la escala que se tomara en cuenta para los objetos del mundo.
``` c++
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>

constexpr float SCALE = 30.0f;
```

Luego se crea la clase para los objetos que se tomaran como estáticos y serán invisibles. La funcion update actualiza la posición del cuerpo y su rotación. Draw dibuja en la pantalla con sfml. La funcion getBody regresa el body que esta dentro de los elementos privados.
```c++
class TransparentBody {
public:
    //Crea el objeto invisible (Constructor)
    TransparentBody(b2World &world, float x, float y, sf::Color color) {
        b2BodyDef bodydef;  //Se inicializa el objeto
        bodydef.position.Set(x / SCALE, y / SCALE); //Asigna posicion
        body = world.CreateBody(&bodydef);  //Se crea en el mundo
    }

    //Actualiza el objeto cuando se llama
    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    //Dibuja el objeto en pantalla
    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    //Obtiene el body del objeto
    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
};
```

Se crea una clase similar llamada StaticBody a la del objeto de arriba, con la diferencia de que este se muestra en pantalla, asignándole una figura al objeto y dibujándola con SFML.
```c++
class StaticBody {
public:
    StaticBody(b2World &world, float x, float y, sf::Color color) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        body = world.CreateBody(&bodydef);

        b2PolygonShape shape;
        shape.SetAsBox((10.f / 2) / SCALE, (10.f / 2) / SCALE);

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        body->CreateFixture(&fixturedef);

        box.setSize(sf::Vector2f(10.f, 10.f));
        box.setFillColor(color);
        box.setOrigin(5.f, 5.f);
    }

    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
};
```

Se crea la clase Cubo que será para objetos dinámicos, definiendo el tipo de objeto de box2d como dinámico, asignándole una forma y mostrándola en pantalla, contara con las mismas funciones que las demás clases pasadas.
```c++
class Cube {
public:
    Cube(b2World &world, float x, float y, sf::Color color) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        bodydef.type = b2_dynamicBody;
        body = world.CreateBody(&bodydef);

        b2PolygonShape shape;
        shape.SetAsBox((10.f / 2) / SCALE, (10.f / 2) / SCALE);

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = 1.0f;
        body->CreateFixture(&fixturedef);

        box.setSize(sf::Vector2f(10.f, 10.f));
        box.setFillColor(color);
        box.setOrigin(5.f, 5.f);
    }

    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0, 0), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
};
```

*(Dentro del main)

Se crea una ventana de 1000 x 900 con su respectivo título y se crea el mundo asignándole una gravedad nula.
```c++
sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);
```

Se crean 2 cuerpos dinámicos de tipo Cube, se crea un joint de tipo distancia, se inicializa con sus elementos necesarios como los 2 objetos y el ancla de ambos cuerpos, luego se asignan los atributos damping y stiffness al joint de distancia y se crea el joint dentro del mundo.
```c++
//Distance Bodies
    Cube cube(world, 400, 300, sf::Color::Red);
    Cube cube1(world, 350, 250, sf::Color::Red);

    //Distance Joint
    b2DistanceJointDef disJointDef;
    disJointDef.Initialize(cube.getBody(), cube1.getBody(), cube.getBody()->GetWorldCenter(), cube1.getBody()->GetWorldCenter());
    disJointDef.damping = 30;
    disJointDef.stiffness = 20;
    world.CreateJoint(&disJointDef);
```

Se crean 2 cuerpos que se usaran para el joint de revolución, un cuerpo es estático y funcionará como el eje de rotación mientras que el otro objeto dinámico será el que rotara sobre el estático.
Luego se crea el joint de tipo revolucion y se inicializa con el cuerpoA, cuerpoB y el ancla sobre el cual rotará el otro objeto, en los atributos se le asigna una fuerza de motor y un torque para que se mueva constantemente, y al final se crea el joint dentro del mundo.
```c++
//Revolute Bodies
    StaticBody Cube3(world, 300, 100, sf::Color::Blue);
    Cube cube4(world, 300, 50, sf::Color::Blue);

    //Revolute Joint
    b2RevoluteJointDef revJointDef;
    revJointDef.Initialize(Cube3.getBody(), cube4.getBody(), Cube3.getBody()->GetWorldCenter());
    revJointDef.enableMotor = true;
    revJointDef.motorSpeed = 0.09f;
    revJointDef.maxMotorTorque = 1;
    world.CreateJoint(&revJointDef);
```

Se crean 2 objetos para el joint prismático, se crea un objeto transparente y uno dinámico el cual se moverá. Se crea el joint prismático y se inicializa con los 2 cuerpos el ancla y el eje por el cual solo se podrá mover el objeto dinámico, se asigna un motor al joint el cual permitirá el movimiento del objeto prismático y se frenará hasta llegar al limite superior del joint, al final se crea el joint dentro del mundo.
```c++
//Prismatic Bodies
    TransparentBody cube5(world, 600, 50, sf::Color::Red);
    Cube cube6(world, 600, 200, sf::Color::Blue);

    //Prismatic Joint
    b2PrismaticJointDef prisJointDef;
    prisJointDef.Initialize(cube5.getBody(),cube6.getBody(),cube5.getBody()->GetWorldCenter(), b2Vec2(0,1));
    prisJointDef.enableMotor = true;
    prisJointDef.motorSpeed = 0.1f;
    prisJointDef.maxMotorForce = 1.0f;
    prisJointDef.enableLimit = true;
    prisJointDef.lowerTranslation = -2;
    prisJointDef.upperTranslation = 7;
    world.CreateJoint(&prisJointDef);
```

Se vuelven a crear cuerpos de revolución para para implementar dentro del joint de engrane, solo uno de ellos girará.
```c++
//Revolute Bodies
    TransparentBody cube7(world, 800, 250, sf::Color::Blue);
    Cube cube8(world, 800, 250, sf::Color::Blue);
    TransparentBody cube9(world, 800, 280, sf::Color::Blue);
    Cube cube10(world, 800, 280, sf::Color::Blue);

    //Revolute Joint
    b2RevoluteJointDef revJointDef2;
    revJointDef2.Initialize(cube7.getBody(), cube8.getBody(), cube7.getBody()->GetWorldCenter());
    revJointDef2.enableMotor = true;
    revJointDef2.motorSpeed = 0.09f;
    revJointDef2.maxMotorTorque = 1;
    revJointDef2.Initialize(cube7.getBody(), cube8.getBody(), cube7.getBody()->GetWorldCenter());
    world.CreateJoint(&revJointDef2);

    b2RevoluteJointDef revJointDef3;
    revJointDef3.Initialize(cube9.getBody(), cube10.getBody(), cube9.getBody()->GetWorldCenter());
    world.CreateJoint(&revJointDef3);
```

Se crea el joint de engrane el cual se le asignan 2 cuerpos y los 2 joints de revolución, el ratio es de 1 para que al rotar el objeto1 el otro rote a la misma frecuencia.
```c++
//Gear Joint
    b2GearJointDef gearJointDef;
    gearJointDef.bodyA = cube8.getBody();
    gearJointDef.bodyB = cube10.getBody();
    gearJointDef.joint1 = world.CreateJoint(&revJointDef2);
    gearJointDef.joint2 = world.CreateJoint(&revJointDef3);
    gearJointDef.ratio = 1.0f;
    world.CreateJoint(&gearJointDef);
```

Se crean 2 objetos dinámicos para para el joint weld, luego se crea el joint weld y se inicializa con el cuerpo 1 y 2 y el cuerpo que será el ancla
```c++
//Weld Joint
    //Weld Bodies
    Cube dynamicWeld1(world, 200, 500, sf::Color::Red);
    Cube dynamicWeld2(world, 180, 500, sf::Color::Blue);

    //Weld Joint
    b2WeldJointDef weldJointDef;
    weldJointDef.Initialize(dynamicWeld1.getBody(), dynamicWeld2.getBody(), dynamicWeld1.getBody()->GetWorldCenter());
    weldJointDef.stiffness = 5.0f;
    world.CreateJoint(&weldJointDef);
```

Se crean 1 objeto dinámico  y uno estático que será el eje, luego se crea el joint de tipo rueda y se inicializa con los 2 cuerpos, definiendo 1 como el eje y el otro como el rotativo, a parte con su ancla y dirección de movimiento.
```c++
//Wheel body
    StaticBody Wheel1(world, 500, 500, sf::Color::Red);
    Cube Wheel2(world, 480, 500, sf::Color::Red);

    b2WheelJointDef wheelJointDef;
    wheelJointDef.Initialize(Wheel1.getBody(),Wheel2.getBody(),Wheel1.getBody()->GetWorldCenter(),b2Vec2(1,0));
    wheelJointDef.enableMotor = true;
    wheelJointDef.motorSpeed = 0.8f;
    wheelJointDef.maxMotorTorque = 10.0f;
    wheelJointDef.stiffness = 2.0f;
    world.CreateJoint(&wheelJointDef);
```

Mientras la ventana este abierta escuchara el evento de los inputs, que aplicara una fuerza sobre el el objeto cubo que se involucra en el joint de distancia dependiendo de la tecla que se presione, w es arriba, s abajo, d derecha y a izquierda, y al presionar esc sale de la ejecución.
```c++
	while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                cube.getBody()->ApplyForceToCenter(b2Vec2(0.1f, 0.0f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                cube.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                cube.getBody()->ApplyForceToCenter(b2Vec2(0.0f, -0.1f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                cube.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                cube.resetPosition();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                cube.stop();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
                return 0; // return from the main function, effectively ending the program
            }
        }
```

Da un paso en el mundo y actualiza los objetos
```c++
		world.Step(1 / 60.f, 8, 3);
        cube.update();
        cube1.update();
        Cube3.update();
        cube4.update();
        cube5.update();
        cube6.update();
        cube7.update();
        cube8.update();
        cube9.update();
        cube10.update();
        dynamicWeld1.update();
        dynamicWeld2.update();
        Wheel1.update();
        Wheel2.update();
```

Limpia la pantalla y dibuja los objetos en pantalla
```c++
		window.clear();
        cube.draw(window);
        cube1.draw(window);
        Cube3.draw(window);
        cube4.draw(window);
        cube5.draw(window);
        cube6.draw(window);
        cube7.draw(window);
        cube8.draw(window);
        cube9.draw(window);
        cube10.draw(window);
        dynamicWeld1.draw(window);
        dynamicWeld2.draw(window);
        Wheel1.draw(window);
        Wheel2.draw(window);
        window.display();
```