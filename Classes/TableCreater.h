#ifndef TABLECREARER_H
#define TABLECREARER_H

#include "cocos2d.h"

class TableCreater{
public:
	cocos2d::Sprite* Create(std::string ObjName);

	cocos2d::Sprite* Create(std::string ObjName, cocos2d::Vec2 pos);
};
#endif