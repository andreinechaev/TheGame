#pragma once

#include "cocos2d.h"
#include "TheGameWebSocket.h"
#include "Spaceship.h"
#include <set>

class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;

    CREATE_FUNC(HelloWorld);

//    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);

    virtual void update(float delta) override;

    std::string createJSON(float x, float y);

    void setBackground(const char* filename);

private:
    Spaceship *_spaceship;
    std::set<Spaceship *> _spaceships;
    TheGameWebSocket *_webSocket;
};