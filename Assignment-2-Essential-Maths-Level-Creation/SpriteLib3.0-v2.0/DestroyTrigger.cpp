#include "DestroyTrigger.h"
#include "ECS.h"
#include "PhysicsPlayground.h"

 int coinpickvar;

void DestroyTrigger::OnTrigger()
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

void DestroyTrigger::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		for (int i = 0; i < m_targetEntities.size(); i++)
		{
			PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
		}
		triggered = true;
		coinpickvar += 5;
	}
}

void DestroyTrigger::OnExit()
{
	Trigger::OnExit();
}
