#pragma once
#include <memory>

class GameManager;

class LevelBase {
protected:
    GameManager* gameManager;

public:
    explicit LevelBase(GameManager* manager) : gameManager(manager) {}
    virtual ~LevelBase() = default;

    virtual void start() = 0;
};

