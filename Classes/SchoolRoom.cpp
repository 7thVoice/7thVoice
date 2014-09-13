#include "schoolroom.h"
#include <random>

USING_NS_CC;

Scene* SchoolRoom::createScene()
{
	auto scene = Scene::create();

	auto layer = SchoolRoom::create();

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

	//backGround->setScale(0.6f);
	this->addChild(backGround, 0);
	
	auto schoolObj = Sprite::create("game.png");

	int randX = rand() % (int)visibleSize.width;
	int randY = rand() % (int)visibleSize.height;

	schoolObj->setPosition(Vec2(randX,randY));

	schoolObj->setScale(0.5f);

	this->addChild(schoolObj, 0);

	return true;
}
