#include <iostream>
#include <Box2d/Box2d.h>

int main() {
    //Creacion del mundo y su gravedad
    b2Vec2 gravity(0.0f,-24.79f);
    b2World world(gravity);

    //Caracteristicas del cuerpo base
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f,-10.0f);

    //Creacion del cuerpo base
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    //Crear su forma
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f,1.0f);

    //Se le da densidad
    groundBody ->CreateFixture(&groundBox, 15600.0);

    //Definir cubo
    b2BodyDef bodyDef;

    //Cuerpo dinamico
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 15.0f);

    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f,1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 60.55f;
    //Suponiendo que no hay aire con el que genere friccion
    fixtureDef.friction = 0.9f;

    body ->CreateFixture(&fixtureDef);

    float timeStep = 1.0f/60.0f;

    int32 velocityIterations = 6;
    int32 positionIteration = 2;

    for(int32 i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIteration);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
    return 0;
}