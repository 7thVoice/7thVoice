#include "TableCreater.h"

cocos2d::Sprite* TableCreater::Create(std::string ObjName){

	auto sprite = cocos2d::Sprite::create(ObjName);

	return sprite;
}

cocos2d::Sprite* TableCreater::Create(std::string ObjName, cocos2d::Vec2 pos)
{
	auto sprite = cocos2d::Sprite::create(ObjName);

	sprite->setPosition(pos);

	sprite->setScale(0.8);

	return sprite;
}