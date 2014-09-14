#include"CreditScene.h"

USING_NS_CC;

cocos2d::Scene* CreditScene::createScene(){
	auto scene = cocos2d::Scene::create();

	auto layer = CreditScene::create();

	scene->addChild(layer);

	return scene;
}

bool CreditScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	cocos2d::Size WinSize = Director::getInstance()->getWinSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto back = Sprite::create("class01.png");

	back->setPosition(Vec2(WinSize.width / 2 + origin.x, WinSize.height / 2 + origin.y));

	this->addChild(back, 0);

	MoveVec = 800;

	addHuman();

	addLabel();

	this->schedule(schedule_selector(CreditScene::update));

	this->scheduleUpdate();

	return true;
}

void CreditScene::addHuman(){
	auto human = getChildByTag(1);
	if (!human){
		human = Sprite::create("girlR.png");
		human->setPosition(0, human->getContentSize().height);
		human->setTag(1);

		this->addChild(human);

	}

	auto move = MoveTo::create(2, Vec2(MoveVec - 220 , human->getContentSize().height));
	move->setTag(1);
	human->runAction(move);
}

void CreditScene::update(float dt){
	auto human = (Sprite *)this->getChildByTag(1);

	if (human->getActionByTag(1)){
		return;
	}
	
	if (MoveVec == 400) {
		human->setTexture("girlR.png");
		MoveVec = 1000;
	}
	else {
		human->setTexture("girlL.png");
		MoveVec = 400;
	}
	
	addHuman();
}

void CreditScene::addLabel(){
	Size winSize = Director::getInstance()->getWinSize();

	addChild(CreateLable("AT", Vec2(winSize.width / 2, -50), 3));

	addChild(CreateLable("cla-ckSE1", Vec2(winSize.width / 2, -150), 3.5));

	addChild(CreateLable("cla-ckSE2", Vec2(winSize.width / 2, -250), 4));
	
	addChild(CreateLable("cla-ckSE3", Vec2(winSize.width / 2, -350), 4.5));
	
	addChild(CreateLable("cla-ckSE4", Vec2(winSize.width / 2, -450), 5));
	
	addChild(CreateLable("cla-ckSE5", Vec2(winSize.width / 2, -550), 5.5));
	
	addChild(CreateLable("cla-ckSE6", Vec2(winSize.width / 2, -650), 6));
	
	addChild(CreateLable("cla-ckSE7", Vec2(winSize.width / 2, -750), 6.5));

	addChild(CreateLable("PG1", Vec2(winSize.width / 2, -850), 7));

	addChild(CreateLable("PG2", Vec2(winSize.width / 2, -950), 7.5));

	addChild(CreateLable("PG3", Vec2(winSize.width / 2, -1050), 8));
}

cocos2d::LabelTTF* CreditScene::CreateLable(std::string text, cocos2d::Vec2 pos, float time){
	Size winSize = Director::getInstance()->getWinSize();

	auto  label = LabelTTF::create(text,"Arial",60);
	label->setPosition(pos);

	auto move = MoveTo::create(time, Vec2(winSize.width / 2, winSize.height + 50));

	label->runAction(move);

	return label;
}