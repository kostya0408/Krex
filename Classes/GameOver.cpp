#include "GameOver.h"


bool GameOver::init() {

    if (!Layer::init())
    {
        return false;
    }

    Size  visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   


    
    auto label1 = Label::createWithSystemFont("Lose", "Arial", 96);
    label1->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height + 10));
    label1->enableShadow();
    this->addChild(label1);



    auto label2 = Label::createWithSystemFont("Back to Menu", "Arial", 64);
    label2->setPosition(Vec2( origin.x + visibleSize.width / 4, origin.y + visibleSize.height + 10));

    label2->enableShadow();
    auto item = MenuItemLabel::create(label2,CC_CALLBACK_1(GameOver::menuCloseCallback, this));
    this->addChild(label2);
    

    

   
   


    return true;
}
void GameOver::menuCloseCallback(Ref* pSender)
{
    
    auto Hello = Trex::createScene();
    
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, Hello));
}