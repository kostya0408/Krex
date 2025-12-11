#include"MenuScene.h"

Scene* MenuScene::createScene()
{




    auto scene = MenuScene::create();
    LayerColor* Layer1 = LayerColor::create(Color4B(0, 255, 0, 255));
    scene->addChild(Layer1, -3);
    auto Layer2 = KidLayer::create();
    scene->addChild(Layer2, -2);
    return scene;
}

bool MenuScene::init()
{

    if (!Scene::init())
    {
        return false;
    }
     return true;

 
}
void MenuScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}


