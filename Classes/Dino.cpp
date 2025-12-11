
#include"Dino.h"



Dino::Dino(Layer* layer) {


	sprite = Sprite::create("dino.png");
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 3 + 50));
	sprite_Body = PhysicsBody::createBox(Size(80, 85), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	
	sprite_Body->setCollisionBitmask(1);
	sprite_Body->setCategoryBitmask(2);
	/*sprite_Body->setContactTestBitmask(1);*/
	sprite_Body->setDynamic(true);
	sprite->setPhysicsBody(sprite_Body);
	layer->addChild(sprite);
}


void Dino::move() {

	auto body = sprite->getPhysicsBody();
	body->applyImpulse(Vec2(0, 15000));

}
void Dino::setposition(int x, int y) {
	sprite->setPosition(origin.x + x, origin.y + y);

}