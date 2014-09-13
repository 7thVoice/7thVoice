#include "GameLayer.h"

USING_NS_CC;

//�V�[������
Scene* GameLayer::createScene()
{
	auto scene = Scene::create();		//�V�[������
	auto layer = GameLayer::create();   //GameLayer�N���X�̃��C���[�𐶐�
	scene->addChild(layer);				//�V�[���ɑ΂��ă��C���[��ǉ�

	return scene;
}

//������
bool GameLayer::init()
{
	if (!Layer::init())
		return false;
	
	return true;
}
