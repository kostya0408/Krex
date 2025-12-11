#pragma once

#ifndef _Enemy_
#define _Enemy_

#include"cocos2d.h"

using namespace cocos2d;


class Enemy
{
public:
	Enemy(Layer* layer, std::string name);
	
	
	void setposition(int x, int y);
	void setdynamic(bool a);

	int getposition_X();
	int getposition_Y();

	/*~Enemy() {
		delete sprite;

	}*/

private:
	Sprite* sprite = nullptr;
	PhysicsBody* sprite_Body = nullptr;
	Size  visibleSize = Director::getInstance()->getVisibleSize(); // auto = Size;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

};


#endif // !_Enemy_


