#include <Box2D/Box2D.h>
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
// Define the gravity vector
    b2Vec2 gravity(0.0f, -24.79f);

// Construct a world object, which will hold and simulate the rigid bodies
    b2World world(gravity);

// Create a dynamic body for the bullet
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);
    b2Body* body = world.CreateBody(&bodyDef);

// Define another box shape for the bullet
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.2f, 0.05f);

// Define the dynamic body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.01f;
    fixtureDef.friction = 0.3f;

// Add the shape to the body
    body->CreateFixture(&fixtureDef);

// Set the initial velocity of the bullet
    float angle = 45.0f; // Angle in degrees
    float speed = 400.0f; // Speed in m/s
    float vx = speed * std::cos(angle * M_PI / 180.0f);
    float vy = speed * std::sin(angle * M_PI / 180.0f);

    body->SetLinearVelocity(b2Vec2(vx, vy));

// Simulate the world
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        std::cout << body->GetPosition().x << " " << body->GetPosition().y << std::endl;

    }

// Remember to clean up
    world.DestroyBody(body);

    return 0;
}