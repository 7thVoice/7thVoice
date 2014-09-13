//
//  LayerFactory.h
//  7th_Voice
//
//  Created by Mac on 9/14/14.
//
//

#ifndef ___th_Voice__LayerFactory__
#define ___th_Voice__LayerFactory__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
class LayerFactory
{
public:
    LayerFactory();
    void CreateLayer(Layer* layer,Color4B color,Size size);
	void CreateLayer(Layer* layer);
    int CreateCount;
};

#endif /* defined(___th_Voice__LayerFactory__) */
