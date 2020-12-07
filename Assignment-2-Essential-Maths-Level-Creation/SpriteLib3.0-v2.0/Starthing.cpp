#include "Starthing.h"
#include "ECS.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "PhysicsPlayground.h"
 int multiplier;

void StarThing::OnTrigger()
{
	Trigger::OnTrigger();

	if (!triggered)
	{
		for (int i = 0; i < m_targetEntities.size(); i++)
		{
			PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
		}
		triggered = true;
	}
}

void StarThing::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		for (int i = 0; i < m_targetEntities.size(); i++)
		{
			PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
		}
		multiplier = 2;
		
	}
}

void StarThing::OnExit()
{
	Trigger::OnExit();
}
