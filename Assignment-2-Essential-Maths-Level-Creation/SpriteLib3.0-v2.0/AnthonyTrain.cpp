#include "AnthonyTrain.h"
#include "ECS.h"
#include "PhysicsPlayground.h"
	int heightVar;

void AnthonyTrain::OnTrigger()
{
	Trigger::OnTrigger();

	if (!triggered)
	{
		if (heightVar < 2)
		{
			for (int i = 0; i < m_targetEntities.size(); i++)
			{
				PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
			}

			triggered = true;
			std::cout << "You hit a wall";
		}
	}
}

void AnthonyTrain::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		if (heightVar < 2)
		{
			for (int i = 0; i < m_targetEntities.size(); i++)
			{
				PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
			}

			triggered = true;

			std::cout << "~~~~~You hit a wall";
		}
	}
}

void AnthonyTrain::OnExit()
{
	Trigger::OnExit();
}