#ifndef SCHOOLROOM_H
#define SCHOOLROOM_H

#include "cocos2d.h"

class SchoolRoom : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void reset(Ref* sender);
	
	cocos2d::Sprite* createRoom(int layerNum);

	CREATE_FUNC(SchoolRoom);

private:
	int layerNumber;
};
#endif