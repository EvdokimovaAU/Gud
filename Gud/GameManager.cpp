#include "GameManager.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

GameManager::GameManager() :
    player(std::make_shared<Player>(60, 100, 5000)),
    shop(std::make_shared<Shop>(player)) {

    // ������������� ���� ������� ����
    levels.push_back(std::make_unique<Level1>(this));  // ������� 1
    levels.push_back(std::make_unique<Level2>(this));  // ������� 2
    levels.push_back(std::make_unique<Level3>(this));  // ������� 3
    // ����� �������� ������ ������� �� ��������:
    // levels.push_back(std::make_unique<Level4>(this));
    // levels.push_back(std::make_unique<Level5>(this));
}

void GameManager::startGame() {
    gameRunning = true;
    if (!levels.empty()) {
        levels[currentLevel]->start();  // �������� � ������� ������
    }
}

void GameManager::nextLevel() {
    currentLevel++;
    if (currentLevel < levels.size()) {
        levels[currentLevel]->start();  // ��������� ��������� �������
    }
    else {
        winGame();  // ���� ������ ����������� - ������
    }
}

void GameManager::winGame() {
    gameRunning = false;
    std::cout << "�� ������� ������ ����! :D" << std::endl;
}

void GameManager::loseGame() {
    gameRunning = false;
    std::cout << "�� ���������" << std::endl;
}