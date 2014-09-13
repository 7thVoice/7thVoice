#ifndef SCHOOLROOM_H
#define SCHOOLROOM_H

#include "cocos2d.h"

class SchoolRoom : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void reset();

	CREATE_FUNC(SchoolRoom);
};
#endif