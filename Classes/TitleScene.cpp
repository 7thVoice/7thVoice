#include "TitleScene.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TitleScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//ƒ{ƒ^ƒ“ì¬
	auto closeItem = MenuItemImage::create(
		"teach.png",
		"Onbutton.png",
		CC_CALLBACK_1(TitleScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width / 2 ,
		origin.y + closeItem->getContentSize().height / 3 ));
	
	closeItem->setRotation(90);
	closeItem->setScale(0.6);
	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	
	auto label = LabelTTF::create("7thVoice", "Arial", 56);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	auto buttonlabel = LabelTTF::create("Push State", "Arial", 56);

	buttonlabel->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 3.5));

	this->addChild(buttonlabel, 1);
	// add "TitleScene" splash screen"
	auto sprite = Sprite::create("class01.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	addHuman();

	this->schedule(schedule_selector(TitleScene::update));
	
	this->scheduleUpdate();

	return true;
}

void TitleScene::addHuman(){
	auto human = Sprite::create("boyR.png");
	human->setPosition(Vec2(0, human->getContentSize().height));

	human->setTag(1);

	this->addChild(human);

	auto move = MoveTo::create(3, Vec2(Director::getInstance()->getWinSize().width, human->getContentSize().height));
	move->setTag(1);
	human->runAction(move);
}


void TitleScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void TitleScene::update(float dt){
	auto human = (Sprite *)this->getChildByTag(1);

	if (human->getActionByTag(1)){
		return;
	}
	this->removeChildByTag(1);

	addHuman();
}