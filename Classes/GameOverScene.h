#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameOverScene);
};
#endif