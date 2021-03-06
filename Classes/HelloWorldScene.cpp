#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("GraphPaperBackground.jpg");
    // position the sprite on the center of the screen
    background->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(background);

    auto shape1 = Sprite::create("shapes/circle.png");
    // position the sprite on the center of the screen
    shape1->setPosition(Vec2(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));
    shape1->setScale(4);
    // add the sprite as a child to this layer
    this->addChild(shape1);

    auto shape2 = Sprite::create("shapes/square.png");
    // position the sprite on the center of the screen
    shape2->setPosition(Vec2(3 * visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));
    shape2->setScale(4);
    // add the sprite as a child to this layer
    this->addChild(shape2);

    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);

    auto dispatcher = this->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

inline Point locationInGLFromTouch(Touch& touch)
{
	auto director = Director::getInstance();
	return director->convertToGL(touch.getLocationInView());
}

void HelloWorld::onTouchesBegan(const vector<Touch*>& touches, Event* event)
{

}

void HelloWorld::onTouchesMoved(const vector<Touch*>& touches, Event* event)
{
	for (auto& touch : touches)
	{
		if (touch)
		{
			drawCircle(locationInGLFromTouch(*touch));
		}
	}
}

void HelloWorld::onTouchesEnded(const vector<Touch*>& touches, Event* event)
{

}

void HelloWorld::drawCircle(const Point& location)
{
	DrawNode *circle = DrawNode::create();
	circle->drawDot(location, 10, Color4F::BLACK);
	this->addChild(circle);
}
