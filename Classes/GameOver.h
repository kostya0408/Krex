
#ifndef _GameOver_
#define _GameOver_


#include "cocos2d.h";
#include "HelloWorldScene.h"
#include "KidLayer.h"


USING_NS_CC;
using namespace std;

class GameOver : public Layer
{
public:
	virtual bool init();



	Size  visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(GameOver);




};


#endif 

