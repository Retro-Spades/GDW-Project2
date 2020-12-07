#pragma once

#include "Scene.h"
#include "PhysicsPlaygroundListener.h"

#ifndef __PhysicsPlayground_h__
#define __PhysicsPlayground_h__
extern int coinpickvar;
#endif
class PhysicsPlayground : public Scene
{
public:
	PhysicsPlayground(std::string name);

	void InitScene(float windowWidth, float windowHeight) override;

	void Update() override;

	void monkey();
	void Combination1(int, float&);
	void Combination2(int, float&);
	void Combination3(int, float&);

	void TestingTrain(int, float&);

	//Input overrides
	void KeyboardHold() override;
	void KeyboardDown() override;
	void KeyboardUp() override;

protected:
	PhysicsPlaygroundListener listener;

	int puzzleWall1;
	int puzzleWall2;
};
