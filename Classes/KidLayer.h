#pragma once
#include "cocos2d.h"
#include "HelloWorldScene.h"

using namespace cocos2d;
using namespace std;



class KidLayer : public Layer
{
public:
	virtual bool init();



	Size  visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(KidLayer);


};