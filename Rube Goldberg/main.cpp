#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>

#include "Shapes.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");

    b2Vec2 gravity(0.0f, 3.0f / shapes::SCALE);
    b2World world(gravity);

    ContactListener::MyContactListener escuchadorDeContacto;
    world.SetContactListener(&escuchadorDeContacto);

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

    //Sensores
    shapes::Cube Sensor1(world, 50, 485, sf::Color::Transparent,20,20,0);
    Sensor1.getBody()->GetFixtureList()->SetSensor(true);
    Sensor1.getBody()->GetFixtureList()->SetDensity(0.0f);
    Sensor1.getBody()->ResetMassData();
    shapes::Cube Sensor2(world, 775, 850, sf::Color::Transparent,30,30,0);
    Sensor2.getBody()->GetFixtureList()->SetSensor(true);
    Sensor2.getBody()->GetFixtureList()->SetDensity(0.0f);
    Sensor2.getBody()->ResetMassData();

    //JOINTS
    b2DistanceJoint* distJoint;
    b2DistanceJointDef distJointDef;
    distJointDef.Initialize(cube1.getBody(), cube2.getBody(), cube1.getBody()->GetWorldCenter(), cube2.getBody()->GetWorldCenter());
    distJointDef.damping = 30;
    distJointDef.stiffness = 20;
    distJoint = (b2DistanceJoint*)world.CreateJoint(&distJointDef);

    b2RevoluteJointDef revJointDef;
    revJointDef.Initialize(LargePlatformCenter.getBody(), LargePlatform.getBody(), LargePlatformCenter.getBody()->GetWorldCenter());
    revJointDef.enableMotor = false;
    world.CreateJoint(&revJointDef);

    b2PrismaticJointDef prismJointDef;
    prismJointDef.Initialize(prismaticImpulseStatic.getBody(), prismaticImpulse.getBody(), prismaticImpulseStatic.getBody()->GetWorldCenter(), b2Vec2(0,1));
    prismJointDef.enableLimit = true;
    prismJointDef.upperTranslation = 0;
    prismJointDef.lowerTranslation = -5;
    world.CreateJoint(&prismJointDef);

    b2PulleyJointDef pulleyJointDef;
    pulleyJointDef.Initialize(platform11.getBody(),platform12.getBody(),pulley1.getBody()->GetWorldCenter(),pulley2.getBody()->GetWorldCenter(),platform11.getBody()->GetWorldCenter(),platform12.getBody()->GetWorldCenter(),1.f);
    world.CreateJoint(&pulleyJointDef);

    b2PrismaticJointDef prismJointDef2;
    prismJointDef2.Initialize(centerPlatform11.getBody(), platform11.getBody(), centerPlatform11.getBody()->GetWorldCenter(), b2Vec2(0,1));
    prismJointDef2.enableLimit = true;
    prismJointDef2.upperTranslation = 10;
    prismJointDef2.lowerTranslation = -10;
    world.CreateJoint(&prismJointDef2);

    b2PrismaticJointDef prismJointDef3;
    prismJointDef3.Initialize(centerPlatform12.getBody(), platform12.getBody(), centerPlatform12.getBody()->GetWorldCenter(), b2Vec2(0,1));
    prismJointDef3.enableLimit = true;
    prismJointDef3.upperTranslation = 0;
    prismJointDef3.lowerTranslation = -10;
    world.CreateJoint(&prismJointDef3);

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

    b2GearJoint* joint;
    b2GearJointDef gearJointDef;
    gearJointDef.bodyA = gear1.getBody();
    gearJointDef.bodyB = gear2.getBody();
    gearJointDef.joint1 = world.CreateJoint(&revGear1);
    gearJointDef.joint2 = world.CreateJoint(&revGear2);
    gearJointDef.ratio = 1.0f;
    world.CreateJoint(&gearJointDef);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
                return 0; // return from the main function, effectively ending the program
            }
        }

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
    }
    return 0;
}