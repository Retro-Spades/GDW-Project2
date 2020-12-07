#include "Player.h"
using namespace std;

Player::Player()
{
}

Player::Player(std::string& fileName, std::string& animationJSON, int width, int height, Sprite* sprite, 
					AnimationController* controller, Transform* transform, bool hasPhys, PhysicsBody* body)
{
	InitPlayer(fileName, animationJSON, width, height, sprite, controller, transform, hasPhys, body);
}

void Player::InitPlayer(std::string& fileName, std::string& animationJSON, int width, int height, Sprite* sprite, 
							AnimationController* controller, Transform* transform, bool hasPhys, PhysicsBody* body)
{
	//Store references to the components
	m_sprite = sprite;
	m_animController = controller;
	m_transform = transform;
	m_hasPhysics = hasPhys;
	if (hasPhys)
	{
		m_physBody = body;
	}

	//Initialize UVs
	m_animController->InitUVs(fileName);

	//Loads the texture and sets width and height
	m_sprite->LoadSprite(fileName, width, height, true, m_animController);
	m_animController->SetVAO(m_sprite->GetVAO());
	m_animController->SetTextureSize(m_sprite->GetTextureSize());

	//Loads in the animations json file
	nlohmann::json animations = File::LoadJSON(animationJSON);

	
	//Idle 
	m_animController->AddAnimation(animations["SurferSpriteAnim"].get<Animation>());

	//Jump
	m_animController->AddAnimation(animations["JumpSpriteAnim"].get<Animation>());



	//Set Default Animation
	m_animController->SetActiveAnim(IDLE);


}

void Player::Update()
{

	MovementUpdate();


	AnimationUpdate();
}

void Player::MovementUpdate()
{
	m_moving = false;

	
	

		//Regular Movement
		float speed = 15.f;
		auto& player = ECS::GetComponent<PhysicsBody>(MainEntities::MainPlayer());

		b2Vec2 position = player.GetPosition();
		cout << position.x << endl;
		if (position.x >= -1 && position.x <= 1)
		{
			player.GetBody()->SetLinearVelocity(b2Vec2(0.f, 0.f));
		}

		if (Input::GetKey(Key::A))
		{
			m_transform->SetPositionX(m_transform->GetPositionX() - (speed * Timer::deltaTime));
			


			
		}
		if (Input::GetKey(Key::D))
		{
			m_transform->SetPositionX(m_transform->GetPositionX() + (speed * Timer::deltaTime));
			
			
		}

		if (Input::GetKeyDown(Key::Space))
		{
			m_jumping = true;
		}


}

void Player::AnimationUpdate()
{
	int activeAnimation = 0;


	if (m_jumping)
	{
		activeAnimation = JUMP;

		//Check if the attack animation is done
		if (m_animController->GetAnimation(m_animController->GetActiveAnim()).GetAnimationDone())
		{
			//Will auto set to idle
			m_locked = false;
			m_jumping = false;
			//Resets the animation
			m_animController->GetAnimation(m_animController->GetActiveAnim()).Reset();

			activeAnimation = IDLE;
		}
	}
	else
	{
		activeAnimation = IDLE;
	}

	SetActiveAnimation(activeAnimation);
}

void Player::SetActiveAnimation(int anim)
{
	m_animController->SetActiveAnim(anim);
}
