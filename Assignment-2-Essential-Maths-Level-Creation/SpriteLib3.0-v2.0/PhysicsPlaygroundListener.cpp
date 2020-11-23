#include "PhysicsPlaygroundListener.h"

#include "ECS.h"

PhysicsPlaygroundListener::PhysicsPlaygroundListener()
	: b2ContactListener()
{

}

void PhysicsPlaygroundListener::BeginContact(b2Contact* contact)
{
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	bool sensorA = fixtureA->IsSensor();
	bool sensorB = fixtureB->IsSensor();

	//if neither or both are sensors, will be false
	if ((sensorA ^ sensorB))
	{
		if (sensorA)
		{
			TriggerEnter(fixtureA);
		}
		else if (sensorB)
		{
			TriggerEnter(fixtureB);
		}
	}

	b2Filter filterA = fixtureA->GetFilterData();
	b2Filter filterB = fixtureB->GetFilterData();

	if ((filterA.categoryBits == PLAYER && filterB.categoryBits == GROUND) || (filterB.categoryBits == PLAYER && filterA.categoryBits == GROUND))
	{
		if (filterA.categoryBits == PLAYER)
		{
			
		}
		else if (filterB.categoryBits == PLAYER)
		{
			
		}
	}

}

void PhysicsPlaygroundListener::EndContact(b2Contact* contact)
{
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	bool sensorA = fixtureA->IsSensor();
	bool sensorB = fixtureB->IsSensor();

	//if neither or both are sensors, will be false
	if ((sensorA ^ sensorB))
	{
		if (sensorA)
		{
			TriggerExit(fixtureA);
		}
		else if (sensorB)
		{
			TriggerExit(fixtureB);
		}
	}
}

void PhysicsPlaygroundListener::TriggerEnter(b2Fixture* sensor)
{
	int entity = (int)sensor->GetBody()->GetUserData();

	ECS::GetComponent<Trigger*>(entity)->OnEnter();
}

void PhysicsPlaygroundListener::TriggerExit(b2Fixture* sensor)
{
	int entity = (int)sensor->GetBody()->GetUserData();

	ECS::GetComponent<Trigger*>(entity)->OnExit();
}
