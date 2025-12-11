#include "HelloWorldScene.h"


USING_NS_CC;

Scene* Trex::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);

    scene->getPhysicsWorld()->setGravity(Vect(0, -200.0));
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto game = GameLayer::create();
    game->SetPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(game);
    
    auto back = Background::create();
    scene->addChild(back, 2);



   

   //auto layer = Trex::create();
   // layer->SetPhysicsWorld(scene->getPhysicsWorld());
   // scene->addChild(layer, 0);



    auto Layer1 = cocos2d::LayerColor::create(Color4B(0, 255, 0, 255));
    scene->addChild(Layer1, -3);

   

    return scene;
   
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Trex::init()
{


    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    //abc = new Dino;//memoraly
    //this->addChild(abc);



    Size  visibleSize = Director::getInstance()->getVisibleSize(); // auto = Size;
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    

    

    

  

   
    

    /*rex->runAction(rexJump);*/

    
    


    /*auto rexMove = MoveBy::create(2, Vec2(50, 100));

    rex->runAction(rexMove);*/
   
   /* auto mySprite = Sprite::create("man.png");
    mySprite->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    auto mySprite_body = PhysicsBody::createBox(mySprite->getContentSize(), PhysicsMaterial(0.5f, 1.0f, 0.3f));
    mySprite_body->setLinearDamping(0.3f);
    mySprite_body->setDynamic(true);
    mySprite->setPhysicsBody(mySprite_body);
    mySprite->setScale(0.5f);
    
    this->addChild(mySprite);*/
   
   
    return true;
}




//void count_scores() {
//    
//    ++score;
//    std::string tempScore = StringUtils::format("%i", score);
//    scoreLabel->setString(tempScore.c_str());
//
//}




void Trex::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
