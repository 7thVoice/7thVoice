#ifndef CHAIRCREARER_H
#define CHAIRCREARER_H

#include "cocos2d.h"

class ChairCreater{

public:
	cocos2d::Sprite* Create(std::string ObjName);

	cocos2d::Sprite* Create(std::string ObjName, cocos2d::Vec2 pos);
};
#endif