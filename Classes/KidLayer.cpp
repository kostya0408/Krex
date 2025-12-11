#include "KidLayer.h"



bool KidLayer::init() {

    if (!Layer::init())
    {
        return false;
    }


    Vector<MenuItem*> MenuItems_1;
    Vector<MenuItem*> MenuItems_2;


    // Створюємо два Label
    auto label1 = Label::createWithSystemFont("Play", "Arial", 40);
    label1->enableShadow();
    auto label2 = Label::createWithSystemFont("Pouse", "Arial", 40);
    label2->enableShadow();
    auto label3 = Label::createWithSystemFont("Option", "Arial", 40);
    label3->enableShadow();
    auto label4 = Label::createWithSystemFont("Exit", "Arial", 40);
    label4->enableShadow();

    // Робимо з них MenuItem
    auto item1 = MenuItemLabel::create(label1, CC_CALLBACK_1(KidLayer::menuCloseCallback, this));
    auto item2 = MenuItemLabel::create(label2, CC_CALLBACK_1(KidLayer::menuCloseCallback, this));
    auto item3 = MenuItemLabel::create(label3, CC_CALLBACK_1(KidLayer::menuCloseCallback, this));
    auto item4 = MenuItemLabel::create(label4, CC_CALLBACK_1(KidLayer::menuCloseCallback, this));

    float x = origin.x;
    float y = origin.y;
    item1->setPosition(Vec2(x, y + 75));
    item2->setPosition(Vec2(x, y + 25));
    item3->setPosition(Vec2(x, y - 25));
    item4->setPosition(Vec2(x, y - 75));


    MenuItems_1.pushBack(item1);
    MenuItems_1.pushBack(item2);
    MenuItems_1.pushBack(item3);
    MenuItems_1.pushBack(item4);
    auto menu_1 = Menu::createWithArray(MenuItems_1);
    menu_1->setPosition(Vec2(x + visibleSize.width - 100, y + visibleSize.height / 2));
    /*this->addChild(menu_1, 1);*/
    this->addChild(menu_1);
    return true;

}
void KidLayer::menuCloseCallback(Ref* pSender)
{
    /*Director::getInstance()->end();*/
    auto Hello = Trex::createScene();
    /*Director::getInstance()->replaceScene(Hello);*/
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, Hello));
}
