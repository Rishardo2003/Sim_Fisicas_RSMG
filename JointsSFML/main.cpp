#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>

constexpr float SCALE = 30.0f;

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

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    //Distance Bodies
    Cube cube(world, 400, 300, sf::Color::Red);
    Cube cube1(world, 350, 250, sf::Color::Red);

    //Distance Joint
    b2DistanceJointDef disJointDef;
    disJointDef.Initialize(cube.getBody(), cube1.getBody(), cube.getBody()->GetWorldCenter(), cube1.getBody()->GetWorldCenter());
    disJointDef.damping = 30;
    disJointDef.stiffness = 20;
    world.CreateJoint(&disJointDef);

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

    //Gear Joint
    b2GearJointDef gearJointDef;
    gearJointDef.bodyA = cube8.getBody();
    gearJointDef.bodyB = cube10.getBody();
    gearJointDef.joint1 = world.CreateJoint(&revJointDef2);
    gearJointDef.joint2 = world.CreateJoint(&revJointDef3);
    gearJointDef.ratio = 1.0f;
    world.CreateJoint(&gearJointDef);

    //Weld Bodies
    Cube dynamicWeld1(world, 200, 500, sf::Color::Red);
    Cube dynamicWeld2(world, 180, 500, sf::Color::Blue);

    //Weld Joint
    b2WeldJointDef weldJointDef;
    weldJointDef.Initialize(dynamicWeld1.getBody(), dynamicWeld2.getBody(), dynamicWeld1.getBody()->GetWorldCenter());
    weldJointDef.stiffness = 5.0f;
    world.CreateJoint(&weldJointDef);

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
    }
    return 0;
}