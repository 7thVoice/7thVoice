#include "SchoolRoomFactory.h"

#include "TableCreater.h"
#include "ChairCreater.h"
#include "MainScene.h"
#include <random>

USING_NS_CC;

#define CHAIRMAX 2
#define TABLEMAX 4

namespace{
	static	std::vector<cocos2d::Vec2> chairPosList;
	static	std::vector<cocos2d::Vec2> tablePosList;
}

void SchoolRoomFactory::addList(){
	if (tablePosList.size() == 0){

		cocos2d::Vec2 LeftDown = cocos2d::Vec2(400, 280);
		cocos2d::Vec2 LeftUp = cocos2d::Vec2(400, 550);
		cocos2d::Vec2 RightDown = cocos2d::Vec2(720, 280);
		cocos2d::Vec2 RightUp = cocos2d::Vec2(720, 550);

		tablePosList.push_back(LeftDown);
		tablePosList.push_back(LeftUp);
		tablePosList.push_back(RightDown);
		tablePosList.push_back(RightUp);
	}
	if (chairPosList.size() == 0){
		cocos2d::Vec2 Down = cocos2d::Vec2(550, 280);
		cocos2d::Vec2 Up = cocos2d::Vec2(550, 550);

		chairPosList.push_back(Down);
		chairPosList.push_back(Up);
	}
}


void  SchoolRoomFactory::SchoolRoomCreate(cocos2d::Layer* layer)
{ 
	addList();

	int startNum = rand() % TABLEMAX;
	int CreateNum = rand() % TABLEMAX / 2 + TABLEMAX / 2;

	TableCreater tc;

	for (int i = 0; i < CreateNum; i++){
		layer->addChild(tc.Create("table.png", tablePosList.at(startNum)));
		startNum++;
		if (startNum > 3) startNum = 0;
	}

	ChairCreater cc;

	startNum = rand() % CHAIRMAX;
	CreateNum = rand() % CHAIRMAX + CHAIRMAX / 2;

	for (int i = 0; i < CreateNum; i++){
		layer->addChild(cc.Create("chair.png", chairPosList.at(startNum)));
		startNum++;
		if (startNum > 1) startNum = 0;
	}
}
void SchoolRoomFactory::Remove(cocos2d::Layer* layer){
	layer->removeAllChildren();
}

void SchoolRoomFactory::Init(cocos2d::Layer* layer){

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = Sprite::create("class01.png");	
	backGround->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	layer->addChild(backGround, 0);

	SchoolRoomCreate(layer);
}