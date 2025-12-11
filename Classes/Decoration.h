
#ifndef _Decoration_
#define _Decoration_

#include"cocos2d.h"

using namespace cocos2d;
using namespace std;


class Decoration
{
public:
	Decoration(Layer* layer, std::string name);


	void setposition(int x, int y);
	void sethitbox(bool a);



	~Decoration() = default;

private:
	Sprite* sprite = nullptr;
	
	Size  visibleSize = Director::getInstance()->getVisibleSize(); // auto = Size;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

};


#endif // !_Decoration_




