//
//  LayerFactory.cpp
//  7th_Voice
//
//  Created by Mac on 9/14/14.
//
//

#include "LayerFactory.h"
#include "schoolroom.h"
LayerFactory::LayerFactory()
:CreateCount(0){}
    


void LayerFactory::CreateLayer(Layer* layer,Color4B color,Size size)
{
    auto layer2 = LayerColor::create(color);
    CreateCount++;
    layer2->setContentSize(size);
    Size wi=Director::getInstance()->getWinSize();
    layer2->setPosition(wi.width*CreateCount, 0);
    layer->addChild(layer2);
}

void LayerFactory::CreateLayer(Layer* layer)
{
	auto childlayer = SchoolRoom::create();
	CreateCount++;
	childlayer->setTag(CreateCount + 1);
	Size wi = Director::getInstance()->getWinSize();
	childlayer->setPosition(wi.width*CreateCount, 0);
	layer->addChild(childlayer);
}