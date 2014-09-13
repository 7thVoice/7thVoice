#ifndef SCHOOLROOMFACTORY_H
#define SCHOOLROOMFACTORY_H

#include "cocos2d.h"
#include <vector>

class TableCreater;
class ChairCreater;
class MainScene;

class SchoolRoomFactory
{
public:
	void SchoolRoomCreate(cocos2d::Layer* layer);

	void Remove(cocos2d::Layer* layer);

	void Init(cocos2d::Layer* layer);

	cocos2d::Sprite* createRoom(int layerNum);

private:
	void addList();
};

#endif