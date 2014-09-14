#include "GameOverScene.h"

USING_NS_CC;

cocos2d::Scene* GameOverScene::createScene(){
	auto scene = cocos2d::Scene::create();

	auto layer = GameOverScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameOverScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	cocos2d::Size WinSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = LabelTTF::create("GameOver", "Arial", 56);


	label->setPosition(Vec2(origin.x + WinSize.width / 2,
		origin.y + WinSize.height - label->getContentSize().height));

	this->addChild(label, 1);
}