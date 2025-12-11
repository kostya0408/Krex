
#include<GameLayer.h>



bool GameLayer::init() {

    if (!Layer::init())
    {
        return false;
    }
  


    ground = make_shared<Decoration>(this, "ground.png");
    ground->setposition(0, -200 );
    ground->sethitbox(false);


    
    cactus = make_shared<Enemy>(this, "cactus1.png");
   

    ptr = make_shared<Enemy>(this, "ptera.png");
    
    ptr->setdynamic(false);

    dino = make_shared<Dino>(this);
    dino->setposition(visibleSize.width / 2 - 300, visibleSize.height / 3 + 50);


    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameLayer::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    this->scheduleUpdate(); // вмикає виклик update(dt)


    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/bird/HD/.plist");

    auto frames = getAnimation("bird_%d.png", 2);
    auto sprite = Sprite::createWithSpriteFrame(frames.front());
    this->addChild(sprite);
    sprite->setPosition(600, 400 );

    auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 2);
    sprite->runAction(RepeatForever::create(Animate::create(animation)));



    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/dino/HDR/.plist");

    auto f = getAnimation("d_%d.png", 3);

    auto d = Sprite::createWithSpriteFrame(frames.front());
    d->setPosition(300, 300);
    //auto d_Body = PhysicsBody::createBox(Size(80, 85), PhysicsMaterial(50.0f, 0.0f, 0.0f));
    //d_Body->setDynamic(true);
    //d->setPhysicsBody(d_Body);
    this->addChild(d);
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    auto a = Animation::createWithSpriteFrames(f, 1.0f / 3);
    d->runAction(RepeatForever::create(Animate::create(a)));


    return true;

}

void GameLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
        dino->move();
    }
}


Vector<SpriteFrame*> GameLayer::getAnimation(const char* format, int count) {
    auto spritecache = SpriteFrameCache::getInstance();

    Vector<SpriteFrame*> animFrames;
    char str[100];
    for (int i = 1; i <= count; i++)
    {
        sprintf(str, format, i);
        //std::string name = StringUtils::format("bird_%d.jpg",i);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return animFrames;
}

void GameLayer::update(float dt)
{
    
    cactus->setposition(visibleSize.width / 2 + 225 - speed, visibleSize.height / 5 + 60);
    speed++;
    ptr->setposition(visibleSize.width / 2 + 300 - speed_1, visibleSize.height / 3 + 100);
    speed_1 += 2;

    if (ptr->getposition_X() < 5) {
        ptr->setposition(visibleSize.width / 2 + 300, visibleSize.height / 3 + 100);
        speed_1 = 1;
    }

    if (cactus->getposition_X() < 10) {
        cactus->setposition(visibleSize.width / 2 + 225, visibleSize.height / 5 + 60);
        speed = 1;
    }
    

}

bool GameLayer::onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    int coll_A = nodeA->getPhysicsBody()->getCollisionBitmask();
    int cat_A = nodeA->getPhysicsBody()->getCategoryBitmask();
    int cont_A = nodeA->getPhysicsBody()->getContactTestBitmask();
    int coll_B = nodeB->getPhysicsBody()->getCollisionBitmask();
    int cat_B = nodeB->getPhysicsBody()->getCategoryBitmask();
    int cont_B = nodeB->getPhysicsBody()->getContactTestBitmask();

    /*nodeB->removeFromParentAndCleanup(true);
    nodeA->removeFromParentAndCleanup(true);*/
    if (nodeA && nodeB)
    {

        if ((cat_A & cont_B) || (cat_A & cont_B))
        {
            
            Director::getInstance()->end();
            
        }

        /*else if (((nodeA->getPhysicsBody()->getCollisionBitmask() == 3) && (nodeB->getPhysicsBody()->getCollisionBitmask() == 2)) || ((nodeA->getPhysicsBody()->getCollisionBitmask() == 2) && (nodeB->getPhysicsBody()->getCollisionBitmask() == 3)))
        {

            if (nodeA->getTag() == 2)
            {

                nodeB->removeFromParentAndCleanup(true);
            }
            else if (nodeB->getTag() == 1)
            {
                nodeA->removeFromParentAndCleanup(true);
            }
        }*/
    }
    return true;
}


