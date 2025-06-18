#include "GameManager.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

GameManager::GameManager() :
    player(std::make_shared<Player>(60, 100, 5000)),
    shop(std::make_shared<Shop>(player)) {

    // Инициализация всех уровней игры
    levels.push_back(std::make_unique<Level1>(this));  // Уровень 1
    levels.push_back(std::make_unique<Level2>(this));  // Уровень 2
    levels.push_back(std::make_unique<Level3>(this));  // Уровень 3
    // Можно добавить больше уровней по аналогии:
    // levels.push_back(std::make_unique<Level4>(this));
    // levels.push_back(std::make_unique<Level5>(this));
}

void GameManager::startGame() {
    gameRunning = true;
    if (!levels.empty()) {
        levels[currentLevel]->start();  // Начинаем с первого уровня
    }
}

void GameManager::nextLevel() {
    currentLevel++;
    if (currentLevel < levels.size()) {
        levels[currentLevel]->start();  // Запускаем следующий уровень
    }
    else {
        winGame();  // Если уровни закончились - победа
    }
}

void GameManager::winGame() {
    gameRunning = false;
    std::cout << "Вы успешно прошли игру! :D" << std::endl;
}

void GameManager::loseGame() {
    gameRunning = false;
    std::cout << "Вы проиграли" << std::endl;
}