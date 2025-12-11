
#include "background.h"



bool Background::init() {

    if (!Layer::init())
    {
        return false;
    }
    

    

    scoreLabel = Label::createWithTTF(tempScore.c_str(), "fonts/Marker Felt.ttf", 33);
    scoreLabel->setColor(Color3B::WHITE);
    scoreLabel->setPosition(Point(visibleSize.width / 2 - 100, visibleSize.height - 22));

    this->scheduleUpdate(); // вмикає виклик update(dt)

    this->addChild(scoreLabel);


   /* cloud = make_shared<Decoration>(this, "cloud.png");*/

}

void Background::update(float dt)
{

    score +=0.05; // збільшуємо score пропорційно часу
    scoreLabel->setString(StringUtils::format("Score: %d", (int)score));


}






   




  




