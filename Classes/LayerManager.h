#ifndef ___th_Voice__LayerManager__
#define ___th_Voice__LayerManager__

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;
class LayerManager
{
public:
    void MoveRight(Layer* layer,int* layerNum,float moveX );
    void MoveLeft(Layer* layer,int* layerNum,float moveX);
    bool MoveCheck(Layer* layer);
};

#endif /* defined(___th_Voice__LayerManager__) */
