#include "LayerManager.h"

void LayerManager::MoveRight(Layer* layer ,int* layerNum,float moveX)
{
    int tttt = (*layerNum);
    if(moveX>=5&& tttt <7)
    {
        (*layerNum)++;
        //layer->setPosition(-Director::getInstance()->getVisibleSize().width*x,0);
        auto move=MoveTo::create(1.0f, Point(-Director::getInstance()->getWinSize().width * ((*layerNum) - 1) ,0.0f));
        move->setTag(1);
        layer->runAction(move);
    }
}
void LayerManager::MoveLeft(Layer* layer,int* layerNum,float moveX)
{
	int tttt = (*layerNum);
    if(moveX<=-5 && (*layerNum) != 1)
    {
        (*layerNum)--;
        //layer->setPosition(-Director::getInstance()->getVisibleSize().width*x,0);
		auto move = MoveTo::create(1.0f, Point(-Director::getInstance()->getWinSize().width  * ((*layerNum) - 1), 0.0f));
        move->setTag(1);
        layer->runAction(move);
		if ((*layerNum) == 0) (*layerNum) = 1;
    }
}

bool LayerManager::MoveCheck(Layer* layer)
{
    
    if(!layer->getActionByTag(1)){
        return false;
    }
    
    return true;
}