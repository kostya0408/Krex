
#ifndef _Cactus_ 
#define _Cactus_

#include "cocos2d.h";
#include "Dino.h"
#include"Enemy.h"
#include"background.h"
#include"Decoration.h"
#include"memory"
USING_NS_CC;
using namespace std;

class GameLayer : public Layer {

public:



	virtual bool init();

	void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
	cocos2d::PhysicsWorld* sceneWorld;

	Vector<SpriteFrame*> getAnimation(const char* format, int count);


	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

	shared_ptr<Enemy>cactus;
	shared_ptr<Enemy>ptr;
	shared_ptr <Dino> dino;
	shared_ptr <Decoration> ground;
	
	void update(float dt);

	Size  visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int speed = 1;
	int speed_1 = 1;

	bool onContactBegin(PhysicsContact& contact);

	CREATE_FUNC(GameLayer);
};



#endif 