#include "Starthing.h"
#include "ECS.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "PhysicsPlayground.h"
bool boots;

void JumpBootThing::OnTrigger()
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


void JumpBootThing::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		for (int i = 0; i < m_targetEntities.size(); i++)
		{
			PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
		}
		boots = true;
	}
}

void JumpBootThing::OnExit()
{
	Trigger::OnExit();
}
