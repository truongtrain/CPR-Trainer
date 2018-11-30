


#include <math.h>
#include <QImage>
#include <QDebug>
#include <QTimer>
#include <Box2D/Box2D.h>


void update(float stepSize, b2World &World);;

void notMain(){
    // Set up the Box2D world in which the animation takes place
    b2Vec2 Gravity(0.f, 9.8f);
    b2World World(Gravity);

    // Create the ground
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(0, 100);
    BodyDef.type = b2_staticBody;
    b2Body* ground = World.CreateBody(&BodyDef);
    b2PolygonShape Shape;
    Shape.SetAsBox(10, 10);
    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.f;
    FixtureDef.shape = &Shape;
    ground->CreateFixture(&FixtureDef);

    // Create a single ambulance
    BodyDef.type = b2_dynamicBody;
    BodyDef.position = b2Vec2(0, 0);
    // BodyDef.linearVelocity = b2Vec2(5.f, 5.f);
    b2Body* ambulance = World.CreateBody(&BodyDef);
    Shape.SetAsBox(10, 10);
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    ambulance->CreateFixture(&FixtureDef);
    ambulance->SetLinearVelocity(b2Vec2(1, -1));


    float stepSize = 0.01;
    int iterationCount = 30;
    for (int i = 0; i < iterationCount; i++)
    {
        qDebug() << "ITERATION " << i << ":";
        update(stepSize, World);
    }

}


void update(float stepSize, b2World &World){
    World.Step(stepSize, 8, 3);

    for (b2Body* BodyIterator = World.GetBodyList();
         BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
    {
        if (BodyIterator->GetType() == b2_dynamicBody)
        {
            qDebug() << "p_x:" << BodyIterator->GetPosition().x << " p_y:" << BodyIterator->GetPosition().y
                       << "     v_x:" << BodyIterator->GetLinearVelocity().x << " v_y:" << BodyIterator->GetLinearVelocity().y;
        }
        else
        {
            // Do nothing yet.  Don't care about the ground.
        }
    }
}


