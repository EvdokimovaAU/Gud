#pragma once
#include "LevelBase.h"
#include "Enemy.h"
#include "Shop.h"
#include "Text.h"

class Level3 : public LevelBase {
private:
    Enemy enemy;
    std::shared_ptr<Shop> shop;

    enum class State {
        START,
        MEETING,
        NO_MEETING,
        SPY,
        CLEVER_SPY,
        SHOOTING,
        LABORATORY,
        KIDNAP_SCIENTISTS
    };

    State currentState = State::START;

public:
    explicit Level3(GameManager* manager);
    void start() override;

private:
    void meeting();
    void noMeeting();
    void spy();
    void cleverSpy();
    void shooting();
    void laboratory();
    void kidnapScientists();

    bool checkResources(int money, int gun = 0, int grenade = 0);
};

