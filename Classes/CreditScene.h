#ifndef CREDITSCENE_H
#define CREDITSCENE_H

#include "cocos2d.h"

class CreditScene : public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CreditScene);

	void addHuman();

	cocos2d::LabelTTF* CreateLable(std::string text, cocos2d::Vec2 pos, float time);

	void update(float dt);

	void addLabel();
private:
	int MoveVec;
};

#endif