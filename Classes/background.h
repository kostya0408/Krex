
#ifndef _background_
#define _background_

#include"cocos2d.h"
//#include"Decoration.h"
#include<memory>
USING_NS_CC;
using namespace std;

class Background : public Layer
{
public:
	virtual bool init();
	
	/*shared_ptr<Decoration>cloud;*/
	
	Size  visibleSize = Director::getInstance()->getVisibleSize(); // auto = Size;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	 double score = 0;
	Label* scoreLabel;
	std::string tempScore;
	void update(float dt);

	CREATE_FUNC(Background);
};


#endif // !_background_

