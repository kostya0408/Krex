#include "Enemy.h"

Enemy::Enemy(Layer* layer, std::string name) {


	sprite = Sprite::create(name);
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 3 + 50));
	sprite_Body = PhysicsBody::createBox(Size(80, 85), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	sprite_Body->setCollisionBitmask(3);
	sprite_Body->setCategoryBitmask(3);
	sprite_Body->setRotationEnable(false);
	/*sprite_Body->setContactTestBitmask(3);*/
	sprite_Body->setDynamic(true);
	sprite->setPhysicsBody(sprite_Body);
	layer->addChild(sprite);
	
}



void Enemy::setposition(int x, int y) {
	sprite->setPosition(origin.x + x, origin.y + y);

}

void Enemy::setdynamic(bool a) {
	sprite_Body->setDynamic(a);

}
int Enemy:: getposition_X() {
	
	return sprite->getPositionX();
}
int Enemy:: getposition_Y() {
	return sprite->getPositionY();
}