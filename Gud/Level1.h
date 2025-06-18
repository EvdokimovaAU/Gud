#pragma once
#include "LevelBase.h"
#include "Enemy.h"
#include "Shop.h"
#include "Text.h"

class Level1 : public LevelBase {
private:
    Enemy enemy;
    int killers = 0;
    std::shared_ptr<Shop> shop;

    // Состояния уровня
    enum class State {
        START,
        DESTROY_ENEMY,
        NEGOTIATIONS,
        PEOPLE_DESERT,
        STRATEGY_DESERT,
        LOSE_OR_WIN,
        ENEMYS_LAIR,
        STRATEGY_LAIR
    };

    State currentState = State::START;

public:
    explicit Level1(GameManager* manager);
    void start() override;

private:
    // Основные ветки сценария
    void destroyEnemy();
    void negotiations();

    // Пустынный сценарий
    void peopleDesert();
    void strategyDesert();
    void loseOrWin();

    // Сценарий логова
    void enemysLair();
    void strategyLair();

    // Вспомогательные методы
    void handleInvalidChoice();
    bool checkPlayerResources(int requiredMoney, int requiredGun = 0);
    void applyDamageToEnemy(int damage);
    void applyDamageToPlayer(int damage);
    void applyMoneyChange(int amount);
    void applyInfluenceChange(int amount);
};
