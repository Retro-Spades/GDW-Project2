#include "PhysicsPlayground.h"
#include "Utilities.h"

#include <random>

PhysicsPlayground::PhysicsPlayground(std::string name)
	: Scene(name)
{
	//No gravity this is a top down scene
	m_gravity = b2Vec2(0.f, -150.f);
	m_physicsWorld->SetGravity(m_gravity);

	m_physicsWorld->SetContactListener(&listener);
}

void PhysicsPlayground::InitScene(float windowWidth, float windowHeight)
{
	//Dynamically allocates the register
	m_sceneReg = new entt::registry;

	//Attach the register
	ECS::AttachRegister(m_sceneReg);

	//Sets up aspect ratio for the camera
	float aspectRatio = windowWidth / windowHeight;

	//Setup MainCamera Entity
	{
		Scene::CreateCameraEntity(true, 5000.f, 5000.f, -85.f, 85.f, -85.f, 85.f, -100.f, 100.f, aspectRatio, true, true);
	}
	//Setup new Entity
	{
		Scene::CreateEntity("StationBackground.jpg", 150, 170, 1.f, vec3(0.f, 0.f, 1.f));
	}
	
	//Main entity
	{

		auto entity = ECS::CreateEntity();
		ECS::SetIsMainPlayer(entity, true);

		//Add components
		ECS::AttachComponent<Player>(entity);
		ECS::AttachComponent<Sprite>(entity);
		ECS::AttachComponent<Transform>(entity);
		ECS::AttachComponent<AnimationController>(entity);
		ECS::AttachComponent<PhysicsBody>(entity);

		std::string fileName = "SurferCharacter.png";
		std::string animation = "SurferSpriteAnim.json";
		ECS::GetComponent<Player>(entity).InitPlayer(fileName, animation, 20, 20, &ECS::GetComponent<Sprite>(entity), &ECS::GetComponent<AnimationController>(entity),
			&ECS::GetComponent<Transform>(entity));
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 0.f, 2.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_dynamicBody;
		tempDef.position.Set(0.f, -40.f);

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, float((tempSpr.GetHeight() - 10.f) / 2.f), vec2(0.f, 0.f), false, PLAYER, PLATFORM | GROUND | ENEMY | OBJECTS | PICKUP | TRIGGER, 0.5f, 3.f);

		tempPhsBody.SetRotationAngleDeg(0.f);
		tempPhsBody.SetFixedRotation(true);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetGravityScale(1.f);
	}
	//Player's platform
	{
		Scene::PlayerPlatform(m_physicsWorld, 150, 10, vec3(30.f, -20.f, 2.f),  110.f, 10.f,  0.f, -50.f, 0.f);
	}

	//Starter Train
	{
		Scene::TrainEntity(m_physicsWorld, "Train.png", 35, 80, 100, vec3 (0.f, 20.f, 2.f), 0.f, 0.f,0.f,50.f);
	}

	////Setup static Top Platform
	//{
	//	Scene::CreateMoveableEntity(m_physicsWorld, "Train2.png", 35, 80, 100, vec3(0.f, -20.f, 2.f), 0.f, 0.f, 37.f, 150.f);
	//}

	////Setup static Top Platform
	//{
	//	Scene::CreateMoveableEntity(m_physicsWorld, "Train3.png", 35, 80, 100, vec3(0.f, -20.f, 2.f), 0.f, 0.f, -37.f, -10.f);
	//}

	////Setup static Top Platform
	//{
	//	Scene::CreateMoveableEntity(m_physicsWorld, "Train.png", 35, 80, 100, vec3(0.f, -20.f, 2.f), 0.f, 0.f, 37.f, 250.f);
	//}

	////Setup static Top Platform
	//{
	//	Scene::CreateMoveableEntity(m_physicsWorld, "Train.png", 35, 80, 100, vec3(0.f, -20.f, 2.f), 0.f, 0.f, 0.f, 250.f);
	//}

	//{
	//	Scene::CreateMoveableEntity(m_physicsWorld, "Train.png", 35, 80, 100, vec3(0.f, -20.f, 2.f), 0.f, 0.f, -37.f, 350.f);
	//}

	//{
	//	Scene::CreateMoveableEntity(m_physicsWorld, "Train.png", 35, 80, 100, vec3(0.f, -20.f, 2.f), 0.f, 0.f, 37.f, 350.f);
	//}


	//Setup static LEFT WALL
	{
		Scene::CreateStaticEntity(m_physicsWorld, "LeftWall.png", 15, 200, vec3(0.f, -20.f, 0.f), 0.f, 0.f, -60.f, -10.f, 0.f);
	}
	//Setup static RIGHT WALL
	{
		Scene::CreateStaticEntity(m_physicsWorld, "RightWall.png", 15, 200, vec3(0.f, -20.f, 0.f), 0.f, 0.f, 60.f, -10.f, 0.f);
	}



	

	ECS::GetComponent<HorizontalScroll>(MainEntities::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(MainEntities::GetFocus()));
	ECS::GetComponent<VerticalScroll>(MainEntities::MainCamera()).SetFocus(&ECS::GetComponent<Transform>(MainEntities::GetFocus()));
}

void PhysicsPlayground::Update()
{
	
}


void PhysicsPlayground::KeyboardHold()
{
	auto& player = ECS::GetComponent<PhysicsBody>(MainEntities::MainPlayer());

	float speed = 1.f;
	b2Vec2 vel = b2Vec2(0.f, 0.f);

	if (Input::GetKey(Key::Shift))
	{
		speed *= 5.f;
	}

	if (Input::GetKeyDown(Key::A))
	{
		player.GetBody()->ApplyForceToCenter(b2Vec2(-1400000.f, 0.f), true);
	}
	if (Input::GetKeyDown(Key::D))
	{
		player.GetBody()->ApplyForceToCenter(b2Vec2(1400000.f, 0.f), true);
	}

	//Change physics body size for circle
	if (Input::GetKey(Key::O))
	{
		player.ScaleBody(1.3 * Timer::deltaTime, 0);
	}
	else if (Input::GetKey(Key::I))
	{
		player.ScaleBody(-1.3 * Timer::deltaTime, 0);
	}
}

void PhysicsPlayground::KeyboardDown()
{
	auto& player = ECS::GetComponent<PhysicsBody>(MainEntities::MainPlayer());

	if (Input::GetKeyDown(Key::T))
	{
		PhysicsBody::SetDraw(!PhysicsBody::GetDraw());
	}
	
}

void PhysicsPlayground::KeyboardUp()
{
	

}
