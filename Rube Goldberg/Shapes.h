//
// Created by ric13 on 05/11/2023.
//

#include <Box2D/Box2D.h>
#ifndef RUBE_GOLDBERG_SHAPES_H
#define RUBE_GOLDBERG_SHAPES_H

namespace shapes{

    constexpr float SCALE = 30.0f;

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
}

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
