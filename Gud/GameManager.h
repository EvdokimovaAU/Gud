#pragma once
#include <memory>
#include <vector>
#include "LevelBase.h"
#include "Player.h"
#include "Shop.h"

class GameManager {
private:
    std::shared_ptr<Player> player;
    std::shared_ptr<Shop> shop;
    std::vector<std::unique_ptr<LevelBase>> levels;
    size_t currentLevel = 0;
    bool gameRunning = false;

public:
    GameManager();
    void startGame();
    void winGame();
    void loseGame();
    void nextLevel();

    std::shared_ptr<Player> getPlayer() const { return player; }
    std::shared_ptr<Shop> getShop() const { return shop; }
    bool isGameRunning() const { return gameRunning; }
};

