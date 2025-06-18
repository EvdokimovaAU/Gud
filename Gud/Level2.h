#pragma once
#include "LevelBase.h"
#include "Enemy.h"
#include "Shop.h"
#include "Text.h"

class Level2 : public LevelBase {
private:
    int killers = 0;
    Enemy enemy;
    std::shared_ptr<Shop> shop;

    enum class State {
        START,
        ATTACK,
        TRAP,
        PEOPLE_ATTACK,
        ATTACK_PLACE,
        STRATEGY_ATTACK,
        CONTINUE_STRAT,
        FINAL_PART
    };

    State currentState = State::START;

public:
    explicit Level2(GameManager* manager);
    void start() override;

private:
    void attack();
    void trap();
    void peopleAttack();
    void attackPlace();
    void strategyAttack();
    void continueStrat();
    void finalPart();

    bool checkResources(int money, int gun = 0, int grenade = 0);
};

