#include "schoolroom.h"
#include <random>
#include "ChairCreater.h"
#include "TableCreater.h"
#include "SchoolRoomFactory.h"


USING_NS_CC;

Scene* SchoolRoom::createScene()
{
	auto scene = Scene::create();

	auto layer = SchoolRoom::create();
	layer->setTag(1);

	SchoolRoomFactory sf;
	sf.SchoolRoomCreate(layer);

	scene->addChild(layer);

	return scene;
}

bool SchoolRoom::init()
{
	srand((unsigned)time(NULL));

	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = Sprite::create("class01.png");

	backGround->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backGround, 0);
	
	return true;
}

void SchoolRoom::reset()
{
	SchoolRoomFactory sf;
	
	auto layer = (cocos2d::Layer *)this->getParent()->getChildByTag(1);
	
	sf.Remove(layer);

	sf.Init(layer);
}