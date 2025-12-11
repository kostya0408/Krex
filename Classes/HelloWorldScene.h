
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__



#include "cocos2d.h"
USING_NS_CC;


#include"GameLayer.h"
#include"background.h"


class Trex : public Layer
{
public:
    static  cocos2d::Scene* createScene();

    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
    cocos2d::PhysicsWorld* sceneWorld;

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback( Ref* pSender);
    
   

     Sprite* ground;
     PhysicsBody* groundBody;
    
     Sprite* cactus_1;
     PhysicsBody* cactus_1Body;

     /*Dino* abc;*/

     Sprite* bird;
     PhysicsBody* birdBody;

    
     Layer* hudLayer;

    

   
        
     Sprite* rex;
     PhysicsBody* rexBody;
     JumpBy* rexJump;
    

    /* MoveBy* rexMove;*/
    // implement the "static create()" method manually
    CREATE_FUNC(Trex);
};


#endif // __HELLOWORLD_SCENE_H__
