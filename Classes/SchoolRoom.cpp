#include "schoolroom.h"
#include <random>
#include "ChairCreater.h"
#include "TableCreater.h"
#include "SchoolRoomFactory.h"



enum LAYERNUMBER{
	LAYERONE = 0,
	LAYERTWO,
	LAYERTHREE,
	LAYERFOUR,
	LAYERFIVE,
	LAYERSIX,
	LAYERSEVEN,
};

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
	Size WinSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	layerNumber = 0;

	auto backGround = createRoom(layerNumber);

	backGround->setPosition(Vec2(WinSize.width / 2 + origin.x, WinSize.height / 2 + origin.y));

	this->addChild(backGround, 0);
	
	auto resetbotton = MenuItemImage::create(
											 "CloseNormal.png",
										     "CloseSelected.png",
											 CC_CALLBACK_1(SchoolRoom::reset, this));

	auto menu = Menu::create(resetbotton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void SchoolRoom::reset(Ref* sender)
{
	SchoolRoomFactory sf;
	
	auto layer = (cocos2d::Layer *)this->getParent()->getChildByTag(1);
	
	sf.Remove(layer);

	layerNumber++; if (layerNumber > 6) layerNumber = 0;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = createRoom(layerNumber);
	backGround->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	layer->addChild(backGround, 0);


	auto resetbotton = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(SchoolRoom::reset, this));

	auto menu = Menu::create(resetbotton, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	if (layerNumber > 5) return;
	sf.Init(layer);
}

Sprite* SchoolRoom::createRoom(int layerNum){
	
	Sprite* stageSprite;

	switch (layerNum)
	{
	case LAYERONE:
		stageSprite = Sprite::create("class01.png");
		break;
	case LAYERTWO:
		stageSprite = Sprite::create("class02.png");
		break;
	case LAYERTHREE:
		stageSprite = Sprite::create("class03.png");
		break;
	case LAYERFOUR:
		stageSprite = Sprite::create("class01.png");
		break;
	case LAYERFIVE:
		stageSprite = Sprite::create("class02.png");
		break;
	case LAYERSIX:
		stageSprite = Sprite::create("class03.png");
		break;
	case LAYERSEVEN:
		stageSprite = Sprite::create("top.png");
		break;
	default:
		break;
	}

	return stageSprite;
}