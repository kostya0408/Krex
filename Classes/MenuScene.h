#pragma once
#include "cocos2d.h"
#include "KidLayer.h"

using namespace cocos2d;
using namespace std;


class MenuScene : public Scene {
public:
    static Scene* createScene();
    virtual bool init();

    Size  visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    void menuCloseCallback(cocos2d::Ref* pSender);

    


    CREATE_FUNC(MenuScene);
};