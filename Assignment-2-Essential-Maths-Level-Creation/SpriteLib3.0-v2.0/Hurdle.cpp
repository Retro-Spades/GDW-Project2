#include "Hurdle.h"
#include "ECS.h"

#include "PhysicsPlayground.h"
int heightVar2;

void HurdleThing::OnTrigger()
{
	Trigger::OnTrigger();

	if (!triggered)
	{
		if (heightVar2 == 0)
		{
			for (int i = 0; i < m_targetEntities.size(); i++)
			{
				PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
			}
			triggered = true;
		}
	}
}

void HurdleThing::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		
		if (heightVar2 == 0)
		{
			std::cout << "dead";
			for (int i = 0; i < m_targetEntities.size(); i++)
			{
				PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
			}
		}
	}
}

void HurdleThing::OnExit()
{
	Trigger::OnExit();
}
