#include "PhysicsPlayground.h"
#include "Utilities.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <ctime>
float posX;
float posY = 100.f;
float apple;
float boat;
float grape, pear, peach;
float tempscore;

using namespace std;
PhysicsPlayground::PhysicsPlayground(std::string name)
	: Scene(name)
{
	//No gravity this is a top down scene
	//m_gravity = b2Vec2(0.f, -150.f);
	m_gravity = b2Vec2(0.f, -30.f);
	m_physicsWorld->SetGravity(m_gravity);

	m_physicsWorld->SetContactListener(&listener);
}

void PhysicsPlayground::Combination1(int posX, float& PosY)
{
	float apple1;
	float apple2;
	int peachnum;
	peachnum = (rand() % 3);
	if (posX == 1)
	{
		apple = 0.f;
		boat = 33.f;
		if (peachnum == 2)
			Scene::JumpBootTrigger(m_physicsWorld, "JumpBoots.png", 15, 15, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, -33, PosY);
	}
	else if (posX == 2)
	{
		apple = 33.f;
		boat = -33.f;
		if (peachnum == 2)
			Scene::JumpBootTrigger(m_physicsWorld, "JumpBoots.png", 15, 15, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, 0, PosY);
	}
	else if (posX == 3)
	{
		apple = -33.f;
		boat = 0.f;
		if (peachnum == 2)
			Scene::JumpBootTrigger(m_physicsWorld, "JumpBoots.png", 15, 15, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, 33, PosY);
	}
	apple2 = boat;
	apple1 = apple;
	Scene::TrainTrigger(m_physicsWorld, "Train.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
	Scene::CoinTrigger(m_physicsWorld, "shmeckel.png", 15, 15, 100., vec3(0.f, 20.f, 2.f), 0, 0, apple2, PosY);
	PosY = PosY + 130.f;
}
void PhysicsPlayground::Combination2(int posX, float& PosY)
{
	float apple1;
	float apple2;
	int pearnum;
	pearnum = (rand() % 3);
	if (posX == 1)
	{
		apple = 0.f;
		boat = -33.f;
		apple1 = apple;
		if (pearnum == 1)
			Scene::HurdleTrigger(m_physicsWorld, "Jump.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
		else
			Scene::TrainTrigger(m_physicsWorld, "Train2.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
	}
	else if (posX == 2)//test
	{
		apple = 33.f;
		boat = 0.f;
		apple1 = apple;
		if (pearnum == 1)
			Scene::HurdleTrigger(m_physicsWorld, "Jump.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
		else
			Scene::TrainTrigger(m_physicsWorld, "Train2.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
	}
	else if (posX == 3)
	{
		apple = -33.f;
		boat = 33.f;
	apple1 = apple;
		if (pearnum == 1)
			Scene::HurdleTrigger(m_physicsWorld, "Jump.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
		else
			Scene::TrainTrigger(m_physicsWorld, "Train2.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
	}
	apple2 = boat;
	Scene::CoinTrigger(m_physicsWorld, "shmeckel.png", 15, 15, 100, vec3(0.f, 20.f, 2.f), 0, 0, apple2, PosY);
	PosY = PosY + 130.f;
}
void PhysicsPlayground::Combination3(int posX, float& PosY)
{
	 
	float apple1;
	float grape1;
	int grapenum;
	grapenum = (rand() % 3);
	if (posX == 1)
	{
		apple = 0.f;
		if(grapenum == 1)
			Scene::StarTrigger(m_physicsWorld, "2xStar.png", 15, 15, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, 33, PosY);
	}
	else if (posX == 2)
	{
		apple = 33.f;
		if (grapenum == 1 )
			Scene::StarTrigger(m_physicsWorld, "2xStar.png", 15, 15, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, 0, PosY);
	}
	else if (posX == 3)
	{
		apple = -33.f;
		if (grapenum == 1)
			Scene::StarTrigger(m_physicsWorld, "2xStar.png", 15, 15, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, -33, PosY);
	}
	apple1 = apple;
	Scene::TrainTrigger(m_physicsWorld, "Train3.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
	PosY = PosY + 57.f;
	Scene::TrainTrigger(m_physicsWorld, "Train.png", 30, 80, 100, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);
	PosY = PosY + 150.f;

}

void PhysicsPlayground::TestingTrain(int posX, float& PosY)
{

	float apple1;
	if (posX == 1)
	{
		apple = 0.f;
	}
	else if (posX == 2)
	{
		apple = 33.f;
	}
	else if (posX == 3)
	{
		apple = -33.f;
	}
	apple1 = apple;

	Scene::TrainTrigger(m_physicsWorld, "Train2.png", 30.f, 80.f, 100.f, vec3(0.f, 20.f, 2.f), 0.f, 0.f, apple1, PosY);

}

void PhysicsPlayground::InitScene(float windowWidth, float windowHeight)
{
	int tempVar;
	multiplier = 1;

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

		std::string fileName = "SurferCharacter4.png";
		std::string animations = "FixedSurfer.json";
		ECS::GetComponent<Player>(entity).InitPlayer(fileName, animations, 20, 50, &ECS::GetComponent<Sprite>(entity), &ECS::GetComponent<AnimationController>(entity),
			&ECS::GetComponent<Transform>(entity));
		ECS::GetComponent<Transform>(entity).SetPosition(vec3(0.f, 0.f, 3.f));

		auto& tempSpr = ECS::GetComponent<Sprite>(entity);
		auto& tempPhsBody = ECS::GetComponent<PhysicsBody>(entity);

		b2Body* tempBody;
		b2BodyDef tempDef;
		tempDef.type = b2_dynamicBody;
		tempDef.position.Set(0.f, -40.f);

		tempBody = m_physicsWorld->CreateBody(&tempDef);

		tempPhsBody = PhysicsBody(entity, tempBody, 10, 10, vec2(0.f, -20.f), false, PLAYER, PLATFORM | GROUND | ENEMY | OBJECTS | PICKUP | TRIGGER, 0.5f, 3.f);

		tempPhsBody.SetRotationAngleDeg(0.f);
		tempPhsBody.SetFixedRotation(true);
		tempPhsBody.SetColor(vec4(1.f, 0.f, 1.f, 0.3f));
		tempPhsBody.SetGravityScale(0.f);
	}
	//Player's platform
	{
		//Scene::PlayerPlatform(m_physicsWorld, 150, 10, vec3(30.f, -70.f, 2.f),  110.f, 10.f,  0.f, -70.f, 0.f);
	}
	float anthony = 50.f;
	{

	}
	//Starter Train
	{
		int* p;
		int num;
		p = randomNumX();
		num = randomNum();
		
		for (int i = 0; i < 100; i=i)
		{

			tempVar = *(p + i);
			i++;
			//std::cout << tempVar << endl;
			Combination1(tempVar,posY);

			tempVar = *(p + i);
			i++;
			//std::cout << tempVar << endl;
			Combination2(tempVar,posY);

			tempVar = *(p + i);
			i++;
			//std::cout << tempVar << endl;
			Combination3(tempVar,posY);


			//std::cout << endl << "Next group" << endl << endl;
		}
	}
	//Right Player Border
	{
		Scene::PlayerPlatform(m_physicsWorld, 15, 15, vec3(30.f, -60.f, 2.f), 10.f, 10.f, 44.f, -60.f, 0.f);
	}
	//Left Player Boarder
	{
		Scene::PlayerPlatform(m_physicsWorld, 15, 15, vec3(30.f, -60.f, 2.f), 10.f, 10.f, -43.f, -60.f, 0.f);
	}
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
float startimer, jumpTime, bootTimer, jumpTime2;
void PhysicsPlayground::Update()
{

	heightVar2 = heightVar;
	auto& player = ECS::GetComponent<Player>(MainEntities::MainPlayer());
	Scene::AdjustScrollOffset();
	player.Update();
	if (multiplier > 1)
	{
		startimer += 0.01;
	}
	if (startimer >= 3)
	{
		multiplier = 1;
		startimer = 0;
	}
	if (boots == true)
	{
		bootTimer += 0.01;
	}
	if (bootTimer >= 5)
	{
		boots = false;
		bootTimer = 0;
	}

	if (heightVar > 0)
	{
		jumpTime += 0.01;
	}
	if (jumpTime >= 1)
	{
		heightVar = 0;
		jumpTime = 0;
	}

	if (heightVar2 > 0)
	{
		jumpTime2 += 0.01;
	}
	if (jumpTime2 >= 1)
	{
		heightVar2 = 0;
		jumpTime2 = 0;
	}
	tempscore += 0.01 * multiplier;
	tempscore += coinpickvar * multiplier;
	coinpickvar = 0;
	displayscore = tempscore;
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

	if (Input::GetKeyDown(Key::Space))
	{
		if( boots==false)
			heightVar = 1;
		else if(boots == true)
			heightVar = 2;
	}

	if (Input::GetKey(Key::A))
	{
		player.GetBody()->ApplyForceToCenter(b2Vec2(-1400000.f, 0.f), true);
	
	}
	if (Input::GetKey(Key::D))
	{
		player.GetBody()->ApplyForceToCenter(b2Vec2(1400000.f, 0.f), true);
	}
	
}

void PhysicsPlayground::KeyboardUp()
{
	

}
