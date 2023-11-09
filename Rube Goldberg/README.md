#### ***Nombre: Monrreal González Ricardo Salvador***

## Explicación del código

##### Main.cpp
Se incluyen las librerías y el header de las formas
```c++
#include <iostream>  
#include <SFML/Graphics.hpp>  
#include <Box2D/Box2D.h>  
#include <SFML/Window.hpp>  
#include <chrono>  
#include <thread>  
  
#include "Shapes.h"
```

Se crea una ventana SFML, la gravedad y se asigna la gravedad al mundo.
```c++
sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");  
  
b2Vec2 gravity(0.0f, 3.0f / shapes::SCALE);  
b2World world(gravity);
```

Se crea un ContactListener para la detección de sensores y se agrega al mundo.
```c++
ContactListener::MyContactListener escuchadorDeContacto;
world.SetContactListener(&escuchadorDeContacto);
```

Se crean los polígonos con sus respectivas características
```c++
//Objetos dinamicos
    shapes::Cube cube1(world, 50, 50, sf::Color::Red,10,10,0);
    shapes::Cube cube2(world, 50, 72, sf::Color::Red,10,10,0);
    shapes::CircleShape wheel(world, 200, 800, sf::Color::Red,10);
    shapes::Cube pilar1(world, 270, 270, sf::Color::Blue,5,40,0);
    pilar1.getBody()->GetFixtureList()->SetFriction(0.5f);
    pilar1.getBody()->GetFixtureList()->SetDensity(1.0f);
    pilar1.getBody()->ResetMassData();
    shapes::Cube pilar2(world, 280, 270, sf::Color::Blue,5,40,0);
    pilar2.getBody()->GetFixtureList()->SetFriction(0.5f);
    pilar2.getBody()->GetFixtureList()->SetDensity(1.0f);
    pilar2.getBody()->ResetMassData();
    shapes::Cube pilar3(world, 290, 270, sf::Color::Blue,5,40,0);
    pilar3.getBody()->GetFixtureList()->SetFriction(0.5f);
    pilar3.getBody()->GetFixtureList()->SetDensity(1.0f);
    pilar3.getBody()->ResetMassData();
    shapes::Cube pilar4(world, 300, 270, sf::Color::Blue,5,40,0);
    pilar4.getBody()->GetFixtureList()->SetFriction(0.5f);
    pilar4.getBody()->GetFixtureList()->SetDensity(1.0f);
    pilar4.getBody()->ResetMassData();
    shapes::Cube pilar5(world, 310, 270, sf::Color::Blue,5,40,0);
    pilar5.getBody()->GetFixtureList()->SetFriction(0.5f);
    pilar5.getBody()->GetFixtureList()->SetDensity(1.0f);
    pilar5.getBody()->ResetMassData();
    shapes::Cube cube1Polea(world, 585, 470, sf::Color::Blue,5,40,0);
    pilar5.getBody()->GetFixtureList()->SetFriction(0.0f);
    pilar5.getBody()->GetFixtureList()->SetDensity(1.0f);
    pilar5.getBody()->ResetMassData();
    shapes::Cube cube2Polea(world, 595, 470, sf::Color::Blue,5,40,0);
    pilar5.getBody()->GetFixtureList()->SetFriction(0.0f);
    pilar5.getBody()->GetFixtureList()->SetDensity(1.0f);
    pilar5.getBody()->ResetMassData();
    shapes::Cube cube3Polea(world, 605, 470, sf::Color::Blue,5,40,0);
    pilar5.getBody()->GetFixtureList()->SetFriction(0.0f);
    pilar5.getBody()->GetFixtureList()->SetDensity(1.0f);
    pilar5.getBody()->ResetMassData();

    //plataformas y paredes estaticas
    shapes::EdgeShape sideWall1(world, 40, 40, 40,300, sf::Color::White);
    shapes::EdgeShape sideWall2(world, 130, 40, 130,190, sf::Color::White);
    shapes::EdgeShape sideWall3(world, 270, 365, 270,380, sf::Color::White);
    shapes::EdgeShape sideWall4(world, 792, 300, 792,850, sf::Color::White);
    shapes::EdgeShape sideWall5(world, 800, 300, 600,100, sf::Color::White);
    shapes::EdgeShape sideWall6(world, 450, 400, 450,800, sf::Color::White);
    shapes::EdgeShape platform1(world, 40, 70, 90,100, sf::Color::White);
    shapes::EdgeShape platform2(world, 130, 110, 80,140, sf::Color::White);
    shapes::EdgeShape platform3(world, 40, 150, 90,180, sf::Color::White);
    shapes::EdgeShape platform4(world, 130, 190, 80,220, sf::Color::White);
    shapes::EdgeShape platform5(world, 40, 230, 250,345, sf::Color::White);
    shapes::EdgeShape platform6(world, 270, 380, 40,500, sf::Color::White);
    shapes::EdgeShape platform7(world, 40, 480, 40,600, sf::Color::White);
    shapes::EdgeShape platform8(world, 40, 850, 750,850, sf::Color::White);
    shapes::EdgeShape platform9(world, 270, 290, 600,290, sf::Color::White);
    shapes::EdgeShape platform10(world, 280, 410, 350,450, sf::Color::White);
    shapes::EdgeShape platform13(world, 580, 300, 610,330, sf::Color::White);

    shapes::CircleShape pulley1(world, 400, 300, sf::Color::Red,10);
    pulley1.getBody()->GetFixtureList()->SetDensity(0);
    pulley1.getBody()->ResetMassData();
    shapes::CircleShape pulley2(world, 600, 300, sf::Color::Red,10);
    pulley2.getBody()->GetFixtureList()->SetDensity(0);
    pulley2.getBody()->ResetMassData();

    //Plataformas dinámicas
    shapes::Cube LargePlatform(world, 200, 690, sf::Color::Cyan,300,5,0);
    shapes::Static LargePlatformCenter(world, 200, 690);
    shapes::Cube prismaticImpulse(world, 775, 875, sf::Color::Cyan,25,25,0);
    shapes::Static prismaticImpulseStatic(world, 775, 875);
    shapes::Cube platform11(world, 400, 500,sf::Color::Cyan, 80,5,0);
    shapes::Static centerPlatform11(world, 400, 500);
    shapes::Cube platform12(world, 600, 500,sf::Color::Cyan, 80,5,0);
    shapes::Static centerPlatform12(world, 600, 500);
    shapes::Cube gear1(world, 500, 600, sf::Color::Cyan,68,68,0);
    shapes::Static centerGear1(world, 500, 600);
    shapes::Cube gear2(world, 600, 600, sf::Color::Cyan,68,68,0);
    shapes::Static centerGear2(world, 600, 600);
```

Se crean 2 sensores
```c++
	//Sensores
	shapes::Cube Sensor1(world, 50, 485, sf::Color::Transparent,20,20,0);
    Sensor1.getBody()->GetFixtureList()->SetSensor(true);
    Sensor1.getBody()->GetFixtureList()->SetDensity(0.0f);
    Sensor1.getBody()->ResetMassData();
    shapes::Cube Sensor2(world, 775, 850, sf::Color::Transparent,30,30,0);
    Sensor2.getBody()->GetFixtureList()->SetSensor(true);
    Sensor2.getBody()->GetFixtureList()->SetDensity(0.0f);
    Sensor2.getBody()->ResetMassData();
```

Se crea el primer joint de distancia que hace referencia al cubo1 y cubo2
```c++
//JOINTS
    b2DistanceJoint* distJoint;
    b2DistanceJointDef distJointDef;
    distJointDef.Initialize(cube1.getBody(), cube2.getBody(), cube1.getBody()->GetWorldCenter(), cube2.getBody()->GetWorldCenter());
    distJointDef.damping = 30;
    distJointDef.stiffness = 20;
    distJoint = (b2DistanceJoint*)world.CreateJoint(&distJointDef);
```

Se crea un joint de revolución el cual no contará con un motor
```c++
	b2RevoluteJointDef revJointDef;
    revJointDef.Initialize(LargePlatformCenter.getBody(), LargePlatform.getBody(), LargePlatformCenter.getBody()->GetWorldCenter());
    revJointDef.enableMotor = false;
    world.CreateJoint(&revJointDef);
```

Se crea el joint prismatico para el objeto que impulsa a la bola hacia arriba y se establece el limite inferior y superior
```c++
	b2PrismaticJointDef prismJointDef;
    prismJointDef.Initialize(prismaticImpulseStatic.getBody(), prismaticImpulse.getBody(), prismaticImpulseStatic.getBody()->GetWorldCenter(), b2Vec2(0,1));
    prismJointDef.enableLimit = true;
    prismJointDef.upperTranslation = 0;
    prismJointDef.lowerTranslation = -5;
    world.CreateJoint(&prismJointDef);
```

Se crea el joint de polea que tomara como referencia 2 objetos prismáticos para que no se mueva la plataforma y se caigan los objetos 
```c++
b2PulleyJointDef pulleyJointDef;
    pulleyJointDef.Initialize(platform11.getBody(),platform12.getBody(),pulley1.getBody()->GetWorldCenter(),pulley2.getBody()->GetWorldCenter(),platform11.getBody()->GetWorldCenter(),platform12.getBody()->GetWorldCenter(),1.f);
    world.CreateJoint(&pulleyJointDef);
```


Se crea el 2do Joint prismático el cual tiene limite de 10 a -10 y sera la plataforma B de la polea
```c++
b2PrismaticJointDef prismJointDef2;
    prismJointDef2.Initialize(centerPlatform11.getBody(), platform11.getBody(), centerPlatform11.getBody()->GetWorldCenter(), b2Vec2(0,1));
    prismJointDef2.enableLimit = true;
    prismJointDef2.upperTranslation = 10;
    prismJointDef2.lowerTranslation = -10;
    world.CreateJoint(&prismJointDef2);
```

Se crea la otra plataforma para la polea
```c++
b2PrismaticJointDef prismJointDef3;
    prismJointDef3.Initialize(centerPlatform12.getBody(), platform12.getBody(), centerPlatform12.getBody()->GetWorldCenter(), b2Vec2(0,1));
    prismJointDef3.enableLimit = true;
    prismJointDef3.upperTranslation = 0;
    prismJointDef3.lowerTranslation = -10;
    world.CreateJoint(&prismJointDef3);
```

Se crean 2 joints de revolución para el joint de engranaje, uno se iniciliza con un motor y el otro no
```c++
	b2RevoluteJointDef revGear1;
    revGear1.Initialize(centerGear1.getBody(), gear1.getBody(), centerGear1.getBody()->GetWorldCenter());
    revGear1.enableMotor = true;
    revGear1.motorSpeed = 0.1f;
    revGear1.maxMotorTorque = 15.f;
    world.CreateJoint(&revGear1);

    b2RevoluteJointDef revGear2;
    revGear2.Initialize(centerGear2.getBody(), gear2.getBody(), centerGear2.getBody()->GetWorldCenter());
    revGear2.enableMotor = false;
    world.CreateJoint(&revGear2);
```

Se crea el joint de engranaje que usara los 2 joints de revolucion
```c++
	b2GearJoint* joint;
    b2GearJointDef gearJointDef;
    gearJointDef.bodyA = gear1.getBody();
    gearJointDef.bodyB = gear2.getBody();
    gearJointDef.joint1 = world.CreateJoint(&revGear1);
    gearJointDef.joint2 = world.CreateJoint(&revGear2);
    gearJointDef.ratio = 1.0f;
    world.CreateJoint(&gearJointDef);
```

Cuando se presiona escape se cierra la ventana
```c++
	sf::Event event{};
	while (window.pollEvent(event)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
			return 0; // return from the main function, effectively ending the program
		}
	}
```

Se utiliza un ciclo for que escucha todas las colisiones que ocurren en el instante (recorre todas las colisiones actuales), luego se comprueba que esté en contacto y si el fixtureA es igual a fixtureB que se desea detectar (cuando el objeto deseado entra al trigger1), se destruye el joint, dejando los 2 objetos de forma independiente. La otra condicion es para el trigger2 y cuando el cuerpo deseado entra en colision con el sensor, se inicia un timer, y cuando acaba el tiempo se aplica una velocidad linear hacia arriba.

```c++
for (b2Contact* WorldContactList = world.GetContactList(); WorldContactList; WorldContactList = WorldContactList->GetNext()) {
            if (WorldContactList->IsTouching()) {
                b2Fixture* fixtureA = WorldContactList->GetFixtureA();
                b2Fixture* fixtureB = WorldContactList->GetFixtureB();

                //Deteccion 1er trigger
                if (escuchadorDeContacto.OnSensorEnter(fixtureA, fixtureB, cube1.getBody())) {
                    //Comprueba que el joint exista
                    if(distJoint != nullptr){
                        world.DestroyJoint(distJoint);    //Destruye el joint
                        distJoint = nullptr;  //Se hace null para evitar romper el programa
                    }
                    break;
                }

                //Deteccion 2do trigger
                if (escuchadorDeContacto.OnSensorEnter(fixtureA, fixtureB, wheel.getBody())) {
                    //Aplica un delay
                    escuchadorDeContacto.BeginTimer(world.GetContactList(), 10.0f);
                    break;
                }
            }
            //Cuando se completa el delay
            if(escuchadorDeContacto.GetAccion()){
                prismaticImpulse.getBody()->SetLinearVelocity(b2Vec2(0,-4));    //Aplica una fuerza linear hacia arriba
                escuchadorDeContacto.ResetAccion(); //Se resetea la accion para que no empuje infinitamente
            }
        }
```

Se da un paso en el mundo, se actualizan los objetos dentro del mundo, se limpia la pantalla y se dibujan los objetos actualizados
```c++
		world.Step(1 / 75.f, 8, 3);
        escuchadorDeContacto.Update(1/75.f);

        cube1.update();
        cube2.update();
        pilar1.update();
        pilar2.update();
        pilar3.update();
        pilar4.update();
        pilar5.update();
        cube1Polea.update();
        cube2Polea.update();
        cube3Polea.update();
        gear1.update();
        gear2.update();
        LargePlatform.update();
        platform11.update();
        platform12.update();
        pulley1.update();
        pulley2.update();
        wheel.update();
        prismaticImpulse.update();
        prismaticImpulseStatic.update();
        Sensor1.update();
        Sensor2.update();

        window.clear();
        cube1.draw(window);
        cube2.draw(window);
        pilar1.draw(window);
        pilar2.draw(window);
        pilar3.draw(window);
        pilar4.draw(window);
        pilar5.draw(window);
        cube1Polea.draw(window);
        cube2Polea.draw(window);
        cube3Polea.draw(window);
        sideWall1.draw(window);
        sideWall2.draw(window);
        sideWall3.draw(window);
        sideWall4.draw(window);
        sideWall5.draw(window);
        sideWall6.draw(window);
        platform1.draw(window);
        platform2.draw(window);
        platform3.draw(window);
        platform4.draw(window);
        platform5.draw(window);
        platform6.draw(window);
        platform7.draw(window);
        platform8.draw(window);
        platform9.draw(window);
        platform10.draw(window);
        platform11.draw(window);
        platform12.draw(window);
        platform13.draw(window);
        pulley1.draw(window);
        pulley2.draw(window);
        gear1.draw(window);
        gear2.draw(window);
        wheel.draw(window);
        prismaticImpulse.draw(window);
        prismaticImpulseStatic.draw(window);
        Sensor1.draw(window);
        Sensor2.draw(window);
        LargePlatform.draw(window);
        LargePlatformCenter.draw(window);
        window.display();
```
##### Shapes.h
Se incluyen las llibrerias necesarias
```c++
#include <Box2D/Box2D.h>
#ifndef RUBE_GOLDBERG_SHAPES_H
#define RUBE_GOLDBERG_SHAPES_H
```

Se crea la clase de estaticos para objetos estaticos y sin cuerpo 
```c++
class Static {
    public:
        Static(b2World &world, float x, float y) {
            b2BodyDef bodydef;  //Se inicializa el objeto
            bodydef.position.Set(x / SCALE, y / SCALE); //Asigna posicion
            body = world.CreateBody(&bodydef);  //Se crea en el mundo
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

Se crea una clase para los objetos dinámicos circulares el cual recibe la posición, color del objeto y radio del objeto
```c++
class CircleShape {
    public:
        CircleShape(b2World &world, float x, float y, sf::Color color, float radio) {
            b2BodyDef bodydef;
            bodydef.position.Set(x / SCALE, y / SCALE);
            bodydef.type = b2_dynamicBody;
            body = world.CreateBody(&bodydef);

            b2CircleShape shape;

            shape.m_radius = radio / SCALE;

            b2FixtureDef fixturedef;
            fixturedef.shape = &shape;
            fixturedef.density = 0.1f;
            fixturedef.friction = 1.15f;
            fixturedef.restitution = 0.5f;
            body->CreateFixture(&fixturedef);

            circle.setRadius(radio);
            circle.setFillColor(color);
            circle.setOrigin(radio, radio);
        }

        void update() {
            circle.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
            circle.setRotation(body->GetAngle() * 180 / b2_pi);
        }

        void draw(sf::RenderWindow &win) const {
            win.draw(circle);
        }

        b2Body *getBody() {
            return body;
        }

    private:
        sf::CircleShape circle;
        b2Body *body;
    };
```

Se crea la clase EdgeShape la cual dibuja lineas con colision dados dos puntos en el espacio
```c++
class EdgeShape {
    public:
        EdgeShape(b2World& world, float Startx, float Starty, float Endx, float Endy, sf::Color color) {
            b2BodyDef bodyDef;
            bodyDef.position.Set(0.0f, 0.0f); // La posición se configurará al agregar la forma
            body = world.CreateBody(&bodyDef);

            b2EdgeShape shape;
            shape.SetTwoSided(b2Vec2(Startx / SCALE, Starty / SCALE), b2Vec2(Endx / SCALE, Endy / SCALE));

            b2FixtureDef fixtureDef;
            fixtureDef.shape = &shape;
            body->CreateFixture(&fixtureDef);

			//Define el punto inicial y final de la linea y su color
            line[0] = sf::Vertex(sf::Vector2f(Startx, Starty), color);
            line[1] = sf::Vertex(sf::Vector2f(Endx, Endy), color);
        }

        void draw(sf::RenderWindow& win) const {
            win.draw(line, 2, sf::Lines);
        }

        b2Body* getBody() {
            return body;
        }

    private:
        sf::Vertex line[2];
        b2Body* body;
    };
```

Se crea la clase cubo la cual permite definir sus dimensiones, ángulo de rotación inicial y color
```c++
class Cube {
    public:
        Cube(b2World &world, float x, float y, sf::Color color, float xSize, float ySize, float angle) {
            b2BodyDef bodydef;
            bodydef.position.Set(x / SCALE, y / SCALE);
            bodydef.type = b2_dynamicBody;
            bodydef.angle = angle * b2_pi / 180;
            body = world.CreateBody(&bodydef);

            b2PolygonShape shape;
            shape.SetAsBox((xSize / 2) / SCALE, (ySize / 2) / SCALE);

            b2FixtureDef fixturedef;
            fixturedef.shape = &shape;
            fixturedef.density = 1.0f;
            fixturedef.friction = 1.3f;
            body->CreateFixture(&fixturedef);

            box.setSize(sf::Vector2f(xSize, ySize));
            box.setFillColor(color);
            box.setOrigin(xSize / 2, ySize / 2);
        }

        void setFixture(){
            body->GetFixtureList()->SetSensor(true);
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

Clase para el contact listener la cual permite poner un timer, actualizar el timer y detectar colisiones entre 2 cuerpos específicos
```c++
	namespace ContactListener{
    class MyContactListener :public b2ContactListener {
    public:
        void BeginTimer(b2Contact* contact, float DelayTime) {
            shouldApplyDelay = true;
            delayTime = DelayTime;
        }
        void Update(float deltaTime) {
            // Si se debe aplicar el retraso, comienza a contar el tiempo.
            if (shouldApplyDelay) {
                delayTimer += deltaTime;
                if (delayTimer >= delayTime) {
                    accion = true;
                    shouldApplyDelay = false;
                    delayTimer = 0.0f;
                }
            }
        }
        bool OnSensorEnter(b2Fixture* fixtureA, b2Fixture* fixtureB, b2Body* bodyA){
            trigger = false;
            if(fixtureA->IsSensor() && fixtureB->GetBody() == bodyA || fixtureB->IsSensor() && fixtureA->GetBody() == bodyA){
                trigger = true;
            }
            return trigger;
        }
        bool GetAccion(){
            return accion;
        }
        void ResetAccion(){
            accion = false;
        }
    private:
        bool shouldApplyDelay = false;
        bool accion = false;
        bool trigger = false;
        float delayTime = 0.0f;
        float delayTimer = 0.0f;
    };
}

#endif //RUBE_GOLDBERG_SHAPES_H
```