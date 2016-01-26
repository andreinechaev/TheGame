//
//  Spaceship.cpp
//  TheGame
//
//  Created by Andrei Nechaev on 1/25/16.
//
//

#include "Spaceship.h"


Spaceship::Spaceship(const std::string &name): _name(name) {

}

Spaceship::~Spaceship() {

}

Spaceship* Spaceship::create(const std::string &name, const std::string &filename) {
    Spaceship *sprite = new (std::nothrow) Spaceship(name);
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        sprite->_name = name;
        sprite->setScale(0.25, 0.25);

        return sprite;
    }
    CC_SAFE_DELETE(sprite);

    return nullptr;
}

int Spaceship::Compare(const Spaceship &sp) const {
    cocos2d::log("Comparing...");
    this->_name.compare(sp._name);
}

std::string &Spaceship::getShipName() { return _name; }

void Spaceship::moveTo(Vec2 dest) {
    Director::getInstance()->getActionManager()->removeAllActions();
    auto spriteLocation = this->getPosition();
    float distance = spriteLocation.distance(dest);
    auto direction = dest - spriteLocation;
    direction.normalize();

    const float offset = 90.f;

    float angle = -CC_RADIANS_TO_DEGREES(direction.getAngle()) + offset;

    float speed = 100.f;

    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions{};
    auto actionRotate = cocos2d::RotateTo::create(0.4, angle);
    auto actionMove = cocos2d::MoveTo::create(distance / speed, dest);

    actions.pushBack(actionRotate);
    actions.pushBack(actionMove);
    auto sequence = cocos2d::Sequence::create(actions);
    this->runAction(sequence);
}
