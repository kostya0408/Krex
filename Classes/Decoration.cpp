
#include "Decoration.h"

Decoration::Decoration(Layer* layer, std::string name) {
	sprite = Sprite::create(name);
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2 , origin.y + visibleSize.height / 2));
	layer->addChild(sprite);
}


void Decoration::sethitbox(bool a ) {
	auto mySprite_body = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.5f, 1.0f, 0.3f));
	mySprite_body->setLinearDamping(0.3f);
	mySprite_body->setDynamic(a);
	sprite->setPhysicsBody(mySprite_body);
}



void Decoration::setposition(int x, int y) {
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2 + x, origin.y + visibleSize.height / 2 + y));
}



