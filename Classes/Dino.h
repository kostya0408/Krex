
#ifndef _Dino_
#define _Dino_

#include"cocos2d.h"
USING_NS_CC;


class Dino  {
public:
	Dino(Layer* layer);

	void move(); 
	void setposition(int x, int y);
	

	/*~Dino(){
		sprite->autorelease();
	}*/

private:
	
	Sprite* sprite = nullptr;
	PhysicsBody* sprite_Body = nullptr;
	Size  visibleSize = Director::getInstance()->getVisibleSize(); // auto = Size;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

};





#endif // !_Dino_

